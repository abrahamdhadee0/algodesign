class Solution {
public:
bool palindrome(string s,int start ,int end){
    while(start<=end){
        if(s[start++]!=s[end--]){
            return false;
        }
     
    }
       return true;
}
  void generate(vector<string>& path,vector<vector<string>>& res,int idx,string s){

    if(idx==s.length()){
        res.push_back(path);
        return;
    }
    for(int i=idx;i<s.size();i++){
        if(palindrome(s,idx,i)){
            path.push_back(s.substr(idx,i-idx+1));
            generate(path,res,i+1,s);
            path.pop_back();
        }
    }
  }



    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>>  res;
        generate(path,res,0,s);
        return res;
    }


};
What Each Line Does:
Step 1: path.push_back(s.substr(idx,i-idx+1))
Purpose: Add current palindromic substring to our partition
Breaking down s.substr(idx,i-idx+1):

idx = starting position of substring
i = ending position of substring
i-idx+1 = length of substring
Example: If idx=1, i=3 in string "abcde"

Substring from position 1 to 3 = "bcd"
Length = 3-1+1 = 3 characters



Step 2: generate(path,res,i+1,s)
Purpose: Recursively partition the remaining string

i+1 = start from next position after current substring
We pass the updated path to the recursive call
Example: If we just added substring ending at position 3, next call starts from position 4

Step 3: path.pop_back()
Purpose: Remove the last added substring (UNDO the choice)

This happens AFTER the recursive call returns
Allows us to try the next possible substring
Critical for exploring all possibilities

Visual Example with "aab":
Initial: path = [], idx = 0

For loop: i = 0 (trying substring "a")
├─ Step 1: path.push_back("a")     → path = ["a"]
├─ Step 2: generate(path,res,1,s)  → Recurse from index 1
│  │
│  │ (Recursive call explores: ["a","a","b"] and ["a","ab"])
│  │
├─ Step 3: path.pop_back()         → path = [] (back to original)

For loop: i = 1 (trying substring "aa")  
├─ Step 1: path.push_back("aa")    → path = ["aa"]
├─ Step 2: generate(path,res,2,s)  → Recurse from index 2
│  │
│  │ (Recursive call explores: ["aa","b"])
│  │
├─ Step 3: path.pop_back()         → path = [] (back to original)

For loop: i = 2 (trying substring "aab")
├─ palindrome check fails, skip this iteration
Why This Pattern Works:
1. Systematic Exploration:

Try each possible substring starting from current position
For each valid choice, explore what comes after it
Undo the choice to try the next possibility

2. State Management:

push_back() modifies the path for the recursive call
pop_back() restores the path to its previous state
This allows the same path vector to be reused across all recursive calls

3. Complete Coverage:

Every possible partition gets explored exactly once
No valid combinations are missed
No invalid combinations are included

Key Insight:
The path vector represents our "current partition attempt". We:

Add a piece to it
Explore what happens with that piece included
Remove the piece to try other possibilities

This is the essence of backtracking: Try → Explore → Undo → Repeat
Memory Efficiency:
Instead of creating new vectors for each recursive call, we reuse the same path vector by adding/removing elements. This saves memory and is more efficient than creating copies.