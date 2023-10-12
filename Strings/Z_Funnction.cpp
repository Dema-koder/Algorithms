#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;
typedef long long ll;

vector<int> z;

void z_function(string s) {
	z.resize(s.size());
	for (int i = 1, l = 0, r = 0; i < s.size(); i++) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
			z[i]++;
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
}

int main() {
	string s; cin >> s;
	z_function(s);
	for (auto to : z)
		cout << to << " ";
}
