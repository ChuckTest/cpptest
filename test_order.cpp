#include <iostream>

struct MyArg {
    int val;
    // Constructor
    MyArg(int v) : val(v) {
        std::cout << "Constructing MyArg: " << val << std::endl;
    }
    // Copy Constructor
    MyArg(const MyArg& other) : val(other.val) {
        std::cout << "Copying MyArg: " << val << std::endl;
    }
    // Destructor (optional, but good for tracking lifetime)
    ~MyArg() {
        std::cout << "Destroying MyArg: " << val << std::endl;
    }
};

void process_args(MyArg a1, MyArg a2) {
    std::cout << "Inside process_args: a1.val=" << a1.val << ", a2.val=" << a2.val << std::endl;
}

int main() {
    std::cout << "--- Main Start ---" << std::endl;
    
    // 方法1：通过已存在的对象传参
    MyArg obj1(10);
    MyArg obj2(20);
    std::cout << "--- Calling with existing objects ---" << std::endl;
    process_args(obj1, obj2);  // 这会触发复制构造
    
    std::cout << "--- Main End ---" << std::endl;
    return 0;
}
/*
--- Main Start ---
Constructing MyArg: 10          // 1. obj1 构造
Constructing MyArg: 20          // 2. obj2 构造
--- Calling with existing objects ---
Copying MyArg: 20               // 3. obj2 → a2 (参数复制，右到左)
Copying MyArg: 10               // 4. obj1 → a1 (参数复制，右到左)
Inside process_args: a1.val=10, a2.val=20  // 5. 函数执行
Destroying MyArg: 10            // 6. a1 析构 (函数结束)
Destroying MyArg: 20            // 7. a2 析构 (函数结束)
--- Main End ---
Destroying MyArg: 20            // 8. obj2 析构 (main结束，LIFO顺序)
Destroying MyArg: 10            // 9. obj1 析构 (main结束，LIFO顺序)
*/