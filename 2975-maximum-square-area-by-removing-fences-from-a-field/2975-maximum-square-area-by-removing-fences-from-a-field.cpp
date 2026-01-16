class Solution {
public:
    int mod = 1e9 + 7;

    int maximizeSquareArea(int m, int n, vector<int>& hF, vector<int>& vF) {
      
        hF.push_back(m); 
        hF.insert(hF.begin(), 1);

        vF.push_back(n); 
        vF.insert(vF.begin(), 1);

        sort(hF.begin(), hF.end());
        sort(vF.begin(), vF.end());

        unordered_set<int> st;
        for(int i = 0; i < hF.size(); i++) {
            for(int j = i + 1; j < hF.size(); j++) {
                st.insert(hF[j] - hF[i]);
            }
        }

        long long ans = -1;

    
        for(int i = 0; i < vF.size(); i++) {
            for(int j = i + 1; j < vF.size(); j++) {
                int val = vF[j] - vF[i];
                if(st.find(val) != st.end()) {
                    ans = max(ans, (long long)val);
                }
            }
        }

        if(ans == -1) return -1;

        long long v = (ans % mod) * (ans % mod);
        return (int)(v % mod);
    }
};
