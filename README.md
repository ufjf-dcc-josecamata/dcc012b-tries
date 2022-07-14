# Busca Digital
## Tries

Trie é uma estrutura de dados de recuperação de informações eficiente. Uma trie, ou árvore de prefixos, é uma estrutura de dados do tipo árvore ordenada, que pode ser usada para armazenar um array associativo em que as chaves são normalmente cadeias de caracteres.

Ao contrário de uma árvore de busca binária, nenhum nó nessa árvore armazena a chave associada a ele; ao invés disso, ela é determinada pela sua posição na árvore. Todos os descendentes de qualquer nó têm um prefixo comum com a cadeia associada com aquele nó, e a raiz é associada com a cadeia vazia. Normalmente, valores não são associados com todos os nós, apenas com as folhas e alguns nós internos que correspondem a chaves de interesse.

### Vantagens e desvantagens com relação a árvore de busca binária
As principais vantagens de trie sobre Árvore de busca binária, são:

 - A busca é mais rápida.
 - Uma árvore Trie requer menos espaço quando contém um grande número de cadeias curtas, porque as chaves não são armazenadas de forma explícita e os nós das chaves iniciais comuns são compartilhados.

 ### Implementação

 Cada nó da Trie possui várias ramificações. Cada ramo representa um possível caractere de chaves. Precisamos marcar o último nó de cada chave como o final da palavra nó. Um campo de nó Trie isEndOfWord é usado para distinguir o nó como o final do nó da palavra. Uma estrutura simples para representar nós do alfabeto portugues poderia ser a seguinte

 ```C++
#define ALFABETO 26
class TrieNode {
    public:
        TrieNode();
        TreeNode* getChild(int idx);
        bool      isEndOfWord();

    private:
        TreeNode* _children[ALFABETO];
        bool     _is_word;
}
 ```

A classe abaixo define um tipo abstrado de dados para representar um Trie e as suas operações básicas.

 ```C++
class Trie {
    public:
        Trie();
        ~Trie();
        void insert(const char* word);
        void insert(string word);
        bool search(const char* word);
        bool search(string word);
    private:
        TrieNode* root;
};
```

**Inserção:**
Inserir uma chave na Trie é simples. Cada caractere da chave de entrada é inserido como um nó individual da Trie. Observe que os filhos são uma matriz de ponteiros (ou referências) para nós trie de próximo nível. O caractere chave atua como um índice para os filhos da matriz. Se a chave de entrada for nova ou uma extensão da chave existente, precisamos construir nós não existentes da chave e marcar o final da palavra para o último nó. Se a chave de entrada for um prefixo da chave existente na Trie, simplesmente marcamos o último nó da chave como  final de uma palavra. O comprimento da chave determina a profundidade do Trie.
 ```C++
void Trie::insert(string word) 
{
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++) {
            if (!cur->getChild(word[i])) {
                cur->children[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->getChild(word[i]);
        }
        cur->is_word = true;
}
```
**Busca:**
A busca por uma chave é semelhante a uma operação de inserção, porém, apenas comparamos os caracteres e descemos. A pesquisa pode terminar devido ao fim de uma string ou falta de chave na trie. No primeiro caso, se o campo *is_word* do último nó for verdadeiro, então a chave existe na trie. No segundo caso, a busca termina sem examinar todos os caracteres da chave, pois a chave não está presente na trie.

 ```C++
bool Trie::search(string word) 
{
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++) 
        {
            if (!cur->getChild(word[i])) {
                return false;
            }
            cur = cur->getChild(word[i]);
        }
        return cur->is_word;
}
```

Inserir e pesquisar custa O(word.lenght()), no entanto, os requisitos de memória de Trie são O(ALPHABET_SIZE * word.length * N) onde N é o número de chaves em Trie. Existem representações eficientes de nós trie (por exemplo, trie compactado, árvore de busca ternária, etc.) para minimizar os requisitos de memória do trie.