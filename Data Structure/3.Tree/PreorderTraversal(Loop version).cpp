vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if(root==nullptr) return result;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
            if(node->right)//不为空的时候才放
            {
                s.push(node->right);//进栈先放右再放左，出栈的时候才是先出左再出右
            }
            if(node->left)
            {
                s.push(node->left);
            }
            result.push_back(node->val);
        }
        return result;
    }