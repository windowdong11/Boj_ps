#include<bits/stdc++.h>
using namespace std;

static bool OOB(int x, int y, int mx, int my)
{
	return (x < 0 || y < 0 || mx <= x || my <= y);
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}
	int count = 0;
	int maxsize = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] != 1)
				continue;
			++count;
			queue<pair<int, int>> q;
			q.push({j, i});
			board[i][j] = 0;
			int size = 1;
			while (!q.empty()) {
				int x, y;
				tie(x, y) = q.front();
				q.pop();
				int dx[4] = {0, 0, 1, -1};
				int dy[4] = {1, -1, 0, 0};
				for (int direction = 0; direction < 4; ++direction) {
					int nx = x + dx[direction];
					int ny = y + dy[direction];
					if (OOB(nx, ny, m, n) || board[ny][nx] != 1)
						continue;
					board[ny][nx] = 0;
					++size;
					q.push({nx, ny});
				}
			}
			maxsize = max(size, maxsize);
		}
	}
	cout << count << '\n' << maxsize;
	return 0;
}