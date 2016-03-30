#ifndef READ_H
#define READ_H
#include "Interface.h"

class Read:public Interface{
	list<Person*> person;
	string name();
    string country();
    list<pair<string,int>> albumyear();
	list<pair<string,int>> songtrack();
    public:
		Read();
		void addPerson()override;
		void showAll()override;
		void addAlbum()override;
		static bool Compare(const pair<string,int> &x,const pair<string,int> &y);
		void displayAlbums()override;
		void displaySongs()override;
		void displayDiscography()override;
};

#endif READ_H