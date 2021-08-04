
public class Solution {
    public TreeNode sortedArrayToBST(int[] num) {
        return buildTree(num, 0, num.length - 1);
    }
    public TreeNode buildTree(int[] num, int start, int end){
        if(start > end)
            return null;
        int mid = start + (end - start) / 2;
        TreeNode root = new TreeNode(num[mid]);
        root.left = buildTree(num, start, mid - 1);
        root.right = buildTree(num, mid + 1, end);
        return root;
    }
}