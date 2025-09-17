#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
public:

    unordered_map<string, pair<string,int>> mpp;
    unordered_map<string, set<pair<int,string>>> mp;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            mpp[foods[i]] = {cuisines[i], ratings[i]};
            mp[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &p = mpp[food];
        string cuisine = p.first;
        int oldRating = p.second;
        auto &s = mp[cuisine];
        s.erase({-oldRating, food});    
        s.insert({-newRating, food});   
        p.second = newRating;           
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].begin()->second;
    }
};
