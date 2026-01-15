class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

       
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        auto solve=[](vector<int>&arr){
            int a=1,cnt=1;

            for(int i=1;i<arr.size();i++){
                arr[i-1]+1==arr[i]? cnt++: cnt=1;
                a=max(a,cnt);
            }
            return a;
        };

        int s=min(solve(hBars),solve(vBars)) +1;
        // cout<<s<<"-"<<a1<<"-"<<a2<<endl;
        return s*s;

        
    }
};