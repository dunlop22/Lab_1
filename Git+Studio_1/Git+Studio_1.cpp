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


int main()
{
    std::cout << "Hello World!\n";
    

}
