#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int h1, m1, s1,
		h2, m2, s2,
		h = 0, m = 0, s = 0;
	char buf;
	cin >> h1 >> buf >> m1 >> buf >> s1
		>> h2 >> buf >> m2 >> buf >> s2;
	s = s2 - s1;
	if (s < 0)
	{
		s += 60;
		m--;
	}
	m += m2 - m1;
	if (m < 0)
	{
		m += 60;
		h--;
	}
	h += h2 - h1;
	if (h < 0) h += 24;
	string hstr = to_string(h), mstr = to_string(m), sstr = to_string(s);
	if (hstr.size() < 2) hstr = string(2 - hstr.size(), '0') + hstr;
	if (mstr.size() < 2) mstr = string(2 - mstr.size(), '0') + mstr;
	if (sstr.size() < 2) sstr = string(2 - sstr.size(), '0') + sstr;
	cout << hstr << ':' << mstr << ':' << sstr;
	return 0;
}
