#include <bits/stdc++.h>
using namespace std;

static bool OOB(int x, int y, int Mx, int My)
{
	return (x < 0 || y < 0 || Mx <= x || My <= y);
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	vector<string> board(12);

	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	for (int y = 0; y < 12; ++y)
		cin >> board[y];
	int combo = -1;
	bool exploded = true;
	while (exploded) {
		exploded = false;
		++combo;
		list<pair<int, int>> rm_list;
		vector<vector<bool>> visited(12, vector<bool>(6, false));
		for(int y = 0; y < 12; ++y) {
			for (int x = 0; x < 6; ++x) {
				if (board[y][x] == '.')
					continue;
				char color = board[y][x];
				list<pair<int, int>> visited_list;
				queue<pair<int, int>> q;
				q.push({x, y});
				visited[y][x] = true;
				visited_list.push_back({x, y});
				while (!q.empty()) {
					int cx, cy;
					tie(cx, cy) = q.front();
					q.pop();
					for(int i = 0; i < 4; ++i) {
						int nx = cx + dx[i];
						int ny = cy + dy[i];
						if (OOB(nx, ny, 6, 12) || board[ny][nx] != color || visited[ny][nx])
							continue;
						visited[ny][nx] = true;
						q.emplace(pair<int, int>(nx, ny));
						visited_list.emplace_back(pair<int, int>(nx, ny));
					}
				}
				if (visited_list.size() < 4)
					continue;
				rm_list.merge(move(visited_list));
			}
		}
		exploded = rm_list.size() != 0;
		for (auto [rx, ry] : rm_list) {
			--ry;
			for (; ry >= 0; --ry)
				board[ry + 1][rx] = board[ry][rx];
			board[0][rx] = '.';
		}
	}
	cout << combo;
	return 0;
}