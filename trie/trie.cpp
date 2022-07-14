
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
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
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
        for (int i = 0; i < word.length(); i++) 
        {
            int index = word[i] - 'a';
            if (!cur->children[index]) {
                return false;
            }
            cur = cur->children[index];
        }
        return cur->is_word;
}
 
void Trie::deallocate(TrieNode* node) 
{
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            deallocate(node->children[i]);
        }
    }
    delete node;
}


Trie::~Trie() {
    deallocate(root);
}

void Trie::auto_suggestions(string word) 
{
    TrieNode* cur = root;
    for (char c : word) {
        int index = c - 'a';
        if (!cur->children[index]) {
            return;
        }
        cur = cur->children[index];
    }

    if(cur->isLastNode()) {
        cout << word << endl;
        return;
    }
    suggestions(cur,word);
}

void Trie::suggestions(TrieNode* node, string currPrefix)
{
    // Encontrou uma palavra na Trie
    if (node->is_word)
        cout << currPrefix << endl;
 
    for (int i = 0; i < 26; i++)
        if (node->children[i]) {
            // Concatena o prefixo atual com a letra atual
            char child = 'a' + i;
            suggestions(node->children[i], currPrefix + child);
        }
}
 