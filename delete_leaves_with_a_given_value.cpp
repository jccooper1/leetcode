class Solution {
public:
    bool is_leaf(TreeNode*root){
        if(root==NULL) return false;
        return (!root->left and !root->right);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return NULL;
        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right,target);
        if(is_leaf(root) and root->val==target) return NULL;
        return root;
    }
};