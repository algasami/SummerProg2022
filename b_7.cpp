#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int station_count, line_count;

struct lan {
	char last, next;
	lan(char l, char n) :last(l), next(n) {}
};



struct station {
	vector<lan> lines;
	char name;
	station(char n, vector<lan> j) : name(n), lines(j) {}
};

ostream& operator<<(ostream& os, station& sta)
{
	os << "Station " << sta.name << endl;
	for (auto& l : sta.lines)
	{
		cout << "Last: " << l.last << "| Next: " << l.next << endl;
	}
	return os;
}
vector<station> stations;

vector<string> results;

int inoutGet(string& ans)
{
	int sum = 0;
	for (char c : ans)
	{
		if (c >= 'A' && c <= 'Z')
			sum++;
	}
	return sum;
}
void solve(char current, int line, char end, string answer) // copy string
{
	if (current == end)
	{
		answer += end;
		results.push_back(answer);
		return;
	}
	if (find(answer.begin(), answer.end(), current) != answer.end()) return;
	for (int ln = 0; ln < line_count; ln++)
	{
		station* const st = &stations.at(current - 'A');
		char last = st->lines[ln].last;
		char next = st->lines[ln].next;
		if (last != 'x') solve(last,
			ln, end,
			answer + current + (ln == line ? "" : to_string(ln + 1)));
		if (next != 'x') solve(next,
			ln, end,
			answer + current + (ln == line ? "" : to_string(ln + 1)));
	}
}

int main()
{
	cin >> station_count >> line_count;
	for (int i = 0; i < station_count; i++)
		stations.push_back(station(i + 'A', vector<lan>(line_count,lan('x','x'))));
	for (int ln = 0; ln < line_count; ln++)
	{
		string l_data;
		cin >> l_data;
		// first line
		stations[l_data[0] - 'A'].lines[ln].next = l_data[1];
		for (int i = 1; i < l_data.size() - 1; i++)
		{
			int stationIndex = l_data[i] - 'A';
			stations[stationIndex].lines[ln].last = l_data[i - 1];
			stations[stationIndex].lines[ln].next = l_data[i + 1];
		}
		stations[l_data[l_data.size()-1] - 'A'].lines[ln].last = l_data[l_data.size() - 2];
	}

	char depart, destination;
	cin >> depart >> destination;
	for (int ln = 0; ln < line_count; ln++)
		solve(depart, ln, destination, to_string(ln + 1));
	vector<string> elites;
	for (string& str : results)
	{
		if (str != "x")
			elites.push_back(str);
	}
	string last = elites[0];
	for (int i = 1; i < elites.size(); i++)
	{
		if (last.size() < elites[i].size())
		{
			continue;
		}
		if (elites[i].size() < last.size())
		{
			last = elites[i];
			continue;
		}
		bool bye = false;
		for(int s = 0;s<min({last.size(),elites[i].size()});s++)
			if (last[s] < elites[i][s])
			{
				bye = true;
				break;
			}
		if (bye) continue;
		last = elites[i];
	}
	cout << inoutGet(last) << endl << last;
	return 0;
}
