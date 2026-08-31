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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        //now we have a reversed linked list whose head is prev.'
        stack<int>st;
        vector<int>nge;
        ListNode* x=prev;
        while(x!=NULL){
            while(!st.empty() && st.top()<=x->val){
                st.pop();
            }
            if(st.empty()){
                nge.push_back(0);
            }
            else{
                nge.push_back(st.top());
            }
            st.push(x->val);
            x=x->next;
        }
        reverse(nge.begin(),nge.end());
        return nge;
    }
};