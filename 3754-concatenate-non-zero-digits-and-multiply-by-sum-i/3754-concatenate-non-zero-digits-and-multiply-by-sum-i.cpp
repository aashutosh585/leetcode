class Solution {
public:
    long long sumAndMultiply(int n) {

        int p=1;
        long long x=0;
        long long sum=0;

        string s=to_string(n);
        for(int i=s.size()-1;i>=0;i--){
            int c=s[i]-'0';
            if(c>0){
                x = x+ p*c;
                p*=10;
            }
            sum+=c;
        }

        return sum*x;
        
    }
};