#include "BaekJoonQuest.h"
#include "MyTimer.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>
#include <list>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <iterator>
#include <fstream>
#include <functional>
using namespace std;
//MyTimer t;

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
			case hedgedog://고슴도치
				hedgedogq.push({ i,j });
				Map[i][j] = visited;//물이 찰 수 있도록 일반 바닥으로 변경
				break;
			case water://물
				waterq.push({ i,j });
				break;
			case cave://동굴
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
				if (newpos.first >= 0 && newpos.second >= 0 && newpos.first < r && newpos.second < c // 맵 안 &
					&& Map[newpos.first][newpos.second] == blank) // 일반바닥임
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
			if (hedgedogpos == cavepos) // 고슴도치가 동굴을 찾음
			{
				arrived = true;
				break;
			}


			for (int i = 0; i < 4; i++)
			{
				pair<int, int> newpos = hedgedogpos + movearr[i];
				if (newpos.first >= 0 && newpos.second >= 0 && newpos.first < r && newpos.second < c) // 맵 안 &
				{
					if (Map[newpos.first][newpos.second] == blank)
					{
						Map[newpos.first][newpos.second] = visited;
						hedgedogq.push(newpos);
					}
					else if (Map[newpos.first][newpos.second] == cave) // 동굴 발견 -> 종료
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

void BaekJoon::Quest_6593()
{
	enum MapStatus
	{
		empty = '.',
		block = '#',
		start = 'S',
		end = 'E',
	};
	while (true)
	{
		int l, r, c;
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;
		tuple<int, int, int> endpos;
		vector<vector<vector<bool>>> visited(l, vector<vector<bool>>(r, vector<bool>(c, false)));
		queue<tuple<int, int, int>> q;
		for (int z = 0; z < l; ++z)
		{
			for (int y = 0; y < r; ++y)
			{
				for (int x = 0; x < c; ++x)
				{
					char tmp;
					cin >> tmp;

					switch (tmp)
					{
					case MapStatus::empty: // 빈공간
						visited[z][y][x] = false;
						break;
					case MapStatus::start: // 시작지점 -> 방문처리 & 시작지점 추가
						q.push(make_tuple(z, y, x));
					case MapStatus::block: // 막힘 -> 방뭉처리하여 가지못하도록 함
						visited[z][y][x] = true;
						break;
					case MapStatus::end: // 끝지점
						endpos = make_tuple(z, y, x);
						break;
					}
				}
			}
		}


		int minute = 0; // 탈출하는데 걸리는 시간 저장
		bool escaped = false;
		vector<tuple<int, int, int>> ways = {
			{0,0,1},
			{0,1,0},
			{1,0,0},
			{0,0,-1},
			{0,-1,0},
			{-1,0,0},
		};
		while (!q.empty())
		{
			++minute;
			int qsize = q.size();
			for (int i = 0; i < qsize; ++i)
			{
				auto curpos = q.front();
				q.pop();
				for (int j = 0; j < ways.size(); ++j)
				{
					int z = get<0>(curpos) + get<0>(ways[j]),
						y = get<1>(curpos) + get<1>(ways[j]),
						x = get<2>(curpos) + get<2>(ways[j]);
					if (z >= 0 && z < l
						&& y >= 0 && y < r
						&& x >= 0 && x < c)
					{
						if (endpos == make_tuple(z, y, x)) // escape
						{
							escaped = true;
							break;
						}
						else if (!visited[z][y][x])
						{
							visited[z][y][x] = true; // 방문처리
							q.push(make_tuple(z, y, x)); // 다음 탐색 기준지점 저장
						}

					}
					if (escaped)
						break;
				}
				if (escaped)
					break;
			}
			if (escaped)
				break;
		}
		if (escaped)
			cout << "Escaped in " << minute << " minute(s)." << endl;
		else
			cout << "Trapped!" << endl;
	}
}

void BaekJoon::Quest_1018()
{
	enum BoardType
	{
		black = false,
		white = true
	};
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> board(n, vector<bool>(m));
	int bcnt = 0; // bcnt : 첫칸이 검은색인 경우 올바른 색의 갯수
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char tmp;
			cin >> tmp;
			if (tmp == 'B' && ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))) // B의 경우 (짝수행 짝수열) 또는 (홀수행 홀수열)에 올수 있다.
			{
				++bcnt;
			}
			else if (tmp == 'W' && ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0))) // W의 경우 (짝수행 홀수열) 또는 (홀수행 짝수열)에 올수 있다.
			{
				++bcnt;
			}
		}
	}
	if (bcnt > n* m - bcnt)
		cout << n * m - bcnt;
	else
		cout << bcnt;
}

