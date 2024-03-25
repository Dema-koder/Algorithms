#include <fstream> // iostream
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

// проверка на простоту
bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

// нахождение всех делителей
vector<int> allDivisors(int n) {
	vector<int>ans;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ans.push_back(i);
			if (i * i != n)
				ans.push_back(n / i);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

// массива для решета
vector<bool>prime;

// алгоритм решето эратосфена
void theSieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (prime[i])
			for (int j = i * i; j <= n; j += i)
				prime[j] = false;
	}
}  

// бинарное возведение в степень
long long binpow(int n, int p, int m) {
	if (p == 0)
		return 1;
	if (p % 2 == 0) {
		long long ans = binpow(n, p / 2, m) % m;
		return ans * ans % m;
	}
	else {
		long long ans = binpow(n, p - 1, m) % m;
		return ans * n % m;
	}
}

// алгоритм Евклида для нахождения НОД
long long gcd(long long a, long long b) {
	if (b != 0)
		return gcd(b, a % b);
	return a;
	//return b ? gcd(b, a % b) : a;
}

// нахождение НОК
long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

// разбиение числа на простые множители
vector<long long> decomposition(long long n) {
	vector<long long> ans;
	for (int i = 2; i * i <= n; i++)
		while (n % i == 0) {
			ans.push_back(i);
			n /= i;
		}
	return ans;
}

int main() {
	int n; cin >> n;
	if (isPrime(n)) 
		cout << n << " - простое\n";
	else 
		cout << n << " - составное\n";

	vector<int>ans = allDivisors(n);
	cout << "Все делители числа " << n << ":" << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;

	prime.resize(n + 1, true);
	prime[0] = false;
	prime[1] = false;
	theSieve(n);
	cout << "Все простые на промежутке от 0 до " << n << endl;
	for (int i = 0; i <= n; i++)
		if (prime[i])
			cout << i << " ";
	cout << endl;

	cout << "Разбиение числа " << n << " на простые числа: \n";
	vector<long long>res = decomposition(n);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
}
