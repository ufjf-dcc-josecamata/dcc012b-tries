
#include "trie.h"
#include <iostream>
#include <string>
using namespace std;

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(string word) 
{
        TrieNode* cur = root;
        for (char c: word) {
            int index = c - 'a';
            if (!cur->children[index]) {
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->is_word = true;
}
    

bool Trie::search(string word) 
{
        TrieNode* cur = root;
        for (char c: word) 
        {
            int index = c - 'a';
            if (!cur->children[index]) {
                return false;
            }
            cur = cur->children[index];
        }
        return cur->is_word;
}
 
void Trie::deallocate(TrieNode* node) 
{
    for (int i = 0; i < NCHARS; i++) {
        if (node->children[i]) {
            deallocate(node->children[i]);
        }
    }
    delete node;
}


Trie::~Trie() {
    deallocate(root);
}

void Trie::auto_suggestions(string prefix) 
{
    // Procura pelo nó final ao prefixo
    TrieNode* cur = root;
    for (char c : prefix) {
        int index = c - 'a';
        if (!cur->children[index]) {
            return;
        }
        cur = cur->children[index];
    }

    // caso contrário, imprime as chaves com prefixo
    // em comum.
    suggestions(cur,prefix);
}

void Trie::suggestions(TrieNode* node, string currPrefix)
{
    // Encontrou uma palavra na Trie
    if (node->is_word)
        cout << currPrefix << endl;
 
    for (int i = 0; i < NCHARS; i++)
        if (node->children[i]) {
            // Concatena o prefixo atual com a letra atual
            char child = 'a' + i;
            suggestions(node->children[i], currPrefix + child);
        }
}
 