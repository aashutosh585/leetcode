class Solution {
public:
    int earliestFinishTime(vector<int>& lt, vector<int>& ld,
                           vector<int>& wt, vector<int>& wd) {

        int ans = INT_MAX;

        for(int i = 0; i < lt.size(); i++) {
            for(int j = 0; j < wt.size(); j++) {
                
                int t1 = lt[i] + ld[i];
                int finish1 = max(t1, wt[j]) + wd[j];

           
                int t2 = wt[j] + wd[j];
                int finish2 = max(t2, lt[i]) + ld[i];

                ans = min({ans, finish1, finish2});
            }
        }

        return ans;
    }
};