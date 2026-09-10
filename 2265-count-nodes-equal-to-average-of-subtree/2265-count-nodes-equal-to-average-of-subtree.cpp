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
    void avg(TreeNode*root,int &sum,int&cnt){
        sum+=root->val;
        if(root->left) {
            cnt++;
            avg(root->left,sum,cnt);
        }
        if(root->right){
            cnt++;
            avg(root->right,sum,cnt);
        }
        return;

    }
    void func(TreeNode* root, int & ans){
        // basic traversal.
        int sum = 0;
        int cnt = 1;
        avg(root,sum,cnt);
        if((sum/cnt) == root->val) ans++;
        if(root->left) func(root->left,ans);
        if(root->right) func(root->right,ans);
        return ;
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        func(root, ans);
        return ans;
    }
};