class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s="";
        for(auto it: words){
            int cnt=0;
            for(auto &c: it) cnt+= weights[c-'a'];
            cout<<cnt%26<<endl;
            s += ('z'- cnt%26 );
            
        }
        return s;
    }
};