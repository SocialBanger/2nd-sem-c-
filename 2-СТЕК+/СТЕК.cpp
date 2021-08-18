#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

struct Stack {
	int info;
	Stack* next;
}  *t;

const int N = 100;

Stack* inStack(Stack*, int);
void view(Stack*);
void delAll(Stack*&);
void sortP(Stack**);
void sortInfo(Stack*);
Stack* individualTask(Stack*);

int main()
{
	setlocale(LC_ALL, "rus");
	srand(unsigned(time(NULL)));
	cout << "\t\t=============== Лабораторная работа №2 || Стек ===============" << endl;
	Stack* begin = NULL;
	int i, number, n;
	char item;
	bool again;
	do
	{
		again = true;
		cout << "\n1 | Создать"
			<< "\n2 | Добавить"
			<< "\n3 | Просмотр"
			<< "\n4 | Удаление"
			<< "\n5 | Индивидуальное задание [удалить нечётные элементы стека]"
			<< "\n6 | Сортировка (1 способ)"
			<< "\n7 | Сортировка (2 способ)"
			<< "\n0 | Выход" << endl;
		do {
			item = _getch();
		} while (!(item >= '0' && item <= '7'));
		switch (item)
		{
		case '1':
		{
			system("cls");
			if (begin != NULL)
			{
				cout << "Стек уже создан." << endl;
				break;
			}
			cout << "Введите количество: ";
			cin >> n;
			for (i = 1; i <= n; i++) {
				number = rand() % N;
				begin = inStack(begin, number);
			}
			cout << "Создание: " << n << endl;
			break;
		}
		case '2':
		{
			system("cls");
			cout << "Введите количество: ";
			cin >> n;
			for (i = 1; i <= n; i++) {
				number = rand() % N;
				begin = inStack(begin, number);
			}
			cout << "Добавление: " << n << endl;
			break;
		}
		case '3':
		{
			system("cls");
			if (!begin) {
				cout << "Стек пуст." << endl;
			}
			else {
				cout << "Стек:" << endl;
				view(begin);
			}
			break;
		}
		case '4':
		{
			system("cls");
			delAll(begin);
			cout << "Память освобождена." << endl;
			break;
		}
		case '5':
		{
			system("cls");
			begin = individualTask(begin);
			cout << "выполнено." << endl;
			break;
		}
		case '6':
		{
			system("cls");
			sortP(&begin);
			cout << "Сортировка выполнена." << endl;
			break;
		}
		case '7':
		{
			system("cls");
			sortInfo(begin);
			cout << "Сортировка выполнена." << endl;
			break;
		}
		case '0':
		{
			again = false;
			break;
		}
		}
	} while (again);
	if (begin != NULL) {
		delAll(begin);
	}
	return 0;
}


Stack* inStack(Stack* p, int number)
{
	Stack* t = new Stack;
	t->info = number;
	t->next = p;
	return t;
}

void view(Stack* p)
{
	Stack* t = p;
	while (t != NULL) {
		cout << t->info << " ";
		t = t->next;
	}
	cout << endl;
}

void delAll(Stack*& p)
{
	Stack* t;
	while (p != NULL) {
		t = p;
		p = p->next;
		delete t;
	}
}

void sortP(Stack** p)
{
	Stack* t = NULL, * t1, * r;
	if ((*p)->next->next == NULL)
		return;
	do {
		for (t1 = *p; t1->next->next != t; t1 = t1->next)
			if (t1->next->info > t1->next->next->info) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while ((*p)->next->next != t);
}

void sortInfo(Stack* p)
{
	Stack* t = NULL, * t1;
	int r;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info)
			{
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;
	} while (p->next != t);
}

Stack* individualTask(Stack* b)
{
	Stack* p = b;
	int i = 0;
	t = p->next;
	while (t != NULL) {
		if (i % 2 != 0) {
			p->next = t->next;
			delete t;
			t = p->next;
		}
		else {
			p = t;
			t = t->next;
		}
		i++;
	}
	if (i % 2 != 0) {
		t = b;
		b = b->next;
		delete t;
	}
	return b;
}