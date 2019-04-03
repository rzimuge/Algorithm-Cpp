#include<iostream>
#include<cmath>
#define H 10
using namespace std;

int BigInt(int X,int Y,int n)
{
	if (n == 1)
	{
		return X * Y;
	}
	int N = n / 2;
	int A = X / pow(H, N);


	int B = X - A* pow(H, N);
	
	int C = Y / pow(H, N);
	int n2 = n / 2;

	int D = Y - C * pow(H,N);


	int ac = BigInt(A, C, N);
	int bd = BigInt(B, D, N);
	int Al = BigInt(A - B,D - C, N);

	return ac * pow(H, n) + (Al + ac + bd)*pow(H, N) + bd;
}
int BigInteger(int X, int Y, int n)
{
	if (n % 2 != 0)
	{
		X *= 10;
		Y *= 10;
		return 	BigInt(X, Y, ++n)/100;
	}
	return BigInt(X, Y, n);

}

int main()
{
	int x, y, n;
	cin >> x >> y >> n;
	cout<< BigInteger(x, y,n);
	return 0;
}
