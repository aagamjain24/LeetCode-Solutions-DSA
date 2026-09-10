class Solution {
public:
    int ans = 0;

    pair<int,int> solve(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        auto L = solve(root->left);
        auto R = solve(root->right);

        int sum = L.first + R.first + root->val;
        int cnt = L.second + R.second + 1;

        if (sum / cnt == root->val)
            ans++;

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};