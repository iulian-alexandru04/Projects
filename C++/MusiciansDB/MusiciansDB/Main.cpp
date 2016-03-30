#include<iostream>
#include "Person.h"
#include "Artist.h"
#include "Interface.h"
#include "Read.h"
using namespace std;

int main(){
	int ok;
	Interface *k=new Read();
	do{
		cout<<"1.Add an artist\n2.Add album for an artist\n3.Dsiplay all album names for an artist\n4.Display all songs an artist has released\n5.Display discography for an artist\n6.Display all artists and their informations\n0.EXIT\n";
		cin>>ok;
		cin.ignore();
		switch(ok){
		case 1:
			k->addPerson();
			break;
		case 2:
			k->addAlbum();
			break;
		case 3:{
			system("cls");
			k->displayAlbums();
			system("pause");
			system("cls");
			   }
			break;
		case 4:{
			system("cls");
			k->displaySongs();
			system("pause");
			system("cls");
			   }
			break;
		case 5:{
			system("cls");
			k->displayDiscography();
			system("pause");
			system("cls");
			   }
			break;
		case 6:{
			system("cls");
			k->showAll();
			system("pause");
			system("cls");
			   }
			break;
		case 0:
			break;
		}
	}while(ok);
	
    system("pause");
    return 0; 
}