void BaekJoon::Quest_2573()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> Map(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	vector<pair<int, int>> icebergpos;
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < m; ++x)
		{
			cin >> Map[y][x];
			if (Map[y][x])	// 모든 빙산위치 순차적 저장
			{
				icebergpos.push_back({ y,x });
				visited[y][x] = false;
			}
			else
			{
				visited[y][x] = true;
			}
		}


	queue<pair<int, int>> q;


	bool divided = false;
	int turn = 0;
	while (!icebergpos.empty())
	{
		q.push(icebergpos[0]);
		visited[icebergpos[0].first][icebergpos[0].second] = true;

		while (!q.empty())
		{
			// bfs
			int qsize = q.size();
			for (int i = 0; i < qsize; ++i)
			{
				pair<int, int> pos = q.front();
				q.pop();
				// 다음 방문지점
				pair<int, int> movepos[4] = { {0,1},{1,0},{0,-1}, {-1,0} };
				for (int j = 0; j < 4; ++j)
				{
					pair<int, int> newpos = pos + movepos[j];
					if (0 <= newpos.first && newpos.first < n && 0 <= newpos.second && newpos.second < m
						&& !visited[newpos.first][newpos.second])
					{
						visited[newpos.first][newpos.second] = true; // 방문처리
						q.push(newpos);
					}
				}
			}
		}

		//cout << "====================" << endl;
		// 쪼개짐 확인
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; ++j)
			{
				//cout << Map[i][j] << visitedturn[i][j];
				if (!visited[i][j])
				{
					divided = true;
					break;
				}
			}
			//cout << endl;
			if (divided)
				break;
		}
		if (divided)
			break;

		vector<int> watercnt(icebergpos.size(), 0);
		// 근처 바다 수 셈
		for (int i = 0; i < icebergpos.size(); i++)
		{
			pair<int, int> movepos[4] = { {0,1},{1,0},{0,-1}, {-1,0} };
			for (int j = 0; j < 4; ++j)
			{
				pair<int, int> newpos = icebergpos[i] + movepos[j];
				if (0 <= newpos.first && newpos.first < n && 0 <= newpos.second && newpos.second < m
					&& Map[newpos.first][newpos.second] == 0)
					++watercnt[i];
			}
		}

		// 빙하 녹음 처리
		vector<pair<int, int>> newvector;
		for (int i = 0; i < icebergpos.size(); i++)
		{
			Map[icebergpos[i].first][icebergpos[i].second] -= watercnt[i];
			if (Map[icebergpos[i].first][icebergpos[i].second] <= 0)
			{
				Map[icebergpos[i].first][icebergpos[i].second] = 0;
			}
			else
			{
				visited[icebergpos[i].first][icebergpos[i].second] = false;
				newvector.push_back(icebergpos[i]);
			}
		}
		icebergpos = move(newvector);
		++turn;
	}

	if (divided)
		cout << turn;
	else
		cout << '0';
}

void BaekJoon::Quest_1697()
{
	const int min_pos = 0, max_pos = 100000; // 이동가능한 최소, 최대 위치 [0,100000]
	auto isPosInArea = [&](int pos)->bool {return(min_pos <= pos && pos <= max_pos); };
	vector<int> visited(max_pos + 1, 0);
	int n_pos, k_pos; // n : 수빈 위치, k : 동생 위치
	cin >> n_pos >> k_pos;
	if (n_pos == k_pos)
	{
		cout << '0';
		return;
	}

	queue<int> q;
	q.push(n_pos);
	while (!q.empty())
	{
		// bfs
		int qsize = q.size();
		for (int i = 0; i < qsize; ++i)
		{
			int curpos = q.front();
			q.pop();
			int newpos;
			int moveways[3] = { 1, -1, curpos };
			for (int i = 0; i < 3; ++i)
			{
				newpos = curpos + moveways[i];
				if (isPosInArea(newpos) && !visited[newpos])
				{
					visited[newpos] = visited[curpos] + 1;
					if (visited[k_pos])
						break;
					q.push(newpos);
				}
			}
			if (visited[k_pos])
				break;
		}
		if (visited[k_pos])
			break;
	}
	cout << visited[k_pos];
}

