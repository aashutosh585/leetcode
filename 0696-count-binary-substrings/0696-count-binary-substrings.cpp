class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt=0,z=0,o=0,p=-1,n=s.size();

        for(int i=0;i<s.size();i++){
            s[i]=='1'? o++:z++;

            if(o!=0 && z!=0){
                if(z==o){
                    cnt++;
                    s[i]=='1'? z=0:o=0;
                }
                else{
                    cnt++;
                    if(i+1<n && s[i+1]!=s[i]) s[i]=='1'? z=0:o=0;
                }
            }  
        }
        return cnt;
    }
};