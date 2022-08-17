#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct line {
	char a,b;
	int weight;
	line(char a, char b, int w) :a(a), b(b), weight(w) {}
};
typedef line* line_ptr;

vector<line> graph = {
	line('A','B',12), line('A','C',40), line('A','D',15),
	line('B','C',3), line('B','D',1),
	line('C','D',25), line('C','G',2),
	line('D','E',2), line('D','G',15), line('D','H',3), line('D','J',3),
	line('E','F',2), line('E','G',1),
	line('G','I',3), line('G','J',20),
	line('I','J',16)
};

line_ptr getline(char a, char b)
{
	for (line& ln : graph)
	{
		if (ln.a == a && ln.b == b)
		{
			return line_ptr(&ln);
		}
	}
	return line_ptr(nullptr);
}

vector<line_ptr> getlines(char a)
{
	vector<line_ptr> lns;
	for (line& ln : graph)
	{
		if (ln.a == a || ln.b == a)
			lns.push_back(line_ptr(&ln));
	}
	return lns;
}
struct mut {
	string val;
	int weight = 0;
	mut(string v, int weight) : val(v), weight(weight) {}
};
mut findMutual(char a, char b, string concat = "")
{
	mut mutual("", 0);
	vector<line_ptr> a_lines = getlines(a), b_lines = getlines(b);
	for (auto& aPtr : a_lines)
	{
		char rel_a = aPtr->a, rel_b = aPtr->b;
		for (auto& bPtr : b_lines)
		{
			char cmp_a = bPtr->a, cmp_b = bPtr->b;
			char sel_a = rel_a != a ? rel_a : rel_b;
			char sel_b = cmp_a != b ? cmp_a : cmp_b;
			if (sel_a == sel_b && find(mutual.val.begin(), mutual.val.end(), sel_a) == mutual.val.end())
			{
				mutual.val += sel_a;
			}
		}
	}
	mutual.val += concat;
	sort(mutual.val.begin(), mutual.val.end(), [](char a, char b) {
		return a < b; });
	for (char c : mutual.val)
	{
		for (char c_1 : mutual.val)
		{
			if (c_1 <= c) continue;
			line_ptr lnptr = getline(c, c_1);
			if (lnptr != nullptr) mutual.weight += lnptr->weight;
			else return mut("", 0);
		}
	}
	return mutual;
}

void push(vector<mut>& din, mut c)
{
	for (mut& m : din)
		if (m.val == c.val) return;
	din.push_back(c);
}

int main()
{
	char a, b, c;
	cin >> a >> b;
	mut mutual = findMutual(a, b);
	if (mutual.val.empty())
	{
		cout << "0" << endl << "0 0";
		return 0;
	}
	cin >> c;
	for (int i = 0; i < mutual.val.size(); i++)
		cout << mutual.val.at(i) << (i != mutual.val.size() - 1 ? " " : "");
	cout << endl;
	vector<mut> dinner_result;
	push(dinner_result, findMutual(a, b,string(1,a) + string(1,b)));
	for (char c : mutual.val)
	{
		push(dinner_result, findMutual(a, c, string(1, a) + string(1, c)));
	}
	for (char c : mutual.val)
	{
		push(dinner_result, findMutual(b, c, string(1, b) + string(1, c)));
	}
	mut* largest = nullptr;
	for (mut& m : dinner_result)
	{
		if (largest == nullptr)
		{
			largest = &m;
			continue;
		}
		if (largest->val.size() < m.val.size())
			largest = &m;
		else if (largest->val.size() == m.val.size() && largest->weight < m.weight)
			largest = &m;
	}
	for (char c : largest->val)
	{
		cout << c << " ";
	}
	cout << largest->weight;
	return 0;
}
