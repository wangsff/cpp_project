/**
 * 本文件是记录与树有关的一些操作
*/
#include <algorithm>

// 树的一些定义
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//计算树的深度,
int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    int count = 1; //由第一层开始计数
    return count + std::max(maxDepth(root->left), maxDepth(root->right));
}