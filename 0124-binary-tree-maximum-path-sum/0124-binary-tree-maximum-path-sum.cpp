/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int check(TreeNode* node,int&maxi){
        if(node==NULL){
            return 0;
        }
        int l=max(0,check(node->left,maxi));
        int r=max(0,check(node->right,maxi));
        maxi=max(maxi,l+r+node->val);
        return max(l,r)+node->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        check(root,maxi);
        return maxi;

        
    }
};