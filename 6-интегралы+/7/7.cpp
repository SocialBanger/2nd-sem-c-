#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

double linf(double*, double, int);
double function(double);
double vvod(string);
double preobraz(char*, int);

int main()
{
	setlocale(LC_ALL, "RUS");
	double a, b, xt, h, masx[100], menu = 2, menu1;
	int i, m, sposob;
	cout << "\n\t\t\tИнтерполяция функции f(x)=x-5*sin(x)*sin(x) (линейный метод).";
	while (true)
	{
		i = 0;
		cout << "\n\n\tВведите координаты начала и конца отрезка [a;b]:" << endl;
		a = vvod("\ta=");
		b = vvod("\tb=");
		m = vvod("\tКоличество заданных точек m=");
		while (!m)
			m = vvod("\nВы ввели не то число. Попробуйте снова: ");
		h = (b - a) / m;
		for (xt = a, i = 0; i < m; i++, xt += h)
		{
			masx[i] = xt;
		}
		for (xt = a, i = 0; i < m; i++, xt += h)
		{
			cout << "\nПри x=" << xt << " f*(x)=" << linf(masx, xt, i) << " функция f(x)=" << function(xt);
		}
		cout << "\n\n\tЖелаете сменить координаты?";
		menu1 = vvod("\n\tПродолжить - 1.\n\tВыйти - 0. : ");
		while (!(menu1 == 1 || menu1 == 0))
		{
			menu1 = vvod("\nВы ввели не то число. Попробуйте снова: ");
		}
		menu = menu1;
		if (menu == 0)
			break;
	}
}

double linf(double* x, double xt, int i)
{
	double n, yi, yii;
	yii = function(x[i + 1]);
	if (i != NULL)
	{
		yi = function(x[i - 1]);
		n = yi + (xt - x[i - 1]) * (yii - yi) / (x[i + 1] - x[i - 1]);
	}
	else
		n = xt * yii / x[i + 1];

	return n;
}

double function(double x)
{
	return x - 5.0 * sin(x) * sin(x);
}

double vvod(string str)
{
	int f, flag, flag2, i = 0;
	double num;
	char smb[10];
	do {
		flag = 0; flag2 = 0;
		f = 1;
		cout << str;
		cin >> smb;
		while (smb[i] != '\0')
		{
			if (!(smb[i] >= '0' && smb[i] <= '9' || smb[i] == '.' || smb[i] == ',' || smb[i] == '-'))
			{
				cout << "\nError. Try again";
				f = 0;
				break;
			}
			if (smb[i] == '.' || smb[i] == ',') flag++;
			if (smb[i] == '-') flag2++;
			if (flag > 1 || flag2 > 1)
			{
				cout << "\nНельзя вводить несколько '" << smb[i] << "'";
				i = 0;
				f = 0;
				break;
			}
			i++;
		}
	} while (f == 0);

	num = preobraz(smb, flag2);
	return num;
}
double preobraz(char* p, int flag2)
{
	int k = 0, a = 10;
	double val = 0, val1 = 0, val2 = 0;
	while (p[k] != '\0')
	{

		if (p[k] == '-')
			k++;
		else if (p[k] == '.' || p[k] == ',')
		{
			if (p[k] == ',')
				p[k] = '.';
			if (p[k + 1] == '\0')
			{
				p[k + 1] = '0';
				p[k + 2] = '\0';
			}
			k++;
			while (p[k] != '\0')
			{
				val2 = val2 * 10 + (int)(p[k] - '0');
				if (val1 < 0) val2 = val2 - 2 * val2;
				k++;
				a = a * 10;
			}
			break;
		}
		else
		{
			val1 = val1 * 10 + (int)(p[k] - '0');
			k++;
		}
	}
	val2 = val2 / (a / 10);
	if (flag2 == 1)val = val1 + val2 - (val1 + val2) * 2;
	else val = val1 + val2;
	return val;
}