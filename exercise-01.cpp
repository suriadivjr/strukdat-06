/*
Author    		: SURIADI VAJRAKARUNA
NPM		        : 140810180038
Deskripsi	    : strukdat-06, exercise-01
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
};

typedef phonebook* pointer;
typedef pointer List;

void createList (List& First)
{
	First=NULL;
}

void createNode (pointer& pBaru)
{
	pBaru=new phonebook;
	cout << "Name: "; cin.ignore(); cin.getline(pBaru->name,30);
	cout << "Number: "; cin >> pBaru->number;
	pBaru->next=NULL;
}

void insertFirst (List& First, pointer pBaru)
{
	if (First==NULL) First=pBaru;
	else 
	{
		pBaru->next=First;
		First=pBaru;
	}
}

void insertLast (List& First, pointer pBaru)
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
	}
}

void deleteFirst (List& First, pointer& pHapus)
{
	if (First==NULL)
	{
		pHapus==NULL;
		cout << "Phonebook is empty." << endl;
	}
	else if (First->next==NULL)
	{
		pHapus=First;
		pHapus=NULL;
	}
	else 
	{
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
	}
}

void deleteLast (List& First, pointer& pHapus)
{
	pointer last,precLast;
	last=First;
	precLast=NULL;
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
			precLast=last;
			last=last->next;
		}
		pHapus=last;
		precLast->next=NULL;
	}
}

void traversal (List First)
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
	List x;
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
