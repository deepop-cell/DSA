
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        else if(head->next==NULL){
          TreeNode* root=new TreeNode(head->val);
          return root;
        }
        ListNode* slow=head;
        ListNode* slow_prev=NULL;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow_prev!=NULL){
                slow_prev=slow_prev->next;
            }
            else if(slow_prev==NULL){
                slow_prev=head;
            }
        }
        TreeNode* root=new TreeNode(slow->val);
        slow_prev->next=NULL;//breaking links
        ListNode* temp=slow->next;
        slow->next=NULL;//breakking links
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(temp);
        return root;
    }
};