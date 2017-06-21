// AOJ Volume 2 Problem 0210 : The Squares
// Source: PC Koshien 2009, 2009-11-14
// Judge: AOJ

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_H = 30, MAX_W = 30;

// input
int H, W;
char maze[MAX_H + 1][MAX_W + 1];

// maze[i][j]に人がいるかどうか
bool person(int i, int j)
{
	return (maze[i][j] == 'E' || maze[i][j] == 'N' || maze[i][j] == 'W'
|| maze[i][j] == 'S');
}

// maze[i][j]が空白かどうか
bool space(int i, int j)
{
	return (i >= 0 && i < H && j >= 0 && j < W && maze[i][j] == '.');
}

// maze[i][j]が非常口かどうか
bool exit_maze(int i, int j)
{
	return (i >= 0 && i < H && j >= 0 && j < W && maze[i][j] == 'X');
}

// 迷路内に一人も人がいないかどうか
bool check()
{
	bool end = true;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			if (person(i, j))
				end = false;
	return end;
}

// maze[x][y]にいる人の向きを変える
void change(int x, int y)
{
	const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
	int t = 0;

	if (maze[x][y] == 'E') t = 0;
	else if (maze[x][y] == 'N') t = 1;
	else if (maze[x][y] == 'W') t = 2;
	else t = 3;

	for (int i = t; i < t + 4; i++)
	{
		int nx = x + dx[i % 4], ny = y + dy[i % 4];
		if (space(nx, ny) || exit_maze(nx, ny))
		{
			switch (i % 4)
			{
				case 0: maze[x][y] = 'S'; break;
				case 1: maze[x][y] = 'E'; break;
				case 2: maze[x][y] = 'N'; break;
				case 3: maze[x][y] = 'W'; break;
			}
			break;
		}
	}
}

void change_all()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (person(i, j))
			{
				change(i, j);
			}
		}
	}
}

void move()
{
	bool used[MAX_H][MAX_W];
	memset(used, 0, sizeof(used));

	// 西
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (maze[i][j] == 'W' && !used[i][j] && space(i, j - 1))
			{
				swap(maze[i][j], maze[i][j - 1]);
				used[i][j - 1] = true;
			}
			else if (maze[i][j] == 'W' && !used[i][j] && !used[i][j - 1] &&
exit_maze(i, j - 1))
			{
				maze[i][j] = '.';
				used[i][j - 1] = true;
			}
		}
	}
	// 南
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (maze[i][j] == 'S' && !used[i][j] && space(i + 1, j))
			{
				swap(maze[i][j], maze[i + 1][j]);
				used[i + 1][j] = true;
			}
			else if (maze[i][j] == 'S' && !used[i][j] && !used[i + 1][j] &&
exit_maze(i + 1, j))
			{
				maze[i][j] = '.';
				used[i + 1][j] = true;
			}
		}
	}
	// 東
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (maze[i][j] == 'E' && !used[i][j] && space(i, j + 1))
			{
				swap(maze[i][j], maze[i][j + 1]);
				used[i][j + 1] = true;
			}
			else if (maze[i][j] == 'E' && !used[i][j] && !used[i][j + 1] &&
exit_maze(i, j + 1))
			{
				maze[i][j] = '.';
				used[i][j + 1] = true;
			}
		}
	}
	// 北
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (maze[i][j] == 'N' && !used[i][j] && space(i - 1, j))
			{
				swap(maze[i][j], maze[i - 1][j]);
				used[i - 1][j] = true;
			}
			else if (maze[i][j] == 'N' && !used[i][j] && !used[i - 1][j] &&
exit_maze(i - 1, j))
			{
				maze[i][j] = '.';
				used[i - 1][j] = true;
			}
		}
	}
}

void solve()
{
	int res = 0;
	for (; res <= 180; res++)
	{
		if (check()) break;

		change_all();
		move();
	}

	if (res > 180) printf("NA\n");
	else printf("%d\n", res);
}

int main()
{
	while (scanf("%d %d", &W, &H) && W)
	{
		for (int i = 0; i < H; i++)
			scanf("%s", maze[i]);
		solve();
	}

	return 0;
}

