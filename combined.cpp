#include<iostream>
#include <list>
#include<string.h>
#include<stdio.h>
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
int main()
{
struct phno a[10];
int i;
for(i=0;i<3;i++){
    cin>>a[i].name;
    scanf("%lld",&a[i].pno);
}
int n =3;
Hash h(10),h1(26);
for (int i = 0; i < n; i++){
	h.insertPhone(a[i].name,a[i].pno);
    h1.insertItem(a[i].name,a[i].pno);
}
//h.searchPhone(9891224061);
string r=h.deletePhone(9891224061);
if(r.compare("Not found")!=0){
h1.deleteItem(r);
}
else{
    cout<<"Not found"<<endl;
}
h.displayHash();
cout<<endl;
h1.displayHash();
//h.displayHash();
//h.searchPhone(9891224061);
return 0;
}
