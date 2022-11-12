#include "TrieNode.h"
#include<bits/stdc++.h>
using namespace std;

class phoneNumber{

string name;
string phno;

public:
    phoneNumber(string contactName,string contactPhno){
      name=contactName;
      phno=contactPhno;
    }

    string getPhoneNumber()const{
       return phno;
    }

    void setPhoneNumber(string contactPhno){
        phno=contactPhno;
    }

    string getName()const{
       return name;
    }

    void setName(string contactName){
       name=contactName;
    }

    void display()const{
       cout<<name<<" "<<phno;
       cout<<endl;
     }
};

class phoneBook{
vector<phoneNumber>listByPhoneNumbers;

public:
    void display(){
      if(listByPhoneNumbers.size()==0){
        cout<<"No Records found";
        return;
      }
      vector<phoneNumber>::iterator it;
       for(it=listByPhoneNumbers.begin();it!=listByPhoneNumbers.end();it++){
           cout<<it->getName()<<" "<<it->getPhoneNumber()<<endl;
        }
      }

    void insertion(string name,string phno){
      phoneNumber contact(name,phno);
      listByPhoneNumbers.push_back(contact);
    }


    void searchByPhoneNumber(string phno){
       vector<phoneNumber>::iterator it;

      for(it=listByPhoneNumbers.begin();it!=listByPhoneNumbers.end();it++){
        if((*it).getPhoneNumber()==phno){
            (*it).display();
            return;
        }
      }
      cout<<"No record found for the number "<<phno<<endl;
    }

    void searchByName(string name){
       vector<phoneNumber>::iterator it;
       int flag=0;
       for(it=listByPhoneNumbers.begin();it!=listByPhoneNumbers.end();it++){
          if((*it).getName() == name){
             (*it).display();
             flag=1;
             break;
          }
       }
       if(flag==0){
         cout<<"No record found with this name";
       }
    }

    void deletes(string name){
      vector<phoneNumber>::iterator it;

      for(it=listByPhoneNumbers.begin();it!=listByPhoneNumbers.end();it++){
        if((*it).getName()== name){
            break;
        }
      }
      if(it!=listByPhoneNumbers.end()){
         listByPhoneNumbers.erase(it);
         return;
      }
      else{
      cout<<"No record found for the name "<<name<<endl;
      }
    }

};

bool isvalid(string phno){
    int n=phno.length();
    if(n<10 || n>10){
        return false;
    }
    else{
        int i=0;
        for(i=0;i<n;i++){
            if(!(phno[i]>='0' && phno[i]<='9')){
                return false;
            }
        }
        return true;
    }
}

void menu(phoneBook book, TrieNode*root){

system("cls");
cout<<"\t\t**********WELCOME TO PHONEBOOK*************";
cout<<"\n\n\t\t\t  MENU\t\t\n\n";
cout<<"\t1.Add New   \t2.List   \t3.Search By Name  \n\t4.Search By Contact Number \t5.Suggestive Search.no\t6.Delete Contact\t7.Exit"<<endl;
int option;
cin>>option;
  switch(option){

   case 1:
       {
       cout<<"Please enter the name and contact number"<<endl;
       string name;
       string phno;
       cin>>name>>phno;
       if(!isvalid(phno)){
         cout<<"Please enter a 10 digit valid contact number"<<endl;
       }
       else{
         book.insertion(name,phno);
         root->insert(name,phno);
       }
       getchar();
       }
       break;

   case 2:
       {
       book.display();
       getchar();
       }
       break;

   case 3:
     {
       string name;
       cout<<"Please enter the name of the contact you wish to search"<<endl;
       cin>>name;
       book.searchByName(name);
       getchar();
     }
       break;

   case 4:
       {
       string phno;
       cout<<"Please enter the contact number you wish to search for"<<endl;
       cin>>phno;
       if(!isvalid(phno)){
         cout<<"Please try again by entering a valid 10 digit mobile number"<<endl;
       }
       else{
         book.searchByPhoneNumber(phno);
       }
       getchar();
    }
       break;

   case 5:
       {
        string prefix;
        cout<<"Please enter the initials of the name to have your options"<<endl;
        cin>>prefix;
        root->startsWith(prefix);
        getchar();
       }
        break;

   case 6:
       {
        string name;
        cout<<"Please enter the contact name you wish to delete"<<endl;
        cin>>name;
        book.deletes(name);
        root->remove(root,name,0);
        getchar();
       }
        break;

   case 7:
         exit(0);
         break;
   default:
        cout<<"Please choose valid number from the menu"<<endl;
    }
    getchar();
    menu(book,root);
}

main(){
phoneBook book;
TrieNode* root = new TrieNode();
menu(book,root);
}
