/**
 * 排序算法的稳定性
 * （不稳定）快选堆希
 * （稳定）插冒归基
*/

#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

/**
 * 快排必须从右开始的原因，如果从左开始错误的情况
 * 5 2 3 7 8
 * i到了7，j从8开始，也到了7，这时候i==j交换了5 和 7，发现错误
 * 交换后5左边的数应该都小于5，但此时7被交换到左边了
*/
void qsort(vector<int> &vec, int left, int right)
{
    if (left >= right)
        return;
    int i = left, j = right;
    int base = vec[left];
    while (i < j)
    {
        while (vec[j] >= base && i < j)
            j--;
        while (vec[i] <= base && i < j)
            ++i;
        if (i < j)
        {
            swap(vec[i], vec[j]);
        }
    }
    vec[left] = vec[i];
    vec[i] = base;
    qsort(vec, left, i - 1);
    qsort(vec, i + 1, right);
}

/**
 * 选择排序不稳定的原因
 * 比方 4 3 9 3 3
 * 第一遍的时候肯定是将9与末尾的3交换，这样就破坏了数字3的稳定性
 * 时间复杂度，不论数组有序性如何，每次都要进行比较遍历，因此最好最坏平均都是O(n2)
*/
void select(vector<int> &nums)
{
    for (int j = nums.size(); j > 0; --j)
    {
        int mmax = INT_MIN;
        int pos = -1;
        for (int i = 0; i < j; ++i)
        {
            if (nums[i] > mmax)
            {
                mmax = nums[i];
                pos = i;
            }
        }
        swap(nums[j - 1], nums[pos]);
    }
}

//删除堆只能删除堆顶元素，将堆顶元素与堆尾交换，自上而下调整
//加入元素，只能加入到堆的末尾，之后从末尾开始向上遍历，比较交换
/**
 * 有m个元素要排序，建立一个大小为m的堆，建堆时间为O(m)
 * 堆排序的时间按：每次调整堆是O(logn)，对于每个元素我们都将其与堆顶交换，因此总时间复杂度是O(nlogn)，额外空间复杂度为O(1)
 * 堆排序是不稳定的 比如3 2 2 2构建一个小根堆
 * 要把最后一个2 与 3交换，那么这时候就不稳定了
*/
class HeapSort
{
public:
    // void adjustHeap(vector<int>&vec, int cur, int length){ //cur是当前要调整的非叶子节点
    //     int curvalue = vec[cur];
    //     for(int k=2*cur+1; k<length; k=2*k+1){
    //         if(k+1<vec.length && vec[k+1]>vec[k]){//右节点值大于左节点
    //             k = k+1;
    //         }
    //         if(vec[k]>curvalue){
    //             vec[cur] = vec[k];
    //             cur = k;
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     vec[cur] = curvalue;
    // }
    void adjustHeap(vector<int> &arr, int cur, int length) //length是边界 不可取
    {
        /**
         * 升序排序建大根堆，降序排序建立小根堆
         * 从当前节点开始，与两个子节点比较交换，并将cur更新为与之交换的那个下标
        */
        for (int i = cur; i < length;)
        {
            int k = 2 * i + 1;
            if (k >= length)
                break;
            if (k + 1 < length && arr[k + 1] > arr[k])
            {
                k += 1;
            }
            if (arr[k] > arr[i])
            {
                swap(arr[k], arr[i]);
                i = k;
            }
            else
            {
                break;
            }
        }
    }
    vector<int> heapsort(vector<int> vec)
    {
        if (vec.size() <= 1)
            return vec;
        for (int i = (vec.size() / 2) - 1; i >= 0; --i)
        { //初始化构建最大堆，从最后一个非叶子节点开始调整
            adjustHeap(vec, i, vec.size());
        }
        //到现在已经是最大堆的格式
        //之后不断交换最后一个节点与根节点，交换排序
        for (int i = vec.size() - 1; i > 0; i--)
        {
            int tmp = vec[0];
            vec[0] = vec[i];
            vec[i] = tmp;
            adjustHeap(vec, 0, i);
        }
        return vec;
    }
};

