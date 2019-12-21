#include<bits/stdc++.h>
#include <list>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct phno{
string name;
long long int pno;
};
class Hash
{
	int BUCKET;
	list<struct phno> *table;
public:
	Hash(int V);

	void insertPhone(string x,long long int pno);

	void insertItem(string x,long long int pno);

	string deletePhone(long long int pno);

    long long int deleteItem(string key);

    void searches(string key);

    void searchPhone(long long int pno);

    int hashFunction(string x) {
		return (x[0]-'a');
	}

	int hashPhone(long long int x) {
		int r,sum=0;
        while(x){
          r=x%10;
          sum+=r;
          x=x/10;}
        return sum%10;
}
void displayHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<struct phno>[BUCKET];
}

void Hash::insertItem(string key,long long  int pno)
{
    struct phno p;
    p.name=key;
    p.pno=pno;
	int index = hashFunction(key);
	table[index].push_back(p);
}

void Hash::insertPhone(string key,long long  int pno)
{
    struct phno p;
    p.name=key;
    p.pno=pno;
	int index = hashPhone(pno);
	table[index].push_back(p);
}

long long int Hash::deleteItem(string key)
{
// get the hash index of key
int index = hashFunction(key);
long long int p;
// find the key in (inex)th list
list <struct phno> :: iterator i;
for (i = table[index].begin();
		i != table[index].end(); i++) {
	if (i->name == key){
	p=i->pno;
	break;}
}

// if key is found in hash table, remove it
if (i != table[index].end()){
	table[index].erase(i);
	return p;}
else
    return -1;
}

string Hash::deletePhone(long long int pno)
{
int index = hashPhone(pno);
string r;
list <struct phno> :: iterator i;
for (i = table[index].begin();
		i != table[index].end(); i++) {
	if (i->pno == pno){
       r=i->name;
	break;}
}

if (i != table[index].end()){
	table[index].erase(i);
	return r;}
else {return "Not found";}
}
void Hash::searchPhone(long long int pno)
{

int index = hashPhone(pno);
list <struct phno> :: iterator i;
for (i = table[index].begin();
		i != table[index].end(); i++) {
	if (i->pno == pno){
	break;
}
		}
if (i != table[index].end()){
        cout<<" "<<i->name;
      	printf("\t%lld",i->pno,"\n");
}
else{
    cout<<"No record found"<<endl;
    return;
}
}
void Hash::searches(string key)
{
// get the hash index of key
int index = hashFunction(key);

// find the key in (inex)th list
list <struct phno> :: iterator i;
for (i = table[index].begin();
		i != table[index].end(); i++) {
	if (i->name == key){
	break;
}
		}
// if key is found in hash table, print it
if (i != table[index].end()){
        cout<<" "<<i->name;
      	printf("\t%lld",i->pno,"\n");
}
else{
    cout<<"No record found"<<endl;
    return;
}
}

void Hash::displayHash() {
for (int i = 0; i < BUCKET; i++) {
	cout << i;
    list<struct phno>::iterator x;
    for (x=table[i].begin();x!=table[i].end();x++){
      	cout<<"--->"<<x->name;
      	printf("\t%lld",x->pno);
	}cout << endl;
}
}

//TRIE IMPLEMENTATION OF PREFIX SEARCH>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


struct TrieNode
{
	// Each Trie Node contains a Map 'child'
	// where each alphabet points to a Trie
	// Node.
	// We can also use a fixed size array of
	// size 256.
	map<char,TrieNode*> child;

	// 'isLast' is true if the node represents
	// end of a contact
	bool isLast;

	// Default Constructor
	TrieNode()
	{
		// Initialize all the Trie nodes with NULL
		for (char i = 'a'; i <= 'z'; i++)
			child[i] = NULL;

		isLast = false;
	}
};

// Making root NULL for ease so that it doesn't
// have to be passed to all functions.
TrieNode *root = NULL;

// Insert a Contact into the Trie
void insert(string s)
{
	int len = s.length();

	// 'itr' is used to iterate the Trie Nodes
	TrieNode *itr = root;
	for (int i = 0; i < len; i++)
	{
		// Check if the s[i] is already present in
		// Trie
		TrieNode *nextNode = itr->child[s[i]];
		if (nextNode == NULL)
		{
			// If not found then create a new TrieNode
			nextNode = new TrieNode();

			// Insert into the Map
			itr->child[s[i]] = nextNode;
		}

		// Move the iterator('itr') ,to point to next
		// Trie Node
		itr = nextNode;

		// If its the last character of the string 's'
		// then mark 'isLast' as true
		if (i == len - 1)
			itr->isLast = true;
	}
}

