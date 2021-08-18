#include <iostream>
using namespace std;

double secantMethod(double a, double b, double eps);
double fun(double x);

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "\t\t=============== Лабораторная работа №5 || Корни уравнения(нелин) ===============\n" << endl;
    double result, eps = 0.01, x, a = -1, b = 3;
    int count = 0;
    cout << "Уравнение: x^2-10sin^2(x)+2" << endl
        << "=== Корни ===" << endl;
    for (x = a; x <= b; x += eps)
    {
        if (fun(x) * fun(x + eps) < 0) {
            count++;
            result = secantMethod(x, x + eps, eps);
            cout << count << "-й = " << result << endl;
        }
    }
    return 0;
}

double secantMethod(double x0, double x1, double eps)
{
    double y, res = 0;
    do {
        y = res;
        res = x1 - ((x1 - x0) / (fun(x1) - fun(x0))) * fun(x1);
        x0 = x1;
        x1 = res;
    } while (fabs(y - res) >= eps);
    return res;
}

double fun(double x)
{
    return x * x - 10 * sin(x) * sin(x) + 2;
}