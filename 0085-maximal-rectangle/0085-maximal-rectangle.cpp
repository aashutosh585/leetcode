class Solution {
public:
  
    int maximalRectangle(vector<vector<char>>& arr) {
        int n=arr.size(),m=arr[0].size(),res=0;
        // if(n==1 && m==1){
        //     if(arr[0][0]==1)
        //     return 1;
        //     else
        //     return 0;
        // }
        vector<int>a(m,0);

        for(int i=0;i<n;i++){
            stack<int>st;
        
            for(int j=0;j<m;j++){
                if(arr[i][j]=='1')
                a[j]++;
                else
                a[j]=0;

                while(!st.empty() && a[st.top()]>a[j]){
                    int idx=st.top();
                    st.pop();

                    if(!st.empty())
                    res=max(res,a[idx]*(j-st.top()-1));
                    else
                    res=max(res,a[idx]*j);
                }
                st.push(j);

            }
            while(!st.empty() ){
                int idx=st.top();
                st.pop();

                if(!st.empty())
                res=max(res,a[idx]*(m-st.top()-1));
                else
                res=max(res,a[idx]*(m));
            }
        }
        return res;
    }
};