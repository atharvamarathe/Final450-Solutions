#include <bits/stdc++.h>

using namespace std;
const int ALPHABET_SIZE = 26;   

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
}Trie;

// Get a new Trie Node initialzed to NULLs
Trie *getNode() {
    Trie *pNode = new TrieNode;

    pNode -> isEndOfWord = false;
    for (int i = 0;i< ALPHABET_SIZE;i++)
        pNode -> children[i] = NULL;
    
    return pNode;
}

void insert(Trie *root,string key) {
    Trie *pCrawl = root;    
    for(int i = 0;i<key.length();i++) {
        int index = key[i] - 'a';
        if(!pCrawl->children[index])
            pCrawl -> children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl -> isEndOfWord = true;
}

bool search(Trie *root,string key) {
    Trie *pCrawl = root;
    for(int i = 0;i<key.length();i++) {
        int index = key[i] - 'a';
        if(!pCrawl -> children[index])
            return false;
        pCrawl = pCrawl -> children[index];
    }

    return (pCrawl != NULL && pCrawl -> isEndOfWord);
}


int main() {
    string keys[] = { "the","a","there","answer",
                    "any","by","bye","their"};
    int n = sizeof(keys)/sizeof(keys[0]);
    Trie *root = getNode();

    for(int i = 0; i < n; i++)
        insert(root ,keys[i]);
    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    search(root, "these") ? cout << "Yes\n" : cout << "No\n";

    return 0;
}