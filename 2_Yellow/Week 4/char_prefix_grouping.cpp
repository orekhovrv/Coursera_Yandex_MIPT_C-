#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

//Напишите функцию FindStartsWith:
//принимающую отсортированный набор строк в виде итераторов range_begin, range_end и один символ prefix;
//возвращающую диапазон строк, начинающихся с символа prefix, в виде пары итераторов.

// Если итоговый диапазон пуст, его границы должны указывать на то место в контейнере,
// куда можно без нарушения порядка сортировки вставить любую строку, начинающуюся с символа prefix (подобно алгоритму equal_range).
// Гарантируется, что строки состоят лишь из строчных латинских букв и символ prefix также является строчной латинской буквой.
// Поиск должен осуществляться за логарифмическую сложность — например, с помощью двоичного поиска.


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end, char prefix
) {
    RandomIt prefix_range_begin = lower_bound(range_begin, range_end, string(1, prefix));
    ++prefix;
    RandomIt prefix_range_end = lower_bound(range_begin, range_end, string(1, prefix));
    return {prefix_range_begin, prefix_range_end};
}


int main() {
    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
         (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
         (z_result.second - begin(sorted_strings)) << endl;

    return 0;

}