class Solution {
public:
    vector<string>ans;
    void generate(string s,int net, int n){
        if(net==0 && s.size()==n){
            ans.push_back(s);
        }

        if(s.size()==n) return;

        if(net==0){
            generate(s+'(',net+1,n);
        }
        else{
            if(net>0){
                generate(s+'(',net+1,n);     
                generate(s+')',net-1,n);          
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        generate("",0,n*2);
        return ans;
    }
};