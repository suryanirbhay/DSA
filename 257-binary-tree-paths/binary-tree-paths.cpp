class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        string path = "";
        dfs(root, path, result);
        return result;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;

        if (!path.empty()) {
            path += "->";
        }
        path += to_string(node->val);

        
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }

       
        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }
};
