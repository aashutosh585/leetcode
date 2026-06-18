
class Solution {
public:
    double mint(double v){
        return 6.0 * v; 
    }
    
    double hr(int v){
        return 30.0 * (v % 12); 
    }

    double ex(double v){
        return 0.5 * v; 
    }

    double angleClock(int hour, int minutes) {
        double resh = hr(hour) + ex(minutes);
   
        double resm = mint(minutes);
    
        double ans = abs(resh - resm);
        
        return min(ans, 360.0 - ans);
    }
};