class Solution {
public:
    int earliestFinishTime(vector<int>& lt, vector<int>& ld, vector<int>& wt, vector<int>& wd) {
        int mn=INT_MAX;
        for(int i=0;i<lt.size();i++) mn=min(mn, lt[i]+ld[i]);

        int res=INT_MAX;
        for(int i=0;i<wt.size();i++){
            if(mn>=wt[i]){
                res=min(res, mn + wd[i] );
            }
            else{
                res=min(res, wd[i] +  wt[i] );
            }
        }

        mn=INT_MAX;
        for(int i=0;i<wt.size();i++) mn=min(mn, wt[i]+wd[i]);

        for(int i=0;i<lt.size();i++){
            if(mn>=lt[i]){
                res=min(res, mn + ld[i] );
            }
            else{
                res=min(res,  ld[i] + lt[i] );
            }
        }


        return res;
    }
};