#include<iostream>
using namespace std;
bool is_safe(int board[][10], int i, int j, int n)
{
	//this is_safe function will return true only if it is facourable to place queen at that particular point
	for (int row = 0; row < i; ++row)//columns
	{
		if (board[row][j] == 1)
		{
			return false;
		}
	}
	int x = i;
	int y = j;
	while (x >= 0 && y >= 0)//left diagonal
	{
		if (board[x][y] == 1)
		{
			return false;
		}
		x--;
		y--;
	}
	x = i;
	y = j;
	while (x >= 0 && y < n) //right diagonal
	{
		if (board[x][y] == 1)
		{
			return false;
		}
		x--;
		y++;
	}
	return true;
}
bool solveNQueen(int board[][10], int i, int n)
{
	//base case
	if (i == n)
	{
		//return ;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j])
				{
					cout << "Q ";
				}
				else
				{
					cout << "_ ";
				}
			}
			cout << "\n";
		}
		cout << "\n";
		return true;//true if only 1 configuration is needed
		//here return false for all possible correct configurations
		//if i want to get all possible cases so just yahan par likh do return false
	}
	for (int j = 0; j < n; j++)
	{
		if (is_safe(board, i, j, n))
		{
			board[i][j] = 1;
			bool next_queen_rakh_paye = solveNQueen(board, i + 1, n);
			if (next_queen_rakh_paye)
			{
				return true;
			}
			//if we land up here so means i,j is not safe
			board[i][j] = 0; //this is backrtracking
		}
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
	int n;
	cin >> n;
	int board[10][10] = {0};
	solveNQueen(board, 0, n);
}