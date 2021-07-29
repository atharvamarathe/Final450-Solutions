#include <iostream>
#include <bits/stdc++.h>


using namespace std;


#define MAX 256

#define MAX_WORD_LENGTH 500

typedef struct trienode {
    struct trienode *child[MAX_WORD_LENGTH];
    int freq;
}Trie;

Trie *newTrieNode() {
    Trie *newNode = new trienode;
    newNode -> freq = 1;
    for(int i = 0;i<MAX;i++)
        newNode -> child[i] = NULL;
    return newNode;
}

void insert(Trie *root,string str) {
    int len = str.length();
    Trie *pCrawl = root;

    for(int level = 0;level < len;level++) {
        int index = str[level];

        if(!pCrawl -> child[index])
            pCrawl -> child[index] = newTrieNode();
        else 
            (pCrawl -> child[index] -> freq)++;
        pCrawl = pCrawl -> child[index];
    }
}

void findPrefixesUtil(Trie *root,char prefix[],int ind) {
    if(root == NULL)
        return;
    if(root -> freq == 1) {
        prefix[ind] = '\0';cout << prefix<<" ";
        return;
    }

    for(int i = 0;i<MAX;i++) {
        if(root -> child[i] != NULL) {
            prefix[ind] = i;
            findPrefixesUtil(root -> child[i],prefix,ind+1);
        }
    }

}

void findPrefixes(string arr[],int n) {
    Trie *root = newTrieNode();
    root -> freq = 0;
    for (int i = 0;i<n;i++) {
        insert(root,arr[i]);
    }

    char prefix[MAX_WORD_LENGTH];

    findPrefixesUtil(root,prefix,0);
}


int main() {
    string arr[] = { "zebra","dog","duck","dove"};
    int n = sizeof(arr)/sizeof(arr[0]);
    findPrefixes(arr,n);

    return 0;
}