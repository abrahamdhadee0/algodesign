#include<iostream>
#include<string>
using namespace std;
bool isplaindrome(string s,int i,int j){
    if(i>=j) return true;
    if(s[i]!=s[j]) return false;
    return isplaindrome(s,i+1,j-1);
}