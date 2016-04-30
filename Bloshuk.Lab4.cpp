#include <iostream>
#include <math.h>

using namespace std;

bool IsDataValid(double, double, double, int);
double LeftRectangle(double, double, int);
double RightRectangle(double, double, int);
double Formula(double);
int TheNumberOfPartitionsInLeftRectangle(double, double, double, int);
int TheNumberOfPartitionsInRightRectangle(double, double, double, int);


int main()
{
	while (true)
	{
		system("cls");
		double eps;
		int a, b, n;
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
		n = TheNumberOfPartitionsInLeftRectangle(eps, a, b, n);
		cout << LeftRectangle(a, b, n) << endl;
		cout << endl << "According to the formula of right rectangle the integral is ";
		n = TheNumberOfPartitionsInRightRectangle(eps, a, b, n);
		cout << RightRectangle(a, b, n) << endl;

		char yes;
		cout << endl << "If you would like to continue, please, press y or Y " << endl;
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
			continue;
		break;
	}
	return 0;
}

bool IsDataValid(double eps, double a, double b, int n)
{
	if (eps < 0 || eps >= 1) return false;
	if (a > b) return false;
	if (n < 0) return false;
	return true;
}

int TheNumberOfPartitionsInLeftRectangle(double eps, double a, double b, int n)
{
	double prev = 0, next = 1;
	while (fabs(prev - next) > eps)
	{
		prev = LeftRectangle(a, b, n);
		next = LeftRectangle(a, b, 2 * n);
		n = 2 * n;
	}
	return n;
}

int TheNumberOfPartitionsInRightRectangle(double eps, double a, double b, int n)
{
	double prev = 0, next = 1;
	while (fabs(prev - next) > eps)
	{
		prev = RightRectangle(a, b, n);
		next = RightRectangle(a, b, 2 * n);
		n = 2 * n;
	}
	return n;
}

double LeftRectangle(double a, double b, int n)
{
	double step = (b - a) / n;
	double integral = 0;
	double t = a;
	while (t < b)
	{
		integral += Formula(t);
		t += step;
	}
	integral *= step; 
	return integral;
}

double RightRectangle(double a, double b, int n)
{
	double step = (b - a) / n;
	double integral = 0;
	double t = a + step;
	while (t < b)
	{
		integral += Formula(t);
		t += step;
	}
	integral *= step;
	return integral;
}

double Formula(double x)
{
	return sin(x) / x;
}
