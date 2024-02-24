#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long a, b; cin >> a >> b;
    vector<bool>isPrime(b + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= b; i++) {
        if (isPrime[i])
            for (int j = i * i; j <= b; j += i)
                isPrime[j] = false;
    }
    for (int i = a; i <= b; i++)
        if (isPrime[i])
            cout << i << " ";
}
