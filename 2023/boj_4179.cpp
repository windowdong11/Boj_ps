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
	vector<vector<int>> v(h, vector<int>(w, 0));
	priority_queue<pii> userq;
	priority_queue<pii> fireq;
	priority_queue<pii> tmpuserq;
	priority_queue<pii> tmpfireq;
	for (int y = 0; y < h; ++y)
	{
		cin >> board[y];
		for (int x = 0; x < w; ++w)
		{
			if (v[y][x] == 'J') {
				board[y][x] = '.';
				tmpuserq.push({x, y});
				v[y][x] = 1;
			}
			else if (v[y][x] == 'F') {
				tmpfireq.push({x, y});
				v[y][x] = -1;
			}
		}
	}
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};
	while (!tmpuserq.empty()) {
		swap(userq, tmpuserq);
		while (!userq.empty()) {
			int ncost, cx, cy;
			tie(cx, cy) = userq.top();
			userq.pop();
			ncost = v[cy][cx] + 1;
			for (int w = 0; w < 4; ++w) {
				int nx = cx + dx[w], ny = cy + dy[w];
				if (OOB(nx, ny, w, h)) {
					cout << ncost - 1;
					return 0;
				}
				if (board[ny][nx] != '.' || v[ny][nx] <= ncost)
					continue;
				v[ny][nx] = ncost;
				tmpuserq.push({nx, ny});
			}
		}
	}
	while (!userq.empty()) {
			int ncost, cx, cy;
			tie(cx, cy) = userq.top();
			userq.pop();
			for (int w = 0; w < 4; ++w) {
				int nx = cx + dx[w], ny = cy + dy[w];
				if (OOB(nx, ny, w, h) || board[ny][nx] != '.')
					continue;
				board[ny][nx] = 'F';
				userq.push({nx, ny});
			}
		}
	}
	return 0;
}
