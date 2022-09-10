#include<iostream>
#include<string>
#include<map>
#include<chrono>
using namespace std;

namespace fs
{
  typedef chrono::high_resolution_clock Time;
  typedef chrono::nanoseconds ns;
  typedef chrono::duration<float> fsec;
  typedef decltype(Time::now()) _n;
  map<string,decltype(Time::now())> _m;
  inline void setflag(const string& s)
  {
    _m[s] = Time::now();
  }
  inline int getflag(const string& s)
  {
    return chrono::duration_cast<ns>(Time::now() - _m[s]).count();
  }
}


int factorial(int x)
{
  if(x == 0) return 1;
  return x * factorial(x-1);
}

template<int N>
struct factorial_mp {
  enum { value = factorial_mp<N - 1>::value * N };
};

template<>
struct factorial_mp<1> {
  enum { value = 1 };
};

constexpr int TEST_VALUE = 100;
constexpr int TEST_ITERS = 20000;
const string TEST_FLAG = "test";

int main(){
  double average_recur = 0.0;
  double average_metas = 0.0;
  for(int i = 0;i < TEST_ITERS;i++)
  {
    fs::setflag(TEST_FLAG);
    factorial(TEST_VALUE);
    average_recur = (average_recur + (double)fs::getflag(TEST_FLAG)) / 2;
  }
  for(int i = 0;i < TEST_ITERS;i++)
  {
    fs::setflag(TEST_FLAG);
    int a = factorial_mp<TEST_VALUE>::value;
    average_metas = (average_metas + (double)fs::getflag(TEST_FLAG)) / 2;
  }
  cout << average_recur << " ns" << endl << average_metas << " ns" << endl;
  return 0;
}
