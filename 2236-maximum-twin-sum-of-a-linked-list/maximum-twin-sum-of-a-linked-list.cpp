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
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        vector<int>v(n);
        temp=head;
        for(int i=0;i<n;i++){
            v[i]=temp->val;
            temp=temp->next;

        }
        int maxsum=0;
        for(int i=0;i<n/2;i++){
            maxsum=max(maxsum,v[i]+v[n-1-i]);
        }
        return maxsum;
    }
};