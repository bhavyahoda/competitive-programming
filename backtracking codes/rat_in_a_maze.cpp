#include<iostream>
#include<cstring>
using namespace std;
bool ratInMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n)
{
	//base case
	if (i == m && j == n)
	{
		soln[m][n] = 1;
		for (int i = 0; i <= m; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				cout << soln[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		return true;
	}
	//first of all we ensure rat should be inside the grid
	if (i > m || j > n || maze[i][j] == 'X')
	{
		return false;
	}
	soln[i][j] = 1; //assuming solution exists
	bool rightsucess = ratInMaze(maze, soln, i, j + 1, m, n);
	bool downsucess = ratInMaze(maze, soln, i + 1, j, m, n);
	//now here we have to do backtracking
	soln[i][j] = 0;//from this we are backtracking
	if (rightsucess || downsucess)
	{
		return true;
	}
	return false;
}
int main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00",
	};
	int soln[10][10];
	memset(soln, 0, sizeof(soln));
	int m = 4, n = 4;
	bool ans = ratInMaze(maze, soln, 0, 0, m - 1, n - 1);
}