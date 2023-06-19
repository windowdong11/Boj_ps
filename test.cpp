#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

static bool OOB(int x, int y, int Mx, int My)
{
	return (x < 0 || y < 0 || Mx <= x || My <= y);
}

void original_sum(int a, int b)
{
	a += b;
}

void reference_sum(int &a, const int &b)
{
	a += b;
}

int main() {
	int n1 = 1, n2 = 2;

	cout << "n1 : " << n1 << ", n2 : " << n2 << '\n';
	original_sum(n1, n2);
	cout << "n1 : " << n1 << ", n2 : " << n2 << '\n';
	reference_sum(n1, n2);
	cout << "n1 : " << n1 << ", n2 : " << n2 << '\n';
	int &ref = n1;
	cout << "n1 : " << &n1 << ", ref : " << &ref << '\n';
	return 0;
}
