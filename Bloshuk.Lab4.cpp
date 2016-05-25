#include <iostream>
#include <math.h>

using namespace std;

bool IsDataValid(double, double, double, int);
typedef double(*Expression)(double);
typedef double(*Formula)(double, double, int, Expression);
double LeftRectangle(double, double, int, Expression);
double RightRectangle(double, double, int, Expression);
double TheNumberOfPartitions(double, double, double, int, Formula, Expression);
double Sinus(double);
bool Continue(char);

int main()
{
	while (true)
	{
		system("cls");
		double eps;
		int a, b, n;
		char yes = 'k';
		while (true)
		{
			cout << "Enter the epsilon" << endl;
			cin >> eps;
			cout << "Enter the lower limit (a)" << endl;
			cin >> a;
			cout << "Enter the upper limit (b) > lower limit (a)" << endl;
			cin >> b;
			cout << "Enter the number of partitions (n)" << endl;
			cin >> n;
			system("cls");
			if (IsDataValid(eps, a, b, n)) break;
			cout << "Error! Invalid data. Please, enter the other value" << endl;
			system("pause");
			system("cls");
		}

		cout << "According to the formula of left rectangle the integral is ";
		Expression expr = Sinus;
		Formula formula = LeftRectangle;
		cout << TheNumberOfPartitions(eps, a, b, n, formula, expr) << endl;
		cout << endl << "According to the formula of right rectangle the integral is ";
		formula = RightRectangle;
		cout << TheNumberOfPartitions(eps, a, b, n, formula, expr) << endl;

		if (Continue(yes))
			continue;
		break;
		system("pause");
	}
	return 0;
}

bool Continue(char)
{
	char yes;
	cout << endl << "If you would like to continue, please, press y or Y " << endl;
	cin >> yes;
	if (yes == 'y' || yes == 'Y')
		return true;
	return false;
}

bool IsDataValid(double eps, double a, double b, int n)
{
	if (eps < 0 || eps >= 1) return false;
	if (a > b) return false;
	if (n < 0) return false;
	return true;
}

double TheNumberOfPartitions(double eps, double a, double b, int n, Formula formula, Expression expr)
{
	double prev = 0, next = 1;
	while (fabs(prev - next) > eps)
	{
		prev = formula(a, b, n, expr);
		next = formula(a, b, 2 * n, expr);
		n = 2 * n;
	}
	double integral = formula(a, b, n, expr);
	return integral;
}

double LeftRectangle(double a, double b, int n, Expression expr)
{
	double step = (b - a) / n;
	double t = a;
	double integral = expr(t);
	while (t < b)
	{
		integral += expr(t);
		t += step;
	}
	integral *= step;
	return integral;
}

double RightRectangle(double a, double b, int n, Expression expr)
{
	double step = (b - a) / n;
	double t = a + step;
	double integral = expr(t);
	while (t < b)
	{
		integral += expr(t);
		t += step;
	}
	integral *= step;
	return integral;
}

double Sinus(double x)
{
	return sin(x) / x;
}



