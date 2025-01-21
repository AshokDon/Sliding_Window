//https://cses.fi/problemset/task/1644
#include <iostream>
#include <set>
#include <vector>
#include <climits>
using namespace std;
 
#define int long long
 
signed main()
{
    int n, a, b;
    cin >> n >> a >> b;
    ;
    vector<int> nums(n);
    for (auto &i : nums)
    {
        cin >> i;
    }
 
    int maxsum = LONG_MIN;
 
    vector<int> pre(n + 1);
 
    for (int i = 1; i <= n; i++)
    {
        pre[i] += pre[i - 1] + nums[i - 1];
    }
 
    multiset<int> ms;
 
    for (int i = a; i <= n; i++)
    {
        if (i > b)
        {
            ms.erase(ms.find(pre[i - b - 1]));
        }
        ms.insert(pre[i - a]);
        maxsum = max(maxsum, pre[i] - *ms.begin());
    }
 
    cout << maxsum;
 
    return 0;
}
