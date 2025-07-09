/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node,unordered_map<Node*,Node*>&mpp){
        for(auto neighbor:node->neighbors){
            if(mpp.find(neighbor)==mpp.end()){
                mpp[neighbor] = new Node(neighbor->val); 
                dfs(neighbor,mpp);
            }
            mpp[node]->neighbors.push_back(mpp[neighbor]);
            
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        unordered_map<Node*,Node*>mpp;
        mpp[node]=new Node(node->val);

        dfs(node,mpp);

        return mpp[node];






        // unordered_map<Node*,Node*>mpp;
        // queue<Node*>q;
        // q.push(node);

        // mpp[node]= new Node(node->val);


        // while(!q.empty()){
        //     Node* temp = q.front();
        //     q.pop();
            

        //     for(auto neighbor:temp->neighbors){
                
        //         if(mpp.find(neighbor)==mpp.end()){
        //             mpp[neighbor]=new Node(neighbor->val);
        //             q.push(neighbor);
        //         }
        //         mpp[temp]->neighbors.push_back(mpp[neighbor]);
 
        //     }
        // }
        // return mpp[node];
    }
};

// unordered_map  Old, New Nodes
// using BFS we travel on Old Graph and at each node create new Node if
// its Not Present in map
// add neigbors to it 