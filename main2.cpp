#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

void solveroot();
void Triangleproblem();
void judge();

void solveroot()
{
	double der;
	double m, n;
	cout << "Please enter the coefficients of the equation you want to calculate in the order of a, b, c." << endl;
	double a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	der = b * b - 4 * a*c;
	int boolist;
	if (der == 0)       //表示有两个相同的根
	{
		boolist = 1;
	}
	else if (der < 0)   //表示有两个非有理数的根
	{
		boolist = 0;
	}
	else      //表示有两个不同的根
	{
		boolist = 2;
	}
	switch (boolist)
	{
	case 0:
		der = -der;
		m = (-b) / (2 * a);
		n = sqrt(der) / (2 * a);
		cout << "The equation has two complex roots" << endl;
		printf("x1=%.3f+%.3fi x2=%.3f-%.3fi", m, n, m, n);
		break;
	case 1:
		m = (-b) / (2 * a);
		n = sqrt(der) / (2 * a);
		cout << "The equation has two identical roots" << endl;
		printf("x1=%.3f x2=%.3f", m + n, m - n);
		break;
	case 2:
		m = (-b) / (2 * a);
		n = sqrt(der) / (2 * a);
		cout << "The equation has two different roots" << endl;
		printf("x1=%.3f x2=%.3f", m + n, m - n);
		break;
	}
}

void Triangleproblem()
{
	double a, b, c;
	double s;
	double fai;
	double number;
	cout << "Please enter the side length of the three sides of the triangle" << endl;
	cin >> a >> b >> c;
	fai = (a + b + c) / 2;
	number = fai * (fai - a)*(fai - b)*(fai - c);
	s = sqrt(number);
	cout << "The area of the triangle is：" << s << endl;
}

void judge()
{
	int year, day;
	int sum, boolist;
	int month;
	cout << "Please enter today's date in the format of year-month-date" << endl;
	cin >> year;
	getchar();
	cin >> month;
	getchar();
	cin >> day;
	getchar();
	switch (month)
	{
	case 1:sum = 0; break;
	case 2:sum = 31; break;
	case 3:sum = 59; break;
	case 4:sum = 90; break;
	case 5:sum = 120; break;
	case 6:sum = 151; break;
	case 7:sum = 181; break;
	case 8:sum = 212; break;
	case 9:sum = 243; break;
	case 10:sum = 273; break;
	case 11:sum = 304; break;
	case 12:sum = 334; break;
	default:cout << "data error" << endl; break;
	}
	sum = sum + day;

	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		boolist = 1;
	}
	if (boolist == 1 && month > 2)
	{
		sum = sum + 1;
	}
	cout << "As of today, this year has passed a total of " << sum << "days.";
	int a, b;
	a = sum / 7;
	b = sum - a * 7;
	cout << "The week is" << a << "and the day is" << b << endl;
}

int main()
{
	int w;
	cout << "The program can complete three tasks" << endl;
	cout << "The task one finds the root of the quadratic equation" << endl;
	cout << "The task two knows the three sides of the triangle to find the area" << endl;
	cout << "The task three judges today according to the date." << endl;
	cout << "Please enter the action you want to take" << endl;
	cin >> w;
	switch (w)
	{
	case 1:solveroot(); break;
	case 2:Triangleproblem(); break;
	case 3:judge(); break;
	}
	return 0;
}
