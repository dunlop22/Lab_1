#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
using namespace std;

//arcsin(x)
double func1(double x, double e)
{
    double sum, tek;
    int k;
    k = 0;
    tek = x;
    sum = 0;

    while (fabs(tek) > e)
    {
        sum = sum + tek;
        k++;
        tek = tek * x * x * (2 * k - 1) * (2 * k - 1) / (2 * k) / (2 * k + 1);
    }
    return sum;
}

//arctg(x)
double func2(double x, double e)
{
    double sum, tek, m;
    int k, d;

    sum = 0;
    k = 0;
    tek = 1 / x;
    m = pow(x, 2);
    d = 1;

    while (fabs(tek) > e)
    {
        sum = sum + tek;
        d = d + 2;
        k++;
        tek = -1 * tek / (m * d) * (d - 2);
    }
    return sum;
}


//вывод результата
void func3(double x, double y, double e)
{
    printf("x = %lf;\ny = %lf;\ne = %lf;\n", x, y, e);
}


int main()
{
    do
    {
        setlocale(LC_ALL, "Rus");
        int N;
        double x, e, y;

        printf("Введите значение x: ");
        scanf("%lf", &x);
        while (getchar() != '\n');

        printf("Введите значение е: ");
        scanf("%lf", &e);
        while (getchar() != '\n');

        printf("Введите N (1 или 2): ");
        do
        {
            scanf("%d", &N);
            if (N != 1 && N != 2)
            {
                printf("Значение N не удовлетворяет условию\n");
            }
        } while (N != 1 && N != 2);

        while (getchar() != '\n');

        if (N == 1)
        {
            y = func1(x, e);
        }
        else
        {
            y = func2(x, e);
        }

        //функция вывода значения x и y
        func3(x, y, e);
        printf("Для продолжения - нажмите любую клавишу. Для выхода - ESC.\n");
    } while (_getch() != 27);
}
