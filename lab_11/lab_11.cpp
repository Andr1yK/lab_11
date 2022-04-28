#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateBIN(char* fname) // створення файлу символів з введених рядків
{
	ofstream fout(fname, ios::binary); // відкрили файл для запису
	
	char ch; // відповідь користувача – чи продовжувати введення
	string s; // введений користувачем рядок
	
	do {
		cin.get(); // очищуємо буфер клавіатури – щоб не було символу
		cin.sync(); // "кінець рядка", який залишився після вводу числа
		cout << "enter line: "; getline(cin, s); // ввели рядок
		
		for (unsigned i = 0; i < s.length(); i++) // скануємо введений рядок
			fout.write((char*)&s[i], sizeof(s[i])); // записали символ у файл
		
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	
	cout << endl;
}

void PrintBIN(char* fname) // виведення файлу на екран
{
	ifstream fin(fname, ios::binary); // відкрили файл для зчитування
	
	char c; // прочитаний символ
	
	while (fin.read((char*)&c, sizeof(c))) // поки можна прочитати символ
	{
		cout << c << endl; // виводимо його на екран
	}
	
	cout << endl;
}

void ProcessBIN1(char* fname, char* gname) // переписати із файлу f
{ // у файл g символи-цифри
	ifstream f(fname, ios::binary); // відкрили файл для зчитування
	
	char ch;
	string current;
	int max = -INFINITY;
	int min = INFINITY;


	while (f.read((char*)&ch, sizeof(ch))) // поки можна прочитати символ
	{
		if (ch != ' ') {
			current += ch;
			continue;
		}

		cout << stoi(current) << endl;
		current = "";
	}

	// ofstream g(gname, ios::binary); // відкрили файл для запису
	// g.write((char*)&max, sizeof(max));
}

void fWrite(fstream& f, const int i, const char x)
{
	f.seekp(i * (long)sizeof(char)); // встановили вказівник
	f.write((char*)&x, sizeof(char)); // записали значення
}

int main()
{
	char fname[100];
	cout << "enter file name 1: "; cin >> fname;
	// CreateBIN(fname);

	PrintBIN(fname);
	char gname[100];

	cout << "enter file name 2: "; cin >> gname;
	ProcessBIN1(fname, gname);
	PrintBIN(gname);

	return 0;
}