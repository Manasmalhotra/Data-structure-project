#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	map<char,TrieNode*> child;
	bool isLast;

	TrieNode()
	{
		for (char i = 'a'; i <= 'z'; i++)
			child[i] = NULL;

		isLast = false;
	}
};

TrieNode *root = NULL;

void insert(string s)
{
	int len = s.length();

	TrieNode *itr = root;
	for (int i = 0; i < len; i++)
	{

		TrieNode *nextNode = itr->child[s[i]];
		if (nextNode == NULL)
		{

			itr->child[s[i]] = nextNode;
		}

		itr = nextNode;

		if (i == len - 1)
			itr->isLast = true;
	}
}
void displayContactsUtil(TrieNode *curNode, string prefix)
{
	if (curNode->isLast)
		cout << prefix << endl;
	for (char i = 'a'; i <= 'z'; i++)
	{
		TrieNode *nextNode = curNode->child[i];
		if (nextNode != NULL)
			displayContactsUtil(nextNode, prefix + (char)i);
	}
}

void displayContacts(string str)
{
	TrieNode *prevNode = root;

	string prefix = "";
	int len = str.length();
	int i;
	for (i=0; i<len; i++)
	{

		prefix += (char)str[i];

		char lastChar = prefix[i];
		TrieNode *curNode = prevNode->child[lastChar];

		if (curNode == NULL)
		{
			cout << "nNo Results Found for "<< prefix
				<< "\n";
			i++;
			break;
		}
		cout << "nSuggestions based on "<< prefix
			<< "are \n";
		displayContactsUtil(curNode, prefix);

		prevNode = curNode;
	}
	for (; i<len; i++)
	{
		prefix += (char)str[i];
		cout << "nNo Results Found for "<< prefix
			<< "\ n";
	}
}

void insertIntoTrie(string contacts[],int n)
{
	root = new TrieNode();

	for (int i = 0; i < n; i++)
		insert(contacts[i]);
}
int main()
{
	string contacts[] = {"gforgeeks" , "geeksquiz"};

	int n = sizeof(contacts)/sizeof(string);
	insertIntoTrie(contacts, n);

	string query = "gekk";
	displayContacts(query);

	return 0;
}
