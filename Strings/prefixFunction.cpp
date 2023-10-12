#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;
typedef long long ll;

vector<int> pref_fun;

void prefix_fun(string s) {
	pref_fun.resize(s.size());
	for (int i = 1; i < s.size(); i++) {
		int j = pref_fun[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pref_fun[j - 1];
		if (s[i] == s[j])
			j++;
		pref_fun[i] = j;
	}
}

int main() {
	string s; cin >> s;
	prefix_fun(s);
	for (auto to : pref_fun)
		cout << to << " ";
}
