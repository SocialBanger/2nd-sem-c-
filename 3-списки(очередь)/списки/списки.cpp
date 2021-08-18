#define _CRT_SECURE_NO_WARNINGS //Суть дела в том, что функции, возвращающие указатель, считаются небезопасными(шоб не ругалось)

#include <stdio.h>
#include <io.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <iomanip> //внешнее оформление
#include <Windows.h>
using namespace std;

struct Spis {
    double info;
    Spis* next, * prev;

};

void INSpis(Spis**, Spis**, int);
void BSpis(Spis** p, Spis** e, int in);
void View(Spis*);
void BView(Spis*);
int vvin();
int vv2();
Spis* Upr(Spis* p);
Spis* Del_all(Spis* p);

void INSpis(Spis** p, Spis** e, int in) {
    Spis* t = new Spis;
    t->info = in;
    if (*p == 0)
    {
        t->next = t->prev = 0;
        *p = *e = t;
    }
    else
    {
        t->next = *p;
        t->prev = 0;
        (*p)->prev = t;
        *p = t;
    }
}
void BSpis(Spis** p, Spis** e, int in) {
    Spis* t = new Spis;
    t->info = in;
    if (*e == 0)
    {
        t->next = t->prev = 0;
        *p = *e = t;
    }
    else
    {
        t->next = 0;
        t->prev = *e;
        (*e)->next = t;
        *e = t;
    }
}
void View(Spis* p)
{
    Spis* t = p;
    cout << "Готово\n";
    while (t)
    {
        cout << t->info << " ";
        t = t->next;
    }

}
void top_View(Spis* e)
{
    Spis* t = e;
    cout << "Готово\n";
    while (t)
    {
        cout << t->info << " ";
        t = t->prev;
    }

}

int vvin() {

    int i = 0;
    char M[8];
    while (1) {
        M[i] = _getch();
        if (M[i] == 13)
        {
            if (i == 0)continue;;
            break;
        }
        if (M[i] == 8)
        {
            if (i == 0)continue;
            i--;
            cout << "\b \b";
            continue;
        }
        if (i >= 6)continue;
        if (!(M[i] >= '0' && M[i] <= '9') && !(M[i] == '-'))continue;
        if (M[i] == '-' && !(i == 0)) continue;
        if (M[0] == '0' && i == 1) continue;
        cout << M[i];
        i++;
    }
    M[i] = '\0';
    return atoi(M);
}
int vv2() {
    int i = 0;
    char M[4];
    while (1) {
        M[i] = _getch();
        if (M[i] == 13)
        {
            if (i == 0)continue;
            break;
        }
        if (M[i] == 8)
        {
            if (i == 0)continue;
            i--;
            cout << "\b \b";
            continue;
        }
        if (i >= 3)continue;
        if (!(M[i] >= '0' && M[i] <= '9'))continue;
        if (M[i] == '0' && i == 0) continue;
        cout << M[i];
        i++;
    }
    M[i] = '\0';
    return atoi(M);
}

