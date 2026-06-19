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
vector<vector<int>>solve(TreeNode* root, vector<vector<int>>&ans){
    if(root==NULL) return ans;
    queue<TreeNode*>q;
    q.push(root);
    bool flag=true;
    while(!q.empty()){
        flag=!flag;
        vector<int>res;
        int size=q.size();
      
        for(int i=0;i<size;i++){
              TreeNode* node = q.front();
              q.pop();
              res.push_back(node->val);
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
  }
  if(flag){
    reverse(res.begin(),res.end());
    }
  ans.push_back(res);
    }
    return ans;
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
      return solve(root,ans);
    }
};