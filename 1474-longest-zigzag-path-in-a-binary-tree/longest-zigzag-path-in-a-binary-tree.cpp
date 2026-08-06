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
    int ans=0;

    void dfs(TreeNode* node,bool dir , int len){
        if(!node) return;
        ans=max(ans,len);

        if(dir){
            //mtlb phle right jyenge fir len+1 krke dir false krdenge taki left sai suru ho sake
             dfs(node->right, false, len + 1);
             dfs(node->left, true, 1);
        }else{
            dfs(node->left, true, len + 1);
            dfs(node->right, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
         if (!root) return 0;

        dfs(root->left, true, 1);   // First move is left
        dfs(root->right, false, 1); // First move is right

        return ans;
    }
};