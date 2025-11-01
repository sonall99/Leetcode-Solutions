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
ListNode* check(set<int>&st,ListNode * head){
    if(!head) return NULL;
    head->next=check(st,head->next);
    if(st.count(head->val)){
        return head->next;
    }
    return head;
}
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st(nums.begin(),nums.end());
        return check(st,head);

    }
};