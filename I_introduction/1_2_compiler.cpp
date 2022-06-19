//
// Created by sergiy on 18/06/22.
//

//terminal pwd, cd, ls, cp, mv, rm, -v (version), man, ctrl+shift+t new tab in terminal
//vim :wq, :q!, :q
//I - insert mode, esc - leave Insert mode

#include <iostream>

int main() {
    int x;
    std::cin >> x;
    std::cout << '\n' << x + 5 << '\n';
}

//cat main.cpp
//g++ main.cpp
// a.out - will not work (because Linux looks for executable files in special directory)
// ./a.out - we will look for a.out in current directory


// g++
// clang (c) main.c - clang++ (c++) main.cpp

// g++ -std=c++11 main.cpp
// ? g++ -std=c++14 main.cpp
// g++ -std=c++17 main.cpp
// g++ -std=c++20 main.cpp
// g++-10 -std=c++20 main.cpp