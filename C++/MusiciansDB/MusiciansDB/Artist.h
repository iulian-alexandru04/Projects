#ifndef ARTIST_H
#define ARTIST_H
#include "Person.h"

class Artist:public Person{
    string Name;
    string Country;
    list<pair<string,int>> AlbumYear;
	list<pair<string,int>> SongTrack;
public:
	Artist();
	Artist(list<pair<string,int>> songtrack, list<pair<string,int>> albumyear, string country, string name);
	virtual ~Artist();
	string getName()override;
    string getCountry()override;
    list<pair<string,int>> &getAlbumYear()override;
	list<pair<string,int>> &getSongTrack()override;
};

#endif ARTIST_H