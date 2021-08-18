#include <iostream>
#include <stdio.h>
 
int binomialCoeff(int n, int k)
{
	if (k == 0 || k == n)
	return 1;
	if (k == 1)
		return n;
	return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

int main()
{
	int n=0, k=0;
	std::cout << "n=";
	while (!(std::cin >> n) || std::cin.peek() != '\n') //проверяет, достигнут ли конец потока входного файла или наличие перехода на новую строку
	{
		std::cin.clear(); //очищает память от ошибок ибо без этого цикл остановится, при введении символьного значения
		std::cin.ignore(256, '\n'); //пропускает символы до нажатия Enter
		std::cout << "Введите ЧИСЛЕННОЕ значение заново ... " << std::endl;
	}

	std::cout << "k=";
	while (!(std::cin >> k) || std::cin.peek() != '\n') //проверяет, достигнут ли конец потока входного файла или наличие перехода на новую строку
	{
		std::cin.clear(); //очищает память от ошибок ибо без этого цикл остановится, при введении символьного значения
		std::cin.ignore(256, '\n'); //пропускает символы до нажатия Enter
		std::cout << "Введите ЧИСЛЕННОЕ значение заново ... " << std::endl;
	}

	std::cout << "Value of C(" << n << "\; " << k << ") is " << binomialCoeff(n, k);
	return 0;
}