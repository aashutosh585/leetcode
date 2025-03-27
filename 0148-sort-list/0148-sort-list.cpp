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
    ListNode* mergeSort(int n, ListNode* head) {
        if(n == 0 || n == 1) return head;

        int m = n / 2;
        int x = n / 2;  // Preserve left sublist size

        ListNode* temp = head, *prev = NULL;
        while(m--) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;  // Break the list into two parts

        ListNode* left = mergeSort(x, head);
        ListNode* right = mergeSort(n - x, temp);
    
        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode *head = new ListNode(0), *hed = head;

        while(left != NULL && right != NULL) {
            if(left->val > right->val) {
                head->next = right;
                right = right->next;
            }
            else {
                head->next = left;
                left = left->next;
            }
            head = head->next;
        }

        if(left != NULL) {
            head->next = left;
        }
        if(right != NULL) {
            head->next = right;
        }

        return hed->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        int n = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            n++;
            temp = temp->next;
        }

        return mergeSort(n, head);
    }
};
