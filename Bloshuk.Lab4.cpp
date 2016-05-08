#include <iostream>
#include <math.h>

using namespace std;

bool IsDataValid(double, double, double, int);
double LeftRectangle(double, double, int);
double RightRectangle(double, double, int);
typedef double(*Formula)(double, double, int);
double TheNumberOfPartitionsInLeftRectangle(double, double, double, int, Formula);
double TheNumberOfPartitionsInRightRectangle(double, double, double, int, Formula);
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
		Formula formula = LeftRectangle;
		cout << TheNumberOfPartitionsInLeftRectangle(eps, a, b, n, formula) << endl;
		cout << endl << "According to the formula of right rectangle the integral is ";
		formula = RightRectangle;
		cout << TheNumberOfPartitionsInRightRectangle(eps, a, b, n, formula) << endl;
		system("pause");

		if(Continue(yes))
			continue;
		break;
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

double TheNumberOfPartitionsInLeftRectangle(double eps, double a, double b, int n, Formula formula)
{
	double prev = 0, next = 1;
	while (fabs(prev - next) > eps)
	{
		prev = formula(a, b, n);
		next = formula(a, b, 2 * n);
		n = 2 * n;
	}
	double integral = formula(a, b, n);
	return integral;
}

double TheNumberOfPartitionsInRightRectangle(double eps, double a, double b, int n, Formula formula)
{
	double prev = 0, next = 1;
	while (fabs(prev - next) > eps)
	{
		prev = formula(a, b, n);
		next = formula(a, b, 2 * n);
		n = 2 * n;
	}
	double integral = formula(a, b, n);
	return integral;
}

double LeftRectangle(double a, double b, int n)
{
	double step = (b - a) / n;
	double t = a;
	double integral = (sin(t)/t);
	while (t < b)
	{
		integral += sin(t)/t;
		t += step;
	}
	integral *= step; 
	return integral;
}

double RightRectangle(double a, double b, int n)
{
	double step = (b - a) / n;
	double t = a + step;
	double integral = (sin(t)/t);
	while (t < b)
	{
		integral += sin(t)/t;
		t += step;
	}
	integral *= step;
	return integral;
}