Spis* Upr(Spis* p)
{
    double sum = 0, f; int k = 0;
    Spis* t = p;
    while (t)
    {
        sum += t->info;
        t = t->next;
        k++;
    }
    f = sum / k;
    system("cls");
    cout << "среднеe арифметическое = " << f << "\n первый элемент списка заменен полученным значением\n";
    p->info = f;
    return p;
}
Spis* Del_all(Spis* p)
{
    Spis* t;
    while (p != 0) {
        t = p;
        p = p->next;
        delete t;
    }
    return p;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int n, in; int kod = 1; Spis* begin = 0, * end = 0; char t, j; bool y = 1;
    while (y == 1)
    {

        switch (kod)
        {
        case 1:
        {

            while (1)
            {
                system("cls");
                puts("\n\n \tМеню\n>Создание<\n Добавление \n Просмотр \n Мое индивидуальное задание \nEsc - Выход\n\t");
                j = _getch();
                if (j == 27) {
                    y = 0;
                    break;
                }
                if (j == 80) {
                    kod = 2;
                    break;
                }
                if (j == 13)
                {
                    bool z = 1;
                    while (z == 1)
                    {

                        system("cls");
                        cout << "\n\tКак именно вы хотите заполнить стек?\t\t\t\t\t\t\t Esc - назад в меню\n\t >Cлучайными числами<\n\t Вводимыми с клавиатуры числами \n\n";
                        t = _getch();
                        if (t == 27) break;
                        if (t == 13)
                        {
                            begin = Del_all(begin);
                            system("cls");
                            cout <<"Введите количество символов в создаваемом списке: ";
                            n = vv2();
                            for (int i = 0; i < n; i++)
                            {
                                in = rand() % 101 - 50;
                                INSpis(&begin, &end, in);
                            }
                            n = 0;
                            break;
                        }

                        if (t == 72 || t == 80)
                        {

                            while (1)
                            {

                                system("cls");

                                cout <<"\n\tКак именно вы хотите заполнить стек?\t\t\t\t\t\t\t Esc - назад в меню\n\t Cлучайными  \n\t >Вводимыми с клавиатуры числами<\n\n";
                                t = _getch();
                                if (t == 27) {
                                    z = 0;
                                    break;
                                }
                                if (t == 13)
                                {
                                    begin = Del_all(begin);
                                    system("cls");
                                    cout << "Введите количество символов в создаваемом списке: ";
                                    n = vv2();

                                    for (int i = 0; i < n; i++)
                                    {
                                        system("cls");
                                        cout  << "введите число: ";
                                        // cin >> in;
                                        in = vvin();
                                        INSpis(&begin, &end, in);

                                        //break;
                                    }
                                    z = 0;
                                    break;

                                }
                                t = _getch();
                                if (t == 72 || t == 80) break;
                            }



                        }
                    }
                }

            }

        }
        break;

        case 2:

            while (1)
            {
                system("cls");
                puts("\n\n \tМеню\n Создание \n>Добавление<\n Просмотр \n Индивидуальное задание \nEsc - Выход\n\t");
                j = _getch();
                if (j == 27) {
                    y = 0;
                    break;
                }
                if (j == 13)
                {
                    bool z = 1;
                    while (z == 1)
                    {
                        system("cls");

                        cout << "\n\n\t\tКуда именно вы хотите добавить элемент?\t\t\t\t\t\tEsc - назад в меню\n\t\t >в начало< в конец ";
                        t = _getch();
                        if (t == 27)break;
                        if (t == 13) {
                            system("cls");
                            cout << "Введите элемент: ";
                            in = vvin();
                            INSpis(&begin, &end, in);
                            break;
                        }
                        if (t == 75 || t == 77)
                        {

                            while (1)
                            {

                                system("cls");

                                cout << "\n\n\t\tКуда именно вы хотите добавить элемент?\n\t\t в начало >в конец<";
                                t = _getch();

                                if (t == 13)
                                {
                                    system("cls");
                                    cout << "Введите элемент: ";
                                    in = vvin();
                                    BSpis(&begin, &end, in);
                                    z = 0;
                                    break;
                                }
                                t = _getch();
                                if (t == 77 || t == 75) break;
                            }
                        }
                    }

                }
                if (j == 80) {
                    kod = 3;
                    break;
                }
                if (j == 72)
                {
                    kod = 1;
                    break;
                }
            }
            break;
        case 3:

            while (1)
            {
                system("cls");
                puts("\n\n \tМеню\n Создание \n Добавление \n>Просмотр<\n Индивидуальное задание \nEsc - Выход\n\t");
                j = _getch();
                if (j == 27) {
                    y = 0;
                    break;
                }
                if (j == 13) {
                    if (!begin)
                    {
                        system("cls");
                        cout << "Список пуст! Press что-нибудь на клаве to menu ";
                        _getch();
                        break;
                    }
                    else
                    {
                        bool z = 1;
                        while (z == 1)
                        {
                            system("cls");

                            cout << "\n\n\t\t Просмотр списка -- \t\t\t\t\t Esc - назад в меню \n\t\t >с начала< с конца ";
                            t = _getch();
                            if (t == 27)break;
                            if (t == 13) {
                                system("cls");
                                View(begin);
                                break;
                            }
                            if (t == 75 || t == 77)
                            {

                                while (1)
                                {
                                    system("cls");
                                    cout << "\n\n\t\t Просмотр списка -- \n\n\t\t с начала >с конца<";
                                    t = _getch();

                                    if (t == 13)
                                    {
                                        system("cls");
                                        top_View(end);
                                        z = 0;
                                        break;
                                    }
                                    t = _getch();
                                    if (t == 77 || t == 75) break;
                                }
                            }
                        }
                        _getch();
                    }
                }
                if (j == 80) {
                    kod = 4;
                    break;
                }
                if (j == 72)
                {
                    kod = 2;
                    break;
                }
            }
            break;
        case 4:

            while (1)
            {
                system("cls");
                puts("\n\n \tМеню\n Создание \n Добавление \n Просмотр \n> индивидуальное задание<\nEsc - Выход\n\t");
                j = _getch();
                if (j == 27) {
                    y = 0;
                    break;
                }
                if (j == 13) {
                    if (!begin)
                    {
                        system("cls");
                        cout << "Список пуст! Press что-нибудь на клаве to menu ";
                        _getch();
                        break;
                    }
                    else
                    {
                        begin = Upr(begin);
                        _getch();
                    }
                }
                if (j == 72)
                {
                    kod = 3;
                    break;
                }
            }
            break;

        }
        if (y == 0) {

            bool z = 1;
            while (z == 1)
            {
                system("cls");

                cout << "======================== Уверены, что хотите выйти?====================\t>да<\t нет ";
                t = _getch();
                if (t == 13) break;
                if (t == 75 || t == 77)
                {

                    while (1)
                    {

                        system("cls");

                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Вы правда хотите выйти?:( \n\t\t\t\t\t\t да \t>нет<";
                        t = _getch();

                        if (t == 13)
                        {
                            z = 0;
                            y = 1;
                            break;
                        }
                        t = _getch();
                        if (t == 77 || t == 75) break;
                    }
                }
            }
        }
    }
}

