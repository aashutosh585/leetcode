class Solution {
public:
    int myAtoi(string s) {
        // trim spaces
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++;
        if (i == n) return 0;

        // sign
        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // skip leading zeros
        while (i < n && s[i] == '0') i++;

        // convert and handle overflow
        long long num = 0;
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;
            i++;
        }

        return (int)(sign * num);
    }
};
