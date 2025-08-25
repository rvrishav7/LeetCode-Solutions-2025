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
    void reorderList(ListNode* head) {
        
        ListNode *curr=head;
        int n=1;
        deque<ListNode *>q;
        while(head){
            q.push_back(head);
            head=head->next;
        }
        head=curr;
        q.pop_front();
        while(!q.empty()){
            if(n&1){
                curr->next=q.back();
                q.pop_back();
            }
            else{
                curr->next=q.front();
                q.pop_front();
            }
            curr=curr->next;
            n++;
        }
        curr->next=NULL;
    }
};