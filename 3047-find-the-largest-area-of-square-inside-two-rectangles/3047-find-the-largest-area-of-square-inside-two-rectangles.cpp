class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bL, vector<vector<int>>& tR) {
        int n=bL.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=bL[i][0],x2=tR[i][0], y1=bL[i][1], y2=tR[i][1];
                int x3=bL[j][0],x4=tR[j][0], y3=bL[j][1], y4=tR[j][1];

                if((x1<x3 && x2<=x3) || (x3<x1 && x4<=x1)) continue;
                else if((y1<y3 && y2<=y3) || (y3<y1 && y4<=y1)) continue;

                long long  len= min(x4,x2)-max(x1,x3);
                long long  bre= min(y4,y2)- max(y1,y3);

                long long side=min(len,bre);
                ans=max(ans,side*side);
                

            }
        }
        return ans;
        
    }
};