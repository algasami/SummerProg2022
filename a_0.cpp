#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

bool palin(const char* begin, const char* end)
{
  if(end - begin == 0) return true;
  if(*end != *begin) return false;
  return palin(++begin,--end);
}

int main(){
  vector<string> buffer;
  {
    string r;
    while(cin >> r)
    {
      if(r == "0") break;
      buffer.push_back(r);
    }
  }
  for(auto& value: buffer)
  {
    const char*const d = value.c_str();
    cout << (palin(d,d+value.size()-1) ? "YES" : "NO") << endl;
  }
  return 0;
}
