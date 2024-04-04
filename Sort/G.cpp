#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    sort(a, a+n);
 
    int ans = a[0];
    for(int i = 0; i < n; i += 4){
        if (a[i] != a[i+1]){
            ans = a[i];
            break;
        }
    }
    cout << ans;
    return 0;
}
