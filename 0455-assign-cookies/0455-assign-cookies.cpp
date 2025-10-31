class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int cnt=0;
        for(auto x:g){
            auto it = lower_bound(s.begin(), s.end(), x);
            if(it == s.end()) break;
            else{
                s.erase(it);
                cnt++;
            }
        }
        return cnt;
    }
};