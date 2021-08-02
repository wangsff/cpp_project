/**
 * 本文件记录一些常用的，但是具有干扰性的算法（比方说边界问题）
*/
#include <iostream>
#include <vector>

using namespace std;

//最大公约数问题
int findMaxCommon(int a, int b)
{
    if (a == b)
        return a;
    int bigger = a > b ? a : b;
    int small = a < b ? a : b;
    if (bigger % small == 0)
        return small;
    return findMaxCommon(bigger - small, small);
}
