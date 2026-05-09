# C++26: Reflection, Contract

## Contract
```cpp
// g++ -std=c++26 contract.cpp -o contract
// ./contract 
Old balance: 100
Withdrawn:   40
New balance: 60
```

## Reflection
```cpp
// g++ -std=c++26 reflection.cpp -o reflection -freflection
// ./reflection 
Point { x = 3, y = 7 }
Person { name = Alice, age = 30 }
Person { name = Bob, age = 32 }
royya@tuff16:~/project-coding/cpp/202605/test-cpp26$ 
```

### Compared to RTTI "poor-mans reflection"
```cpp
// g++ -std=c++26 typeid.cpp -o typeid
// ./typeid 
=== Simple Reflection Demo ===
Variable: name  | Type: string | Value: HelloWorld
Variable: value | Type: int    | Value: 42
Variable: pi    | Type: double | Value: 3.14159

=== RTTI Reflection ===
Type of 'name': NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
Type of 'value': i
Type of 'pi': d
```

## Inplace Vector
```cpp
// g++ -std=c++26 inplace_vector.cpp -o inplace_vector
// ./inplace_vector 
Successfully added 40
Current size: 4
Max capacity: 5
Elements: 10 20 30 40 
```

## Placeholder
```cpp
// g++ -std=c++26 placeholder.cpp -o placeholder
// ./placeholder 
Directly from GCC 16!
Directly from GCC 16!
Directly from GCC 16!
```