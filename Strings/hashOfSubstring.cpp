#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;
typedef long long ll;

const int P = 31;
const ll MOD = 1e9 + 7;

// вычисление хэша для подстроки
const int SIZE = 1e5; // максимальный размер строки S
vector<ll>p_pows;
void build_p_pows(int n) {
	p_pows.resize(n, 1);
	for (int i = 1; i < n; i++)
		p_pows[i] = (p_pows[i - 1] * P) % MOD;
}

vector<ll>pref_hash;
void build_pref_hash(string s) {
	pref_hash.resize(s.size());
	build_p_pows(s.size());
	for (int i = 0; i < s.size(); i++) {
		pref_hash[i] = (s[i] - 'a' + 1) * p_pows[i];
		if (i > 0)
			pref_hash[i] += pref_hash[i - 1];
		pref_hash[i] %= MOD;
	}
}

ll hashOfSubstring(int i, int j) {
	ll hash = pref_hash[j];
	if (i > 0)
		hash = pref_hash[i - 1];
	return hash;
}

int main() {
	string s; cin >> s;
	build_pref_hash(s);

	int l, r; cin >> l >> r;
	cout << hashOfSubstring(l - 1, r - 1);
}
