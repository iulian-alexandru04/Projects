#include "Read.h"
#include<iostream>
#include<string>
#include<algorithm>

string Read::name(){
		string name;
		cout<<"Insert the name of the artist\n";
		cin>>name;
		cin.ignore();
		return name;
}

string Read::country(){
		string country;
		cout<<"Insert country\n";
		cin>>country;
		cin.ignore();
		return country;
}

list<pair<string,int>> Read::albumyear(){
	cout<<"Insert artist's album\n";
	list<pair<string,int>> albumyear;
	string a;
	getline(cin,a);
	int year;
	cout<<"Insert album's year\n";
	cin>>year;
	cin.ignore();
	albumyear.push_back(make_pair(a,year));
	return albumyear;
}

list<pair<string,int>> Read::songtrack(){
	cout<<"Insert the number of songs the album contains\n";
	int n;
	cin>>n;
	cin.ignore();
	list<pair<string,int>> songtrack;
	cout<<"Insert the songs and tracks\n";
	string a;
	int b;
	for(int i=0;i<n;i++){	
		getline(cin,a);
		cin>>b;
		cin.ignore();
		songtrack.push_back(make_pair(a,b));
	}
	songtrack.push_back(make_pair(" ",1));

	return songtrack;

}

Read::Read(){}
	  
void Read::addPerson(){
	this->person.push_back(new Artist(songtrack(),albumyear(),country(),name()));
}

void Read::showAll(){
	for(list<Person*>::iterator i=this->person.begin();i!=this->person.end();i++){
		cout<<(*i)->getName()<<", "<<(*i)->getCountry()<<endl;
		list<pair<string,int>>::iterator j=(*i)->getSongTrack().begin();
		for(list<pair<string,int>>::iterator k=(*i)->getAlbumYear().begin();k!=(*i)->getAlbumYear().end();k++,j++){
			cout<<k->first<<" , "<<k->second<<endl;
			while(j->first!=" " && j!=(*i)->getSongTrack().end()){
				cout<<j->second<<" , "<<j->first<<endl;
				j++;
			}
		}		
	}
}

void Read::addAlbum(){
	cout<<"Insert artist's name\n";
	string name;
	getline(cin,name);
	for(list<Person*>::iterator i=person.begin();i!=person.end();i++)
		if(name.compare((*i)->getName())==0){
			cout<<"Insert the number of albums\n";
			int n;
			cin>>n;
			cin.ignore();
			for(int t=0;t<n;t++){
				cout<<"Insert album's name and year\n";
				string b;
				int c;
				getline(cin,b);
				cin>>c;
				cin.ignore();
				(*i)->getAlbumYear().push_back(make_pair(b,c));
				cout<<"Insert the number of songs the album contains\n";
				int n;
				cin>>n;
				cin.ignore();
				cout<<"Insert song's name and track\n";
				for(int j=0;j<n;j++){
					getline(cin,b);
					cin>>c;
					cin.ignore();
					(*i)->getSongTrack().push_back(make_pair(b,c));

				}
				(*i)->getSongTrack().push_back(make_pair(" ",1));
			}
			return;
		}
		cout<<"The artist was not found\nWould you like to add him/her? (y/n)\n";
		string a;
		cin>>a;
		cin.ignore();
		cout<<a;

		if(a=="y")
			addPerson();
}

bool Read::Compare(const pair<string,int> &x,const pair<string,int> &y){
	return x.second>y.second;
}
void Read::displayAlbums(){
	cout<<"Insert artist's name\n";
	string name;
	getline(cin,name);
	for(list<Person*>::iterator i=this->person.begin();i!=this->person.end();i++)
		if(name.compare((*i)->getName())==0){
			(*i)->getAlbumYear().sort(Compare);
			for(list<pair<string,int>>::iterator j=(*i)->getAlbumYear().begin();j!=(*i)->getAlbumYear().end();j++)
				cout<<j->first<<" ";
		}
}
void Read::displaySongs(){
	cout<<"Insert artist's name\n";
	string name;
	getline(cin,name);
	for(list<Person*>::iterator i=this->person.begin();i!=this->person.end();i++)
		if(name.compare((*i)->getName())==0){
			for(list<pair<string,int>>::iterator j=(*i)->getSongTrack().begin();j!=(*i)->getSongTrack().end();j++){
				if(j->first==" ")
					cout<<endl;
				else cout<<j->first<<endl;	
			}		
		}
}
void Read::displayDiscography(){
	cout<<"Insert artist's name\n";
	string name;
	getline(cin,name);
	for(list<Person*>::iterator i=this->person.begin();i!=this->person.end();i++)
		if(name.compare((*i)->getName())==0){
			cout<<(*i)->getName()<<", "<<(*i)->getCountry()<<endl;
			list<pair<string,int>>::iterator j=(*i)->getSongTrack().begin();
			for(list<pair<string,int>>::iterator k=(*i)->getAlbumYear().begin();k!=(*i)->getAlbumYear().end();k++,j++){
				cout<<k->first<<" , "<<k->second<<endl;
				while(j->first!=" " && j!=(*i)->getSongTrack().end()){
					cout<<j->second<<" , "<<j->first<<endl;
					j++;
				}
			}
		}
}
