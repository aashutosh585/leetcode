/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());

        ListNode *ans=new ListNode(0);
        ans->next=head;
        ListNode* prev=ans, *curr=head,*temp;

        while(curr){
            if(st.find(curr->val)!=st.end()){
                prev->next=NULL;
                temp=curr->next;
                curr->next=NULL;
                curr=temp;
                prev->next=curr;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }

        return ans->next;
        
    }
};