#include <iostream>
#include <vector>

using namespace std;

int main() {
	int x;
	vector<int>count(101);
	while (cin >> x) {
		count[x]++;
	}
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j < count[i]; j++)
			cout << i << " ";
}
