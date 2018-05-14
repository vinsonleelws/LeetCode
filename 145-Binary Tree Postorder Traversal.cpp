Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]

Follow up: Recursive solution is trivial, could you do it iteratively?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> result;
        postoderTraversalDFS(root, result);
        return result;
    }
    
    void postoderTraversalDFS(TreeNode* root, vector<int>& result)
    {
        if(root->left)
            postoderTraversalDFS(root->left, result);
        if(root->right)
            postoderTraversalDFS(root->right, result);
        result.push_back(root->val);        
    }
};

// Iterative

// #1
// 反向加入vector的解法
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s{{root}};
        while (!s.empty()) 
        {
            TreeNode *t = s.top(); 
            s.pop();
            res.insert(res.begin(), t->val);
            if (t->left) s.push(t->left);
            if (t->right) s.push(t->right);
        }
        return res;
    }
};


// #2
// 在Binary Tree Preorder Traversal中的解法二也可以改动一下变成后序遍历，改动的思路跟上面的解法一样，都是先将先序遍历的根-左-右顺序变为根-右-左，再翻转变为后序遍历的左-右-根，
// 翻转还是改变结果res的加入顺序，然后把更新辅助结点p的左右顺序换一下即可。
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (!s.empty() || p) 
        {
            if (p) 
            {
                s.push(p);
                res.insert(res.begin(), p->val);
                p = p->right;
            } 
            else 
            {
                TreeNode *t = s.top(); 
                s.pop();
                p = t->left;
            }
        }
        return res;
    }
};

// #3
// 双栈的解法，其实本质上跟#1没什么区别，都是利用了改变先序遍历的顺序来实现后序遍历的
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            TreeNode *t = s1.top(); s1.pop();
            s2.push(t);
            if (t->left) s1.push(t->left);
            if (t->right) s1.push(t->right);
        }
        while (!s2.empty()) {
            res.push_back(s2.top()->val); s2.pop();
        }
        return res;
    }
};


// #4
// 其它解法：
// 们先将根结点压入栈，然后定义一个辅助结点head，while循环的条件是栈不为空，在循环中，首先将栈顶结点t取出来，如果栈顶结点没有左右子结点，或者其左子结点是head，
// 或者其右子结点是head的情况下。我们将栈顶结点值加入结果res中，并将栈顶元素移出栈，然后将head指向栈顶元素；否则的话就看如果右子结点不为空，将其加入栈，再看左
// 子结点不为空的话，就加入栈，注意这里先右后左的顺序是因为栈的后入先出的特点，可以使得左子结点先被处理。下面来看为什么是这三个条件呢，首先如果栈顶元素如果没有
// 左右子结点的话，说明其是叶结点，而且我们的入栈顺序保证了左子结点先被处理，所以此时的结点值就可以直接加入结果res了，然后移出栈，将head指向这个叶结点，这样的话
// head每次就是指向前一个处理过并且加入结果res的结点，那么如果栈顶结点的左子结点或者右子结点是head的话，说明其子结点已经加入结果res了，那么就可以处理当前结点了。
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s{{root}};
        TreeNode *head = root;
        while (!s.empty()) {
            TreeNode *t = s.top();
            if ((!t->left && !t->right) || t->left == head || t->right == head) {
                res.push_back(t->val);
                s.pop();
                head = t;
            } else {
                if (t->right) s.push(t->right);
                if (t->left) s.push(t->left);
            }
        }
        return res;
    }
};