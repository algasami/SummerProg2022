#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;
typedef pair<int, int> patient;
typedef pair<int, int> cost;

int pcount;
vector<patient> patientData;

int getCost(string& str)
{
	if (str.size() <= 1) return 0;
	int sum = 0;
	for (int i = 1; i < str.size(); i++)
	{
		sum += patientData[str[i - 1] - '0'].first * patientData[str[i - 1] - '0'].second;
	}
	return sum;
}
queue<pair<string,cost>> solves;
int leastCost = -1;
vector<pair<string,int>> answers;
void solve(string current, cost cur)
{
	if (current.size() == pcount)
	{
		if (leastCost == -1 || leastCost >= cur.first)
		{
			if (leastCost > cur.first) answers.clear();
			answers.push_back(pair<string, int>(current, cur.first));
			leastCost = cur.first;
		}
		return;
	}
	while (solves.empty() == false && solves.front().second.first > cur.first) solves.pop();
	for (int i = 0; i < pcount; i++)
	{
		if (find(current.begin(), current.end(), i + '0') == current.end())
		{
			solves.push(pair<string, cost>(current + string(1, i + '0'), cost(cur.first + cur.second * patientData[i].second, patientData[i].first + cur.second)));
		}
	}
}

int main()
{
	cin >> pcount;
	for (int i = 0; i < pcount; i++)
	{
		int therapyTime, anxietyWeight;
		cin >> therapyTime >> anxietyWeight;
		patientData.push_back(patient(therapyTime, anxietyWeight));
		solves.push(pair<string, cost>(string(1, i + '0'), cost(0, therapyTime)));
	}
	while (solves.empty() == false)
	{
		pair<string, cost> sol = solves.front();
		solve(sol.first, sol.second);
		if (solves.empty() == true) break;
		solves.pop();
	}
	for (int i = 0; i < pcount; i++)
	{
		// lexicographical sort
		int smallIndex = -1;
		for (int n = 0; n < answers.size(); n++)
		{
			if (smallIndex == -1 && answers[n].first.empty() == false) smallIndex = n;
			if (answers[n].first[i] < answers[smallIndex].first[i])
			{
				answers[smallIndex].first = "";
				smallIndex = n;
			}
		}
	}
	for (auto& ans : answers)
	{
		if (ans.first.empty() == false)
		{
			for (int i = 0; i < ans.first.size(); i++)
			{
				cout << (char)(ans.first[i] + 1) << (i != ans.first.size() - 1 ? " " : "");
			}
			cout << endl << ans.second;
		}
	}
}
