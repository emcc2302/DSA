// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
        
//         if(head->next==NULL){
//             delete head;
//             return NULL;
//         }

//         int count =0;
//         ListNode*temp = head;

//         while(temp !=NULL){
//             count++;
//             temp=temp->next;
//         }

//         int middle=count/2;

//         ListNode*curr=head;

//         for(int i=0;i<middle-1;i++){
//             curr=curr->next;
//         }

//         ListNode*del=curr->next;
//         curr->next=del->next;

//         delete del;

//         return head;
//     }
// };


//in leetcode delete is not work manually

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if (head->next == NULL) {
            return NULL;
        }

        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int middle = count / 2;

        ListNode* curr = head;

        for (int i = 0; i < middle - 1; i++) {
            curr = curr->next;
        }

        curr->next = curr->next->next;

        return head;
    }
};