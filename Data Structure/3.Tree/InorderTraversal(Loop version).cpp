vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if(root==nullptr) return result;
        TreeNode *cur = root;
        //中序遍历 左根右
        //不是很好理解
        while( !(cur == nullptr && s.empty()) )//只有 栈为空 而且 cur为空 的时候才退出迭代
        {
            if(cur != nullptr)//先处理 cur当前指向的结点 的左边的节点，直到左端为空
            {
                s.push(cur);//将其入栈
                cur = cur->left;//去左边看看
            }
            else
            {
                cur = s.top();//第一次到第15行代码的时候，栈顶一定是最左端的元素
                s.pop();//出栈
                result.push_back(cur->val);//将其放入result数组
                cur = cur->right;//去右边看看
                //处理右边的节点，如果右边为空，那么下次迭代将会执行17行的代码，
                //把中间的节点加入result数组
            }
        }
        return result;
    }