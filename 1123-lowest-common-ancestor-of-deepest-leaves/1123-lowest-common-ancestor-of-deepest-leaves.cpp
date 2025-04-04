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
private:
    vector<TreeNode*>vec; 
    int height(TreeNode*root){
        if(!root)return 0;

        return 1+max(height(root->left),height(root->right));
    }

    bool leaf(TreeNode*root){  
        if(!root->left and !root->right)return true;
        return false;
    }

    void nodes(TreeNode*root,int h,int maxh){ 
        if(!root)return;
        if(leaf(root) and h==maxh)vec.push_back(root);
        nodes(root->left,h+1,maxh);
        nodes(root->right,h+1,maxh);
    }

  TreeNode* solve(TreeNode*root){  
      if(!root)return NULL;
        for(auto&it:vec){ 
            if(root==it)return root;
        }
        TreeNode*l=solve(root->left);
        TreeNode*r=solve(root->right);

            if(l and r)return root;
            else if(!r and l)return l;
            else if(!l and r)return r;
            else return NULL;
            
  }  
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int h=height(root);
        nodes(root,1,h);
        return solve(root);
    }
};