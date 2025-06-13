# 检测文件编码的函数
function Test-FileEncoding {
    param([string]$FilePath)
    
    $bytes = [System.IO.File]::ReadAllBytes($FilePath)
    
    # 检查 UTF-8 BOM
    if ($bytes.Length -ge 3 -and $bytes[0] -eq 0xEF -and $bytes[1] -eq 0xBB -and $bytes[2] -eq 0xBF) {
        return "UTF8-BOM"
    }
    
    # 检查是否为有效的UTF-8（无BOM）
    try {
        $utf8 = [System.Text.Encoding]::UTF8
        $decoded = $utf8.GetString($bytes)
        # 尝试重新编码，如果结果一致则可能是UTF-8
        $reencoded = $utf8.GetBytes($decoded)
        if ([System.Linq.Enumerable]::SequenceEqual($bytes, $reencoded)) {
            return "UTF8"
        }
    }
    catch {
        # UTF-8 解码失败
    }
    
    # 默认假设是 GBK/ANSI
    return "GBK"
}

# 查找所有 .cpp 文件（包括子目录）
Get-ChildItem -Path . -Filter "*.cpp" -Recurse | ForEach-Object {
    $file = $_.FullName
    $tempFile = "$file.utf8"
    
    # 检测文件编码
    $encoding = Test-FileEncoding -FilePath $file
    
    if ($encoding -eq "UTF8" -or $encoding -eq "UTF8-BOM") {
        Write-Host "跳过（已是UTF-8）: $file" -ForegroundColor Cyan
        return
    }
    
    try {
        # 读取 GBK 编码文件并转换为 UTF-8
        $content = Get-Content -Path $file -Encoding Default
        $content | Out-File -FilePath $tempFile -Encoding UTF8
        
        # 替换原文件
        Move-Item -Path $tempFile -Destination $file -Force
        Write-Host "转换成功: $file" -ForegroundColor Green
    }
    catch {
        # 如果转换失败，删除临时文件
        if (Test-Path $tempFile) {
            Remove-Item $tempFile -Force
        }
        Write-Host "转换失败: $file - $($_.Exception.Message)" -ForegroundColor Red
    }
}

Write-Host "所有 .cpp 文件处理完成！" -ForegroundColor Yellow