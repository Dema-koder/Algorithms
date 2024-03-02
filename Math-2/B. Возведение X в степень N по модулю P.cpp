#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <random>
#include <set>
#include <unordered_map>

using namespace std;
typedef long long ll;

long long pow(long long x, long long n, long long p) {
	if (n == 0)
		return 1;
	if (n % 2 == 0) {
		long long temp = pow(x, n / 2, p) % p;
		return (temp * temp) % p;
	}
	else {
		long long temp = pow(x, n - 1, p) % p;
		return (temp * x) % p;
	}
}

int main() {
	long long x, n, p; cin >> x >> n >> p;
	cout << pow(x, n, p);
}
