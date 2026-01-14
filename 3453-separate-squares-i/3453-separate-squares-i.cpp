class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long sum=0;
        double low =INT_MAX,high=INT_MIN;
        for(auto &sq:squares){
            int l=sq[2];
            sum+= 1LL * l*l;
            low=min(low,(double)sq[1]);
            high=max(high,(double)(sq[1]+l));
        }
        double tar= sum/2.0;

        for(int i=0;i<100;i++){ //precision

            double mid= (low+high)/2.0;
            double area=0;

            for(auto &sq:squares){
                int y=sq[1],l=sq[2];
                if(mid<=y) continue;
                else if(mid>=y+l) area+=1.0 * l* l;
                else{
                    double h=mid-y;
                    area+= h*l;
                }
            }

            if(area<tar) low=mid;
            else high=mid;
            
        }

        return (low+high)/2.0;

    }
};