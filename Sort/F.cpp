#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    //freopen("mex.in", "r", stdin);
    //freopen("mex.out", "w", stdout);
    
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &i : a)
		cin >> i;
	sort(a.begin(), a.end());
	int x = 0;
	for (int i : a) {
		if (i == x)
			x++;
		if (i > x)
			break;
	}
	cout << x;
 
	return 0;
}
