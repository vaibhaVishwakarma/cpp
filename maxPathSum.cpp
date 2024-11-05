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
    typedef TreeNode node;
    int depthSum(node* root){
      if(!root) return 0;
      if(!root->left && !root->right) return root->val;
      if(root->left && !root->right) return max({root->val + depthSum(root->left) , root->val});
      if(!root->left && root->right) return max({root->val + depthSum(root->right) , root->val});
      return max({root->val + max(depthSum(root->left) , depthSum(root->right)) , root->val });
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        
        int l = depthSum(root->left);      
        int r = depthSum(root->right);    
          
        if(!root->left && root->right)
            return max({root->val , r + root->val, maxPathSum(root->right)});
        
        if(root->left && !root->right)
            return max({root->val , l + root->val , maxPathSum(root->left) });

        return max({root->val , l+root->val , r+root->val , l+r+root->val , maxPathSum(root->left) , maxPathSum(root->right)});
        
        
    }
};
