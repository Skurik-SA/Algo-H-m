#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void Archivate();
void UnArchivate();
void Arch();

int main()
{
	Arch();
	//UnArchivate();


	return 0;
}

void Archivate()
{
	vector<int> kount; // Динамический массив чисел, который заполняется количесвтом чисел какой-то определённой буквой в порядке сжатия
	string inp; // Что-то временное для пары тестов
	string line; // Переменная, строка, которая считывается при чтении файла
	ifstream fin;
	ofstream fout;

	fin.open("input.txt");
	fout.open("output.txt");

	if (fin.is_open() && fout.is_open()) // Окрылись файлы или нет
	{
		int m = 0; // Переменная, которая отвечает за индекс вывода подсчёта массива kount

		while (getline(fin, line)) // Чтение файла
		{
			int count = 1;

			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == line[i + 1])
				{
					while (line[i] == line[i + 1])
					{

						line.erase(i, 1);
						count++;

					}
				}
				kount.push_back(count);
				count = 1;
			}

			for (int i = 0; i < line.length(); i++)
			{
				fout << char(kount[m++]) << line[i];
			}

			fout << endl;
		}
	}
	fin.close();
	fout.close();

}

void Arch()
{
	vector<char> kounter; // Массив для хранения длин символов
	string line; // Переменная нужная для считывания файла по строкам
	ifstream fin; // Чтение
	ofstream fout; // Запись
	bool index = 0; // Ключ

	fin.open("input.txt");
	fout.open("output.txt",fstream::binary);

	if (fin.is_open() && fout.is_open())
	{
		int m = 0;

		while (getline(fin, line))
		{

			int count = 1;

			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == line[i + 1])
				{
					index = 1;

					while (line[i] == line[i + 1])
					{
						line.erase(i, 1);
						count++;
					}

					fout << count << line[i];

					count = 1;
				}
				else if (index == 1)
				{
					fout << line[i];
				}

			}

			fout << endl;
		}
	}

	fin.close();
	fout.close();
}





void UnArchivate()
{
	ofstream fout;//Выходной
	ifstream fin;//Входной
	fin.open("output.txt");//Открытие входного
	fout.open("input1.txt");//Открытие выходного

	if (fout.is_open() && fin.is_open())//Если файлы открылись
	{
		cout << "Файл открыт для разархивации\n";
		bool is_for_one = 0;//режим выключен
		char cur;
		unsigned char counter = 0;
		while (fin.get(cur))//Считывает текущий элемент
		{
			if (counter == 0 && !is_for_one)//Если не включена запис посимвольно и длинна символа не установленн значит текущий символ означает длинну либо переключение режима
			{
				if (cur == 0)
				{
					is_for_one = 1;
				}
				else
				{
					counter = cur;
				}

			}
			else if (is_for_one)//Если включен режим записи посимвольно
			{
				if (cur == 0)//Если текущий символ равен разделительному значи надо переключить режим
				{
					is_for_one = 0;
				}
				else//В другом же случае, просто вписать элемент
				{
					fout << cur;
				}
			}
			else //Если есть счетчик
			{
				while (counter > 0)//Пока счетчик не равен 0 запись текущего символа в файл
				{
					fout << cur;
					counter--;
				}
			}

		}
	}
	else//Файл не открылся
	{
		cout << "Cann't open file" << endl;
	}
	fin.close();
	fout.close();
}