class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res=0, a=0;
        for(auto &i:gain){
            a+=i;
            res=max(res, a);
        }
        return res;
    }
};