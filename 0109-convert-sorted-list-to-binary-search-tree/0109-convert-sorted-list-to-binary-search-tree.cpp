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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return nullptr;
        }
        else if(head->next==NULL){
            TreeNode* root=new TreeNode(head->val);
            return root;
        }
        //middle node find kro..
        ListNode* slow=head;
        ListNode*  fast=head;
        ListNode* slow_prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow_prev!=NULL){
                slow_prev=slow_prev->next;
            }
            else{
                slow_prev=head;
            }
        }
        // ab jo slow hai wo middle hai...
        TreeNode* root=new TreeNode(slow->val);
        ListNode* temp=slow->next;
        slow_prev->next=NULL;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(temp);
        return root;
        
    }
};