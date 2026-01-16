#include<bits/stdc++.h>
using namespace std;
int main(){
    unodered_map<int,int> mp;
  pair<string,int> p1;
  p1.first="abc";
  p1.second=1;
  m.insert(p1);

  m["Harsh"]=15;
  m["Lokesh"]=20;

  for(auto x:mp){
    cout<<x.first<<" "<<x.second<<endl;
  }
  mp.erase("abc");
  mp.erase("Harsh");
    cout<<"after erasing"<<endl;
     for(auto x:mp){
        cout<<x.first<<" "<<x.second<<endl;
    }
}