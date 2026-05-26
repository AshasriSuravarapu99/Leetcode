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
    unordered_map<int,int>m;
    int postIdx;
    TreeNode* build(vector<int>& postorder, int left, int right){
        if(left > right) return nullptr;

        TreeNode* root = new TreeNode(postorder[postIdx]);
        int mid = m[postorder[postIdx]];
        postIdx--;

        root->right = build(postorder,mid+1,right);
        root->left = build(postorder,left,mid-1);

        return root;

        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        postIdx = postorder.size()-1;
        return build(postorder,0,inorder.size()-1);
    }
};