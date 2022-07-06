/*
 * У каждого из нас есть повторяющиеся ежемесячные дела, каждое из которых нужно
 * выполнять в конкретный день каждого месяца: оплата счетов за электричество,
 * абонентская плата за связь и пр. Вам нужно реализовать работу со списком
 * таких дел на месяц, а именно, реализовать набор следующих операций:
 *
 * ADD i s
 * Назначить дело с названием s на день i текущего месяца.
 *
 * DUMP i
 * Вывести все дела, запланированные на день i текущего месяца.
 *
 * NEXT
 * Перейти к списку дел на новый месяц. При выполнении данной команды вместо
 * текущего (старого) списка дел на текущий месяц создаётся и становится
 * активным (новый) список дел на следующий месяц: все дела со старого списка
 * дел копируются в новый список. После выполнения данной команды новый список
 * дел и следующий месяц становятся текущими, а работа со старым списком дел
 * прекращается.  При переходе к новому месяцу необходимо обратить внимание на
 * разное количество дней в месяцах:
 * - если следующий месяц имеет больше дней, чем текущий, «дополнительные» дни
 *   необходимо оставить пустыми (не содержащими дел);
 * - если следующий месяц имеет меньше дней, чем текущий, дела со всех «лишних»
 *   дней необходимо переместить на последний день следующего месяца.
 *
 * Замечания
 * - Историю списков дел хранить не требуется, работа ведется только с текущим
 *   списком дел текущего месяца. Более того, при создании списка дел на
 *   следующий месяц, он «перетирает» предыдущий список.
 * - Обратите внимание, что количество команд NEXT в общей последовательности
 *   команд при работе со списком дел может превышать 11.
 * - Начальным текущим месяцем считается январь.
 * - Количества дней в месяцах соответствуют Григорианскому календарю с той лишь
 *   разницей, что в феврале всегда 28 дней.
 *
 * Формат ввода
 * Сначала число операций Q, затем описания операций.
 * Названия дел s уникальны и состоят только из латинских букв, цифр и символов
 * подчёркивания. Номера дней i являются целыми числами и нумеруются от 1 до
 * размера текущего месяца.
 *
 * Формат вывода
 * Для каждой операции типа DUMP в отдельной строке выведите количество дел в
 * соответствующий день, а затем их названия, разделяя их пробелом. Порядок
 * вывода дел в рамках каждой операции значения не имеет.
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int NextMonth(int month) {
  return month != 11 ? ++month : 0;
}

int main() {
  map<int, int> days = {
      {0, 31},
      {1, 28},
      {2, 31},
      {3, 30},
      {4, 31},
      {5, 30},
      {6, 31},
      {7, 31},
      {8, 30},
      {9, 31},
      {10, 30},
      {11, 31}
  };
  // 0 is January
  int month = 0;
  vector<vector<string>> month_tasks(days[0]);

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    string command;
    cin >> command;
    if (command == "NEXT") {
      int next_month = NextMonth(month);
      vector<string> extra_tasks;
      for (int j = days[next_month]; j < days[month]; ++j) {
        extra_tasks.insert(end(extra_tasks),
                           begin(month_tasks[j]),
                           end(month_tasks[j]));
      }
      month = next_month;
      month_tasks.resize(days[month]);
      month_tasks[days[month] - 1].insert(end(month_tasks[days[month] - 1]),
                                          begin(extra_tasks),
                                          end(extra_tasks));
    } else {
      int j;
      cin >> j;
      if (command == "DUMP") {
        cout << month_tasks[j - 1].size();
        for (const auto &task : month_tasks[j - 1]) {
          cout << ' ' << task;
        }
        cout << endl;
      } else if (command == "ADD") {
        string s;
        cin >> s;
        month_tasks[j - 1].push_back(s);
      }
    }
  }
}