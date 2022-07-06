/*
 * Напишите функцию, которая
 * - называется Factorial
 * - возвращает int
 * - принимает int и возвращает факториал своего аргумента. Гарантируется,
 *   что аргумент функции по модулю не превышает 10. Для отрицательных
 *   аргументов функция должна возвращать 1.
 */
#include <iostream>

int Factorial(int n) {
    return n < 1 ? 1 : n * Factorial(n - 1);
}

int main() {
    std::cout << Factorial(4);
}