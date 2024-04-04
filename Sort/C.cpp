#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    long day, k, x, ans = 0;
    cin >> day >> k;
    vector <long long> times;     
    for (int i = 0; i < k; i++) {
        cin >> x;
        times.push_back(x);
    }
    sort(times.begin(), times.end());
    for (int i = 0; i < k; i++) {
        if (day - times[i] >= 0) {
            ans ++;
            day -= times[i];
        }
        else {
            break;
        }
    }
    cout << ans;
    return 0;
}
