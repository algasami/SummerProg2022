#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
int ccount;// component count
struct comp { int pre = 0, pos = 0; };
comp pool[26];

comp* const get(char ch)
{
	return pool + ch - 'A';
}

/*
* A depends on B
* 1. Change A's pos
* 2. Change A's pre's pos
*/
int depend(char a, char b)
{
	comp* const ptr = get(a);
	ptr->pos |= 1 << (b - 'A');
	for (int i = 0; i < ccount; i++)
	{
		if (ptr->pre & (1 << i))
		{
			if (i + 'A' == b)
				return -1;
			if (depend(i + 'A', b) == -1) return -1;
		}
	}
	return 0;
}

/*
* A is required by B
* 1. Change A's pre
* 2. Change A's pos's pre
*/
int req(char a, char b)
{
	comp* const ptr = get(a);
	ptr->pre |= 1 << (b - 'A');
	for (int i = 0; i < ccount; i++)
	{
		if (ptr->pos & (1 << i))
		{
			if (i + 'A' == b)
				return -1;
			if (req(i + 'A', b) == -1) return -1;
		}
	}
	return 0;
}


void TopdownDFS(string answer, vector<string>& pool)
{
	if (answer.size() == ccount)
	{
		pool.push_back(answer);
		return;
	}
	comp* const headptr = get(answer[answer.size() - 1]);
	for (int i = 0; i < ccount; i++)
	{
		if (headptr->pos & (1 << i))
			TopdownDFS(answer + static_cast<char>(i + 'A'), pool);
	}
}

void BottomupDFS(string answer, vector<string>& pool)
{
	if (answer.size() == ccount)
	{
		reverse(answer.begin(), answer.end());
		pool.push_back(answer);
		return;
	}
	comp* const headptr = get(answer[answer.size() - 1]);
	for (int i = 0; i < ccount; i++)
	{
		if (headptr->pre & (1 << i))
			BottomupDFS(answer + static_cast<char>(i + 'A'), pool);
	}
}

int bg()
{
	int rcount;// relation count
	cin >> ccount >> rcount;
	vector<char> first, second;
	string answer;
	bool many = false;
	bool ansed = false;
	int cycleIndex = -1, ansIndex = -1;
	for (int i = 0; i < rcount; i++)
	{
		char f, s;
		cin >> f >> s;
		first.push_back(f);
		second.push_back(s);
		bool cyc = true;
		if (depend(f, s) == -1 || req(s, f) == -1)
		{
			cycleIndex = i;
			break;
		}
		vector<string> td, bu;
		for (int j = 0; j < ccount; j++)
		{
			if (pool[j].pos == 0 || pool[j].pre == 0)
			{
				cyc = false;
				TopdownDFS(string(1, j + 'A'), td);
				BottomupDFS(string(1, j + 'A'), bu);
			}
		}
		if (cyc)
		{
			cycleIndex = i;
			break;
		}
		if (td.size() > 1 || bu.size() > 1) many = true;
		else if (td.size() == 1 && bu.size() == 1)
		{
			if (td.front() == bu.front())
			{
				if (ansed == false)
				{
					ansed = true;
					answer = td.front();
					ansIndex = i;
				}
				else if (answer != td.front())
					many = true;
			}
			else {
				ansed = true;
				many = true;
			}
		}
	}
	if (cycleIndex != -1)
	{
		cout << "Order conflict after getting pair " << (cycleIndex + 1);
		return 0;
	}
	if (many == true || ansed == false)
	{
		cout << "No answer";
		return 0;
	}
	cout << "Determine the testing sequence after getting pair " << (ansIndex + 1) << " : " << answer;
	return 0;
}
