#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

static bool OOB(int x, int y, int Mx, int My)
{
	return (x < 0 || y < 0 || Mx <= x || My <= y);
}

/* 6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1
*/
int main() {
	int width, height;
	cin >> width >> height;
	int count = 0;
	vector<vector<int>> board(height, vector<int>(width));
	queue<pii> q, nextq;
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			cin >> board[y][x];
			count += board[y][x] != 0;
			if (board[y][x] == 1)
				nextq.emplace(pii(x, y));
		}
	}
	int days = 0;
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};
	while (!nextq.empty()) {
		swap(q, nextq);
		while (!q.empty()) {
			pii cur = q.front();
			q.pop();
			for(int way = 0; way < 4; ++way) {
				int nx = cur.X + dx[way], ny = cur.Y + dy[way];
				if (OOB(nx, ny, width, height) || board[ny][nx])
					continue;
				count++;
				board[ny][nx] = 1;
				nextq.push(pii(nx, ny));
			}
		}
		days += nextq.size() > 0;
	}
	if (count == width * height)
		cout << days;
	else
		cout << -1;
	return 0;
}
