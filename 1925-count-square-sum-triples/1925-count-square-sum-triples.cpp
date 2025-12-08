class Solution {
public:
    int countTriples(int n) {
        if(n<3) return 0;

        int cnt=0;
        for(int i=1;i<=n-2;i++)
            for(int j=i+1;j<=n-1;j++)
                for(int z=j+1;z<=n;z++)
                    if((i*i)+(j*j)==(z*z)) cnt+=2;

        return cnt;
        
    }
};