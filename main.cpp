#include <iostream>

#include "trie.h"

int main(int, char**) {

    Trie trie;
    trie.insert("hello");
    trie.insert("dog");
    trie.insert("hell");
    trie.insert("cat");
    trie.insert("a");
    trie.insert("hel");
    trie.insert("help");
    trie.insert("helps");
    trie.insert("helping");
    trie.auto_suggestions("hel");

    return 0;
}