void BaekJoon::Quest_12851()
{
	const int min_pos = 0, max_pos = 100000; // 이동가능한 최소, 최대 위치 [0,100000]
	auto isPosInArea = [&](int pos)->bool {return(min_pos <= pos && pos <= max_pos); };
	vector<int> visitedturn(max_pos + 1, 0);
	int n_pos, k_pos; // n : 수빈 위치, k : 동생 위치
	cin >> n_pos >> k_pos;
	if (n_pos == k_pos)
	{
		cout << '0' << endl << '1';
		return;
	}

	int wayscnt = 0;
	queue<int> q;
	q.push(n_pos);
	visitedturn[n_pos] = 0;
	while (!q.empty())
	{
		// bfs
		int qsize = q.size();
		for (int i = 0; i < qsize; ++i)
		{
			int curpos = q.front();
			q.pop();
			int newpos;
			int moveways[3] = { 1, -1, curpos };
			for (int i = 0; i < 3; ++i)
			{
				newpos = curpos + moveways[i];
				if (isPosInArea(newpos) && (visitedturn[newpos] == visitedturn[curpos] + 1 || visitedturn[newpos] == 0))
				{
					if (!visitedturn[newpos])
						visitedturn[newpos] = visitedturn[curpos] + 1;
					if (newpos == k_pos)
						++wayscnt;
					else
						q.push(newpos);
				}
			}
		}
		if (visitedturn[k_pos])
			break;
	}
	cout << visitedturn[k_pos] << endl
		<< wayscnt;
}

void BaekJoon::Quest_13549()
{
	const int min_pos = 0, max_pos = 100000; // 이동가능한 최소, 최대 위치 [0,100000]
	auto isPosInArea = [&](int pos)->bool {return(min_pos <= pos && pos <= max_pos); };
	vector<int> distance(max_pos + 1, max_pos + 1);
	int n_pos, k_pos; // n : 수빈 위치, k : 동생 위치
	cin >> n_pos >> k_pos;
	if (n_pos == k_pos)
	{
		cout << '0';
		return;
	}

	queue<int> q;
	q.push(n_pos);
	distance[n_pos] = 0;
	while (!q.empty())
	{
		// bfs
		int qsize = q.size();
		for (int i = 0; i < qsize; ++i)
		{
			int curpos = q.front();
			q.pop();
			int newpos[3] = { curpos + 1, curpos - 1, curpos * 2 };
			if (isPosInArea(newpos[2]))
			{
				if (distance[newpos[2]] > distance[curpos])
				{
					distance[newpos[2]] = distance[curpos];
					q.push(newpos[2]);
				}
			}
			for (int i = 0; i < 2; ++i)
			{
				if (isPosInArea(newpos[i]))
				{
					if (distance[newpos[i]] > distance[curpos] + 1)
					{
						distance[newpos[i]] = distance[curpos] + 1;
						q.push(newpos[i]);
					}
				}
			}
		}
	}
	cout << distance[k_pos];
}

void BaekJoon::Quest_13913()
{
	const int min_pos = 0, max_pos = 100000; // 이동가능한 최소, 최대 위치 [0,100000]
	auto isPosInArea = [&](int pos)->bool {return(min_pos <= pos && pos <= max_pos); };
	vector<int> visited(max_pos + 1, 0);
	vector<int> prevnode(max_pos + 1, 0);
	int n_pos, k_pos; // n : 수빈 위치, k : 동생 위치
	cin >> n_pos >> k_pos;
	if (n_pos == k_pos)
	{
		cout << '0' << endl
			<< n_pos;
		return;
	}

	queue<int> q;
	q.push(n_pos);
	while (!q.empty())
	{
		// bfs
		int qsize = q.size();
		for (int i = 0; i < qsize; ++i)
		{
			int curpos = q.front();
			q.pop();
			int newpos[3] = { curpos + 1, curpos - 1, curpos * 2 };
			for (int i = 0; i < 3; ++i)
			{
				if (isPosInArea(newpos[i]) && !visited[newpos[i]])
				{
					visited[newpos[i]] = visited[curpos] + 1;
					prevnode[newpos[i]] = curpos;
					if (visited[k_pos])
						break;
					q.push(newpos[i]);
				}
			}
			if (visited[k_pos])
				break;
		}
		if (visited[k_pos])
			break;
	}
	cout << visited[k_pos] << endl;

	stack<int> path;
	int pos = k_pos;
	while (pos != n_pos)
	{
		path.push(pos);
		pos = prevnode[pos];
	}
	cout << pos << ' ';
	while (!path.empty())
	{
		cout << path.top() << ' ';
		path.pop();
	}
}

