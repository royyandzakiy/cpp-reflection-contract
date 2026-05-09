#include <iostream>
#include <inplace_vector>

int main() {
    // Create an inplace_vector that can hold up to 5 integers.
    // Capacity is fixed at 5, but size starts at 0.
    std::inplace_vector<int, 5> nums;

    // Standard modifiers work as usual
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);

    // try_push_back is a safe way to add elements without exceptions.
    // It returns a pointer to the new element, or nullptr if full.
    if (nums.try_push_back(40)) {
        std::cout << "Successfully added 40\n";
    }

    std::cout << "Current size: " << nums.size() << "\n";
    std::cout << "Max capacity: " << nums.capacity() << "\n";

    // You can iterate just like a normal vector
    std::cout << "Elements: ";
    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    // This would throw std::bad_alloc if we used push_back
    // but try_push_back just handles it gracefully
    nums.push_back(50);
    auto result = nums.try_push_back(60); 

    return 0;
}