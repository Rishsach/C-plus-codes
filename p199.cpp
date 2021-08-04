class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return ArrayToBST(nums,0,nums.size()) ;
    }
 
    TreeNode* ArrayToBST(vector<int>& nums,int start,int end){
        if(start>=end)
            return NULL ;
         
        int mid=(start+end)/2 ;
        TreeNode* node=new TreeNode(nums[mid]) ;
     
        node->left= ArrayToBST(nums,start,mid) ;
        node->right= ArrayToBST(nums,mid+1,end) ;
     
        return node ;
    }
};