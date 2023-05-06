class Solution{	
    public:
		string FirstNonRepeating(string A){
		    vector<int> ans (26,0);
		    string str = "";
		    queue<char> q;
		    
		    for(int i=0; i<A.size(); i++)
		    {
		        //increasing the count of that index character
		        int a = A[i] - 'a';
		        ans[a]++;
		        
		        //for the first non-repeating character track
		        q.push(A[i]);
		        
		        bool repeat = false;
		        
		        //popping from the queue till first non-repeating character is found
		        while(!q.empty())
		        {
		            int c = q.front() - 'a';
		            
		            if(ans[c] > 1) q.pop();
		            else
		            {
		                str.push_back(q.front());
		                repeat = true;
		                break;
		            }
		        }
		      
		        //if no non-repeating character is found
		        if(repeat == false) str.push_back('#');
		        
		    }
		    return str;
		}
};