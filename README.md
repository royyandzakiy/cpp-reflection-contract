# C++26: Reflection, Contract

Implementing latest functions of C++26. Tested on WSL2 Ubuntu 24.04.

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

---

## Acquire gcc v16.1 on linux machine
```bash
sudo apt update
sudo apt install build-essential libmpfr-dev libgmp3-dev libmpc-dev flex bison -y

cd ~
wget https://ftp.gnu.org/gnu/gcc/gcc-16.1.0/gcc-16.1.0.tar.gz
tar -xf gcc-16.1.0.tar.gz
cd gcc-16.1.0

# Download support libraries
./contrib/download_prerequisites

# Create a separate build directory (GCC docs recommend this)
mkdir build && cd build

# Configure the build
# --disable-multilib: Speeds things up by only building for 64-bit
# --enable-languages: We only need C and C++
../configure -v \
    --build=x86_64-linux-gnu \
    --host=x86_64-linux-gnu \
    --target=x86_64-linux-gnu \
    --prefix=$HOME/gcc-16.1.0 \
    --enable-checking=release \
    --enable-languages=c,c++ \
    --disable-multilib

make -j6

sudo make install

# Verify the version
~/gcc-16.1.0/bin/g++ --version

# Compile your project
~/gcc-16.1.0/bin/g++ -std=c++26 -freflection reflection.cpp -o reflection
```