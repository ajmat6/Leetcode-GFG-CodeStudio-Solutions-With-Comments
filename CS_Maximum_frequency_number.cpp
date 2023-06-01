#include<unordered_map>

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> m;
    int maxFre = 0;
    int ans = 0;

    for(int i=0; i<arr.size(); i++)
    {
        m[arr[i]]++;
        maxFre = max(maxFre, m[arr[i]]);
    }

    for(int i=0; i<arr.size(); i++)
    {
        if(maxFre == m[arr[i]])
        {
            ans = arr[i];
            break;
        }
    }


    return ans;
}