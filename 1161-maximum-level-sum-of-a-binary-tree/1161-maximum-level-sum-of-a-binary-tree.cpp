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
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int level = 0;
        queue<TreeNode*>q;
        q.push(root);
        int max_sum = INT_MIN;
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            level ++;
            int sum = 0;
            for(int i=0; i<s; i++){
                TreeNode* ele = q.front();
                q.pop();
                sum+=(ele->val);
                if(ele->left != nullptr) q.push(ele->left);
                if(ele -> right != nullptr) q.push(ele -> right);
            }
            if(sum > max_sum){
                max_sum = sum;
                ans = level;
            }
        }
        return ans;
    }
};