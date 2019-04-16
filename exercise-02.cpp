/*
Author    		: SURIADI VAJRAKARUNA
NPM		        : 140810180038
Deskripsi	    : strukdat-06, exercise-02
Tahun           : 2019
*/

#include <iostream>
#include <windows.h>
using namespace std;

struct phonebook
{
	char name[30];
	char number[15];
	phonebook* next;
	phonebook* prev;
};

typedef phonebook* pointer;
typedef pointer list;

void createList (list& First)
{
	First=NULL;
}

void createNode (pointer& pBaru)
{
	pBaru=new phonebook;
	cout << "Name: "; cin.ignore(); cin.getline(pBaru->name,30);
	cout << "Number: "; cin >> pBaru->number;
	pBaru->next=NULL;
	pBaru->prev=NULL;
}

void insertFirst (list& First, pointer pBaru)
{
	if (First==NULL) First=pBaru;
	else
	{
		pBaru->next=First;
		First->prev=pBaru;
		First=pBaru;
	}
}

void insertLast (list& First, pointer pBaru)
{
	pointer last;
	last=First;
	if (First==NULL) First=pBaru;
	else
	{
		while (last->next!=NULL) 
		{
			last=last->next;
		}
		last->next=pBaru;
		pBaru->prev=last;
	}
}

void deleteFirst (list& First, pointer& pHapus)
{
	if (First==NULL) 
	{
		pHapus==NULL;
		cout << "Phonebook is empty." << endl;	
	}
	else if (First->next==NULL)
	{
		pHapus=First;
		First=NULL;
	}
	else
	{
		pHapus=First;
		First=First->next;
		First->prev=NULL;
		pHapus->next=NULL;
	}
}

void deleteLast (list& First, pointer& pHapus)
{
	pointer last;
	last=First;
	if (First==NULL)
	{
		pHapus=NULL;
		cout << "Phonebook is empty." << endl;
	}
	else if (First->next==NULL)
	{
		pHapus=First;
		First=NULL;
	}
	else
	{
		while (last->next!=NULL)
		{
			last=last->next;
		}
		pHapus=last;
		last->prev->next=NULL;
		pHapus->prev=NULL;
	}
}

void traversal (list First)
{
	pointer pBantu;
	pBantu=First;
	if (First==NULL) cout << "Phonebook is empty." << endl;
	else
	{
		do
		{	
			cout << "Name: " << pBantu->name << endl;
			cout << "Number: " << pBantu->number << endl;
			pBantu=pBantu->next;
		}
		while (pBantu!=NULL);
	}
}

int main(int argc, char** argv)
{
	pointer p, pHapus;
	list x;
	int opt;
	char opt1;
	
	createList(x);
	
	do
	{
		system("cls");
		cout << "My Phonebook\n"
			 << "Menu:\n"
			 << "1. Insert First\n"
			 << "2. Insert Last\n"
			 << "3. Delete First\n"
			 << "4. Delete Last\n"
			 << "5. Traversal\n"
			 << "Option: "; cin >> opt;
			 
		switch(opt)
		{
			case 1:  createNode(p);
					 insertFirst(x,p);
					 break;
			case 2:  createNode(p);
					 insertLast(x,p);
					 break;
			case 3:  deleteFirst(x,pHapus);
					 break;
			case 4:  deleteLast(x,pHapus);
					 break;
			case 5:  traversal(x);
					 break;
			default: cout << "Your option is not valid." << endl;
					 break;
		}
		cout << "Do you want to still edit the phonebook? (Y/N) "; cin >> opt1;
	}
	while (opt1=='Y' || opt1=='y');
}
