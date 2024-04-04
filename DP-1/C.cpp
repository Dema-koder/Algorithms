#include <vector>
#include <iostream>
 
using namespace std;
 
int main()
{
    vector<int> route;
    vector<int> coins(10002);
    int sm = 0;
    int n, k, x, ind=-1, new_ind = -1;
    cin >> n >> k;
    for (int i=0; i<n-2;i++) {
        cin >> x;
        coins[i] = x;
    }
    while (ind < n - 2 - k) {
        int mx = -10^6;
        
        for (int j = ind + 1; j <= k + ind; j++) {
            if (coins[j] >= 0) {
                new_ind = j;
                break;
            }
            if (coins[j] >= mx) {
                mx = coins[j];
                new_ind = j;
            }
        }
        sm += coins[new_ind];
        route.push_back(new_ind);
        ind = new_ind;
    }
    for (int i=ind + 1; i < n - 2; i++) {
        if (coins[i] >= 0) {
            route.push_back(i);
            sm += coins[i];
        }
    }
    cout << sm << endl;
    cout << route.size() + 1 << endl;
    cout << 1 << " ";
    for (int i=0; i < route.size(); i++) {
        cout << route[i] + 2<< " ";
    }
    cout << n;
    return 0;
}
