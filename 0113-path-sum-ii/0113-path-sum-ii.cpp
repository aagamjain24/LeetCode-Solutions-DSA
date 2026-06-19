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
vector<vector<int>>solve(TreeNode* root, int target,vector<int>res,vector<vector<int>>&ans){
    if(root==NULL) return ans;

     res.push_back(root->val);
    if(root->left==NULL && root->right==NULL && root->val==target){
        ans.push_back(res);

    }
    else if(root->left==NULL && root->right==NULL && root->val!=target){
        res.pop_back();
    }

    solve(root->left,target-root->val,res,ans);
    solve(root->right,target-root->val,res,ans);

    return ans;

}
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>>ans;
        vector<int>res;
       return  solve(root,target,res,ans);
    }
};