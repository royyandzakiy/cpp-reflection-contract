#include <iostream>
#include <vector>

int main() {
    // C++26: Placeholder variables
    for (auto _ : {1, 2, 3}) {
        std::cout << "Directly from GCC 16!" << std::endl;
    }

    // C++26: User-generated static_assert messages (experimental)
    static_assert(true, "This will compile");
    
    return 0;
}