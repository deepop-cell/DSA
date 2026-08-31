
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* next=curr->next;
        vector<int>cpoints;
        int i=1;
        while(next!=NULL){
            if((curr->val>prev->val && curr->val>next->val)||(curr->val <prev->val && curr->val <next->val)){
                cpoints.push_back(i);
            }
            prev=curr;
            curr=next;
            next=next->next;
            i++;
        }
        sort(cpoints.begin(),cpoints.end());
        vector<int>ans;
        if(cpoints.size()<2){
            return {-1,-1};
        }
        int mn=INT_MAX;
        for(int i=0;i<cpoints.size()-1;i++){
            int currdiff=cpoints[i+1]-cpoints[i];
            mn=min(mn,currdiff);
        }
        ans.push_back(mn);
        ans.push_back(cpoints[cpoints.size()-1]-cpoints[0]);
        return ans;
    }
};