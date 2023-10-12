#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;
typedef long long ll;

const int P = 31;
const ll MOD = 1e9 + 7;

ll p_pow = 1;
ll hashFromString(string s) {
	ll hash = 0;
	for (int i = 0; i < s.size(); i++) {
		hash += (s[i] - 'a' + 1) * p_pow;
		hash %= MOD;
		p_pow *= P;
		p_pow% MOD;
	}
	return hash;
}

int main() {
	string s; cin >> s;
	cout << hashFromString(s);
}
