class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i=0,n=s1.size();
        while(i<n){
            if(s1[i]!=s2[i]){
                char x,y;
                x=s1[i],y=s2[i];
                i++;
                while(i<n && s1[i]==s2[i]){
                    i++;
                }
                if(i==n)  return false;
                else{
                    if(x==s2[i] && y==s1[i]){
                        return true;
                    } else{
                        return false;
                    }
                }
            }
            i++;
        }
        return true;
    }
};