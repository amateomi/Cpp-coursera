/*
 * Реализуйте шаблонную функцию GetRefStrict, которая на вход принимает: map и
 * значение ключа k. Если элемент по ключу k в коллекции отсутствует, то функция
 * должна бросить исключение runtime_error, иначе вернуть ссылку на элемент в
 * коллекции.
 */
#include <iostream>
#include <map>

using namespace std;

template<typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, const Key& k) {
  if (m.count(k) == 0) {
    throw runtime_error("no such key in map");
  }
  return m[k];
}

int main() {
  map<int, string> m = {{0, "value"}};
  string& item = GetRefStrict(m, 0);
  item = "newvalue";
  cout << m[0] << endl;
}
