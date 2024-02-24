#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n; cin >> n;
    long long x = n;
    vector<long long>divs;

    for (int i = 2; i * i <= x; i++)
        while (x % i == 0) {
            divs.push_back(i);
            x /= i;
        }
    if (x > 1)
        divs.push_back(x);
    cout << ((divs.size() == 2 && divs[0] != divs[1]) ? "YES" : "NO");
}
