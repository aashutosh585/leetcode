class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++) if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ) cnt++;

        if(cnt==0) return false;
        else if(cnt%2==1) return true;
        else{
            return true;
        }
    }
};