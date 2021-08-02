#include<iostream>
#include<windows.h>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<math.h>
#include<algorithm>
#include<map>
#include<stack>
#include<unordered_map>
#include<functional>
#include<unordered_set>


using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode(int x):val(x), left(NULL),right(NULL), next(NULL){}
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


void preorderTraversalNew(TreeNode *root, vector<int> &path)
{
    stack< pair<TreeNode *, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while(!s.empty())
    {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if(root == NULL)
            continue;
        if(visited)
        {
            path.push_back(root->val);
        }
        else
        {
            s.push(make_pair(root->right, false));
            s.push(make_pair(root->left, false));
            s.push(make_pair(root, true));
        }
    }
}


void inorderTraversalNew(TreeNode*root, vector<int>&path){
    if(!root)return;
    stack<pair<TreeNode*, bool>>s;
    bool visited;
    s.push({root, false});
    while(!s.empty()){
        auto tmp = s.top();
        s.pop();
        root = tmp.first;
        visited  = tmp.second;
        if(root == NULL){
            continue;
        }
        if(visited){
            path.push_back(root->val);
        }
        else{
            s.push({root->right, false});
            s.push({root, true});
            s.push({root->left, false});
        }
    }
}

void postorderTraversalNew(TreeNode*root, vector<int>& path){
    if(!root)return;
    stack<pair<TreeNode*, bool>>s;
    bool visited;
    s.push({root, false});
    while(!s.empty()){
        auto tmp = s.top();
        s.pop();
        root = tmp.first;
        visited = tmp.second;
        if(root == NULL){
            continue;
        }
        if(visited){
            path.push_back(root->val);
        }
        else{
            s.push({root, true});
            s.push({root->right, false});
            s.push({root->left, false});
        }
    }
}





int main(){
    vector<int>nodelist = {8,6,10,5,7,9,11};
    TreeNode*head = buildTree(nodelist);

    vector<int>pre_ans;
    preorderTraversalNew(head, pre_ans);
    for(const auto a:pre_ans)cout<<a<<ends;
    cout<<endl;

    vector<int>in_ans;
    inorderTraversalNew(head, in_ans);
    for(const auto a:in_ans)cout<<a<<ends;
    cout<<endl;

    vector<int>post_ans;
    postorderTraversalNew(head, post_ans);
    for(const auto a:post_ans)cout<<a<<ends;
    cout<<endl;


    system("pause");
    return 0;
}