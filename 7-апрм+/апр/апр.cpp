#include<iostream>
#include<stdio.h>
#include<cmath>
#include<string>

using namespace std;

double Function(double, double, int);
double funy(double);
double vvod(string);
double changeorg(char*);

void main()
{
	setlocale(LC_ALL, "RUS");
	double a, b, eps, n, n1, f1, f2, sposob1;
	int sposob;
	cout << "\t\t\tНахождение значений интеграла от функции f(x) = x - 5 * sin(x)^2 (метод средних)";
	while (true)
	{
		sposob1 = vvod("\n\n\t\tРассчёт интеграла с указанной точностью - 1.\n\t\tРассчёт интеграла с указанным числом разбиения - 2.\n\t\tВыход - 0. : ");
		while (!(sposob1 == 1 || sposob1 == 2 || sposob1 == 0))
		{
			sposob1 = vvod("Вы ввели не то число. Попробуйте снова: ");
		}
		sposob = sposob1;
		if (sposob == 0)
			break;
		cout << "\n\n\tУкажите пределы интегрирования.\n";
		a = vvod("\t a="); b = vvod("\t b=");
		switch (sposob)
		{
		case 1:
			cout << "\n\tУкажите точность.\n";
			eps = vvod("\teps=");
			cout << "\n\tПри заданной точности eps=" << eps;
			n1 = 2;//количество собственных разбиений для указанной точности
			f1 = Function(a, b, n1);
			while (true)
			{
				n1 *= 2;
				f2 = Function(a, b, n1);
				if (fabs(f2 - f1) < eps)
					break;
				f1 = f2;
			}
			f1 = f2;
			cout << " и соответствующим числом\nразбиений N=" << n1;
			break;
		case 2:
			cout << "\n\tУкажите число разбиений.\n";
			n = vvod("\tN=");
			f1 = Function(a, b, n);
			cout << "\n\tПри заданном числе разбиений N=" << n;
			break;
		}
		cout << " результат интегрирования функции f(x) = x - 5 * sin(x)^2 = " << f1 << endl;
	}
}
double Function(double a, double b, int n)
{
	double integ = 0, h = (b - a) / n;
	for (int i = 1; i < n; i++)
	{
		integ += funy(a + h / 2.0 + i * h);
	}
	return h * integ;
}
double funy(double x)
{
	return x - 5 * sin(x) * sin(x);
}
double vvod(string str)
{
	int f, i = 0;
	double num;
	char smb[10];
	do {
		f = 1;
		cout << str;
		cin >> smb;
		while (smb[i] != '\0')
		{
			if (!(smb[i] >= '0' && smb[i] <= '9' || smb[i] == '.' || smb[i] == ','))
			{
				cout << "Error. Try again";
				f = 0; break;
			}
			i++;
		}
	} while (f == 0);
	num = changeorg(smb);
	return num;
}
double changeorg(char* p)
{
	int k = 0, a = 10, leng = 0, n = 0, flag = 0;
	double val = 0, val1 = 0, val2 = 0;
	while (p[k] != '\0')
	{
		if (p[k] == '.' || p[k] == ',')
		{
			if (p[k] == ',')
				p[k] = '.';
			k++;
			while (p[k] != '\0')
			{
				val2 = val2 * 10 + (int)(p[k] - '0');
				k++;
				a = a * 10;
			}
			break;
		}
		else val1 = val1 * 10 + (int)(p[k] - '0');
		k++;
	}
	val2 = val2 / (a / 10);
	val = val1 + val2;
	return val;
}