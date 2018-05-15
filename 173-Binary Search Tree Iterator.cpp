Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        
    }

    /** @return the next smallest number */
    int next() {
        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 
//----------------------------------------------------------

// 这道题实际上是BST的非递归中序遍历，使用栈来实现。
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(s.size())
            return true;
        else
            return false;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* n = s.top();
        s.pop();
        int v = n->val;
        if(n->right)
        {   
           n = n->right;
           while(n)
           {
               s.push(n);
               n = n->left;
           }
        }
        return v;
    }
    
private:
    stack<TreeNode*> s;
};