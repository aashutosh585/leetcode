class Solution {
public:
    int countOdds(int low, int high) {
        int cnt=0;
        while(high!=low){
            if(low%2) cnt++;
            low++;
        }
        return cnt + (low%2==1?1:0);
    }
};