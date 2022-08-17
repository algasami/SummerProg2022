#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int n;
	string scramble;
	cin >> n >> scramble;
	vector<vector<char>> map = vector<vector<char>>(n, vector<char>(n, '*'));
	int offset = 0;
	// function(x) = x
	int lines = 2 * n - 1;
	int count = 0;
	for (int i = 0; i < lines; i++)
	{
		for (int x = 0; x < n; x++)
		{
			int y = -x + i;
			if (y >= n || y < 0) continue;
			map[y][x] = scramble[count++];
		}
		cout << endl;
	}
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			if(map[y][x] != '*')
				cout << map[y][x];

	return 0;
}
