class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char data)
        {
            this -> data = data;
            for(int i=0; i<26; i++)
            {
                children[i] = NULL;
            }

            isTerminal = false;
            childCount = 0;
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

        void InsertCharacter(TrieNode* root, string word)
        {
            if(word.size() == 0)
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
                root -> childCount++;
            }

            InsertCharacter(child, word.substr(1));
        }

        void Insert(string word)
        {
            InsertCharacter(root, word);
        }

        void LongestCommonPrefix(TrieNode* root, string word, string& ans)
        {
            if(word.length() == 0)
            {
                return;
            }

            int index = word[0] - 'a';
            TrieNode* child;

            if(root -> childCount == 1)
            {
                ans.push_back(word[0]);
                child = root -> children[index];
                LongestCommonPrefix(child, word.substr(1), ans);
            }

            else return;
        }

        void checkLCP(string word, string& ans)
        {
            LongestCommonPrefix(root, word, ans);
        }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* obj = new Trie();

        for(int i=0; i<strs.size(); i++)
        {
            obj -> Insert(strs[i]);
        }

        int size = INT_MAX;
        string word;
        for(int i=0; i<strs.size(); i++)
        {
            if(strs[i].size() < size)
            {
                size = strs[i].size();
                word = strs[i];
            }
        }

        string ans = "";

        obj -> checkLCP(word, ans);

        return ans;
    }
};