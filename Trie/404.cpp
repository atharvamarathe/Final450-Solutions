#include <iostream>
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

bool wordBreak(string str,Trie *root) {

    int size = str.size();

    if(size == 0)
        return true;
    for(int i = 1;i<=size;i++) {
        if(search(root,str.substr(0,i)) && wordBreak(str.substr(i,size-i),root))
            return true;
        
    }

    return false;
}



int main()
{
    string dictionary[] = {"mobile","samsung","sam",
                           "sung","ma\n","mango",
                           "icecream","and","go","i",
                           "like","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    Trie *root = getNode();
  
    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);
  
    wordBreak("ilikesamsung", root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii", root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("", root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii", root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango", root)? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok", root)? cout <<"Yes\n": cout << "No\n";
    return 0;
}
