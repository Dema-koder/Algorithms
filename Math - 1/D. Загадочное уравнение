#include <cstdio>
#include <iostream>
#include <cmath>
 
using namespace std;
 
int main()
{
	int n;
	cin >> n, n++;
	int ans = 1, sq = sqrt(n);
	for (int i = 2; i <= sq; i++)
		if (n % i == 0)
		{
			int k = 0;
			while (n % i == 0) k++, n /= i;
			ans *= (k + 1);
		}
   	if (n > 1) ans  *= 2;
	cout << ans;
 
}
