class Solution {
 public:
  void flatten(TreeNode* root) {
    if (!root)
      return;

    while (root) {
      if (root->left) {

        TreeNode* rightmost = root->left;
        while (rightmost->right)
          rightmost = rightmost->right;
        
        rightmost->right = root->right;
        root->right = root->left;
        root->left = nullptr;
      }
      
      root = root->right;
    }
  }
};