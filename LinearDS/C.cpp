#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>

using namespace std;
typedef long long ll;

//ifstream cin("input.txt");
//ofstream cout("output.txt");


int main() {

	stack<char>st;
	string s; cin >> s;
	for (auto to : s) {
		if (to == '(' || to == '{' || to == '[')
			st.push(to);
		else {
			if (st.empty()) {
				cout << "NO";
				exit(0);
			}
			char top = st.top();
			if ((top == '(' && to != ')') || (top == '[' && to != ']') || (top == '{' && to != '}')) {
				cout << "NO";
				exit(0);
			}
			else {
				st.pop();
			}
		}
	}
	if (!st.empty())
		cout << "NO";
	else
		cout << "YES";
}
