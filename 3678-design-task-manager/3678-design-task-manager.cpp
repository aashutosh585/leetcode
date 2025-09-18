#include <bits/stdc++.h>
using namespace std;

class TaskManager {
public:
    map<long long, set<int>> pri;
    unordered_map<int, pair<int,long long>> mpp;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &v : tasks) {
            int u = v[0], t = v[1];
            long long p = v[2];
            pri[p].insert(t);
            mpp[t] = {u, p};
        }
    }

    void add(int userId, int taskId, int priority) {
        pri[priority].insert(taskId);
        mpp[taskId] = {userId, priority};
    }

    void edit(int taskId, int newPriority) {
        auto itTask = mpp.find(taskId);
        if (itTask == mpp.end()) return;
        long long old = itTask->second.second;
        auto itMap = pri.find(old);
        if (itMap != pri.end()) {
            itMap->second.erase(taskId);
            if (itMap->second.empty()) pri.erase(itMap);
        }
        pri[newPriority].insert(taskId);
        itTask->second.second = newPriority;
    }

    void rmv(int taskId) {
        auto itTask = mpp.find(taskId);
        if (itTask == mpp.end()) return;
        long long pr = itTask->second.second;
        auto itMap = pri.find(pr);
        if (itMap != pri.end()) {
            itMap->second.erase(taskId);
            if (itMap->second.empty()) pri.erase(itMap);
        }
        mpp.erase(itTask);
    }

    int execTop() {
        if (pri.empty()) return -1;
        auto it = pri.rbegin();
        long long bestP = it->first;
        int bestTask = *it->second.rbegin(); 
        int userId = mpp[bestTask].first;
        auto mit = pri.find(bestP);
        mit->second.erase(bestTask);
        if (mit->second.empty()) pri.erase(mit);
        mpp.erase(bestTask);
        return userId;
    }
};
