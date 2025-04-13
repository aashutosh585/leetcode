class Solution {
public:
    int mod=1e9+7;
    int mpow(int a, long long  n) {
        int ans = 1;
        a %= mod;
        while (n > 0) {
            if (n & 1) {
                ans = (1ll*ans * a) % mod;
            }
            a=a%mod;
            a = (1ll*a * a) % mod;
            n >>= 1;
        }
        return ans % mod;
    }
    int countGoodNumbers(long long n) {
        long long m=n/2;
        if(n==1) return 5;

        if(n%2==0){
            int x=mpow(5,m)%mod;
            int y=mpow(4,m)%mod;
            return (1ll*x*y)%mod;
        }
        else{
            int x=mpow(5,m+1)%mod;
            int y=mpow(4,m)%mod;
            return (1ll*x*y)%mod;
        }
    }
};