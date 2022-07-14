/**
 * Implementação do tipo abstrado de dados - Trie
*/

#ifndef TRIE_H__
#define TRIE_H__

#include <string>
using namespace std;

#define NCHARS 26

class trie;
class TrieNode
{    
    friend class Trie;
    public:
        TrieNode() : is_word(false) {
            for (int i = 0; i < NCHARS; i++) {
                children[i] = nullptr;
            }
        }

        TrieNode* getChild(char c) {
            return children[c - 'a'];
        }

        bool isEndOfWord() {
            return is_word;
        }

        bool isLastNode()
        {
            for (int i = 0; i < NCHARS; i++)
            {
                if (children[i])
                    return false;
            }
            return true;
        }

    private: 
        bool      is_word;
        TrieNode* children[NCHARS];
};

class Trie {
    public:
        Trie();
        ~Trie();
        void insert(string word);
        bool search(string word);
        void auto_suggestions(string word);
    private:
        TrieNode* root;
        void suggestions(TrieNode* node, string word);
        void deallocate(TrieNode* node);
};

#endif /* TRIE_H__ */