void BaekJoon::Quest_3197()
{
	int r, c;
	cin >> r >> c;

	vector<vector<bool>> isIce(r, vector<bool>(c)), waterVisited(r, vector<bool>(c, false)), swanVisited(r, vector<bool>(c, false));
	queue<pair<int, int>> waterQ, swanQ;
	pair<int, int> swanPos[2]{ {-1,-1}, {-1,-1} };

	bool activeSwan = 0;
	auto isInArea = [&r, &c](const pair<int, int>& pos)-> bool {return 0 <= pos.first && pos.first < r && 0 <= pos.second && pos.second < c; };
	int ways[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
	
	for (int y = 0; y < r; ++y)
		for (int x = 0; x < c; ++x)
		{
			char tmp;
			cin >> tmp;
			switch (tmp)
			{
			case 'X':
				isIce[y][x] = true;
				break;
			case 'L':
				if (swanPos[0].first == -1)
					swanPos[0] = { y,x };
				else
				{
					swanPos[1] = { y,x };
					swanVisited[y][x] = true;
					swanQ.push({ y,x });
				}
			case '.':
				isIce[y][x] = false;
				waterVisited[y][x] = true;
				waterQ.push({ y,x });
				break;
			}
		}


	bool found = false;
	int turncnt = 0;
	while (true)
	{
		queue<pair<int, int>> tmpQ;

		// 2번 백조에서 1번백조로 가는 길을 탐색함.
		while (!swanQ.empty())
		{
			auto curpos = swanQ.front();
			swanQ.pop();
			for (int i = 0; i < 4; ++i)
			{
				pair<int, int> newpos = { curpos.first + ways[i][0], curpos.second + ways[i][1] };
				if (isInArea(newpos) && !swanVisited[newpos.first][newpos.second])
				{
					swanVisited[newpos.first][newpos.second] = true;
					if (isIce[newpos.first][newpos.second])
					{
						tmpQ.push(newpos);
					}
					else
					{
						swanQ.push(newpos);
					}


					if (swanPos[0] == newpos)
					{
						cout << turncnt;
						return;
					}
				}
			}
		}
		swap(swanQ, tmpQ);

		++turncnt;
		while (!waterQ.empty())
		{
			auto curpos = waterQ.front();
			waterQ.pop();
			for (int i = 0; i < 4; ++i)
			{
				pair<int, int> newpos = { curpos.first + ways[i][0], curpos.second + ways[i][1] };
				if (isInArea(newpos) && !waterVisited[newpos.first][newpos.second])
				{
					waterVisited[newpos.first][newpos.second] = true;
					if (isIce[newpos.first][newpos.second])
					{
						tmpQ.push(newpos);
						isIce[newpos.first][newpos.second] = false; 
					}
					else
					{
						waterQ.push(newpos);
					}
				}
			}
		}
		swap(waterQ, tmpQ);
	}
}

void BaekJoon::Quest_1485()
{
	//auto compareDouble = [](double a, double b)-> bool { return abs(a - b) < 1e-6; };
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; ++t)
	{
		int pos[4][2];
		for (int c = 0; c < 4; ++c)
			cin >> pos[c][0] >> pos[c][1];

		double dist[6];
		int count = 0;
		for (int i = 0; i < 4; ++i)
			for (int j = i + 1; j < 4; ++j)
			{
				dist[count] = pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2);
				++count;
			}
		sort(dist, dist + 6);
		cout << (dist[0] == dist[1] && dist[0] == dist[2] && dist[0] == dist[3] && dist[4] == dist[5]) << endl;
	}
}

void BaekJoon::Quest_1103()
{
	int n, m;
	cin >> n >> m;
	bool visited[50][50];
	int map_[50][50];
	auto isPosInArea = [&](pair<int, int> pos)->bool {return(0 <= pos.first && pos.first < n && 0 <= pos.second && pos.second < m); };
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < m; ++x)
			cin >> map_[y][x];
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
}

void BaekJoon::Quest_17608()
{
	int n;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		s.push(tmp);
	}
	int highest = 0, cnt = 0;
	while (!s.empty())
	{
		int tmp = s.top();

		if (tmp > highest)
		{
			++cnt;
			highest = tmp;
		}
		s.pop();
	}
	cout << cnt;
}

