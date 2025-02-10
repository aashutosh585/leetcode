class Solution {
public:
    string reverse(string str){
        return string(str.rbegin(),str.rend() );
    }
    
    string clearDigits(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return reverse(ans);
        
    }
};