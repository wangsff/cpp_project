/**
 * 本文件实现了一些常用的搜索算法
*/

#include <iostream>
#include <vector>

using namespace std;
//二分搜索
int binSearch(vector<int> &nums, int target) //小于的情况，正确结果在nums[left]中
{
    if (nums.empty())
        return -1;
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        /*  当target>=mid时，right = mid-1，因此是寻找左边界
            正确结果在nums[left]中，left肯定在right的右边
        */
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << "i is " << left << endl;
    cout << "j is " << right << endl;
    //搜索左边界时，当target都<nums时，结果不存在，left == 0因此不用判断
    //但当target > nums时，left是nums.size()，因此一定要判断
    if (left < nums.size() && nums[left] == target)
        return nums[left];
    else
        return -1;
}

int binSearch2(vector<int> &nums, int target)
{
    if (nums.empty())
        return -1;
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)
        /*
            当target与mid相同时，仍然left++，因此寻找右边界
            正确结果在nums[right]中，且left = right + 1
        */
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << "i is " << left << endl;
    cout << "j is " << right << endl;
    //当target < nums时，right = -1, 因此要判断right
    if (right >= 0 && nums[right] == target)
        return target;
    else
        return -1;
}
/**
 * 两种二分搜索的总结
 * 1、不论是否有正确结果，跳出循环后j一定在i的左边，也就是j i的情况
 * 2、当没有正确结果时，两种搜索有相同之处
 *      当target大于所有的nums，那么结果是j在nums.size()-1处，i在nums.size()处
 *      当target小于所有的nums，那么结果是i在0处，j在-1处 
 *      当target并不存在于nums，但大小在nums中间时，按找得出的结果依据题意改写
 * 2、不同的是，当判断条件是 if(nums[mid] < target) left = mid + 1时，这是寻找左边边界，
 *      正确结果在nums[left]中
 * 3、当判断条件是 if(nums[mid] <= target) left = mid + 1时，这是寻找右边边界
 *      正确结果在nums[right]中
*/

//二分搜素，直接写死，i左边界，j右边界，整个边界左闭右开
//mid = i + (j-i)/2，当>=设置的阈值时j = mid，否则i=mid+1
//最后的输出的结果位置就是i，再根据i得出最终的结果
//典型题：leetcode 1539

int binSearch3(vector<int> &arr)
{
    if (arr.empty())
        return -1;
    int threshold;
    int i = 0, j = arr.size(); //左闭右开
    while (i < j)
    {
        int mid = i + (j - i) / 2; //防止溢出
        if (arr[mid] >= threshold)
            j = mid; // 大于等于的话 j动
        else
            i = mid + 1; //小于的话 i动
    }
    return i;
}
int main()
{
    vector<int> nums{1};
    cout << binSearch2(nums, 1);
}