#ifndef PERSON_H
#define PERSON_H
#include<list>
using namespace std;

class Person{
public:
    virtual string getName()=0;
    virtual string getCountry()=0;
	virtual list<pair<string,int>> &getAlbumYear()=0;
	virtual list<pair<string,int>> &getSongTrack()=0;
	virtual ~Person(){}
};

#endif PERSON_H