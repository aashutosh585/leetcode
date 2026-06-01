class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());

        int i=cost.size()-1, ans=0;
        while(i-1>=0){
            ans+= cost[i]+cost[i-1];
            i=i-3;
        }

        for( int j=i ;j>=0 ;j--) ans+=cost[j];

        return ans;
    }
};