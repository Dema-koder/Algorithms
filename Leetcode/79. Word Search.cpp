class Solution {
public:
	vector<pair<int, int>>moves{ {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	vector<vector<bool>>used;
	bool dfs(vector<vector<char>>&board, string& word, int x, int y, int ind) {
		if (ind == word.size() - 1)
			return true;
		
		used[x][y] = true;
		bool res = false;
		
		for (auto to : moves) {
			int x1 = x + to.first, y1 = y + to.second;
			if (x1 < 0 || x1 >= board.size() || y1 < 0 || y1 >= board[0].size())
				continue;
			if (!used[x1][y1] && board[x1][y1] == word[ind + 1])
				res |= dfs(board, word, x1, y1, ind + 1);
		}
		used[x][y] = false;
		return res;
	}

public:
	bool exist(vector<vector<char>>& b, string word1) {
		used.resize(b.size(), vector<bool>(b[0].size(), false));
		bool res = false;
		for (int i = 0; i < b.size(); i++)
			for (int j = 0; j < b[i].size(); j++)
				if (b[i][j] == word1[0]) {
					if (dfs(b, word1, i, j, 0))
						return true;
				}
		return false;
	}
};
