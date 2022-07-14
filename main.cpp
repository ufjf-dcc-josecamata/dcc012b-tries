#include <iostream>

#include "trie.h"

int main(int, char**) {

    // Cria uma nova trie
    Trie trie;

    // Insere um conjunto de paravras
    trie.insert("hello");
    trie.insert("dog");
    trie.insert("hell");
    trie.insert("cat");
    trie.insert("a");
    trie.insert("hel");
    trie.insert("help");
    trie.insert("helps");
    trie.insert("helping");

    // Imprime todas as chaves com prefixo hel
    trie.auto_suggestions("hel");

    // Imprime nada pois não há chaves com prefixo tre
    trie.auto_suggestions("tre");

    return 0;
}