/**
 * 插入排序，最好时间复杂度为正序，只循环外层，为O(n)，最坏情况为逆序，每放置一个数字都要比较前面所有，为O(n2)
 * 稳定
*/
void insert_Sort(vector<int> &nums)
{
    int i, j;
    int n = nums.size();
    for (int i = 1; i < n; ++i)
    {
        int tmp = nums[i];
        for (j = i; j > 0 && nums[j - 1] > tmp; --j)
        {
            nums[j] = nums[j - 1];
        }
        nums[j] = tmp;
    }
}

/**
 * 最好时间复杂度是正序，只需要一次冒泡为O(n)
 * 最坏时间复杂度是逆序，每次都需要冒泡为O(n2)
 * 稳定
*/
void bubblesort(int a[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        int flag = 0;
        for (int j = 0; j < length - i - 1; ++j) // 一次冒泡
        {                                        //选取后面的作为顺序的时候
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

/**
 * 归并排序将nums不断划分一半，一共能划分logn段
 * 每次归并的时候都是完全遍历一次为n
 * 总的时间复杂度为O(nlogn)
*/
class mergeSort
{
public:
    void merge(vector<int> &vec, int left, int mid, int right)
    {
        if (left >= right)
            return;
        vector<int> tmp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right)
        {
            if (vec[i] < vec[j])
                tmp.push_back(vec[i++]);
            else
            {
                tmp.push_back(vec[j++]);
            }
        }
        while (i <= mid)
            tmp.push_back(vec[i++]);
        while (j <= right)
            tmp.push_back(vec[j++]);
        for (int i = 0; i < tmp.size(); ++i)
            vec[left++] = tmp[i];
    }
    void mergesort(vector<int> &vec)
    { //非递归方法
        int size = 1;
        int n = vec.size();
        int low = 0;
        while (size <= n - 1)
        {
            low = 0;
            while (low + size <= n - 1)
            {
                int mid = low + size - 1;
                int high = mid + size;
                if (high > n - 1)
                    high = n - 1;
                merge(vec, low, mid, high);
                low = high + 1;
            }
            size *= 2;
        }
    }

    void mergesort2(vector<int> &vec, int low, int high)
    {
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            mergesort2(vec, low, mid);
            mergesort2(vec, mid + 1, high);
            merge(vec, low, mid, high);
        }
    }
};

//delete

class Solution
{ //这个是leetcode题，序列中逆序数的个数
public:
    int reversePairs(vector<int> &nums)
    {
        mergesort(nums, 0, nums.size() - 1);
        return count;
    }
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        if (left >= right)
            return;
        int i = left, j = mid + 1;
        vector<int> tmp;
        while (i <= mid && j <= right)
        {
            if (nums[i] < nums[j])
            {
                tmp.push_back(nums[i]);
                ++i;
            }
            else
            {
                count += mid - i + 1;
                tmp.push_back(nums[j]);
                ++j;
            }
        }
        while (i <= mid)
            tmp.push_back(nums[i++]);
        while (j <= right)
            tmp.push_back(nums[j++]);
        i = right;
        while (!tmp.empty())
        {
            nums[i--] = tmp.back();
            tmp.pop_back();
        }
    }

    void mergesort(vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;
            mergesort(nums, low, mid);
            mergesort(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }

private:
    int count = 0;
};

int main()
{

    vector<int> arr = {1, 3, 2, 3, 1}; //8,32,9,23,6,9,1
    // HeapSort h;
    // vector<int> ans = h.heapsort(arr);
    // for(auto a:ans)cout<<a<<ends;
    // mergeSort merge  = mergeSort();
    // merge.mergesort2(arr, 0, arr.size()-1);
    // for(const auto a : arr)cout<<a<<ends;
    Solution s = Solution();
    auto tmp = s.reversePairs(arr);

    system("pause");
    return 0;
}
