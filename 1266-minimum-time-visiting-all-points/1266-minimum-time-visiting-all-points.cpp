class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size(),cnt=0,px=points[0][0],py=points[0][1];
        for(int i=1;i<n;i++){
            cnt+=max(abs(points[i][0]-px),abs(points[i][1]-py));
            px=points[i][0],py=points[i][1];
        }

        return cnt;
    }
};