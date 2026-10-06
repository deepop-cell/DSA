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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* temp=head;
        unordered_map<int,bool>vis;
        while(temp!=NULL){
            ListNode* curr=temp->next;
            while( curr!=NULL && curr->val==temp->val){
  vis[curr->val]=true;
                curr=curr->next;
            }
            temp->next=curr;
            temp=temp->next;
        }
        //ab sare vis wale hata do 
        ListNode* temp2=head;
        while( temp2 !=NULL && temp2->next!=NULL){
        while( temp2->next!=NULL && vis.find(temp2->next->val)!=vis.end()){
        temp2->next=temp2->next->next;
        }
        temp2=temp2->next;
        }
        while(  head!=NULL && vis.find(head->val)!=vis.end()){
            head=head->next;
        }
        return head;
    }
};