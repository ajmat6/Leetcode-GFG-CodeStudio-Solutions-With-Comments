class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char character)
        {
            this -> data = character;
            for(int i=0; i<26; i++)
            {
                children[i] = NULL;
            }

            isTerminal = false;
        }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');  // passing null character to the root  
    }

    void insertCharacter(TrieNode* root, string word)
    {
        // base case:
        if(word.length() == 0)
        {
            root -> isTerminal = true; // if insertion process is complete then making the isTerminal memeber true.
            return;
        }

        // Assuming the word will be in lowercase letters:
        int index = word[0] - 'a'; // Finding the index to check for present
        TrieNode* child;

        // present then aaghe badho
        if(root -> children[index] != NULL)
        {
            child = root -> children[index];
        } 

        // Not present then insert
        else
        {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        // Now Recursion will handle rest of the cases:
        insertCharacter(child, word.substr(1)); // word ke 1st index se substring
    }
    
    void insert(string word)
    {
        insertCharacter(root, word);
    }

    bool SearchCharacter(TrieNode* root, string word)
    {
        // Base case:
        if(word.length() == 0)
        {
            return root -> isTerminal; // to check for the terminal node
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // Present condition
        if(root -> children[index] != NULL)
        {
            child = root -> children[index];
            return SearchCharacter(child, word.substr(1));
        }

        // if not present return false:
        return false;
    }

    bool SearchPrefix(TrieNode* root, string word)
    {
        // Base case:
        if(word.length() == 0)
        {
            return true; // to check for the terminal node
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // Present condition
        if(root -> children[index] != NULL)
        {
            child = root -> children[index];
            return SearchPrefix(child, word.substr(1));
        }

        // if not present return false:
        return false;
    }
    
    bool search(string word) {
        return SearchCharacter(root, word);
    }
    
    bool startsWith(string prefix) {
        return SearchPrefix(root, prefix);
    }
};