#include<iostream>
#define int long long
using namespace std;
int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int max_so_far = 0, max_ending_here = 0;
	for (int i = 0; i < n; ++i)
	{
		max_ending_here += a[i];
		if (max_ending_here < 0)
		{
			max_ending_here = 0;//becoz in worst case when everything is negative then ans is 0
		}
		if (max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;//updating
		}
	}
	cout << max_so_far << "\n";
	return 0;
}