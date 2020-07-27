//this program will generate all possible configurations of a string
#include<iostream>
using namespace std;
void permute(char *in, int i)
{
	if (in[i] == '\0')
	{
		cout << in << ',';//base case
		return;
	}
	for (int j = i; in[j] != '\0'; ++j)
	{
		swap(in[i], in[j]);
		permute(in, i + 1);//recursive call
		swap(in[i], in[j]);
		//this step is backtracking
		//that means while making recursion tree the things that we did need to be undone
	}
}
int main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char a[100];
	cin >> a;
	permute(a, 0);//calling the recursive function
}
