class Solution {
public:
    string processStr(string s) {
        string r="";
        for(auto &c:s){
            if(c=='*'){
                if(!r.empty())
                r.pop_back();
            }
            else if(c=='#'){
                r = (r+r);
            }
            else if(c=='%'){
                reverse(r.begin(), r.end());
            }
            else{
                r+= c;
            }
        }

        return r;
    }
};