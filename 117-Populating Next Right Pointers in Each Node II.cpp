/*Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    Recursive approach is fine, implicit stack space does not count as extra space for this problem.

Example:

Given the following binary tree,

     1
   /  \
  2    3
 / \    \
4   5    7

After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
    }
};


// 填充任意二叉树的每个结点的右向指针  [M]
// DFS ; Levelorder traversal


// 法一：递归法
// 关键点：
// 1) 需对左孩子和右孩子找到正确的连接对象。
// 为此，用一个指针p记录当前根节点的右孩子将要连接的对象（若右孩子不存在，则p是左孩子（若存在的话）的连接对象）
// 2) 递归调用的时候先递归创建右子树，然后递归创建左子树。具体原因看以下示例：
   		  2
       /     \
    4         3
   / \        / \
  0   7     9   1
 /   / \       / \
5  12  6      8   11
       /
     10

// 关键在里面的7和9节点，由于9没有子节点，如果我们先递归左子节点，那么当递归到节点7时，右边节点9的next还没有连上右边的节点1，
// 那么节点7的右子节点6的next就只能NULL, 而并非右边的节点8，这就出错了。而如果我们先递归右子节点，就不会有这个问题。

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) 
        	return;
        TreeLinkNode *p = root->next;
        while (p) 
        {
            if (p->left) 
            {
                p = p->left;
                break;
            }

            if (p->right) 
            {
                p = p->right;
                break;
            }
            p = p->next;
        }
        if (root->right) 
        	root->right->next = p; 
        if (root->left) 
        	root->left->next = root->right ? root->right : p; 
        connect(root->right);
        connect(root->left);
    }
};


// 法二：空间复杂度为O(1)的解法
// 思路：使用一个dummy结点来指向每层的首结点的前一个结点，然后指针t用来遍历这一层，建立这一层的连接关系：
// 首先从根结点开始，如果左子结点存在，那么t的next连上左子结点，然后t指向其next指针；如果root的右子结点存在，那么t的next连上右子结点，然后t指向其next指针。
// 此时root的左右子结点都连上了，此时root向右平移一位，指向其next指针，如果此时root不存在了，说明当前层已经遍历完了，我们重置t为dummy结点，root此时为dummy->next，
// 即下一层的首结点，然后dummy的next指针置空。
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *dummy = new TreeLinkNode(0), *t = dummy;
        while (root) {
            if (root->left) {
                t->next = root->left;
                t = t->next;
            }
            if (root->right) {
                t->next = root->right;
                t = t->next;
            }
            root = root->next;
            if (!root) {
                t = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
    }
};


// 法三：基于层次遍历的实现，使用队列。此法可直接使用与"116-Populating Next Right Pointers in Each Node"同样的方法。
// 空间复杂度为O(n).
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                TreeLinkNode *t = q.front(); q.pop();
                if (i < len - 1) t->next = q.front();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
    }
};