class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int>st;
        int ans=0,n=arr.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int idx=st.top();
                st.pop();

                if(!st.empty())
                ans=max(ans,arr[idx]*(i-st.top()-1));
                else
                ans=max(ans,arr[idx]*i);

            }
            ans=max(ans,arr[i]);
            st.push(i);
        }
        while(!st.empty()){
            int idx=st.top();
            st.pop();

            if(!st.empty())
            ans=max(ans,arr[idx]*(n-st.top()-1));
            else
            ans=max(ans,arr[idx]*n);
        }

        return ans;
        
    }
};