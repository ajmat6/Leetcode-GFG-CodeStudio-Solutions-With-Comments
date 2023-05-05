//TC = O(n)
//SC = O(n)
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    vector<long long> ans;
    deque<long long int> d;
    
    for(int i=0; i<K; i++)
    {
        if(A[i] < 0) d.push_back(i);
    }
    
    if(d.size() > 0) ans.push_back(A[d.front()]);
    else ans.push_back(0);
    
    for(long long int i=K; i<N; i++)
    {
        if(!d.empty() && i-d.front() >= K)
        {
            d.pop_front();
        }
        
        if(A[i] < 0) d.push_back(i);
        
        if(d.size() > 0) ans.push_back(A[d.front()]);
        else ans.push_back(0);
    }
    return ans;
}