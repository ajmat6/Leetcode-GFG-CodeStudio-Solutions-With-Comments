class Solution {
public:
    // function for palindrome:
    bool ispal(string s)
    {
        int low = 0;
        int high = s.size() - 1;
        string copy = s;

        while(low < high) swap(s[low++], s[high--]);

        if(copy == s) return true;
        else return false;
    }

    // function for finding base no:
    string base(int base, int n)
    {
        string s = "";
        while(n > 0)
        {
            int rem = n % base;
            s = s + to_string(rem);
            n = n / base;
        }

        reverse(s.begin(), s.end());
        return s;
    }
    
    bool isStrictlyPalindromic(int n) {
        int flag = 1;
        
        // checking for base no from 2 to n-2:
        for(int i=2; i<=n-2; i++)
        {
            // storing base in a string:
            string s = base(i, n);

            // checking for palindrome:
            if(!ispal(s))
            {
                flag = 0;
                break;
            }
        }

        if(flag == 1) return true;
        else return false;
    }
};