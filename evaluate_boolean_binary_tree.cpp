class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (!root) return false;  // Return false if the root is NULL
        if (root->val == 0) return false;  // Return false if the node is 0
        if (root->val == 1) return true;  // Return true if the node is 1
        bool right = evaluateTree(root->right);  // Recursively evaluate the right child
        bool left = evaluateTree(root->left);  // Recursively evaluate the left child
        if (root->val == 2) return right || left;  // Return the OR of the children if the node is 2
        if (root->val == 3) return right && left;  // Return the AND of the children if the node is 3
        return false;  // Return false as a default case
    }
};