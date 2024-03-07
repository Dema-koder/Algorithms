#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <random>
#include <set>
#include <unordered_map>

using namespace std;
typedef long long ll;

ifstream cin("input.txt");
ofstream cout("output.txt");

vector<int>queue;
int ind = 0;

void push(int p) {
	queue.push_back(p);
}

void clear() {
	queue.clear();
	ind = 0;
}

int main() {

	string s; 
	while (cin >> s) {
		if (s == "push") {
			int x; cin >> x;
			cout << "ok\n";
			push(x);
		} 
		if (s == "front") 
			if (queue.size() == ind)
				cout << "error\n";
			else
				cout << queue[ind] << endl;
		if (s == "pop")
			if (queue.size() == ind)
				cout << "error\n";
			else 
				cout << queue[ind++] << endl;
		if (s == "size")
			cout << queue.size() - ind << endl;
		if (s == "exit") {
			cout << "bye\n";
			exit(0);
		}
		if (s == "clear") {
			clear();
			cout << "ok\n";
		}
	}

}
