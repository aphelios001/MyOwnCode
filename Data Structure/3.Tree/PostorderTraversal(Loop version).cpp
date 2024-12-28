vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if(root==nullptr) return result;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
            //与前序遍历相比：改了两行的顺序+反转数组
            //如果栈是先放左再放右，遍历顺序就变成了根右左
            //最后result数组反转就变成了左右根
            if(node->left)
            {
                s.push(node->left);
            }
            if(node->right)
            {
                s.push(node->right);
            }
            result.push_back(node->val);
        }
        reverse(result.begin(),result.end());//记得反转
        return result;
    }