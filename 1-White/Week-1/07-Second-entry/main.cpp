/*
 * Дана строка. Найдите в этой строке второе вхождение буквы f и выведите
 * индекс этого вхождения. Если буква f в данной строке встречается только один
 * раз, выведите число -1, а если не встречается ни разу, выведите число -2.
 * Индексы нумеруются с нуля.
 */
#include <iostream>
#include <string>

int main() {
    using namespace std;

    string s;
    cin >> s;

    int i, f = -2;
    for (i = 0; i < s.size(); ++i) {
        if (s[i] == 'f') {
            ++f;
            if (f == 0) {
                break;
            }
        }
    }
    cout << (f == 0 ? i : f);
}
