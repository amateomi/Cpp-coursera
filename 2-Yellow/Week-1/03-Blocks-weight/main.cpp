/*
 * Вычислите суммарную массу имеющих форму прямоугольного параллелепипеда блоков
 * одинаковой плотности, но разного размера.
 *
 * Указание
 * Считайте, что размеры блоков измеряются в сантиметрах, плотность — в граммах
 * на кубический сантиметр, а итоговая масса — в граммах. Таким образом, массу
 * блока можно вычислять как простое произведение плотности на объём.
 *
 * Формат ввода
 * В первой строке вводятся два целых положительных числа: количество блоков N
 * и плотность каждого блока R. Каждая из следующих N строк содержит три целых
 * положительных числа W, H, D — размеры очередного блока.
 *
 * Гарантируется, что:
 * - количество блоков N не превосходит 10^5;
 * - плотность блоков R не превосходит 100;
 * - размеры блоков W, H, D не превосходят 10^4.
 */
#include <iostream>
#include <cinttypes>

using namespace std;

int main() {
  uint64_t total_mass = 0;

  uint32_t n;
  cin >> n;
  uint16_t r;
  cin >> r;
  for (uint32_t i = 0u; i < n; ++i) {
    uint16_t w, h, d;
    cin >> w >> h >> d;
    uint64_t v = static_cast<uint64_t>(w) * h * d;
    total_mass += v * r;
  }
  cout << total_mass << endl;
}
