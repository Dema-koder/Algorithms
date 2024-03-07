#include <iostream>
#include <vector>

using namespace std;

//ifstream cin("input.txt");
//ofstream cout("output.txt");

struct Stack {
	vector<int>st;
	int ind = -1;

	void push(int x) {
		if (st.size() == ind + 1)
			st.push_back(x);
		else
			st[ind + 1] = x;
		ind++;
		cout << "ok\n";
	}

	void pop() {
		cout << st[ind] << endl;
		ind--;
	}

	void back() {
		cout << st[ind] << "\n";
	}

	void size() {
		cout << ind + 1 << endl;
	}

	void clear() {
		cout << "ok\n";
		ind = -1;
	}

	void exxit() {
		cout << "bye";
		exit(0);
	}
};

int main() {
	Stack st;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (s == "push") {
			int x; cin >> x;
			st.push(x);
		}
		if (s == "pop")
			st.pop();
		if (s == "back") 
			st.back();
		if (s == "size")
			st.size();
		if (s == "clear")
			st.clear();
		if (s == "exit")
			st.exxit();
	}
}
