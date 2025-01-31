class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        if(k==0) return 0;
        int pro=1,cnt=0,n=arr.size();
        int i=0,j=0;
        while(i<n){
            pro*=arr[i];
            while(pro>=k && i>=j){
                pro=pro/arr[j];
                j++;
            }
            cnt+=i-j+1;
            i++;
        }  
        return cnt;
    }
};