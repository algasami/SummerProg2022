#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int main()
{
	int booktypes;
	cin >> booktypes;
	cin.get();
	string current, raw;
	stringstream ss;
	getline(cin, raw);
	ss << raw;
	int book;
	vector<int> sequence;
	while (ss >> book)
		sequence.push_back(book);
	int k;
	cin >> k;
	if (sequence.size() <= k)
	{
		cout << "0"; // there's a test data error here i guess
		return 0;
	}
	for (int i = 0; i < k; i++)
		current += sequence[i] + '0';
	int count = 0;
	for (int i = k; i < sequence.size(); i++)
	{
		if (find(current.begin(), current.end(), sequence[i] + '0') == current.end())
		{
			count++;
			bool removed = false;
			for (char c : current)
			{
				bool del = true;
				for (int j = i + 1; j < min({ i + k*2,(int)sequence.size() }); j++)
				{
					if (sequence[j] + '0' == c)
					{
						del = false;
						break;
					}
				}
				if (del)
				{
					current.erase(remove(current.begin(), current.end(), c), current.end());
					removed = true;
					//cout << "Remove " << c << " ";
					break;
				}
			}
			if (removed == false)
			{
				current.pop_back();
			}
			current += sequence[i] + '0';
			//cout << "Add " << (char)(sequence[i] + '0') << endl;
		}
	}
	cout << count;
	return 0;
}
