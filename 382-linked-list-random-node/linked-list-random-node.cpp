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
    int size=0;
    ListNode *root=NULL,*curr;
    Solution(ListNode* head) {
        curr=head;
        root=head;
        while(curr){
            size++;
            curr=curr->next;
        }

    }
    
    int getRandom() {
        int randi=rand()%size;
        curr=root;
        int val;
        while(randi-- &&curr){
            val=curr->val;
            curr=curr->next;
        }
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */