class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> stack;
        int i = 0;
        while(i < traversal.length()) {
            int level = 0, val = 0;
            while(traversal[i] == '-') {
                i++;
                level++;
            }
            while(i < traversal.length() && traversal[i] != '-') {
                val = val*10 + traversal[i] - '0';
                i++;
            }

            TreeNode* node = new TreeNode(val);
            while(stack.size() > level) stack.pop_back();
            if(!stack.empty()) {
                if(!stack.back()->left) stack.back()->left = node;
                else stack.back()->right = node;
            }
            stack.push_back(node);
        }
        return stack[0];
    }
};
