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
ListNode* dfs(ListNode *root, int &n){
    if(!root)
        return root;
    ListNode *f = dfs(root->next,n);
    root->next=f;
    n--;
    cout<<root->val<<" "<<n<<endl;
    if(n==0)
        return root->next;
    return root;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return dfs(head,n);
    }
};