class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        GetNodes(root, nodes); 
        return MakeBalance(nodes, 0, nodes.size()-1);
    }
private:
    TreeNode* MakeBalance(vector<int>& nodes, int left, int right){
        int mid = ( left + right ) / 2;
        TreeNode* new_root = new TreeNode( nodes[mid] );
        new_root->left = left < mid ? MakeBalance( nodes, left, mid-1) : nullptr;
        new_root->right = mid < right ? MakeBalance( nodes, mid+1, right) : nullptr;
        return new_root;
    }
    
    void GetNodes(TreeNode* root, vector<int>& nodes){ 
        if( !root ) return;
        if( root->left ) GetNodes( root->left, nodes);
        nodes.push_back( root->val );
        if( root->right ) GetNodes( root->right, nodes);
    }
};