/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root) return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL) s+="#,";
            else s+=to_string(node->val)+',';
            if(node!=NULL){
            q.push(node->left);
            q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        queue<TreeNode*>q;
        TreeNode* node=new TreeNode(stoi(str));
        q.push(node);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#") curr->left=NULL;
            else  {
                TreeNode* newnode=new TreeNode(stoi(str));
                curr->left=newnode;
                q.push(newnode);
                
            }
            
             getline(s,str,',');
            if(str=="#") curr->right=NULL;
            else  {
                 TreeNode* newnode=new TreeNode(stoi(str));
                curr->right=newnode;
                q.push(newnode);
            }
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));