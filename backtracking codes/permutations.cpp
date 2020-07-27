#include<iostream>
using namespace std;
void permute_karo_bc(char *in, int i)
{
	if (in[i] == '\0')
	{
		cout << in << ',';
		return;
	}
	for (int j = i; in[j] != '\0'; ++j)
	{
		swap(in[i], in[j]);
		permute_karo_bc(in, i + 1);
		swap(in[i], in[j]);//yeh step is backtracking
		//means neeche jaate hue recursion tree bante vakat
		//jo kaam kiya tha usko undo karte jao
		//yeh hota hai backtracking
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
	permute_karo_bc(a, 0);
}