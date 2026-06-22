class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int>mpp;
        mpp['b']=0;
        mpp['n']=0;
        mpp['a']=0;
        mpp['o']=0;
        mpp['l']=0;

        for(auto &c:text){
            if(c=='b' || c=='l' || c=='a' || c=='o' || c=='n'){
                mpp[c]++;
            }
        }
        int  mn=mpp['b'];

        for(auto &it:mpp){
            char c= it.first;
            int val=mpp[c];
            if(c=='l' || c=='o') val/=2;
            mn=min(mn, val);
        }

        return mn;
    }
};