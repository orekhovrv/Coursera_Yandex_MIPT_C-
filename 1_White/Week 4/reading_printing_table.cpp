# include <iostream>
# include <fstream>
# include <iomanip>

using namespace std;

//В первой строке файла input.txt записаны два числа N и M.
// Далее в файле находится таблица из N строк и M столбцов, представленная в формате CSV (comma-separated values).
// Такой формат часто используется для текстового представления таблиц с данными:
// в файле несколько строк, значения из разных ячеек внутри строки отделены друг от друга запятыми.
// Ваша задача — вывести данные на экран в виде таблицы. Формат таблицы:
//
//1)  размер ячейки равен 10,
//
//2)  соседние ячейки отделены друг от друга пробелом,
//
//3)  последняя ячейка в строке НЕ оканчивается пробелом,
//
//4)  последняя строка НЕ оканчивается символом перевода строки.
// Гарантируется, что в таблице будет ровно N строк и M столбцов, значение каждой из ячеек — целое число.


int main() {
    ifstream file_stream("1_White\\Week 4\\input.txt");
    if (file_stream) {
        int n, m;
        string value;
        string line;

        file_stream >> n >> m;
        file_stream.ignore(1);

        for (int i = 0; i < n; ++i) {
            getline(file_stream, line);
            stringstream line_stream(line);
            if (line_stream){
                for (int j = 0; j < m; ++j) {
                    getline(line_stream, value, ',');
                    cout << setw(10) << value;
                    if (j < m - 1) {
                        cout << " ";
                    }
                }
                if (i < n - 1) {
                    cout << endl;
                }
            }

        }

    }
    return 0;
}
