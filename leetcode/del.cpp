
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


using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int> bucket(4, 0);
        vector<int> used(4, 0);
        vector<int> v_index(s.size(), 0);
        bucket[0] = s[0]-'0';
        fill_bucket(s, 1, bucket, ans, v_index, used);
        return ans;

    }

    void fill_bucket(string s, int index, vector<int> bucket, vector<string>& ans, vector<int> v_index, vector<int> used){
        int sum = 0;
        for(int i=0; i<4; ++i){
            sum += used[i];
        }
        if(index == s.length()){
             if(sum == 4){
                    string tmp;
                for(int i=0; i<4; ++i){
                    tmp += to_string(bucket[i]);
                    tmp += '.';
                }
                tmp.pop_back();
                ans.push_back(tmp);
            }
            return;
            
        }

        for(int i=0; i<4; ++i){
            if(v_index[index-1]>i)continue;
            int v = s[index]-'0';
            if(bucket[i]*10+v <= 255){
                int tmp = bucket[i];
                int tmp2 = v_index[index];
                int tmp3 = used[i];
                bucket[i] = bucket[i]*10 + v;
                v_index[index] = i;
                used[i] = 1;
                fill_bucket(s, index+1, bucket, ans, v_index, used);
                used[i] = tmp3;
                v_index[index] = tmp2;
                bucket[i] = tmp;
            }
        }
    } 
};



int main(){
    
//    Solution s = Solution();
//    vector<vector<int>>  board;

//    vector<int> a0 = {0,0,1,0,1,1,1,0,1,1};
//    vector<int> a1 = {1,1,1,1,0,1,1,1,1,1};
//    vector<int> a2 = {1,1,1,1,1,0,0,0,1,1};
//    vector<int> a3 = {1,0,1,0,1,1,1,0,1,1};
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

    //vector<vector<int>> matrix;
//    vector<int> b0 = {1,2,3};
//    vector<int> b1 = {0,0,0};
//    vector<int> b2 = {7,6,5};
//    vector<int> b3 = {1,0,1,0,1};
//    vector<int> b4 = {0,0,1,1,1};
//    matrix.push_back(b0); 
//    matrix.push_back(b1);
//    matrix.push_back(b2);
//    matrix.push_back(b3);
//    matrix.push_back(b4);

   
    string str = "2222";
    Solution s = Solution();
    vector<string> ans = s.restoreIpAddresses(str);
    for(int i=0; i<ans.size(); ++i){
        cout<<ans[i]<<endl;
    } 

    system("pause");
    return 0;
}
