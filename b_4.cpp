#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> moneyWeight;

int result = -1;
int c, n;

int coinCount(vector<int>& count)
{
	int s = 0;
	for (auto v : count)
		s += v;
	return s;
}
int sum(vector<int>& count)
{
	int s = 0;
	for (int i = 0; i < count.size(); i++)
	{
		s += count[i] * moneyWeight[i];
	}
	return s;
}
void dig(vector<int>& count)
{
	if (sum(count) == c)
	{
		if (coinCount(count) < result || result == -1)
			result = coinCount(count);
		return;
	}
	else if (sum(count) > c) return;
	int delta = c - sum(count);
	for (int i = 0; i < moneyWeight.size(); i++)
	{
		int weight = moneyWeight[i];
		vector<int> cp,cp2;
		for (int v : count)
		{
			cp.push_back(v);
			cp2.push_back(v);
		}
		if (weight > delta) continue;
		int val = floor(delta / weight);
		cp[i] += val;
		if (val == 0)
			continue;
		dig(cp);
		if (val - 2 > 0)
		{
			cp2[i] += val - 2;
			dig(cp2);
		}
	}
}

int main()
{
	cin >> c >> n;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		moneyWeight.push_back(x);
	}
	sort(moneyWeight.begin(), moneyWeight.end(), [](int a, int b) {return a < b; });
	vector<int> x = vector<int>(n, 0);
	dig(x);
	cout << result;
	return 0;
}
