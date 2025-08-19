class Solution {
public:
    unordered_map<char, string> mpp = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

    void solve(int idx,string &s,string &digits, vector<string>&ans){

        if(idx==digits.size()){
            ans.push_back(s);
            return;
        }

        string t =mpp[digits[idx]];
        for(int i=0;i<t.size();i++){
            s.push_back(t[i]);
            solve(idx+1,s,digits,ans);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if (digits.empty()) return ans;
        string s="";

        solve(0,s,digits,ans);

        return ans;
    }
};