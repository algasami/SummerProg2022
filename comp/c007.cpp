#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef unsigned long int li;

int main()
{
	li a, b;
	char op;
	cin >> a >> op >> b;
	if (op == '+' || op == '-')
	{
		li res = op == '+' ? a + b : a - b;
		string a_str = to_string(a), b_str = to_string(b), res_str = to_string(res);
		int maxlen = max({ a_str.size(),b_str.size() + 1,res_str.size() });
		cout << string(maxlen - a_str.size(), '#') << a_str << endl;
		cout << string(maxlen - b_str.size() - 1, '#') << op << b_str << endl;
		int hypenCount = max({ a_str.size(),b_str.size() + 1 });
		cout << string(maxlen - hypenCount, '#') << string(maxlen, '-') << endl;
		cout << string(maxlen - res_str.size(), '#') << res;
		return 0;
	}
	li res = a * b;
	string astr = to_string(a), bstr = to_string(b), rstr = to_string(res);
	vector<string> middles;
	int maxlen = max({ astr.size(),bstr.size() + 1,rstr.size() });
	for (int i = 0; i < bstr.size(); i++)
	{
		middles.push_back(to_string(a * (li)(bstr[bstr.size() - i - 1] - '0')));
		maxlen = max({ maxlen, (int)middles.front().size() });
	}
	cout << string(maxlen - astr.size(), '#') << astr << endl;
	cout << string(maxlen - bstr.size() - 1, '#') << op << bstr << endl;
	int hypenCount = max({ astr.size(),bstr.size() + 1 });
	cout << string(maxlen - hypenCount, '#') << string(hypenCount, '-') << endl;
	for (int i = 0; i < middles.size(); i++)
	{
		int len = middles.at(i).size() + i;
		cout << string(maxlen - len, '#') << middles.at(i) << string(i, '#') << endl;
	}
	cout << string(maxlen, '-') << endl;
	cout << rstr;
	return 0;
}
