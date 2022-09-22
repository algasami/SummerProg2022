#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int age;
  cin >> age;
  cout <<
    (
     (age <= 5) ? 0
     : (
     (age <= 11) ? 590
     : (
     (age <= 17) ? 790
     : (
       (age <= 59) ? 890
     : 399
     )
     )
     )
    );
  return 0;
}

//0 ~ 5 歲兒童免票

//兒童票 (6 ~ 11 歲)：590 元

//青少年票 (12 ~ 17 歲)：790 元

//成人票 (18 ~ 59 歲)：890 元

//敬老票 (60歲以上)：399 元
