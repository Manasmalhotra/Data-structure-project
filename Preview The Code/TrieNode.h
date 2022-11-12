#ifndef TRIENODE_H
#define TRIENODE_H
#include<bits/stdc++.h>
#define CHAR_SIZE 128
using namespace std;

///The Header files help us define the design of our application and also helps in documenting the design and related decisions.

class TrieNode
{
    private:
        string name;
        string phoneno;
        bool isLast;
        TrieNode*links[26];

    public:
        TrieNode();
        ///Getters and setters are defined to access the class variables. Concept: Data Encapsulation.
        void setName(string name);
        string getName();

        void setPhoneNum(string phno);
        string getPhoneNum();

        void setEnd(bool);
        bool getEnd();

        ///Common Functionalities of Trie like checking if a key is present in a node or not, setting the key and getting the key.
        ///Defining these functions help us avoid writing the low level code again and again. Concept: Abstraction.

        bool containsKey(char ch);
        void put(char ch, TrieNode*);
        TrieNode*get(char ch);

        /// Major Functionalities of Trie.

        void insert(string,string);
        void dfs(TrieNode*curr,string name,vector<TrieNode*>&result);
        void startsWith(string name);
        bool isEmpty(TrieNode* root);
        TrieNode* remove(TrieNode* root, string key,int depth);
        virtual ~TrieNode();


    protected:
};

#endif // TRIENODE_H
