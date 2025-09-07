class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>arr(n,0);
        int i=0,j=n-1,p=1;
        while(i<j){
            arr[i]=p;
            arr[j]=-1*p;
            p++;
            i++;
            j--;
        }
        return arr;
    }
};