#include <iostream>
#include <algorithm>
using namespace std;

class TriesNode
{

public:
    char data;
    TriesNode *children[26];
    bool isTerminal;

    // constructor
    TriesNode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{

public:
    TriesNode *root;

    // constructor
    Trie()
    {
        root = new TriesNode('\0');
    }

    void insertUtil(TriesNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // word will be in CAPS
        int index = word[0] - 'A';
        TriesNode *child;

        // present
        if (root->children[index] != NULL)
        {
            cout << "hii insertutil" << endl;
            child = root->children[index];
        }
        else
        {
            // creating new node
            child = new TriesNode(word[0]);
            cout << "creating new node " << endl;
            root->children[index] = child;
        }
        cout << word.substr(1) << endl;
        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        cout << "hii insert word" << endl;
        insertUtil(root, word);
    }

    bool searchUtil(TriesNode *root, string word)
    {

        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        // word will be  in CAPS
        int index = word[0] - 'A';
        TriesNode *child;

        // present
        if (root->children[index] != NULL)
        {
            cout << "child " << child << endl;
            child = root->children[index];
        }
        else
        {
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        cout << "hii" << endl;
        return searchUtil(root, word);
    }

    bool removeutil(TriesNode *root, string word )
    {

        // last element
        if (word.length() == 0)
        {
           

            root->isTerminal = false;

            // check the node has children or not
            for (int i = 0; i < 26; ++i)
            {
                if (root->children[i] != NULL)
                {
                    return true; // node has children should not be deleted
                }
            }
            return false;
        }

        int index = word[0] - 'A';
        if (root->children[index] == NULL)
        {
            return false;// word is not present in trie
        }
        

        // recursive call
       bool  nodetoDelete = removeutil(root->children[index],word.substr(1));
      
      // if child is not deleted so set NULL ans delete
      if (nodetoDelete)
      {

        cout << "true" << endl;
        delete root->children[index];
        root->children[index]= NULL;

        if (root->isTerminal)
        {
            return false;
        }

        for (int i = 0; i < 26; ++i)
        {
            if (root->children[i] != NULL)
            {
                return false;// current node has another children
            }
            
        }
        return true; // current node has be delete  
      }
      return false;// no need to perform deletion at this level
      
    }
    bool removeWord(string word)
    {
      
        return removeutil(root, word);
    }
};

int main()
{

    cout << " hii";
    Trie *t = new Trie();

    t->insertWord("ABC");

    cout << "present or not " << t->searchWord("ABC") << endl;

    cout << t->removeWord("ABC") << "remove" << endl;
    cout << "present or not " << t->searchWord("AB") << endl;
    return 0;
}
