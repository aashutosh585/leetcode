class SegmentTree {
public:
    int n;
    vector<int> maxValues, minValues;

    SegmentTree(int n) : n(n) {
        maxValues.resize(4 * n);
        minValues.resize(4 * n);
    }

    void insert(int idx, int val) {
        insert(1, 0, n - 1, idx, val);
    }

    void insert(int node, int lo, int hi, int idx, int val) {
        if (lo == hi) {
            maxValues[node] = val;
            minValues[node] = val;
            return;
        }

        int mid = lo + (hi - lo) / 2;

        if (idx <= mid)
            insert(2 * node, lo, mid, idx, val);
        else
            insert(2 * node + 1, mid + 1, hi, idx, val);

        maxValues[node] =
            max(maxValues[2 * node], maxValues[2 * node + 1]);

        minValues[node] =
            min(minValues[2 * node], minValues[2 * node + 1]);
    }

    pair<int, int> query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    pair<int, int> query(int node, int lo, int hi, int l, int r) {
        // No overlap
        if (r < lo || l > hi)
            return {INT_MAX, INT_MIN};

        // Complete overlap
        if (l <= lo && hi <= r)
            return {minValues[node], maxValues[node]};

        int mid = lo + (hi - lo) / 2;

        auto left = query(2 * node, lo, mid, l, r);
        auto right = query(2 * node + 1, mid + 1, hi, l, r);

        return {
            min(left.first, right.first),
            max(left.second, right.second)
        };
    }
};

class Solution {
public:
    struct Node {
        long long value;
        int l, r;

        bool operator<(const Node& other) const {
            return value < other.value; // max-heap
        }
    };

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree st(n);
        for (int i = 0; i < n; i++) {
            st.insert(i, nums[i]);
        }

        priority_queue<Node> pq;

        auto res = st.query(0, n - 1);
        pq.push({1LL * (res.second - res.first), 0, n - 1});

        unordered_set<long long> visited;

        auto encode = [&](int l, int r) -> long long {
            return (static_cast<long long>(l) << 32) | r;
        };

        visited.insert(encode(0, n - 1));

        long long ans = 0;

        while (k > 0 && !pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            ans += curr.value;
            --k;

            int l = curr.l;
            int r = curr.r;

            // [l + 1, r]
            if (l + 1 <= r) {
                long long key = encode(l + 1, r);

                if (!visited.count(key)) {
                    auto val = st.query(l + 1, r);
                    visited.insert(key);

                    pq.push({
                        1LL * (val.second - val.first),
                        l + 1,
                        r
                    });
                }
            }

            // [l, r - 1]
            if (l <= r - 1) {
                long long key = encode(l, r - 1);

                if (!visited.count(key)) {
                    auto val = st.query(l, r - 1);
                    visited.insert(key);

                    pq.push({
                        1LL * (val.second - val.first),
                        l,
                        r - 1
                    });
                }
            }
        }

        return ans;
    }
};