class Solution {
public:
    int mod = 1e9 + 7;

    int concatenatedBinary(int n) {
        long long result = 0;
        int bitLength = 0;

        for (int i = 1; i <= n; i++) {
            // Increase bit length when i is a power of 2
            if ((i & (i - 1)) == 0) {
                bitLength++;
            }
            result = ((result << bitLength) % mod + i) % mod;
        }

        return (int)result;
    }
};
