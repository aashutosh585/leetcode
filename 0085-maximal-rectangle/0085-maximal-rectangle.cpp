class Solution {
public:

    int solve(vector<int>&arr){
        int ans=0,n=arr.size();
        stack<int>st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()] > arr[i]) ){
                int hi=arr[st.top()];
                st.pop();

                int wi= st.empty()? i: i- st.top()-1;

                ans=max(ans,hi*wi);
            }
            st.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix[0].size(),m=matrix.size();
        vector<int>arr(n);

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0') arr[j]=0;
                else arr[j]+=1;
            }
            ans=max(ans,solve(arr));
        }

        return ans;
    }
};