class Solution {
public:
    int longestBalanced(string s) {
        int ans=0,n=s.size();
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;

                int k=0;
                bool f=true;
                for(auto x:freq){
                    if(x>0){
                        if(k==0) k=x;
                        else if(x!=k){
                            f=false;
                            break;
                        }
                    }
                }
                if(f){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};