void BaekJoon::Quest_14491()
{
	stack<int> s;
	int n;
	cin >> n;
	while (n)
	{
		s.push(n % 9);
		n /= 9;
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

void BaekJoon::Quest_14487()
{
	int tc;
	int sum = 0, max = 0;
	cin >> tc;
	for (int t = 0; t < tc; ++t)
	{
		int n;
		cin >> n;
		if (n > max)
		{
			sum += max;
			max = n;
		}
		else
		{
			sum += n;
		}
	}
	cout << sum;
}

void BaekJoon::Quest_1051()
{
	int n, m;
	cin >> n >> m;
	int maxsize = (n > m ? m : n) - 1;
	char arr[50][50];
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < m; ++x)
			cin >> arr[y][x];

	for (int size = maxsize; 0 < size; --size)
	{
		for (int y = 0; y < n - size; ++y)
		{
			for (int x = 0; x < m - size; ++x)
			{
				int ry = y + size, dx = x + size;
				int val = arr[y][x];
				if (val == arr[ry][x] && val == arr[y][dx] && val == arr[ry][dx])
				{
					++size;
					cout << size * size;
					return;
				}
			}
		}
	}
	cout << 1;
}

void BaekJoon::Quest_1113()
{
	/*{
		int n, m, highest = 0;
		int land[50][50];
		bool visitied[50][50];
		queue<pair<int, int>> q[9];
		auto isInArea = [&](pair<int, int> pos) { 0 <= pos.first && pos.first < n && 0 <= pos.second && pos.second < m; };
		cin >> n >> m;
		for (int y = 0; y < n; ++y)
			for (int x = 0; x < m; ++x)
			{
				cin >> land[y][x];
				if (land[y][x] > highest)
					highest = land[y][x];
				q[land[y][x] - 1].push(make_pair(y, x));
			}

	}*/
}

void BaekJoon::Quest_17294()
{
	//char s[18];
	string s;
	cin >> s;
	int size = s.size();
	int gap = s[0] - s[1];
	for (int i = 1; i < size; ++i)
	{
		if (s[i - 1] != s[i] + gap)
		{
			cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
			return;
		}
	}
	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	return;
}

void BaekJoon::Quest_17296()
{
	int n;
	cin >> n;
	bool ispressed = false;
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		double d;
		cin >> d;
		//count += (int)(d / 0.5) / 2;
		count += (int)d;
		if (count)
			ispressed = true;
		if (!ispressed && (int)(d / 0.5) % 2)
		{
			ispressed = true;
			++count;
		}
	}
	cout << count;
}

void BaekJoon::Quest_15922()
{

	int n;
	cin >> n;
	vector<pair<int, int>> line;
	int len = 0;
	pair<int, int> s(0, 1), e(0, -1);
	for (int i = 0; i < n; ++i)
	{
		cin >> s.first >> e.first;
		line.emplace_back(s);
		line.emplace_back(e);
	}
	sort(line.begin(), line.end());
	int linecnt = 0;
	for (auto& elem : line)
	{
		if (elem.second == 1)
		{
			++linecnt;
			if (linecnt == 1)
				s.first = elem.first;
		}
		else
		{
			--linecnt;
			if (linecnt == 0)
				len += elem.first - s.first;
		}

	}

	/*for (auto& elem : line)
		cout << elem.first << elem.second << endl;*/
	cout << len;
}

