class Solution {
public:
    int bitwise(int i){
        int cnt = 0;
        while(i > 0){
            if(i & 1) cnt++;
            i >>= 1;
        }
        return cnt;
    }

    vector<string> readBinaryWatch(int k) {
        vector<string> ans;
        if(k == 0) return {"0:00"};
        if(k > 8) return {};

        for(int h = 0; h < 12; h++){
            int bitH = bitwise(h);
            for(int m = 0; m < 60; m++){
                int bitM = bitwise(m);
                if(bitH + bitM == k){
                    string time = to_string(h) + ":";
                    if(m < 10) time += "0" + to_string(m);
                    else time += to_string(m);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};
