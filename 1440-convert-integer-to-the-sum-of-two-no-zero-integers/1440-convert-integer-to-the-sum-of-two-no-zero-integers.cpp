class Solution {
public:
    bool cnt(int x){
        string s = to_string(x);
        for(auto c:s) if(c=='0') return false;
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        int m=1;
        while(m<n){
            if(cnt(m) && cnt(n-m) ) break;
            m++;
        }
        return {m,n-m};
    }
};