void BaekJoon::Quest_5212()
{
	int r, c;
	cin >> r >> c;
	bool isLand[12][12] = { false, };
	vector<pair<int, int>> landpos;
	int up = 12, left = 12, down = 0, right = 0;
	for (int y = 1; y <= r; ++y)
		for (int x = 1; x <= c; ++x)
		{
			char c;
			cin >> c;
			if (c == 'X')
			{
				landpos.emplace_back(pair<int, int>(y, x));
				isLand[y][x] = true;
				if (up > y)
					up = y;
				else if (down < y)
					down = y;
				if (left > x)
					left = x;
				else if (right < x)
					right = x;
			}
		}

	int landcnt = landpos.size();
	int ways[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
	vector<pair<int, int>> erasedLands;
	for (int i = 0; i < landcnt; ++i)
	{
		int cury = landpos[i].first, curx = landpos[i].second;
		int watercnt = 0;
		for (int j = 0; j < 4; ++j)
		{
			int newy = cury + ways[j][0], newx = curx + ways[j][1];
			if (!isLand[newy][newx])
			{
				if (++watercnt == 3)
				{
					erasedLands.emplace_back(pair<int, int>(cury, curx));
					break;
				}
			}
		}
	}

	int erasecnt = erasedLands.size();
	for (int i = 0; i < erasecnt; ++i)
		isLand[erasedLands[i].first][erasedLands[i].second] = false;

	swap(up, down);
	swap(left, right);
	for (int i = 0; i < landcnt; ++i)
	{
		int y = landpos[i].first, x = landpos[i].second;
		if (isLand[y][x])
		{
			if (up > y)
			{
				up = y;
				if (up > down)
					down = up;
			}
			else if (down < y)
			{
				down = y;
				if (up > down)
					up = down;
			}
			if (left > x)
			{
				left = x;
				if (left > right)
					right = left;
			}
			else if (right < x)
			{
				right = x;
				if (left > right)
					left = right;
			}
		}
	}
	
	for (int y = up; y <= down; ++y)
	{
		for (int x = left; x <= right; ++x)
		{
			cout << (isLand[y][x] ? 'X' : '.');
		}
		cout << endl;
	}
}

void BaekJoon::Quest_6581()
{
	string s;
	
	while (!cin.eof())
	{
		cin >> s;
		/*istringstream iss(s);

		vector<string> words(
			istream_iterator<string>(istringstream(iss)),
			istream_iterator<string>()
		);*/
		
	}
}

void BaekJoon::Quest_16946()
{
	/*
	방문여부, 제로큐, 큐, 각 칸 그룹번호, 그룹요소갯수
	1. 모든 0칸을 제로큐에 넣는다.
	2. 제로큐에서 원소를 꺼내어 해당 칸을 방문하지 않았다면 큐에 넣고 그룹번호를 증가시키고 그룹을 지정한다.
	3. 해당 그룹의 원소의 갯수를 증가시키고, 큐에서 원소를 꺼내어 그 칸에 그룹번호를 지정한 후 그 칸에 상/하/좌/우로 인접한 4개의 칸에 대해 4번행동을 한다.
	4. 해당 칸을 이전에 방문했다면 아무것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고, 해당 칸을 큐에 넣는다.
	5. 큐의 모든 원소가 빌 때까지 3을 반복한다.
	6. 제로큐의 모든 원소가 빌 때까지 2를 반복한다.
	7. 원래 지도에서 모든칸에 대해 순회를 하며 8번 행동을 한다.
	8. 해당 칸이 0일경우 0을 출력한다. 1일경우 인접한 상/하/좌/우 네칸에 대해 9번 행동을 한다.
	9. 해당 칸의 그룹이 0이 아니고, 그룹의 값을 합치지 않았다면 해당칸의 그룹번호에 대응하는 요소의 갯수를 합치고 +1을 한다.
	*/
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	//ifstream in("tc10001000.txt");
	
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> visited(n, vector<bool>(m));
	vector<vector<int>> group(n, vector<int>(m, 0));
	vector<vector<bool>> map_(n, vector<bool>(m));
	vector<int> groupElemCnt(1, 0);
	queue<pair<int, int>> zeroq, oneq;
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			char t;
			cin >> t;
			bool element = (t == '1');
			map_[y][x] = visited[y][x] = element;
			if (element)
				oneq.push({ y,x });
			else
				zeroq.push({ y,x });
		}
	}
	/*MyTimer timerBOJ;
	timerBOJ.enable();
	timerBOJ.start();*/
	queue<pair<int, int>> q;
	int ways[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
	int groupcnt = 0;
	while (!zeroq.empty())
	{
		pair<int, int> firstpos = zeroq.front();
		int elemcnt = 0;
		if(!visited[firstpos.first][firstpos.second])
		{
			visited[firstpos.first][firstpos.second] = true;
			q.push(firstpos);
			++groupcnt;
		}
		zeroq.pop();
		while (!q.empty())
		{
			pair<int, int> curpos = q.front();
			group[curpos.first][curpos.second] = groupcnt;
			++elemcnt;
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				pair<int, int> newpos(curpos.first + ways[i][0], curpos.second + ways[i][1]);
				if ( 0 <= newpos.first && newpos.first < n && 0 <= newpos.second && newpos.second < m && !visited[newpos.first][newpos.second])
				{
					visited[newpos.first][newpos.second] = true;
					q.push(newpos);
				}
			}
		}
		if (elemcnt)
			groupElemCnt.push_back(elemcnt);
	}
	/*for(auto l : group)
	{
		for (auto e : l)
			cout << e;
		cout << endl;
	}
	for (auto e : groupElemCnt)
		cout << e << ' ';
	cout << endl;*/
	//ofstream cout("result.txt");
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			if (map_[y][x])
			{
				vector<bool> isGroupAdded(groupElemCnt.size(), false);
				int sum = 1;
				for (int i = 0; i < 4; ++i)
				{
					pair<int, int> newpos(y + ways[i][0], x + ways[i][1]);
					if (0 <= newpos.first && newpos.first < n && 0 <= newpos.second && newpos.second < m && !isGroupAdded[group[newpos.first][newpos.second]] && group[newpos.first][newpos.second])
					{
						sum += groupElemCnt[group[newpos.first][newpos.second]];
						isGroupAdded[group[newpos.first][newpos.second]] = true;
					}
				}
				cout << sum % 10;
			}
			else
				cout << 0;
		}
		cout << '\n';
	}
	/*timerBOJ.stop();
	timerBOJ.printTime();*/
}

