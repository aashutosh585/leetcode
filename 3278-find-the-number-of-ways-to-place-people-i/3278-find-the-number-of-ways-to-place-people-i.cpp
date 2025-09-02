class Solution {
public:
    int numberOfPairs(vector<vector<int>>& arr) {

        set<pair<int,int>> st;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            st.insert({arr[i][0], arr[i][1]});
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int prevX = arr[i][0], prevY = arr[i][1];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int currX = arr[j][0], currY = arr[j][1];

                // only consider ordered pairs where prev is top-left relative to curr
                if (!(prevX <= currX && prevY >= currY)) continue;

                st.erase({prevX, prevY});
                st.erase({currX, currY});

                bool f = true;
                for (auto it : st) {
                  
                    if (it.first >= prevX && it.first <= currX &&
                        it.second <= prevY && it.second >= currY) {
                        f = false;
                        break;
                    }
                }
                if (f) cnt++;

                st.insert({prevX, prevY});
                st.insert({currX, currY});
            }
        }

        return cnt;
    }
};
