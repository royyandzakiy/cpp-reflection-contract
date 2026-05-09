#include <iostream>
#include <string>

int main() {
    std::cout << "=== Simple Reflection Demo ===\n";
    
    std::string name = "HelloWorld";
    int value = 42;
    double pi = 3.14159;
    
    // Simple "reflection" - just printing variable info
    std::cout << "Variable: name  | Type: string | Value: " << name << "\n";
    std::cout << "Variable: value | Type: int    | Value: " << value << "\n";
    std::cout << "Variable: pi    | Type: double | Value: " << pi << "\n";
    
    // Using typeid for basic RTTI reflection
    std::cout << "\n=== RTTI Reflection ===\n";
    std::cout << "Type of 'name': " << typeid(name).name() << "\n";
    std::cout << "Type of 'value': " << typeid(value).name() << "\n";
    std::cout << "Type of 'pi': " << typeid(pi).name() << "\n";
    
    return 0;
}