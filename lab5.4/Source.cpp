
#include <iostream>
#include <cmath>
using namespace std;
double S0(const int i)
{
	double s = 0;
	for ( int i = 1; i <= 15; i++)
		s += ((sin(10 * i) + cos(10 / i)) / sqrt(i));
	return s;
}
double S1(const int i)
{
	if (i > 15)
		return 0;
	else
		return (((sin(10 * i) + cos(10 / i)) / sqrt(i)) + S1 (i + 1));
}
double S2(const int i)
{
	if (i < 15)
		return 0;
	else
		return (((sin(10 * i) + cos(10 / i)) / sqrt(i)) + S1(i + 1));
}
double S3( const int i, double t)
{
	t = t + ((sin(10 * i) + cos(10 / i)) / sqrt(i));
	if (i >= 15)
		return t;
	else
		return S3( i + 1, t);
}
double S4(const int i, double t)
{
	t = t + ((sin(10 * i) + cos(10 / i)) / sqrt(i));;
	if (i <= 15)
		return t;
	else
		return S4( i - 1, t);
}
int main()
{
	double i, S;

	S = 0;
	i = 1;

	cout << "(iter) S0 = " << S0(i) << endl;
	cout << "(rec up ++) S1 = " << S1(i) << endl;
	cout << "(rec up --) S2 = " << S2(i) << endl;
	cout << "(rec down ++) S3 = " << S3(i, 0) << endl;
	cout << "(rec down --) S4 = " << S4(i, 0) << endl;
	return 0;
}
