#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
#define X first
#define Y second

static bool OOB(int x, int y, int Mx, int My)
{
	return (x < 0 || y < 0 || Mx <= x || My <= y);
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	vector<string> board(h);
	vector<vector<int>> v(h, vector<int>(w, 1000 * 1000 * 1000));
	priority_queue<pii> userq;
	priority_queue<pii> fireq;
	priority_queue<pii> tmpuserq;
	priority_queue<pii> tmpfireq;
	for (int y = 0; y < h; ++y)
	{
		cin >> board[y];
		for (int x = 0; x < w; ++x)
		{
			if (board[y][x] == 'J') {
				board[y][x] = '.';
				tmpuserq.push({x, y});
				v[y][x] = 0;
			}
			else if (board[y][x] == 'F') {
				tmpfireq.push({x, y});
			}
		}
	}
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};
	while (!tmpuserq.empty()) {
		swap(userq, tmpuserq);
		swap(fireq, tmpfireq);
		while (!userq.empty()) {
			int ncost, cx, cy;
			tie(cx, cy) = userq.top();
			userq.pop();
			if (board[cy][cx] == 'F')
				continue;
			ncost = v[cy][cx] + 1;
			for (int d = 0; d < 4; ++d) {
				int nx = cx + dx[d], ny = cy + dy[d];
				if (OOB(nx, ny, w, h)) {
					cout << ncost;
					return 0;
				}
				if (board[ny][nx] != '.' || v[ny][nx] <= ncost)
					continue;
				v[ny][nx] = ncost;
				tmpuserq.push({nx, ny});
			}
		}
		while (!fireq.empty()) {
			int cx, cy;
			tie(cx, cy) = fireq.top();
			fireq.pop();
			for (int d = 0; d < 4; ++d) {
				int nx = cx + dx[d], ny = cy + dy[d];
				if (OOB(nx, ny, w, h) || board[ny][nx] != '.')
					continue;
				board[ny][nx] = 'F';
				tmpfireq.push({nx, ny});
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
