class Solution {
public:
    int maxBottlesDrunk(int Bo, int Ex) {
        int ans = Bo;       
        int em = Bo;       

        while (em >= Ex) {
            em -= Ex;      
            em++;          
            ans++;          
            Ex++;           
        }

        return ans;
    }
};
