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
        unordered_set<int>s(nums.begin(),nums.end());
        ListNode*prev=NULL;
        ListNode*st=head;
        while(st!=NULL){
            if(s.count(st->val)){
                if(prev!=NULL){
                prev->next=st->next;
                st=st->next;
                }
                else{
                    head=st->next;
                    st=st->next;
                }
            }
            else{
                prev=st;
                st=st->next;
            }
        }
        return head;
    }
};