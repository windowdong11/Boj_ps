#include "BaekJoonQuest.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

pair<int, int> operator+(const pair<int, int>& left, const pair<int, int>& right)
{
	return { left.first + right.first, left.second + right.second };
}

void BaekJoon::Quest_2628()
{
	int xSize, ySize, cutCount;
	cin >> xSize >> ySize >> cutCount;

	vector<int> cutX, cutY;
	cutX.push_back(0);
	cutX.push_back(xSize);
	cutY.push_back(0);
	cutY.push_back(ySize);

	for (int i = 0; i < cutCount; i++)
	{
		bool checkWay;
		int cuttingPosition;
		cin >> checkWay >> cuttingPosition;
		(checkWay ? cutX : cutY).push_back(cuttingPosition);
	}

	sort(cutX.begin(), cutX.end());
	int xMax = 0;
	const size_t xEnd = cutX.size() - 1;
	for (size_t it = 0; it < xEnd; it++)
		if (xMax < cutX[it + 1] - cutX[it])
			xMax = cutX[it + 1] - cutX[it];

	sort(cutY.begin(), cutY.end());
	int yMax = 0;
	const size_t  yEnd = cutY.size() - 1;
	for (size_t it = 0; it < yEnd; it++)
		if (yMax < cutY[it + 1] - cutY[it])
			yMax = cutY[it + 1] - cutY[it];

	cout << xMax * yMax << endl;
}

void BaekJoon::Quest_1158()
{
	int N, K;
	cin >> N >> K;
	++N;
	--K;
	queue<int> q;
	for (int i = 1; i < N; ++i)
		q.push(i);
	cout << "<";
	N -= 2;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">";
}

void BaekJoon::Quest_2851()
{
	int newScore, scoreSum = 0, tmp = 0;
	for (int i = 0; i < 10; ++i)
	{
		cin >> newScore;
		int dist = 100 - scoreSum;
	}
}

void BaekJoon::Quest_14647()
{
	int y, x;
	cin >> y >> x;
	int max = 0;
	vector<vector<int>> bingoBoard(y + 1, vector<int>(x + 1, 0));
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			int val;
			cin >> val;
			while (val > 8)
			{
				if (val % 10 == 9)
					++bingoBoard[i][j];
				val /= 10;
			}
			bingoBoard[i][x] += bingoBoard[i][j];
			bingoBoard[y][j] += bingoBoard[i][j];
		}
		bingoBoard[y][x] += bingoBoard[i][x];
		if (bingoBoard[i][x] > max)
			max = bingoBoard[i][x];
	}
	for (int j = 0; j < x; ++j)
		if (bingoBoard[y][j] > max)
			max = bingoBoard[y][j];
	cout << bingoBoard[y][x] - max;
}

void BaekJoon::Quest_7568()
{
	int count = 0;
	cin >> count;
	vector<pair<int, int>> list;
	for (int i = 0; i < count; i++)
	{
		int weight, height;
		cin >> weight >> height;
		list.push_back(make_pair(weight, height));
	}
	for (int i = 0; i < count; i++)
	{
		int rank = 1;
		for (int j = 0; j < i; j++)
		{
			if (list[i].first < list[j].first && list[i].second < list[j].second)
			{
				rank++;
			}
		}
		for (int j = i + 1; j < count; j++)
		{
			if (list[i].first < list[j].first && list[i].second < list[j].second)
			{
				rank++;
			}
		}
		cout << rank << " ";
	}
}

void BaekJoon::Quest_7576()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> tomatobox(n, vector<int>(m, 0));
	queue<pair<int, int>> ripedpos;
	pair<int, int> lastpos;
	int ripedcnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> tomatobox[i][j];
			if (tomatobox[i][j] == 1)
			{
				ripedcnt++;
				ripedpos.push(make_pair(i, j));
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (tomatobox[i][j] == 0
				&& ((0 <= i - 1) ? tomatobox[i - 1][j] == -1 : true)
				&& ((i + 1 < n) ? tomatobox[i + 1][j] == -1 : true)
				&& ((0 <= j - 1) ? tomatobox[i][j - 1] == -1 : true)
				&& ((j + 1 < m) ? tomatobox[i][j + 1] == -1 : true))
			{
				cout << "-1";
				return;
			}
		}
	while (!ripedpos.empty())
	{
		lastpos = ripedpos.front();
		int y = lastpos.first, x = lastpos.second;
		ripedpos.pop();
		if ((0 <= y - 1) && tomatobox[y - 1][x] == 0)
		{
			ripedpos.push(make_pair(y - 1, x));
			tomatobox[y - 1][x] = tomatobox[y][x] + 1;
		}
		if ((y + 1 < n) && tomatobox[y + 1][x] == 0)
		{
			ripedpos.push(make_pair(y + 1, x));
			tomatobox[y + 1][x] = tomatobox[y][x] + 1;
		}
		if ((0 <= x - 1) && tomatobox[y][x - 1] == 0)
		{
			ripedpos.push(make_pair(y, x - 1));
			tomatobox[y][x - 1] = tomatobox[y][x] + 1;
		}
		if ((x + 1 < m) && tomatobox[y][x + 1] == 0)
		{
			ripedpos.push(make_pair(y, x + 1));
			tomatobox[y][x + 1] = tomatobox[y][x] + 1;
		}
	}
	/*for (auto&& out : tomatobox)
	{
		for (auto&& elem : out)
			cout << elem;
		cout << endl;
	}*/
	cout << tomatobox[lastpos.first][lastpos.second] - 1;
}

