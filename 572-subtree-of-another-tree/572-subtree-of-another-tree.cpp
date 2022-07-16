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
public:

    bool isIdentical(TreeNode* root, TreeNode* subRoot){
        
        // base case
        if (root == NULL && subRoot == NULL){
            return true;
        }
        
        if(root == NULL && subRoot != NULL){
            return false;
        }
        
        if(root != NULL && subRoot == NULL){
            return false;
        }
        
        bool left = isIdentical(root->left,subRoot->left);
        bool right = isIdentical(root->right,subRoot->right);
        
        bool value = root->val == subRoot->val;
        
        if(left && right && value){
            return true;
        }
        else{
            return false;
        }
        
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
       // base case
        if (subRoot == NULL){
            return true;
        }
        
        if(root == NULL){
            return false;
        }
        
        if(isIdentical(root,subRoot)){
            return true;
        }
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};