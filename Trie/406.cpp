#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    unordered_map<char,TrieNode*>child;
    bool isLast;
    TrieNode() {
        for(char i = 'a';i <= 'z';i++)
            child[i] = NULL;
        isLast - false;
    }
};

TrieNode *root = NULL;

void insert(string str) {
    int len = str.length();
    TrieNode *itr = root;
    for(int i =0;i < len; i++) {
        TrieNode* nextNode = itr -> child[s[i]];
        if(nextNode == NULL) {
            nextNode = new TrieNode();
            itr -> child[s[i]] = nextNode;
        }

        itr = nextNode;
        if(i == len - 1)
            itr -> isLast = true;
    }
}

void displayContactUtil(TrieNode *currNode,string prefix) {
    if(currNode -> isLast)
        cout << prefix << endl;
    for(char i = 'a';i<= 'z';i++) {
        TrieNode *nextNode = currNode ->child[i];
        if(nextNode != NULL)
            displayContactUtil(nextNode,preifx+(char)i);
    }
}


void dislayContacts(string str) {
    TrieNode* prevNode = root;
    string prefix = "";
    int len = str.length();
    int i;
    for(i =0;i<len;i++) {
        prefix += (char)str[i];
        char lastChar = prefix[i];
        TrieNode *currNode = prevNode -> child[lastchar];
        if(currNode == NULL) {
            cout << "No results for " << prefix << "n";
            i++;
            break;
        }
        cout << "Suggestions based on " << prefix << " are n";
        displayContactUtil(currNode,prefix);
        preNode = currNode;
    }
    for(;i<len;i++) {
        prefix += (char)str[i];
        cout ,, "No results Found for "<<prefix<<"\n";
    }
}

void insertIntoTrie(string contacts[],int n)
{
    // Initialize root Node
    root = new TrieNode();
  
    // Insert each contact into the trie
    for (int i = 0; i < n; i++)
        insert(contacts[i]);
}


int main()
{
    // Contact list of the User
    string contacts[] = {"gforgeeks" , "geeksquiz"};
  
    // Size of the Contact List
    int n = sizeof(contacts)/sizeof(string);
  
    // Insert all the Contacts into Trie
    insertIntoTrie(contacts, n);
  
    string query = "gekk";
  
    // Note that the user will enter 'g' then 'e', so
    // first display all the strings with prefix as 'g'
    // and then all the strings with prefix as 'ge'
    displayContacts(query);
  
    return 0;
}