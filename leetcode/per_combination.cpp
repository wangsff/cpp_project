
//本代码实现了输入一个数字串，输出指定位数的全排列功能

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void permutation(const vector<int> digit, int depth, int l, vector<bool> used, vector<int> &cur, vector<vector<int>> &ans);
// digit输入数字串，depth递归深度，l是要求的几位数
void combination(const vector<int> digit, int depth, int l, int s, vector<int> &cur, vector<vector<int>> &ans);

int main()
{
    string s;
    cin >> s;
    vector<int> digits;
    for (int i = 0; i < s.length(); ++i)
    {
        digits.push_back(s[i] - '0');
    }
    vector<vector<int>> ans;
    vector<int> cur;
    vector<bool> used(digits.size(), false);

    //permutation(digits, 0, 4, used, cur, ans);
    combination(digits, 0, 2, 0, cur, ans);

    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[0].size(); ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}

void permutation(const vector<int> digit, int depth, int l, vector<bool> used, vector<int> &cur, vector<vector<int>> &ans)
{
    if (depth == l)
    {
        ans.push_back(cur);
        return;
    }

    for (int i = 0; i < digit.size(); ++i)
    {
        if (used[i])
            continue;
        { //这个作用域块可以保证剔除掉重复元素构成的排列
            int flag = 0;
            if (i > 0)
            {
                int t = i - 1;
                for (t; t >= 0; --t)
                {
                    if (digit[t] == digit[i] && used[t] == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1)
                continue
            /**
             * 更简单的方法是，先将digit排序，那么判断是否重复就是 if(i>0 && digit[i-1] == digit[i] && used[i-1] == 0)
             * 那么就跳过
            */
        }

        used[i] = true;
        cur.push_back(digit[i]);
        permutation(digit, depth + 1, l, used, cur, ans);
        cur.pop_back();
        used[i] = false;
    }
}

void combination(const vector<int> digit, int depth, int l, int s, vector<int> &cur, vector<vector<int>> &ans)
{
    if (depth == l) //这里并不一定要等于深度，而是可以设置个什么target==0来得到和为target的组合leetcode39 40
    {
        ans.push_back(cur);
        return;
    }

    for (int i = s; i < digit.size(); ++i)
    {
        if (i > s && digit[i] == digit[i - 1])
            continue; //去除重复，简直牛批！！！,不过也可以用上面那个先排序后判断相邻来做
        cur.push_back(digit[i]);
        combination(digit, depth + 1, l, i, cur, ans); //如果是i+1的话，不允许重复，如果是i的话，允许重复
        cur.pop_back();
    }
}

//去重写法
void combination(const vector<int> digit, int depth, int l, int s, vector<int> &used, vector<int> &cur, vector<vector<int>> &ans)
{
    //加入used来判断前面的数是否循环过，跟permutation去重一个思路
    if (l == depth)
    {
        ans.push_back(cur);
        return;
    }
    for (int i = s; i < digit.size(); ++i)
    {
        { //去重代码块
            int flag = 0;
            if (i > 0)
            {
                for (int t = i - 1; t >= 0; --t)
                {
                    if (digit[t] == digit[i])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1)
                continue;
        }

        used[i] = 1;
        cur.push_back(digit[i]);
        combination(digit, depth + 1, l, i + 1, used, cur, ans);
        used[i] = 0;
        cur.pop_back();
    }
}