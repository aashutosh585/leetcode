class Solution {
public:
    int climbStairs(int n) {
        int a=0,b=1,c=0;
        for(int i=n-1;i>=0;i--){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
        
    }
};