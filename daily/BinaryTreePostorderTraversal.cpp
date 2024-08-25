//----------------------------------------------- USING RECURSION ---------------------------------------
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }

private:
    void postorder(TreeNode* root,vector<int>& res){
        if(root==nullptr)
        return;
        postorder(root->left,res);
        postorder(root->right,res);
        res.push_back(root->val);
    }
};

//----------------------------------------------- ITERATIVE METHOD ---------------------------------------
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr)
        return {};

        vector<int> res;
        stack<TreeNode*> nodes{{root}};

        while(!nodes.empty()){
            root = nodes.top(), nodes.pop();
            res.push_back(root->val);
            if(root->left)
            nodes.push(root->left);
            if(root->right)
            nodes.push(root->right);
        }

        ranges::reverse(res);
        return res;
    }

};
