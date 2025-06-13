#!/bin/bash

# 检查是否安装了 iconv
if ! command -v iconv &> /dev/null; then
    echo "错误: 需要 iconv 工具，但未安装。"
    exit 1
fi

# 查找所有 .cpp 文件（包括子目录）
find . -type f -name "*.cpp" | while read -r file; do
    # 临时文件
    temp_file="${file}.utf8"

    # 尝试用 GBK 转 UTF-8
    if iconv -f GBK -t UTF-8 "$file" > "$temp_file" 2>/dev/null; then
        # 替换原文件
        mv -f "$temp_file" "$file"
        echo "转换成功: $file"
    else
        # 如果转换失败，删除临时文件
        rm -f "$temp_file"
        echo "转换失败（可能不是 GBK 编码）: $file"
    fi
done

echo "所有 .cpp 文件处理完成！"