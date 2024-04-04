#include <bits/stdc++.h>

#include <random>

using namespace std;

pair<int, int> partition(vector<int>& a, int l, int r, int x) {
    int n = a.size();
    int i = l;
    int j = r;
    while (i < j) {
        while (a[i] < x) {
            ++i;
        }
        while (a[j] > x) {
            --j;
        }
        if (j <= i) break;
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
        }
        ++i;
    }
    j = -1;
    for (i = l; i <= r; ++i) {
        if (a[i] > x) {
            j = i - 1;
            break;
        }
    }
    if (j == -1) {
        j = r;
    }
    pair<int, int> res = {-1, j + 1};
    for (i = j; i >= l; --i) {
        if (a[i] == x) {
            swap(a[i], a[j]);
            --j;
        }
    }
    res.first = j;
    return res;
}

void quick_sort(vector<int>& a, int l, int r) {
    if (r <= l) {
        return;
    }
    int x = a[(l + r) / 2];
    pair<int, int> p = partition(a, l, r, x);
    quick_sort(a, l, p.first);
    quick_sort(a, p.second, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    shuffle(a.begin(), a.end(), std::mt19937(std::random_device()()));
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}
