#include "Artist.h"

Artist::Artist(){}
Artist::~Artist(){}
Artist::Artist(list<pair<string,int>> songtrack, list<pair<string,int>> albumyear, string country, string name):
	Name(name),Country(country),AlbumYear(albumyear),SongTrack(songtrack){}

string Artist::getName(){
	return this->Name;
}

string Artist::getCountry(){
	return this->Country;
}

list<pair<string,int>> &Artist::getAlbumYear(){
	return this->AlbumYear;
}

list<pair<string,int>> &Artist::getSongTrack(){
	return this->SongTrack;
} 