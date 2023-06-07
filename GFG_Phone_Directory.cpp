class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        
        TrieNode(char data)
        {
            this -> data = data;
            for(int i=0; i<26; i++)
            {
                children[i] = NULL;
            }
            
            isTerminal = false;
        }
};

class Trie
{
    public:
        TrieNode* root;
        Trie()
        {
            root = new TrieNode('\0');
        }
        
        void InsertWord(TrieNode* root, string word)
        {
            if(word.length() == 0)
            {
                root -> isTerminal = true;
                return;
            }
            
            int index = word[0] - 'a';
            TrieNode* child;
            
            if(root -> children[index] != NULL)
            {
                child = root -> children[index];
            }
            
            else
            {
                child = new TrieNode(word[0]);
                root -> children[index] = child;
            }
            
            InsertWord(child, word.substr(1));
        }
        
        void Insert(string word)
        {
            InsertWord(root, word);
        }
        
        void AddSuggestions(TrieNode* root, vector<string>& temp, string track)
        {
            // if the node is terminal node it means it is a word in trie and store in the temp vector
            if(root -> isTerminal)
            {
                temp.push_back(track);
            }
            
            // checking for each possible child of the root node
            for(char ch='a'; ch <= 'z'; ch++)
            {
                TrieNode* next = root -> children[ch - 'a'];
                if(next != NULL)
                {
                    track.push_back(ch);
                    AddSuggestions(next, temp, track);
                    
                    // Backtracking: removing the last character in the track string for the next character
                    track.pop_back();
                }
            }
        }
        
        vector<vector<string>> Suggestions(string str)
        {
            TrieNode* prev = root;
            string track = "";
            vector<vector<string>> ans;
            
            int i;
            
            for(i=0; i<str.size(); i++)
            {
                char ch = str[i];
                track.push_back(str[i]);
                
                // Check if root have any child with ch:
                TrieNode* curr = prev -> children[ch - 'a'];
                
                //Absent
                if(curr == NULL) break;
                
                // Present
                
                vector<string> temp;
                
                AddSuggestions(curr, temp, track);
                ans.push_back(temp);
                
                prev = curr;
            }
            
            // if the loop breaks before the string size then stor "0" as the string
            if(i < str.size())
            {
                while(i<str.size())
                {
                    ans.push_back({"0"});
                    i++;
                }
            }
            
            return ans;
        }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie* t = new Trie();
        
        //Insertion into the trie:
        for(int i=0; i<n; i++)
        {
            t -> Insert(contact[i]);
        }
        
        return t -> Suggestions(s);
    }
};