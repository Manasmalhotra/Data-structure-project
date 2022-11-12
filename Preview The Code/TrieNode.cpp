#include "TrieNode.h"
#include<bits/stdc++.h>
using namespace std;

TrieNode::TrieNode()
{
    	 for(int i=0;i<26;i++){
          links[i]=NULL;
          }
		isLast = false;
}

bool TrieNode :: containsKey(char ch){
  if(links[ch-'a']!=NULL){
    return true;
  }
  return false;
}

void TrieNode :: put(char ch,TrieNode* node){
  links[ch-'a']=node;
}

TrieNode* TrieNode :: get(char ch){
  return links[ch-'a'];
}

void TrieNode :: setEnd(bool value){
  isLast=value;
}

bool TrieNode :: getEnd(){
   return isLast;
}

void TrieNode :: setPhoneNum(string phno){
 phoneno=phno;
}
string TrieNode :: getPhoneNum(){
  return phoneno;
}

void TrieNode :: setName(string str){
  name=str;
}

string TrieNode :: getName(){
 return name;
}

void TrieNode :: insert(string name,string phno)
{
	   int i,n=name.length();
       TrieNode*curr=this;
       for(i=0;i<n;i++){
          if(!curr->containsKey(name[i])){   ///Check if the current node contains the required alphabet
              curr->put(name[i],new TrieNode()); ///If it does not contain then we insert it.
          }
          curr=curr->get(name[i]);           ///Go to the child contained by our current character.
       }
       curr->setEnd(true);                       ///After insertion of the last alphabet we mark the child of the last alphabet to indicate the end of the word.
       curr->setName(name);
       curr->setPhoneNum(phno);
}

void TrieNode :: dfs(TrieNode*curr,string name,vector<TrieNode*>&result){
      if(curr->getEnd()){
         result.push_back(curr);
      }
      char i;
      for(i='a';i<='z';i++){
         if(curr->containsKey(i)){
            dfs(curr->get(i),name+i,result);
         }
      }
}

void TrieNode :: startsWith(string name){
       int i,n=name.length();
       TrieNode*curr=this;
       for(i=0;i<n;i++){
           if(!curr->containsKey(name[i])){
              cout<<"No Results Found."<<endl;
              return;
           }
           curr=curr->get(name[i]);
       }
       vector<TrieNode*>result;
       dfs(curr,name,result);
       cout<<"Search Results"<<endl;
       for(i=0;i<result.size();i++){
         cout<<result[i]->getName()<<" "<<result[i]->getPhoneNum()<<endl;
       }
}


bool TrieNode:: isEmpty(TrieNode* root)
{
    for (char i='a';i<='z'; i++)
        if (root->containsKey(i)){
            return false;
        }
    return true;
}

/// Recursive function to delete a key from given Trie
TrieNode* TrieNode:: remove(TrieNode* root, string key, int depth = 0)
{
    /// If tree is empty
    if (!root)
        return NULL;

    /// If last character of key is being processed
    if (depth == key.size()) {

        /// This node is no more end of word after
        /// removal of given key
        if (root->getEnd()){
            root->setEnd(false);
        }

        /// If given is not prefix of any other word
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }

        return root;
    }

    /// If not last character, recur for the child
    /// obtained using ASCII value
    char index = key[depth];
    root->put(index,remove(root->get(index), key, depth + 1));

    /// If root does not have any child (its only child got
    /// deleted), and it is not end of another word.
    if (isEmpty(root) && root->getEnd() == false) {
        delete (root);
        root = NULL;
    }
    return root;
}

TrieNode::~TrieNode()
{
    //dtor
}

