#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long n, limn;
	cin >> n;
	limn = n;
	long long i = 1;
	while (i * i < limn) {
		i++;
		while (n % i == 0) {
			limn = n;
			n /= i;
			cout << i << " ";
		}		
	}
	if (n != 1)
		cout << n;

	return 0;
}
