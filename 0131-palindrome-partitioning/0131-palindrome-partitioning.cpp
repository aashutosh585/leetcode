class Solution {
public:
    bool pali(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }

        return true;
    }

    vector<vector<string>>ans;

    void solve(int idx,vector<string>&arr,string &s){
        if(idx==s.size()){
            ans.push_back(arr);
            return;
        } 

        for(int i=idx;i<s.size();i++){
            if(pali(s,idx,i)){
                arr.push_back(s.substr(idx,i-idx+1));
                solve(i+1,arr,s);
                arr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>arr;
        solve(0,arr,s);
        return ans;
    }
};