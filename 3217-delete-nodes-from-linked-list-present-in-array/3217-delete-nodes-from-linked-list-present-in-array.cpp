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
        set<int> s;
        for (int i : nums) {
            s.insert(i);
        }
        ListNode* dn = new ListNode(-1);
        dn->next = head;
        ListNode* temp = dn;
        while (temp->next) {
            if (s.find(temp->next->val) != s.end()) {
                ListNode* d = temp->next;
                temp->next = temp->next->next;
                delete (d);

            } else {
                temp = temp->next;
            }
        }
        return dn->next;
    }
};