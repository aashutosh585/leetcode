class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt=0;

        for(int n=num1;n<=num2;n++){
            string s= to_string(n);
            int i=0, j=2;
            while(j<s.size()){
                if(s[i+1]>s[i] && s[i+1]>s[j]) cnt++;
                else if(s[i+1]<s[i] && s[i+1] < s[j]) cnt++;
                i++,j++;
            }
        }

        return cnt;
    }
};