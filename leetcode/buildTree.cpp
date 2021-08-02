/**
 * 这个文件实现了建树的函数，用于模拟leetcode中输入的树
 * 输入：树层次遍历的序列
 * 输出：buildTree()函数构造出对应的树
 * 输出：levelTraversal()函数层次遍历树
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> nums)
{
    TreeNode *head = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    q.push(head);
    int i = 1;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (i >= nums.size())
            break;
        node->left = new TreeNode(nums[i++]);
        q.push(node->left);
        if (i >= nums.size())
            break;
        node->right = new TreeNode(nums[i++]);
        q.push(node->right);
    }
    return head;
}

vector<int> levelTraversal(TreeNode *head)
{ // 层次遍历
    queue<TreeNode *> q;
    vector<int> ans;
    q.push(head);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        ans.push_back(node->val);
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }

    return ans;
}

int main()
{
    string str;
    cout << "please input the tree node sequeue " << endl;
    cin >> str;
    vector<int> sequeue;
    for (char c : str)
    {
        sequeue.push_back(c - '0');
    }
    TreeNode *head = buildTree(sequeue);
    auto ls = levelTraversal(head);
    for (int i : ls)
        cout << i << " ";
}