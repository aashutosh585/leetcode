class Solution {
public:

    long long mergeSortAndcnt(int l, int r, vector<int>& P, vector<int>& temp) {
        if (l >= r) return 0;

        int mid = l + (r - l)/ 2;
        long long cnt = mergeSortAndcnt(l, mid, P, temp) + 
                          mergeSortAndcnt(mid + 1, r, P, temp);

        // cal.. cnt
        int i = l;
        for(int j = mid + 1; j <= r; j++){
            while(i <= mid && P[i] < P[j]) i++;
            cnt += (i - l);
        }

        // normal merge sort
        i = l;
        int j = mid + 1;
        int k = l;
        
        while(i <= mid && j <= r)
            if(P[i] <= P[j])temp[k++] = P[i++];
            else temp[k++] = P[j++];
            
        while(i <= mid) temp[k++] = P[i++];
        while(j <= r) temp[k++] = P[j++];

        for(i = l; i <= r; i++) P[i] = temp[i];

        return cnt;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> P(n + 1, 0);
        
        for(int i = 0; i < n; i++) P[i + 1] = P[i] + (nums[i] == target ? 1 : -1);
        
        vector<int>temp(n + 1);
        return mergeSortAndcnt(0, n, P, temp);
    }
};