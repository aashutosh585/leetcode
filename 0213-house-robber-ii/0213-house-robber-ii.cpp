class Solution {
public:
    int roob(vector<int>&arr){
        int n=arr.size();

        vector<int>loot(n);
        loot[0]=arr[0];
        loot[1]=max(arr[0],arr[1]);

        for(int i=2;i<n;i++)
        loot[i]=max(arr[i]+loot[i-2],loot[i-1]);

        return loot[n-1];

    }

    int rob(vector<int>& arr) {
        int n=arr.size();

        if(n==1) return arr[0];
        if(n==2) return max(arr[0],arr[1]);
        if(n==3) return max({arr[0],arr[1],arr[2]});

        vector<int>a(n-1),b(n-1);

        for(int i=0;i<n-1;i++)
        a[i]=arr[i];
        for(int i=1;i<n;i++)
        b[i-1]=arr[i];

        int ans1=roob(a);
        int ans2=roob(b);

        return max(ans1,ans2);
    }
};