class Solution {
public:
    int rob(vector<int>& arr) {

        int n=arr.size();
        if(n==1) return arr[0];
        if(n==2) return max(arr[0],arr[1]);

        vector<int>loot(n,0);
        loot[0]=arr[0];
        loot[1]=max(arr[0],arr[1]);


        for(int i=2;i<n;i++){
            loot[i]=max((arr[i]+loot[i-2]),loot[i-1]);
        
        }

        return loot[n-1];
    }
};