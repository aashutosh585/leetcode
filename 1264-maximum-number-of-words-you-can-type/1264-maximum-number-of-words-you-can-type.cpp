class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char>st; int ans=0; bool f=true;
        for(auto it:brokenLetters){ st.insert(it); }
        for(auto it:text){ 
            if(it==' '){ if(f)ans++; else f=true; } 
            else{ if(st.find(it)!=st.end()) f=false; }
        }
        if(f) ans++;
        return ans;
    }
};