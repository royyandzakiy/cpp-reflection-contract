```cpp
g++16 -std=c++26 test26.cpp -o test26
./test26 
Directly from GCC 16!
Directly from GCC 16!
Directly from GCC 16!
```
```cpp
royya@tuff16:~/project-coding/cpp/202605/test-cpp26$ g++16 -o reflection reflection.cpp -std=c++23
royya@tuff16:~/project-coding/cpp/202605/test-cpp26$ ./reflection 
=== Simple Reflection Demo ===
Variable: name  | Type: string | Value: HelloWorld
Variable: value | Type: int    | Value: 42
Variable: pi    | Type: double | Value: 3.14159

=== RTTI Reflection ===
Type of 'name': NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
Type of 'value': i
Type of 'pi': d
royya@tuff16:~/project-coding/cpp/202605/test-cpp26$ ./reflection | c++filt -t
=== Simple Reflection Demo ===
Variable: name  | Type: string | Value: HelloWorld
Variable: value | Type: int    | Value: 42
Variable: pi    | Type: double | Value: 3.14159

=== RTTI Reflection ===
Type of 'name': std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >
Type of 'value': int
Type of 'pi': double
royya@tuff16:~/project-coding/cpp/202605/test-cpp26$ 
```