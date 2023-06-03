#include<iostream>
using namespace std;

// TC - Insertion = O(l) where l is the lenght of the word
//      Searching = O(l)

class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        // Initialisation:
        TrieNode(char ch)
        {
            this -> data = ch;
            for(int i=0; i<26; i++)
            {
                children[i] = NULL;
            }

            isTerminal = false; // Initializing the isTerminal data memeber
        }
};

class Trie
{
    public:
        TrieNode* root;

        Trie()
        {
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

            // Assuming the word will be in CAPITAL LETTERS:
            int index = word[0] - 'A'; // Finding the index to check for present
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


        bool SearchCharacter(TrieNode* root, string word)
        {
            // Base case:
            if(word.length() == 0)
            {
                return root -> isTerminal; // to check for the terminal node
            }

            int index = word[0] - 'A';
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

        void DeleteWordBySearch(TrieNode* root, string word)
        {
            // Base Case:
            if(word.length() == 0)
            {
                root -> isTerminal = false;
                return;
            }

            int index = word[0] - 'A';

            TrieNode* child;
            
            // Present:
            if(root -> children[index] != NULL)
            {
                child = root -> children[index];
            }

            else
            {
                cout << "Word not found" << endl;
                return;
            } 

            DeleteWordBySearch(child, word.substr(1));
        }

        void insertWord(string word)
        {
            insertCharacter(root, word);
        }

        bool SeachWord(string word)
        {
            return SearchCharacter(root, word);
        }

        void DeleteWord(string word)
        {
            DeleteWordBySearch(root, word);
        }
};

int main()
{
    Trie* t = new Trie();

    t -> insertWord("AJMAT");
    t -> insertWord("ABS");
    t -> insertWord("CAT");
    t -> insertWord("DU");
    t -> insertWord("TIME");

    cout << "Checking for the presence of the word in the trie: "<< t -> SeachWord("CAR") << endl;
    t -> insertWord("CAR");
    cout << "Checking for the presence of the word in the trie: "<< t -> SeachWord("CAR") << endl;

    t -> DeleteWord("AJMAT");
    cout << "Checking for the presence of the word in the trie: "<< t -> SeachWord("AJMAT") << endl;


    return 0;
}