void BaekJoon::Quest_1012()
{
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		pair<int, int> mapsize;
		int cabbagecnt;
		cin >> mapsize.first >> mapsize.second >> cabbagecnt;
		vector<vector<bool>> iscabbage(mapsize.second, vector<bool>(mapsize.first, false));
		vector<vector<bool>> issnailunavail(mapsize.second, vector<bool>(mapsize.first, true));
		queue<pair<int, int>> cabbageposition;
		for (int i = 0; i < cabbagecnt; i++)
		{
			int x, y;
			cin >> x >> y;
			iscabbage[y][x] = true;
			cabbageposition.push({ x,y });
		}
		int snailcnt = 0;
		queue<pair<int, int>> q;
		while (!cabbageposition.empty())
		{
			if (issnailunavail[cabbageposition.front().second][cabbageposition.front().first])
			{
				snailcnt++;
				issnailunavail[cabbageposition.front().second][cabbageposition.front().first] = false;
				q.push(cabbageposition.front());
			}
			cabbageposition.pop();
			while (!q.empty())
			{
				pair<int, int> lastpos = q.front();
				q.pop();
				if (0 <= lastpos.second - 1 && iscabbage[lastpos.second - 1][lastpos.first] && issnailunavail[lastpos.second - 1][lastpos.first])
				{
					issnailunavail[lastpos.second - 1][lastpos.first] = false;
					q.push({ lastpos.first, lastpos.second - 1 });
				}
				if (lastpos.second + 1 < mapsize.second && iscabbage[lastpos.second + 1][lastpos.first] && issnailunavail[lastpos.second + 1][lastpos.first])
				{
					issnailunavail[lastpos.second + 1][lastpos.first] = false;
					q.push({ lastpos.first, lastpos.second + 1 });
				}
				if (0 <= lastpos.first - 1 && iscabbage[lastpos.second][lastpos.first - 1] && issnailunavail[lastpos.second][lastpos.first - 1])
				{
					issnailunavail[lastpos.second][lastpos.first - 1] = false;
					q.push({ lastpos.first - 1, lastpos.second });
				}
				if (lastpos.first + 1 < mapsize.first && iscabbage[lastpos.second][lastpos.first + 1] && issnailunavail[lastpos.second][lastpos.first + 1])
				{
					issnailunavail[lastpos.second][lastpos.first + 1] = false;
					q.push({ lastpos.first + 1, lastpos.second });
				}
			}
		}
		cout << snailcnt << endl;
	}
}

void BaekJoon::Quest_3055()
{
	enum MapStatus
	{
		water = '*',
		rock = 'X',
		hedgedog = 'S',
		cave = 'D',
		blank = '.',
		visited = 'v'
	};
	int r, c;
	cin >> r >> c;
	vector<vector<char>> Map(r, vector<char>(c));
	pair<int, int> cavepos;
	queue<pair<int, int>> waterq, hedgedogq;
	pair<int, int> movearr[4] = {
		{0,1},
		{1,0},
		{0,-1},
		{-1,0}
	};
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			cin >> Map[i][j];
			switch (Map[i][j])
			{
			case hedgedog://°í½¿µµÄ¡
				hedgedogq.push({ i,j });
				Map[i][j] = visited;//¹°ÀÌ Âû ¼ö ÀÖµµ·Ï ÀÏ¹Ý ¹Ù´ÚÀ¸·Î º¯°æ
				break;
			case water://¹°
				waterq.push({ i,j });
				break;
			case cave://µ¿±¼
				cavepos.first = i;
				cavepos.second = j;
				break;
			}
		}


	int turncnt = 0;
	bool arrived = false;
	while (!hedgedogq.empty())
	{
		turncnt++;
		int qsize = waterq.size();
		for (int j = 0; j < qsize; j++)
		{
			pair<int, int> waterpos = waterq.front();
			for (int i = 0; i < 4; i++)
			{
				pair<int, int> newpos = waterpos + movearr[i];
				if (newpos.first >= 0 && newpos.second >= 0 && newpos.first < r && newpos.second < c // ¸Ê ¾È &
					&& Map[newpos.first][newpos.second] == blank) // ÀÏ¹Ý¹Ù´ÚÀÓ
				{
					Map[newpos.first][newpos.second] = water;
					waterq.push(newpos);
				}
			}
			waterq.pop();
		}

		qsize = hedgedogq.size();
		for (int j = 0; j < qsize; j++)
		{
			pair<int, int> hedgedogpos = hedgedogq.front();
			if (hedgedogpos == cavepos) // °í½¿µµÄ¡°¡ µ¿±¼À» Ã£À½
			{
				arrived = true;
				break;
			}


			for (int i = 0; i < 4; i++)
			{
				pair<int, int> newpos = hedgedogpos + movearr[i];
				if (newpos.first >= 0 && newpos.second >= 0 && newpos.first < r && newpos.second < c) // ¸Ê ¾È &
				{
					if (Map[newpos.first][newpos.second] == blank)
					{
						Map[newpos.first][newpos.second] = visited;
						hedgedogq.push(newpos);
					}
					else if (Map[newpos.first][newpos.second] == cave) // µ¿±¼ ¹ß°ß -> Á¾·á
					{
						cout << turncnt;
						return;
					}
				}
			}
			hedgedogq.pop();
		}
	}
	cout << "KAKTUS";
}

