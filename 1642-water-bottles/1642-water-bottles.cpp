class Solution {
public:
    int numWaterBottles(int nBo, int nEx){
        int ans=nBo,e=nBo;

        while(e>=nEx){
           ans+=e/nEx;
           e= e/nEx + e%nEx;

        }
    
        return ans;
    }
};