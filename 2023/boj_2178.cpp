#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

static bool OOB(int x, int y, int Mx, int My)
{
	return (x < 0 || y < 0 || Mx <= x || My <= y);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	for (int y = 0; y < n; ++y)
		cin >> board[y];
	int distance = 0;
	vector<vector<int>> cost(n, vector<int>(m, -1));
	queue<pii> q;
	vector<pii> ways4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	q.emplace(pii(0, 0));
	cost[0][0] = 0;
	int destx = m - 1, desty = n - 1;
	while (!q.empty()) {
		int cx, cy;
		tie(cx, cy) = q.front();
		q.pop();
		int next_cost = cost[cy][cx] + 1;
		for (auto [dx, dy] : ways4) {
			int nx = cx + dx, ny = cy + dy;
			if (OOB(nx, ny, m, n) || board[ny][nx] == '0' || cost[ny][nx] != -1)
				continue;
			q.emplace(pii(nx, ny));
			cost[ny][nx] = next_cost;
			if (ny == desty && nx == destx) {
				cout << next_cost + 1;
				return 0;
			}
		}
	}
	return 0;
}
