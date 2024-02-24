#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>>table(n, vector<int>(m)); // изначальная таблица
	vector<vector<int>>d(n, vector<int>(m, 1e9)); // массив расстояний, соответственно и ответа
	vector<pair<int, int>>moves({ { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } }); // возможные ходы из каждой ячейки(вверх, вниз, вправо, влево)
	queue<pair<int, int>>q; // очередь необходимая для bfs
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> table[i][j];   // считываем таблицу
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			if (table[i][j] == 1) { // для каждой 1 запускаем bfs
				q.push({ i, j }); // добавляем в очередь первую клетку
				vector<vector<bool>>used(n, vector<bool>(m, false));
				d[i][j] = 0; // сразу ставим 0
				while (!q.empty()) {
					auto v = q.front(); // достаем из очереди
					q.pop();
					int x = v.first, y = v.second; // для простоты кода выделим координаты
					used[x][y] = true; 
					for (auto to : moves) { // перебираем все возможные ходы
						int x1 = x + to.first, y1 = y + to.second; // новые координаты(возможный переход)
						if (x1 < n && x1 >= 0 && y1 >= 0 && y1 < m && !used[x1][y1]) { // проверяем что мы можем туда пойти
							if (d[x1][y1] > d[x][y] + 1) { // в случае если в новой ячейке обновиться ответ, то идем туда
								q.push({ x1, y1 });
								used[x1][y1] = true;
								d[x1][y1] = d[x][y] + 1;
							}
						}
					}
				}
			}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
}
