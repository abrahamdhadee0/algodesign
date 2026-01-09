// in maps the inset and search and delete everything done o(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
cout<<"hello world";
unordered_set<int> s;
s.insert(1);
s.insert(2);
s.insert(3);///it used to dtore only unique values.
s.insert(4);
s.erase(3);
for(auto x:s){//for each loop will be used here.
    cout<<x<<" ";

}
int target=2;
if(s.find(target)!=s.end()){/// agghr eo element mil gya to wo end ke barabar nhi hoga is actually oppsite of normal finding method.
    cout<<"found"<<endl;
}
else{
    cout<<"not found"<<endl;
}
}


