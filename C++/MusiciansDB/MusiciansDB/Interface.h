#ifndef INTERFACE_H
#define INTERFACE_H
#include "Person.h"
#include "Artist.h"

class Interface{
public:
	virtual void addPerson()=0;
	virtual void showAll()=0;
	virtual void addAlbum()=0;
	virtual void displayAlbums()=0;
	virtual void displaySongs()=0;
	virtual void displayDiscography()=0;
};

#endif INTERFACE_H