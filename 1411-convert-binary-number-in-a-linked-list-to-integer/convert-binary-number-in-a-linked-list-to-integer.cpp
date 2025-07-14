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
    int getDecimalValue(ListNode* head) 
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;

 
        while (curr != nullptr) 
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        int sum = 0;
        int power = 0;
        while (prev != nullptr) 
        {
            sum += (prev->val) * pow(2, power);
            prev = prev->next;
            power++;
        }

        return sum;
    }
};