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
    int findl(TreeNode*node){
        int h=0;
        while(node){
            h++;
            node=node->left;
        }
        return h;
    }
    int findr(TreeNode*node){
        int h=0;
        while(node){
            h++;
            node=node->right;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int l=findl(root);
        int h=findr(root);
        if(l==h) return((1<<l)-1);
        return(1+countNodes(root->left)+countNodes(root->right));

    }

};