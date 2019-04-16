/*
Author    		: SURIADI VAJRAKARUNA
NPM		        : 140810180038
Deskripsi	    : strukdat-06, exercise-04
Tahun           : 2019
*/

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Isi
{
	char nama[20];
	char nomor[20];
	Isi* nextIsi;
};

struct Index
{
	char huruf[10];
	Isi* FirstIsi;
	Index* next;
};

typedef Index* pointerInd;
typedef Isi* pointerIsi;
typedef pointerInd ListInd;

void createListInd(ListInd& First)
{
	First=NULL;
}

void createElementInd(pointerInd& pBaru)
{
	pBaru=new Index;
	cout << "Nama Index: "; cin >> pBaru->huruf;
	pBaru->next=NULL;
	pBaru->FirstIsi=NULL;
}

void createElementIsi(pointerIsi& pBaru)
{
	pBaru=new Isi;
	cout << "Nama: "; cin >> pBaru->nama;
	cout << "Nomor: "; cin >> pBaru->nomor;
	pBaru->nextIsi=NULL;
}

void insertFirstInd(ListInd& First, pointerInd pBaru)
{
	if (First==NULL) First=pBaru;
	else
	{
		pBaru->next=First;
		First=pBaru;
	}
}

void deleteFirstInd(ListInd& First, pointerInd& pHapus)
{
	if (First==NULL) cout << "Data Index kosong." << endl;
	else if (First->next==NULL)
	{
		pHapus=First;
		First=NULL;
	}
	else
	{
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
	}
}

void linearSearch(ListInd First,char key[10],int& found, pointerInd& pCari){
	found=0;
	pCari=First;
	while(found==0 && pCari!=NULL)
	{
		if(strcmp(pCari->huruf,key)==0)
		{
			found=1;
		}
		else
		{
			pCari=pCari->next;
		}
	}
}

void insertFirstIsi(ListInd& First, pointerIsi pBaru, pointerInd pInd, char key[10])
{
	if (pInd->FirstIsi==NULL)
	{
		pInd->FirstIsi=pBaru;
	}
	else
	{
		pBaru->nextIsi=pInd->FirstIsi;
		pInd->FirstIsi=pBaru;
	}
}

void deleteFirstIsi(ListInd& First, pointerIsi& pHapus, pointerInd pInd, char key[10])
{	
	if(pInd->FirstIsi==NULL)
		{
			cout << "Tidak ada data di index ini." << endl;
		}
		else if(pInd->FirstIsi->nextIsi==NULL)
		{
			pHapus=pInd->FirstIsi;
			pInd->FirstIsi=NULL;
		}
		else
		{
			pHapus=pInd->FirstIsi;
			pInd->FirstIsi=pInd->FirstIsi->nextIsi;
			pHapus->nextIsi=NULL;	
		}
}
	
void traversal (ListInd First)
{
	pointerInd pBantuIndex;
	pointerIsi pBantuIsi;
	pBantuIndex=First;
    while (pBantuIndex!=NULL)
	{
        cout << pBantuIndex->huruf << endl;
        pBantuIsi=pBantuIndex->FirstIsi;
        	while (pBantuIsi!=NULL)
			{
            	cout << "	- " << pBantuIsi->nama << " / " << pBantuIsi->nomor << endl;
            	pBantuIsi=pBantuIsi->nextIsi;
        	}
      	pBantuIndex=pBantuIndex->next;
    }
}

int main(int argc, char** argv)
{
	pointerInd pInd, pHapusInd;
	ListInd x;
	pointerIsi pIsi, pHapusIsi;
	char key[10], pil;
	int n, menu, found;
	
	cout << "Jumlah Index: "; cin >> n;
	createListInd(x);
	for (int i=0; i<n; i++)
	{	
		createElementInd(pInd);
		insertFirstInd(x,pInd);
	}
	
	do
	{
		system("cls");
		cout << "Menu:\n"
			 << "1. Insert Index\n"
			 << "2. Insert Contact\n"
			 << "3. Delete Index\n"
			 << "4. Delete Contact\n"
			 << "5. Tampilkan phonebook\n"
			 << "Pilihan: "; 
		cin >> menu;
		switch (menu)
		{
			case 1: 
				createElementInd(pInd);
				insertFirstInd(x,pInd);
				break;
			case 2:
				cout << "Index yang ingin ditambah karyawan urutan pertama (Case Sensitive): "; cin>>key;
				linearSearch(x,key,found,pInd);
				if (found)
				{
					cout << "Index ditemukan." << endl;
					createElementIsi(pIsi);
					insertFirstIsi(x,pIsi,pInd,key);
				}
				else cout << "Index tidak ditemukan." << endl;
				break;
			case 3:
				deleteFirstInd(x,pHapusInd);
				break;
			case 4:
				cout << "Index yang ingin dihapus karyawan urutan pertama (Case Sensitive): "; cin>>key;
				if (found)
				{
					cout << "Index ditemukan." << endl;
					deleteFirstIsi(x,pHapusIsi,pInd,key);
				}
				else cout << "Index tidak ditemukan." << endl;
				break;
			case 5:
				traversal(x);
				break;
			default: 
			cout << "Menu yang anda inginkan tidak ada." << endl;
		}
		cout << "Apakah anda masih ingin menyunting (Y untuk Ya) "; cin >> pil;
	}
	while (pil=='Y' || pil=='y');
	return 0;
}
