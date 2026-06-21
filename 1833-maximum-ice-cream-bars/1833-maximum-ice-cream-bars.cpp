class Solution {
public:
    int maxIceCream(vector<int>& cos, int c) {
        sort(cos.begin(), cos.end());
        int len=0;
        for(int i=0;i<cos.size();i++){
            c-=cos[i];
            if(c<0) break;
            len=i+1;
        }
        return len;
    }
};