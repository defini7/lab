#include <iostream>
#include <math.h>
using namespace std;

class Calculate 
{
public:
	float plus(float a, float b);
	float minus(float a, float b);
	float multiply(float a, float b);
	float divide(float a, float b);
	float remainder(float a, float b);
	float sqr(float a);
	float sqrtt(float a);
};

float Calculate::plus(float a, float b)
{
	return a + b;
}

float Calculate::minus(float a, float b)
{
	return a - b;
}

float Calculate::multiply(float a, float b)
{
	return a * b;
}

float Calculate::divide(float a, float b)
{
	return a / b;
}

float Calculate::remainder(float a, float b)
{
	return int(a) % int(b);
}

float Calculate::sqr(float a)
{
	return pow(a, 2);
}

float Calculate::sqrtt(float a)
{
	return sqrt(a);
}

int main()
{
	cout << "Help:\n\t'r' for sqr()\n\t't' for sqrt()" << endl << endl;
	Calculate calculate;
	float a, b;
	char c[1];
	cin >> a;
	cin >> c[0];
	if (c[0] == '+' || c[0] == '-' || c[0] == '/' || c[0] == '%' || c[0] == '*' || c[0] == '%')
	{
		cin >> b;
		system("cls");
		if (c[0] == '+')
		{
			cout << a << " + " << b << " = " << calculate.plus(a, b) << endl;
		}
		else if (c[0] == '-')
		{
			cout << a << " - " << b << " = " << calculate.minus(a, b) << endl;
		}
		else if (c[0] == '/')
		{
			cout << a << " / " << b << " = " << calculate.divide(a, b) << endl;
		}
		else if (c[0] == '%')
		{
			cout << a << " % " << b << " = " << calculate.remainder(a, b) << endl;
		}
		else if (c[0] == '*')
		{
			cout << a << " * " << b << " = " << calculate.multiply(a, b) << endl;
		}
	}
	else if (c[0] == 'r' || c[0] == 't')
	{
		system("cls");
		if (c[0] == 'r')
		{
			cout << "sqr(" << a << ")" << " = " << calculate.sqr(a) << endl;
		}
		if (c[0] == 't')
		{
			cout << "sqrt(" << a << ")" << " = " << calculate.sqrtt(a) << endl;
		}
	}
}

/* Standart calculator -- defini7 */