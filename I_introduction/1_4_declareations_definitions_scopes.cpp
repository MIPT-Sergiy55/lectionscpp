//
// Created by sergiy on 19/06/22.
//

/*
 * int main() {
 *  ...;
 *  ...; ...;
 *
 *  ...;
 * }
 *
 * statements - то, после чего стоит;
 * statements три типа:
 * declarations
 * expressions
 * control statements
 */

#include <iostream>

char y = 'c'; // global scope

int h(int x){
    return x + y;
}

int main() {
    int x = 5; // local scope
}

// declaration != definition (not initialization)
// any definition iаs declaration

// One Definition Rule

// объявление и определение для переменных почти всегда одно и тоже, но для функций - нет
// мотивировка:

int f(x) {
    return g(x);
}

int g(x) {
    return f(x);
}

// более локальная переменная затмевает более глобальную

int x = 3;

void a() {
    int x = 5;
    if(true) {
        char x = '6';
        std::cout << x;
        std::cout << ::x; // к глобальному (который int x = 3) и только к нему, к тому который в main нельзя никак вроде
    }
}