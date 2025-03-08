class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int n = blocks.size();
        int sum = 0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W'){
                sum++;
            }
        }
        cout<<sum<<endl;

        int minSum = sum;
        for(int i=0;i<n-k;i++){
            cout<<i<<" "<<k+i<<" "<<blocks[i]<<" "<<blocks[k+i]<<endl;
            if(blocks[i]=='W'){
                sum-=1;
            }
            if(blocks[k+i]=='W'){
                sum+=1;
            }
            minSum = min(minSum,sum);
        }
        return minSum;
    }
};