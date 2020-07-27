#include<iostream>
#include<cmath>
using namespace std;
bool can_place(int mat[][9], int i, int j, int n, int number)
{
	for (int x = 0; x < n; ++x)
	{
		//row and column check
		if (mat[x][j] == number || mat[i][x] == number)
		{
			return false;
		}
	}
	int rn = sqrt(n);
	int sx = i / rn;
	sx *= rn;
	int sy = j / rn;
	sy *= rn;
	//now traversing the subgrid
	for (int x = sx; x < sx + rn; ++x)
	{
		for (int y = sy; y < sy + rn; ++y)
		{
			if (mat[x][y] == number)
			{
				return false;
			}
		}
	}
	return true;
}
bool solve_sudoku(int mat[][9], int i, int j, int n)
{
	//Base case
	if (i == n)
	{
		//it means n rows have been filled completely and solution was found
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << mat[i][j] << ' ';
			}
			cout << "\n";
		}
		return true;
	}
	//case of row ending means row needs to be changed
	if (j == n)
	{
		return solve_sudoku(mat, i + 1, 0, n);
	}
	//skipping the prefilled cells
	if (mat[i][j] != 0)
	{
		return solve_sudoku(mat, i, j + 1, n);
	}
	for (int number = 1; number <= n; number++)
	{
		if (can_place(mat, i, j, n, number)) //this is the main checking function
		{
			//assuming that esse ans banega
			mat[i][j] = number;
			bool ho_paya = solve_sudoku(mat, i, j + 1, n);
			if (ho_paya)
			{
				return true;//badiya agar solution mil gaya
				//nahi mila toh backtrack karna padega
			}
		}
	}
	//here backtracking will be done
	mat[i][j] = 0;
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
	int mat[9][9] =
	{
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};
	solve_sudoku(mat, 0, 0, 9);
}