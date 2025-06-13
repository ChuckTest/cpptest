#include <iostream>

int id(int val) {
    std::cout << "Evaluating argument: " << val << std::endl;
    return val;
}

struct MyArg {
    MyArg(int v) {
        std::cout << "Constructing MyArg(" << v << ")" << std::endl;
    }
};

void test(MyArg a, MyArg b) {
    std::cout << "In test()" << std::endl;
}

int main() {
    std::cout << "--- Start ---" << std::endl;
    test(MyArg(id(1)), MyArg(id(2)));
    std::cout << "--- End ---" << std::endl;
}

/*
--- Start ---
Evaluating argument: 2
Constructing MyArg(2)
Evaluating argument: 1
Constructing MyArg(1)
In test()
--- End ---
*/
