#include <iostream>
#include <cmath>

using namespace std;
double f(double x)
{
double pi = acos(-1.0);
return (sin(abs(pi*x))*sin(abs(pi*x))*sin(abs(pi*x)));
}

int main()
{
setlocale(LC_ALL,"Russian");

double a,b,n,integ = 0.0,integ1,integ2;
integ = integ1=integ2;
double h = 0.04;
cout << "Введите начало отрезка интегрирования"<< endl;
cin >> a;
cout << "Введите конец отрезка интегрирования" << endl;
cin >> b;
n = (b - a) / h;

for(int i = 1; i <= n; i++)
{
integ = integ + h * f(a + h * (i - 0.5));
}
cout << "Интеграл по формуле центральных треугольников=" << integ << endl;

integ1 = h * (f(a) + f(b)) / 2.0;
  for(int i = 1; i <= n-1; i++)
  {
	integ1 = integ1 + h * f(a + h * i);
  }
  cout << "Интеграл по формуле трапеций = " << integ1 << endl;
   integ2 = h * (f(a) + f(b)) / 6.0;
  for(int i = 1; i <= n; i++)
  {
	integ2 = integ2 + 4.0 / 6.0 * h * f(a + h * (i - 0.5));
  }
  for(int i = 1; i <= n-1; i++)
  {
	integ2 = integ2 + 2.0 / 6.0 * h * f(a + h * i);
  }
  cout << "По формуле симпсона = " << integ2 << endl;
}
