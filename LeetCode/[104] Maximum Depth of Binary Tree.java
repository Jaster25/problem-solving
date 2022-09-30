import java.util.*;
 
class Solution {
    public int maxDepth(TreeNode root) {       
        
        int depth = 0;
        if (root == null) {
            return depth;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        
        while (!queue.isEmpty()) {
            depth++;
            int queueSize = queue.size();
            for (int i = 0 ; i < queueSize ; i++) {
                TreeNode node = queue.poll();
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
        }
        
        return depth;
    }
}