void BaekJoon::Quest_16933()
{
}

void BaekJoon::Quest_2493()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;
	stack<pair<int, int>> s;
	for (int i = 0; i < tc; ++i)
	{
		int newN;
		cin >> newN;
		bool found = false;
		while (!s.empty())
		{
			auto curN = s.top();
			if (curN.first > newN)
			{
				cout << curN.second << ' ';
				found = true;
				break;
			}
			else
				s.pop();
		}
		if (!found)
			cout << 0 << ' ';
		s.push({ newN, i + 1 });
	}
}

void BaekJoon::Quest_9012()
{
	/*cin.tie(NULL);
	ios::sync_with_stdio(false);*/
	int tc;
	//cin >> tc;
	scanf_s("%d", &tc);
	getchar();
	stack<bool> s;
	for (int i = 0; i < tc; ++i)
	{
		char c;
		bool isRegular = true;
		while ((c = getchar()) != '\n')
		{
			if (c == '(')
			{
				s.push(true);
			}
			else
			{
				if (!s.empty() && s.top())
					s.pop();
				else
				{
					while (getchar() != '\n');
					isRegular = false;
					break;
				}
			}
		}
		if (isRegular && s.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
		s = {};
	}
}

void BaekJoon::Quest_1629()
{
	int num, cnt, div;
	cin >> num >> cnt >> div;
	function<long long(long long, long long)> func = [&func, &div](long long n, long long c) -> long long {
		if (c == 1)
			return n % div;
		long long result = func(n, c / 2);
		result = (result * result) % div;
		if (c % 2)
			result = result * n % div;
		return result;
	};
	cout << func(num, cnt);
}

void BaekJoon::Quest_15649()
{
	int n, m;
	list<int> l;
	cin >> n >> m;
	vector<int> isUsed(n);

	function<void()> NnM1 = [&]()
	{
		if (l.size() == m)
		{
			for (const auto& elem : l)
				cout << elem << ' ';
			cout << '\n';
			return;
		}
		for (int i = 0; i < n; ++i)
		{
			if (!isUsed[i])
			{
				isUsed[i] = true;
				l.push_back(i + 1);
				NnM1();
				l.pop_back();
				isUsed[i] = false;
			}
		}
	};
	NnM1();
}

void BaekJoon::Quest_15652()
{
	int n, m;
	list<int> l;
	cin >> n >> m;
	function<void()> NnM4 = [&]()
	{
		if (l.size() == m)
		{
			for (const auto& elem : l)
				cout << elem << ' ';
			cout << '\n';
			return;
		}
		for (int i = (l.size() ? *(l.rbegin()) : 1); i <= n; ++i)
		{
			l.push_back(i);
			NnM4();
			l.pop_back();
		}
	};
	NnM4();
}

void BaekJoon::Quest_9663()
{
	int n;
	cin >> n;
	vector<bool> isXUsed(n, false), isUUsed(2 * n, false), isDUsed(2 * n, false);
	int count = 0;
	function<void(int)> f = [&](int y)
	{
		if (y == n)
		{
			++count;
			return;
		}

		for (int x = 0; x < n; ++x)
		{
			if (isXUsed[x] || isUUsed[x + y] || isDUsed[x - y + n - 1])	continue;	// 현재 열or우상향대각선or 우하향대각선 중 하나라도 존재, x-y의 최소값이 -n+1이라 n-1을 더해 최소값을 0으로 만듬

			// 퀸 배치 처리
			isXUsed[x] = true;
			isUUsed[x + y] = true;
			isDUsed[x - y + n - 1] = true;
			f(y + 1);
			// 퀸 배치 취소
			isXUsed[x] = false;
			isUUsed[x + y] = false;
			isDUsed[x - y + n - 1] = false;
		}
	};

	f(0);
	cout << count;
}

void BaekJoon::Quest_9663_cheat()
{
	int arr[] = { 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596 };
	int n;
	cin >> n;
	cout << arr[n - 1];
}

void BaekJoon::Quest_1182_1()
{
	/*
	1의 갯수를 변경시켜 next_permutation으로 해당 1의 갯수에 대한 모든 순열을 만들어 해결하는 방식
	0001(1이 1개)
	0010
	0100
	1000
	0011(1이 2개)
	0101
	0110
	...
	*/
	int n, s;
	int count = 0;
	cin >> n >> s;
	vector<int> val(n);
	vector<bool> sel(n);
	for (int i = 0; i < n; ++i)
		cin >> val[i];
	sort(val.begin(), val.end());
	for (int i = 0; i < n; ++i)
	{
		sel[n - (i + 1)] = true;
		do
		{
			int sum = 0;
			for (int k = 0; k < n; ++k)
				if (sel[k]) sum += val[k];
			if (sum == s)
				++count;
		} while (next_permutation(sel.begin(), sel.end()));
	}
	cout << count;
}

void BaekJoon::Quest_1182_2()
{
	/*
	0001
	0010
	0011
	0101
	...
	이러한 형식으로 증가하는 이진수의 형태를 이용해 모든 순열을 만들어 푸는 방식
	*/
	int n, s;
	int count = 0;
	cin >> n >> s;
	vector<int> val(n);
	for (int i = 0; i < n; ++i)
		cin >> val[i];
	const int end = 1 << n;
	for (int i = 1; i < end; ++i)
	{
		int tmp = i;
		int sum = 0;
		for (int k = 0; k < n; ++k)
		{
			if (tmp % 2) sum += val[k];
			tmp /= 2;
		}
		if (sum == s)
			++count;
	}
	cout << count;
}

void BaekJoon::Quest_1463_1()
{
	int x;
	cin >> x;
	if (x == 1)
	{
		cout << 0;
		return;
	}
	vector<int> mem(x + 1, 0);
	queue<int> p;
	p.push(x);
	while (!mem[1]) {
		int pos = p.front();
		p.pop();
		if (!(pos % 3))
		{
			if (!mem[pos / 3])
			{
				p.push(pos / 3);
				mem[pos / 3] = mem[pos] + 1;
			}
		}
		if (!(pos & 1))
		{
			if (!mem[pos / 2])
			{
				p.push(pos / 2);
				mem[pos / 2] = mem[pos] + 1;
			}
		}
		if (!mem[pos - 1])
		{
			p.push(pos - 1);
			mem[pos - 1] = mem[pos] + 1;
		}
	}
	cout << mem[1];
}

void BaekJoon::Quest_1463_2()
{
}

void BaekJoon::Quest_2579()
{
	int n;
	cin >> n;
	int maxval[300][2];
	int tmp;
	cin >> tmp;
	if (n == 1)
	{
		cout << tmp;
		return;
	}
	maxval[0][0] = tmp;
	maxval[0][1] = 0;
	cin >> tmp;
	maxval[1][0] = tmp;
	maxval[1][1] = maxval[0][0] + tmp;
	for (int i = 2; i < n; ++i)
	{
		cin >> tmp;
		maxval[i][0] = max(maxval[i - 2][0], maxval[i - 2][1]) + tmp;
		maxval[i][1] = maxval[i - 1][0] + tmp;
	}
	cout << max(maxval[n - 1][0], maxval[n - 1][1]);
}

void BaekJoon::Quest_1149()
{
	int n;
	cin >> n;
	int rgbval[1000][3];
	int rgbcase[3][3] = { {0, 1, 2}, {1, 2, 0}, {2, 0, 1} };
	for (int j = 0; j < 3; ++j)
		cin >> rgbval[0][j];
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < 3; ++j)
		{
			int tmp;
			cin >> tmp;
			rgbval[i][rgbcase[j][0]] = min(rgbval[i - 1][rgbcase[j][1]], rgbval[i - 1][rgbcase[j][2]]) + tmp;
		}
	cout << min({ rgbval[n - 1][0], rgbval[n - 1][1], rgbval[n - 1][2] });
}

void BaekJoon::Quest_11726()
{
	int n;
	cin >> n;
	int arr[1000]; // arr[i] = 2 * (i+1) 만큼의 타일을 채우는 경우의 수
	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i < n; ++i)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	cout << arr[n - 1];
}

void BaekJoon::Quest_1912()
{
	int n;
	cin >> n;
	int mem[100000];
	cin >> mem[0];
	int max = mem[0];
	for (int i = 1; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		if (mem[i - 1] > 0)
			mem[i] = mem[i - 1] + tmp;
		else
			mem[i] = tmp;
		if (mem[i] > max)
			max = mem[i];
	}
	cout << max;
}

