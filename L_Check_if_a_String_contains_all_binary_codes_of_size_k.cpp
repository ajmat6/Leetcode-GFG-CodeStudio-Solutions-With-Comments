class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> Myset;
        string ans = "";

        for(int i=0; i<s.size(); i++)
        {
            ans.push_back(s[i]); // Pushing it index element of string s into the ans string
            if(i >= k) ans.erase(0,1); // erase one element for making it fit into the size of the k
            if(ans.size() == k) Myset.insert(ans); // Inserting into the set
        }

        if(Myset.size() == pow(2,k)) return true; // as possible binary codes of size k are 2 raise to the power k
        else return false;
    }
};