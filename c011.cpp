#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


inline void rev(string& str)
{
	reverse(str.begin(), str.end());
}

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		string x; cin >> x;
		rev(x);
		sum += stoi(x);
	}
	cout << sum;
	return 0;
}
