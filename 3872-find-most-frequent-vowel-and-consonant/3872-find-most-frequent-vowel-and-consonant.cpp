class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int>mpp;
        int ans=0,ans1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                mpp[s[i]]++;
                ans=max(ans,mpp[s[i]]);
            }
            else{
                mpp[s[i]]++;
                ans1=max(ans1,mpp[s[i]]);
            }
        }

        return ans+ans1;
        
    }
};