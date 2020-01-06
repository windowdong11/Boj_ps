#include "BaekJoonQuest.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>
#include <list>
#include <stack>
#include "MyTimer.h"
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
					if(!visitedturn[newpos])
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
			int newpos[3] = { curpos + 1, curpos - 1, curpos * 2};
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

