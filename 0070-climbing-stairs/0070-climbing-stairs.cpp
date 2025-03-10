class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int ans = 0;
  
        for (int a = 0; a <= n / 2; a++) {
            int oneSteps = n - 2 * a;      
            int totalMoves = a + oneSteps; 
           
            long long binom = 1;
            for (int i = 1; i <= a; i++) {
                binom = binom * (totalMoves - i + 1) / i;
            }
            ans += binom;
        }
        return ans;
    }
};
