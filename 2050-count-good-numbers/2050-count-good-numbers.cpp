class Solution {
public:
    const long long mod = 1e9 + 7;

    long long mpow(long long a, long long n) {
        long long ans = 1;
        while (n > 0) {
            if (n & 1) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;  
            n /= 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;  
        long long odd = n / 2;    

        long long ans = (mpow(5, even) * mpow(4, odd)) % mod;
        return (int)ans;
    }
};
