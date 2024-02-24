#include <bits/stdc++.h>
using namespace std;
 
int main(){ 
    long long n;
    cin >> n;
    if (n < 5040000) {
        for (long long i = n; i * 100 <= 101 * n; i++) {
            int numDivs = 0;
            for (long long j = 1; j * j <= i; j++) {
                if (numDivs >= 100) {
                    break;
                }
                if (i % j == 0) {
                    numDivs++;
                    if (j * j != i) {
                        numDivs++;
                    }
                }
            }
            if (numDivs >= 100) {
                cout << i << endl;
                return 0;
            }
        }
        cout << -1 << endl;
    } else{
        cout << (n / 50400 + 1) * 50400 << endl;
    }
}
