/*
 * Написать программу вычисления стоимости покупки товара с учётом скидки. Если
 * исходная стоимость товара больше A рублей, то на неё устанавливается скидка
 * в X процентов. Если исходная стоимость товара больше B рублей, то на неё
 * устанавливается скидка в Y процентов.
 *
 * На вход программе даны пять вещественных чисел:
 * N, A, B, X, Y (A < B) - где N - исходная стоимость товара.
 * Выведите стоимость покупки товара с учётом скидки.
 */
#include <iostream>

int main() {
    using namespace std;

    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;

    if (n > b) {
        cout << n * (1 - y / 100);
    } else if (n > a) {
        cout << n * (1 - x / 100);
    } else {
        cout << n;
    }
}
