/*
https://t.me/algoses/93
Дается массив из 0 и 1. Ваша задача выбрать такую позицию нуля, чтобы минимальное расстояние 
до единицы было максимальным.
Например 100110001
ответом будет позиция 6. 100110001. В задаче нельзя использовать дополнительную память, 
то есть можете использовать только О(1) дополнительной памяти.
*/

int solve(string s) {
	if (s.size() == 0)
		return -1;
	int res = 0, one = s.find('1'), prev_one = -1, ans = -1;
	if (one == -1)
		return s.size();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			if (prev_one == -1) {
				if (one != -1)
					if (res < one - i + 1)
						ans = i, res = one - i + 1;
			}
			else {
				if (one != -1) {
					if (min(one - i + 1, i - prev_one + 1) > res)
						res = max(res, min(one - i + 1, i - prev_one + 1)), ans = i;
				}
				else
					if (i - prev_one + 1 > res)
						res = i - prev_one + 1, ans = i;
			}
		else
			prev_one = one, one = s.find('1', one + 1);
	}
	return ans;
}
