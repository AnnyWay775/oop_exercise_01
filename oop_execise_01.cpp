/*

Создать класс Money для работы с денежными суммами. Сумма денег должна быть представлено двумя
полями: типа unsigned long long для рублей и типа unsigned char – для копеек. Дробная часть (копейки) при
выводе на экран должна быть отделена от целой части запятой. Реализовать сложение сумм, вычитание,
деление сумм, деление суммы на дробное число, умножение на дробное число и операции сравнения.

Кулагин Даниил Николаевич
М8О-201Б-18

*/

#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Money
{
public:
	unsigned long long r; //рубли типа unsigned long long
	unsigned char c1, c2; //копейки представлениы двумя переменными типа unsigned char
	double fullSumm; //внутреннее представление суммы для дальнейших преобразований
	void get_normal_sum(Money a); //функция, переводящая исходные переменные в fullSumm
	void Add(Money a); //функция сложения сумм
	void Sub(Money a); //функция разности сумм
	void Div(Money a); //функция деления сумм
	int Comp(Money a); //функция сравнения сумм
};

void Money::Add(Money a) {
	fullSumm += a.fullSumm;
}

void Money::Sub(Money a) {
	try {
		if (fullSumm<a.fullSumm) throw "Сумма денег не может быть отрицательна";
		fullSumm -= a.fullSumm;
	}
	catch (char* str) { cout << "Ошибка: " << str << endl; }
}

void Money::Div(Money a) {
	try {
		if (a.fullSumm == 0) throw "деление на ноль";
		fullSumm /= a.fullSumm;
	}
	catch (char* str) {
		cout << "Ошибка: " << str << endl;
	}
}

int Money::Comp(Money a) {
	if (fullSumm > a.fullSumm) return 1; else
		if (fullSumm < a.fullSumm) return 2; else
			return 3;
}

void Money::get_normal_sum(Money a) {
	double normal_cop = 0;
	fullSumm = 0;
	try {
		if (a.c1 == 48) normal_cop += 0.0; else
			if (a.c1 == 49) normal_cop += 0.1; else
				if (a.c1 == 50) normal_cop += 0.2; else
					if (a.c1 == 51) normal_cop += 0.3; else
						if (a.c1 == 52) normal_cop += 0.4; else
							if (a.c1 == 53) normal_cop += 0.5; else
								if (a.c1 == 54) normal_cop += 0.6; else
									if (a.c1 == 55) normal_cop += 0.7; else
										if (a.c1 == 56) normal_cop += 0.8; else
											if (a.c1 == 57) normal_cop += 0.9; else throw "Некорректный ввод";
	}
	catch (char* str) { cout << "Ошибка: " << str << endl; }
	try {
		if (a.c2 == 48) normal_cop += 0.00; else
			if (a.c2 == 49) normal_cop += 0.01; else
				if (a.c2 == 50) normal_cop += 0.02; else
					if (a.c2 == 51) normal_cop += 0.03; else
						if (a.c2 == 52) normal_cop += 0.04; else
							if (a.c2 == 53) normal_cop += 0.05; else
								if (a.c2 == 54) normal_cop += 0.06; else
									if (a.c2 == 55) normal_cop += 0.07; else
										if (a.c2 == 56) normal_cop += 0.08; else
											if (a.c2 == 57) normal_cop += 0.09; else throw ("Некорректный ввод");
	}
	catch (char* str) { cout << "Ошибка: " << str << endl; }
	fullSumm = double(r + normal_cop);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	Money a1, b1;
	cout << "Введите рубли: " << endl;
	cin >> a1.r;
	cout << "Введите копейки: " << endl;
	cin >> a1.c1;
	cin >> a1.c2;
	a1.get_normal_sum(a1);
	printf("%.2f\n", a1.fullSumm);
	int user_command = 1;
	for (;;) {
		if (user_command == 1) {
			cout << "Введите число от 1 до 6 или 0 для действий: " << endl <<
				"1. Распечатать меню" << endl <<
				"2. Сложение сумм" << endl <<
				"3. Вычитание сумм" << endl <<
				"4. Деление сумм" << endl <<
				"5. Умножение суммы на дробное число" << endl <<
				"6. Деление суммы на дробное число" << endl <<
				"7. Сравнение двух сумм" << endl <<
				"0. Выход из программы" << endl;
		}
		else if (user_command == 2) {
			cout << "Введите рубли: " << endl;
			cin >> b1.r;
			cout << "Введите копейки: " << endl;
			cin >> b1.c1;
			cin >> b1.c2;
			b1.get_normal_sum(b1);
			a1.Add(b1);
			printf("%.2f\n", a1.fullSumm);

		}
		else if (user_command == 3) {
			cout << "Введите рубли: " << endl;
			cin >> b1.r;
			cout << "Введите копейки: " << endl;
			cin >> b1.c1;
			cin >> b1.c2;
			b1.get_normal_sum(b1);
			a1.Sub(b1);
			printf("%.2f\n", a1.fullSumm);
		}
		else if (user_command == 4) {
			cout << "Введите рубли: " << endl;
			cin >> b1.r;
			cout << "Введите копейки: " << endl;
			cin >> b1.c1;
			cin >> b1.c2;
			b1.get_normal_sum(b1);
			a1.Div(b1);
			printf("%.2f\n", a1.fullSumm);
		}
		else if (user_command == 5) {
			float f;
			cout << "Введите множитель: " << endl;
			cin >> f;
			a1.fullSumm *= f;
			printf("%.2f\n", a1.fullSumm);
		}

		else if (user_command == 6) {
			try {
				double f;
				cin >> f;
				cout << "Введите делитель: " << endl;
				if (f == 0) throw "деление на ноль";
				a1.fullSumm /= f;
				printf("%.2f\n", a1.fullSumm);
			}
			catch (char* str) {
				cout << "Ошибка: " << str << endl;
			}
		}
		else if (user_command == 7) {
			cout << "Введите рубли: " << endl;
			cin >> b1.r;
			cout << "Введите копейки: " << endl;
			cin >> b1.c1;
			cin >> b1.c2;
			b1.get_normal_sum(b1);
			if (a1.Comp(b1) == 1) cout << "Первая сумма больше второй" << endl; else
				if (a1.Comp(b1) == 2) cout << "Вторая сумма больше первой" << endl; else
					cout << "Суммы равны" << endl;
		}
		else if (user_command == 0)
			break;
		else
			cout << "Нет такого пункта меню" << endl;
		cout << "Введите номер пункта меню > " << endl;
		cin >> user_command;
	}
	return 0;
}