// This function simply displays all dictionary words
// going through current node. String 'prefix'
// represents string corresponding to the path from
// root to curNode.
void displayContactsUtil(TrieNode *curNode, string prefix)
{
	// Check if the string 'prefix' ends at this Node
	// If yes then display the string found so far
	if (curNode->isLast)
		cout << prefix << endl;

	// Find all the adjacent Nodes to the current
	// Node and then call the function recursively
	// This is similar to performing DFS on a graph
	for (char i = 'a'; i <= 'z'; i++)
	{
		TrieNode *nextNode = curNode->child[i];
		if (nextNode != NULL)
			displayContactsUtil(nextNode, prefix + (char)i);
	}
}

// Display suggestions after every character enter by
// the user for a given query string 'str'
void displayContacts(string str)
{
	TrieNode *prevNode = root;

	string prefix = "";
	int len = str.length();

	// Display the contact List for string formed
	// after entering every character
	int i;
	for (i=0; i<len; i++)
	{
		// 'prefix' stores the string formed so far
		prefix += (char)str[i];

		// Get the last character entered
		char lastChar = prefix[i];

		// Find the Node corresponding to the last
		// character of 'prefix' which is pointed by
		// prevNode of the Trie
		TrieNode *curNode = prevNode->child[lastChar];

		// If nothing found, then break the loop as
		// no more prefixes are going to be present.
		if (curNode == NULL)
		{
			cout << "No Results Found for " << prefix
				<< "\n";
			i++;
			break;
		}

		// If present in trie then display all
		// the contacts with given prefix.
		cout << "Suggestions based on "<< prefix<<" "
			<< "are"<< "\n";
		displayContactsUtil(curNode, prefix);

		// Change prevNode for next prefix
		prevNode = curNode;
	}

	// Once search fails for a prefix, we print
	// "Not Results Found" for all remaining
	// characters of current query string "str".
	for (; i<len; i++)
	{
		prefix += (char)str[i];
		cout << "No Results Found for "<< prefix<<" "
			<< "\n";
	}
}

// Insert all the Contacts into the Trie
void insertIntoTrie(string contacts[],int n)
{
	// Initialize root Node
	root = new TrieNode();

	// Insert each contact into the trie
	for (int i = 0; i < n; i++)
		insert(contacts[i]);
}
//////END OF FUNCTIONALITIES.>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Menu
void menu(Hash h,Hash h1)
{
    system("cls");
printf("\t\t**********WELCOME TO PHONEBOOK*************");

printf("\n\n\t\t\t  MENU\t\t\n\n");
printf("\t1.Add New   \t2.List   \t3.Exit  \n\t4.Search by name \t5.Search by phone.no\t6.Suggestive search\t7.Delete");
int u;
string x;
string query;
long long int i;
cout<<endl;
cin>>u;
switch(u)
{
    case 1:
         cout<<"Enter name and phone number";
         cin>>x>>i;
         h.insertPhone(x,i);
         h1.insertItem(x,i);
         insert(x);
         cout<<endl;
         getch();
         menu(h,h1);
         break;
    case 2 :
        h1.displayHash();
        h.displayHash();
        cout<<endl;
        getch();
        menu(h,h1);
        break;
    case 3:
        exit(0);
        break;
    case 4:
        cout<<"Enter the name to search";
        cin>>x;
        h1.searches(x);
        cout<<endl;
        getch();
        menu(h,h1);
        break;
    case 5:
        cout<<"Enter the phone number to search";
        cin>>i;
        h.searchPhone(i);
        cout<<endl;
        getch();
        menu(h,h1);
        break;

    case 6:
    cout<<"please enter the initials of name to search";
    cin>>query;
    displayContacts(query);
    cout<<endl;
    getch();
    menu(h,h1);
    break;

    case 7:
        int y;
        cout<<"Enter 1 for entering phone number and 2 for entering name";
        cin>>y;
        if(y==1){
            long long int i;
            cin>>i;
            string r=h.deletePhone(i);
            if(r.compare("Not found")!=0){
            h1.deleteItem(r);
         }
        else{
           cout<<"Not found"<<endl;
}
        }
        else if(y==2){
            string x;
            cin>>x;
            long long int w=h1.deleteItem(x);
            if(w==-1){cout<<"Not Found";}
            else{
            h.deletePhone(w);}
        }
        else{
            cout<<"Invalid input";
        }
        cout<<endl;
        getch();
        menu(h,h1);
        break;
    default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                cin>>u;

menu(h,h1);
}
}

int main()
{
struct phno a[10];
int i,k;
for(i=0;i<3;i++){
    cin>>a[i].name;
    scanf("%lld",&a[i].pno);
}
FILE *f;
f=fopen("project.txt","ab+");
for(i=0;i<3;i++){
fwrite(&a[i],sizeof(a[i]),1,f);
}
int n =3;
Hash h(10),h1(26);
root = new TrieNode();
for (int i = 0; i < n; i++){
	h.insertPhone(a[i].name,a[i].pno);
    h1.insertItem(a[i].name,a[i].pno);
    insert(a[i].name);
}
menu(h,h1);
return 0;
}
