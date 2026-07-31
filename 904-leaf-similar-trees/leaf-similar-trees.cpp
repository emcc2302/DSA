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

void getLeaves(TreeNode* root, vector<int>& leaves){
    if(root==nullptr) return;

    if(root->left == nullptr && root->right==nullptr){
        leaves.push_back(root->val);
        return;
    }
     getLeaves(root->left, leaves);
     getLeaves(root->right, leaves);
}
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      vector<int> leaf1;
        vector<int> leaf2;

        getLeaves(root1, leaf1);
        getLeaves(root2, leaf2);

        return leaf1 == leaf2;
    }
};