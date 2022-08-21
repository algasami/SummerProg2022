#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int lineCount;

vector<string> original;

void lower(string& str)
{
	for (char& ch : str)
	{
		if (ch >= 'A' && ch <= 'Z')
			ch = ch - 'A' + 'a';
	}
}

vector<string> getToken(string& str)
{
	vector<string> toks;
	stringstream ss;
	ss << str;
	string tok;
	while (ss >> tok)
	{
		lower(tok);
		toks.push_back(tok);
	}
	return toks;
}

int getOverlap(vector<string>& token, vector<string>& token2)
{
	int big = 0;
	for (auto& mytk : token)
	{
		for (auto& thtk : token2)
		{
			if (mytk == thtk) big++;
		}
	}
	return big;
}
int main()
{
	cin >> lineCount;
	getchar();
	for (int i = 0; i < lineCount; i++)
	{
		string line;
		stringstream ss;
		getline(cin, line);
		original.push_back(line);
	}
	string ans_line, ans_token;
	getline(cin, ans_line);
	vector<string> answerTokens = getToken(ans_line);
	int big = 0;
	
	sort(original.begin(), original.end(), [](string& a, string& b)
		{
			return a.size() > b.size();
		});
	for (int i = 0; i < lineCount; i++)
	{
		vector<string> t = getToken(original[i]);
		if (getOverlap(t, answerTokens) >= big)
		{
			cout << original[i];
			return 0;
		}
	}

	return 0;
}
