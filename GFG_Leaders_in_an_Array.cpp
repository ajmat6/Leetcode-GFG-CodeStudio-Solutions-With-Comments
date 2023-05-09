class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        stack<int> ajmat;
        vector<int> ans;
        for(int i=n-1; i>=0; i--)
        {
            if(ajmat.empty()) ajmat.push(a[i]);
            else if(a[i] >= ajmat.top()) ajmat.push(a[i]);
        }
        
        while(!ajmat.empty())
        {
            ans.push_back(ajmat.top());
            ajmat.pop();
        }
        return ans;
    }
};