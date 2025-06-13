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
    
    process_args(MyArg(10), MyArg(20));  //
    
    std::cout << "--- Main End ---" << std::endl;
    return 0;
}
/*
--- Main Start ---
Constructing MyArg: 20
Constructing MyArg: 10
Inside process_args: a1.val=10, a2.val=20
Destroying MyArg: 10
Destroying MyArg: 20
--- Main End ---
*/