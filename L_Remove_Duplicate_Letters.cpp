class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        vector<int> count (26,0);
        vector<int> visited (26,0);

        //counting the characters count in string s:
        for(int i=0; i<s.size(); i++) count[s[i] - 'a']++;

        for(int i=0; i<s.size(); i++)
        {
            //Decreasing the frequency of the character:
            count[s[i] - 'a']--;

            //if curr string character is unvisited:
            if(visited[s[i] - 'a'] == 0)
            {
                //pop ans's last element untill it is lesser than curr string character:
                while(ans.size() != 0 && ans.back() > s[i] && count[ans.back() - 'a'] > 0)
                {
                    //if last character is greater than curr character than marking it unvisited and popping it out:
                    visited[ans.back() - 'a'] = 0;
                    ans.pop_back();
                }

                //pushing the curr character into the ans string and marking it visited:
                ans.push_back(s[i]);
                visited[s[i] - 'a'] = 1;
            }
        }
        
        return ans;
    }
};