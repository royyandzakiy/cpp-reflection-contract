#include <iostream>
#include <string>
#include <print>

int main() {
    std::println("=== Simple Reflection Demo ===");
    
    std::string name = "HelloWorld";
    int value = 42;
    double pi = 3.14159;
    
    // Simple "reflection" - just printing variable info
    std::println("Variable: name  | Type: string | Value: {}", name);
    std::println("Variable: value | Type: int    | Value: {}", value);
    std::println("Variable: pi    | Type: double | Value: {}", pi);
    
    // Using typeid for basic RTTI reflection
    std::println("\n=== RTTI Reflection ===");
    std::println("Type of 'name': {}", typeid(name).name());
    std::println("Type of 'value': {}", typeid(value).name());
    std::println("Type of 'pi': {}", typeid(pi).name());
    
    return 0;
}