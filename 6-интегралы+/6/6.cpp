#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

typedef double (*type_f)(double);
double fun(double);
double Simps(type_f, double, double, int);

main() {
    setlocale(, "");
    cout << "\t\t=============== Лабораторная работа №6 || Интегралы ===============\n" << endl;
    double a, b, x, eps, h, Int1, Int2, pogr;
    int n, n1;
    a = StrToFloat(Edit1->Text);
    b = StrToFloat(Edit2->Text);
    eps = StrToFloat(Edit3->Text);
    n = StrToInt(Edit4->Text);
    h = (b - a) / 100; // Шаг вывода исходной функции
    Chart1->Series[0]->Clear();
    for (x = a - h; x < b + h; x + = h)
        Chart1->Series[0]->AddXY(x, fun(x));

    switch (RadioGroup2->ItemIndex) {
    case 0:
            Memo1->Lines->Add("Расчет по разбиению на n = " + IntToStr(n));
        Int1 = Simps(fun, a, b, n);
        break;
    case 1:
        n1 = 2;
        Memo1->Lines->Add("Расчет по точности eps");
        Int1 = Simps(fun, a, b, n1);
        do {
            n1 *= 2;
            Int2 = Simps(fun, a, b, n1);
            pogr = fabs(Int2 - Int1);
            Int1 = Int2;
        } while (pogr > eps);
        Memo1->Lines->Add("При n = " + IntToStr(n1));
        break;
    }
    Memo1->Lines->Add("Значение интеграла = " + FloatToStrF(Int1, ffFixed, 8, 6));

    //----------------- Подынтегральная функция f(x) ---------------------
    double fun(double x){
        return pow(x,3) + 5 * cos(x); // На интервале [–2, 5] значение 154    }}