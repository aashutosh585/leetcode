class Solution {
public:
    string removeDuplicates(string s) {
        int j=0,n=s.size();
        string ans="";
        stack<char>st;
       
        for(auto &x:s){
            if(st.empty()){
                st.push(x);
            }
            else if(st.top()==x){
                st.pop();
            }
            else
            st.push(x);

        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};