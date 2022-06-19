//
// Created by sergiy on 18/06/22.
//

#include <iostream>

// main types
// статически типизированный язык - тип переменной определяется один раз при ее создании (его нельзя изменить)
// динамически типизированный язык - тип переменной меняется

int integer_types() {
    short a; // 2-bytes -32768...32767
    int b; // 4-bytes = 32-bit = -2^31...2^31-1 = [2'147'483'647]
    long c; // 4-bytes
    long long d; // 8-bytes = -2^63...2^63-1
    unsigned long long e; // [0....~18*10^18]
    a = a + b - c * d %  e & a | b ^ c;


    char ch = 'a';
    std::cout << ch + 'b';
    return 0;
}

float floating_point() {
    float f;//4bytes
    double d;//8bytes
    long double ld;//16bytes
    return f+d-ld/d*f;
}


bool logical() {
    bool b = true;//1byte = 8bites
    return b||b&&b;
}


std::string strings() {
    std::string str;
    str[0] == 'a';
    return str;
}

std::vector<int> vec() {
    std::vector<int> vec = {1, 2, 3, 4};
        v.push_back(111);

    set;
    ,
}