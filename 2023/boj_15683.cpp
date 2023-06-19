#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

static bool OOB(int x, int y, int Mx, int My)
{
	return (x < 0 || y < 0 || Mx <= x || My <= y);
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int	find_max_views(vector<vector<set<pii>>> &view, set<pii> &points, int cur, int count)
{
	if (cur == count)
		return points.size();
	int result = 0;
	set<pii> backup = points;
	for (int w = 0; w < view[cur].size(); w++) {
		set_difference(view[cur][w].begin(), view[cur][w].end(), points.begin(), points.end(),
                        inserter(points, points.end()));
		result = max(result, find_max_views(view, points, cur + 1, count));
		points = backup;
	}
	return result;
}

int main() {
	int spaces = 0;
	int height, width;
	cin >> height >> width;
	vector<vector<int>> board(height, vector<int>(width));
	vector<pii> camera_pos;
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			cin >> board[y][x];
			spaces += board[y][x] != 6;
			if (1 <= board[y][x] && board[y][x] <= 5)
				camera_pos.emplace_back(pii(x, y));
		}
	}
	vector<vector<set<pii>>> view(camera_pos.size());
	vector<vector<vector<int>>> view_direction = {
		{},
		{
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1},
		},
		{
			{1, 0, 1, 0},
			{0, 1, 0, 1},
		},
		{
			{0, 0, 1, 1},
			{1, 0, 0, 1},
			{1, 1, 0, 0},
			{0, 1, 1, 0},
		},
		{
			{0, 1, 1, 1},
			{1, 0, 1, 1},
			{1, 1, 0, 1},
			{1, 1, 1, 0},
		},
		{
			{1, 1, 1, 1},
		},
	};
	for (int i = 0; i < camera_pos.size(); ++i) {
		int cx, cy;
		tie(cx, cy) = camera_pos[i];
		for (int w = 0; w < view_direction[board[cy][cx]].size(); ++w) {
			view[i].push_back({});
			for (int z = 0; z < 4; ++z)
			{
				if (!view_direction[board[cy][cx]][w][z])
					continue;
				int x = cx, y = cy;
				while (!OOB(x, y, width, height) && board[y][x] != 6) {
					view[i][w].insert(pii(x, y));
					x += dx[z];
					y += dy[z];
				}
			}
		}
	}
	set<pii> view_points;
	cout << spaces - find_max_views(view, view_points, 0, camera_pos.size());
	return 0;
}
