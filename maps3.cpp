// ordered shit
#include <bits/stdc++.h>
using namespace std;
int main(){

    set<int> s;///asceding set;
    /// or we can write unordered_set<int> s; for unordered set
    s.insert(5);
    s.insert(2);
    for( auto ele : s){
        cout<<ele<<" ";
    }

///key kai basis par sorting hogi in case of map.
    map<int,int> mp;
    mp[1]=30;
    mp[2]=20;
    mp[3]=10;
    for(auto x:mp){
        cout<<x.second<<endl;
    }

}