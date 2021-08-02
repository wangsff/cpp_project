/**
 * 看labuladong的滑动窗口模板
 * 遇到子串问题要想着用滑动窗口
 * 思路：用一个map记录子串t中每个字符要求的次数，用另一个map记录当前窗口中满足子串中字符的个数
 * 主要改变的就是在规定窗口左侧什么时候收缩
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//leetcode 76
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> need;   //记录子串t中需要字符的个数
        unordered_map<char, int> window; //记录当前窗口中 在子串中出现的字符个数
        for (char c : t)
            need[c]++; //统计子串字符个数
        int left = 0, right = 0;

        int start = 0, len = INT_MAX, vaild = 0;
        while (right < s.size())
        {
            char c = s[right]; //右侧即将加入窗口的字符
            right++;
            if (need.count(c))
            { //如果当前字符在need中 才记录
                window[c]++;
                if (need[c] == window[c])
                { //这个字符c的数量已经满足need了，因此就可以增加一个已完成的值
                    vaild++;
                }
            }

            while (vaild == need.size())
            { //当窗口以满足的值等于子串中所要求的所有值，一定是need.size() 不是 t.size()
                if (right - left < len)
                {
                    start = left;
                    len = right - left;
                }
                char del = s[left]; //左侧窗口即将删除的字符
                left++;
                if (need.count(del))
                {   //删除字符在need中
                    //将window中该字符的个数减一
                    if (window[del] == need[del])
                    { //当window中该字符的个数已经不满足need的需求了，那么就减少一个已完成值
                        window[del]--;
                        vaild--;
                    }
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};