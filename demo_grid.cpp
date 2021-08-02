
#include<iostream>
#include<windows.h>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<math.h>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<functional>
#include<unordered_set>


using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL),right(NULL){}
};

TreeNode* buildTree(vector<int>nodeList){  //层次遍历构造二叉树，用int构造，用INT_MAX表示空
    TreeNode* root = new TreeNode(nodeList[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i=1;
    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        if(i<nodeList.size()){
            if(nodeList[i]!= INT_MAX){
                tmp->left = new TreeNode(nodeList[i]);
                q.push(tmp->left);
            }
            i++;
        }
        if(i<nodeList.size()){
            if(nodeList[i] != INT_MAX){
                tmp->right = new TreeNode(nodeList[i]);
                q.push(tmp->right);
            }
            i++;
            
        }
    }
    return root;
}

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
// class Solution {
// public:
//     TreeNode* Convert(TreeNode* pRootOfTree)
//     {
//         if(pRootOfTree==nullptr)return nullptr;
//         TreeNode* pre = nullptr;
//         midOrder(pRootOfTree, pre);
//         TreeNode* head = pRootOfTree;
//         return head;
        
//     }
//     void midOrder(TreeNode* root,TreeNode* pre ){
//         if(root==nullptr)return;
//         midOrder(root->left, pre);
//         root->left = pre;
//         if(pre)pre->right = root;
//         pre = root;
//         midOrder(root->right, pre);
//     }
// };
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot)return nullptr;
        midOrder(pRoot, k);
        return ans;
    }
    TreeNode* midOrder(TreeNode* p, int k){
        if(p==nullptr)return nullptr;
        midOrder(p->left, k);
        count++;
        if(count == k)ans = p;
        midOrder(p->right, k);
        
    }

private:
    int count = 0;
    TreeNode* ans = nullptr;
};

int main(){
    
//    Solution s = Solution();
//    vector<vector<int>>  board;
//    vector<int> a0 = {1,1,0};
//    vector<int> a1 = {1,1,0};
//    vector<int> a2 = {0,0,1};
//    vector<char> a3 = {'0','0','0','0','0'};
//    vector<int> a4 = {0,0,1,1,1,0,1,1,1,1};
//    vector<int> a5 = {1,0,1,1,1,1,1,1,1,1};
//    vector<int> a6 = {1,1,1,1,0,1,0,1,0,1};
//    vector<int> a7 = {0,1,0,0,0,1,0,0,1,1};
//    vector<int> a8 = {1,1,1,0,1,1,0,1,0,1};
//    vector<int> a9 = {1,0,1,1,1,0,1,1,1,0};
//    board.push_back(a0);
//    board.push_back(a1);
//    board.push_back(a2);
//    board.push_back(a3);
//    board.push_back(a4);
//    board.push_back(a5);
//    board.push_back(a6);
//    board.push_back(a7);
//    board.push_back(a8);
//    board.push_back(a9);

    // vector<vector<int>> matrix;
    // vector<int> b0 = {1,2,3,4};
    // vector<int> b1 = {5,6,7,8};
    // vector<int> b2 = {9,10,11,12};
    // vector<int> b3 = {13,14,15,16};
    // vector<int> b4 = {17,18,19,20};
    // matrix.push_back(b0); 
    // matrix.push_back(b1);
    // matrix.push_back(b2);
    // matrix.push_back(b3);
    // matrix.push_back(b4);
    vector<int> nodeList = {5,3,7,2,4,6,8};
    TreeNode*head = buildTree(nodeList);

    Solution s = Solution();
    auto ans = s.KthNode(head, 2);
    cout<<ans->val;
    
    


    system("pause");
    return 0;
}
