/*
 * Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить
 * в конец и уходить оттуда. Более того, иногда некоторые люди могут прекращать
 * и начинать беспокоиться из-за того, что очередь не продвигается.
 *
 * Будем считать, что люди в очереди нумеруются целыми числами, начиная с 0.
 *
 * Реализуйте обработку следующих операций над очередью:
 * - WORRY i: пометить i-го человека с начала очереди как беспокоящегося;
 * - QUIET i: пометить i-го человека как успокоившегося;
 * - COME k: добавить k спокойных человек в конец очереди;
 * - COME -k: убрать k человек из конца очереди;
 * - WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
 *
 * Изначально очередь пуста.
 *
 * Формат ввода
 * Количество операций Q, затем описания операций.
 * Для каждой операции WORRY i и QUIET i гарантируется, что человек с номером i
 * существует в очереди на момент операции.
 * Для каждой операции COME -k гарантируется, что k не больше текущего размера
 * очереди.
 *
 * Формат вывода
 * Для каждой операции WORRY_COUNT выведите одно целое число — количество
 * беспокоящихся людей в очереди.
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int q;
  cin >> q;

  // true - calm person
  // false - anxious person
  vector<bool> queue;
  for (int i = 0; i < q; ++i) {
    string command;
    cin >> command;
    if (command == "WORRY_COUNT") {
      cout << count(begin(queue), end(queue), false) << endl;
    } else {
      int n;
      cin >> n;
      if (command == "COME") {
        queue.resize(queue.size() + n, true);
      } else {
        queue[n] = command == "QUIET";
      }
    }
  }
}
