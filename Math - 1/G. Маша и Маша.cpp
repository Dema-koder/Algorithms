#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if (a < b) {
    	swap(a, b);
    }
    if (b == 0) {
    	return a;
    } else {
    	return gcd(b, a%b);
    }
}

int main() {
	long long a, b, n;
	cin >> a >> b >> n;

	long long lcm = (a * b) / gcd(a, b);

    cout << n - n / lcm << endl;

    return 0;
}
