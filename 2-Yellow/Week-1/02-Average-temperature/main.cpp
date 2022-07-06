/*
 * Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
 * Найдите номера дней (в нумерации с нуля) со значением температуры выше
 * среднего арифметического за все N дней.
 * Гарантируется, что среднее арифметическое значений температуры является целым
 * числом.
 *
 * Формат ввода:
 * Вводится число N, затем N целых чисел — значения температуры в 0-й, 1-й, ...
 * (N−1)-й день. Гарантируется, что N не превышает миллиона (10^6), а значения
 * температуры, измеряющиеся в миллионных долях градусов по Цельсию, лежат в
 * диапазоне от −10^8 до 10^8. Проверять соблюдение этих ограничений не нужно:
 * вы можете ориентироваться на них при выборе наиболее подходящих типов для
 * переменных.
 *
 * Формат вывода:
 * Первое число K — количество дней, значение температуры в которых выше
 * среднего арифметического. Затем K целых чисел — номера этих дней.
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <cinttypes>

using namespace std;

int32_t AvgTemperature(const vector<int32_t>& temperatures) {
  int64_t sum = accumulate(begin(temperatures),
                           end(temperatures),
                           static_cast<int64_t>(0));
  return static_cast<int32_t>(
      sum / static_cast<int64_t>(temperatures.size())
  );
}

int main() {
  int32_t n;
  cin >> n;
  vector<int32_t> temperatures(n);
  for (auto& t : temperatures) {
    cin >> t;
  }

  int32_t avg = AvgTemperature(temperatures);

  cout << count_if(begin(temperatures), end(temperatures),
                   [avg](int32_t value) {
                     return value > avg;
                   })
       << endl;

  for (size_t i = 0; i < temperatures.size(); ++i) {
    if (temperatures[i] > avg) {
      cout << i << ' ';
    }
  }
}
