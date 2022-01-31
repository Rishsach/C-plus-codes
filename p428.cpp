class Solution {
 public:
  Node* connect(Node* root) {
    Node* node = root;  

    while (node) {
      Node dummy(0);  
      for (Node* needle = &dummy; node; node = node->next) {
        if (node->left) {  
          needle->next = node->left;
          needle = needle->next;
        }
        if (node->right) {  
          needle->next = node->right;
          needle = needle->next;
        }
      }
      node = dummy.next;  
    }

    return root;
  }
};
