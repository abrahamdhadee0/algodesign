class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(st.top()==s[i]) continue;
                else{
                    st.push(s[i]);
                }
            }
        }
            s="";
            while(st.size()>0){
                s+=st.top();
                st.pop();
            }
        
        reverse(s.begin(),s.end());
        return s;
    
}
};