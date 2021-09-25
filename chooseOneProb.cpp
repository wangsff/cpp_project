#include <iostream>
#include <random>
#include <vector>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
    int tmp;
    vector<int> problems;
    freopen("problem.txt", "r", stdin);
    while ((cin >> tmp))
    {
        problems.push_back(tmp);
    }
    cout << "total problem is " << problems.size() << endl;
    srand(time(0));
    for (int i = 0; i < 3; ++i)
    {
        int choose = rand() % (int(problems.size()));
        cout << problems[choose] << endl;
    }
}
