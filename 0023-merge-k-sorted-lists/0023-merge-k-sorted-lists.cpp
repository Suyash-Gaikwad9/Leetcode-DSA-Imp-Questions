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
    ListNode* mergeList(ListNode *p, ListNode *q){
        ListNode *start = new ListNode(-1);
        ListNode *head = new ListNode;
        head = start;
        while(p && q){
            if(p->val > q->val){
                start->next = q;
                q = q->next;
            }
            else{
                start->next = p;
                p = p->next;
            }
            start = start->next;
        }
        while(p){
            start->next = p;
            p = p->next;
            start = start->next;
        }
        while(q){
            start->next = q;
            q = q->next;
            start = start->next;
        }
        return head->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        
        ListNode* head = new ListNode;
        head = lists[0];
        
        for(int i = 1; i < lists.size(); i++){
            head = mergeList(lists[i], head);
        }
        return head;
    }
};