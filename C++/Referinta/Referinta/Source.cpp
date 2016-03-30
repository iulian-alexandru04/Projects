#include<iostream>
#include<string>
using namespace std;

class Referinta {
public:
	Referinta() {}
	virtual ~Referinta() {}
	virtual void show(ostream &out) {}
	friend ostream &operator<<(ostream &out, Referinta &x) {
		x.show(out);
		return out;
	}
};

class Webografie :public Referinta {
	char* name;
	char* title;
	char* url;
	int* date;
public:
	virtual ~Webografie() {
		delete[] name;
		delete[] title;
		delete[] date;
	}
	Webografie(int* _date, char* _url, char* _title, char* _name) :Referinta(), date(new int[3]), url(new char[100]), title(new char[100]), name(new char[100]) {
		date = _date;
		url = _url;
		title = _title;
		name = _name;
	}
	virtual void show(ostream &out) {
		out << this->name << ": " << this->title << ". " << this->url << " (accesat " << this->date[0] << " " << this->date[1] << " " << this->date[2] << " )" << endl;
	}

};


class Bibliografie :public Referinta {
public:
	virtual ~Bibliografie() {}
	Bibliografie() {}
	friend ostream &operator<<(ostream &out, Bibliografie &x) {
		x.show(out);
		return out;
	}

};


class Articol :public Bibliografie {
	char* name;
	char* title;
	int year;
	char* eName;
	int no;
	int nr;
public:
	virtual ~Articol() {
		delete[] name;
		delete[] title;
		delete[] eName;
	}
	Articol(int _nr, int _no, char* _eName, int _year, char* _title, char* _name) :Bibliografie(), nr(_nr), no(_no), eName(new char[100]), year(_year), title(new char[100]),
		name(new char[100]) {
		name = _name;
		eName = _eName;
		title = _title;
	}
	virtual void show(ostream &out) {

		out << this->name << ": " << this->title << ". " << this->eName << ", " << this->year << ", " << this->nr << ", " << this->no << ".\n";
	}

};

class Carte :public Bibliografie {
	char* name;
	char* title;
	int year;
	char* eName;
	char* cityname;

public:
	Carte(char* _cityname, char* _eName, int _year, char* _title, char* _name) :Bibliografie(), cityname(new char[100]), eName(new char[100]), year(_year), title(new char[100]),
		name(new char[100]) {
		name = _name;
		title = _title;
		eName = _eName;
		cityname = _cityname;

	}
	virtual ~Carte() {
		delete[] name;
		delete[] title;
		delete[] eName;
		delete[] cityname;
	}
	virtual void show(ostream &out) {

		out << this->name << ": " << this->title << ". " << this->eName << ". " << this->cityname << ", " << this->year << ".\n";
	}
};
class Read {
public:
	Read() {}
	char* seteName() {
		cout << "Introduceti numele editurii/articolului\n";
		char* s = new char[100];
		cin.get();
		cin.get(s, 99);

		return s;
	}
	int setNo() {
		cout << "Introduceti numarul articolului\n";
		int s;
		cin >> s;
		return s;
	}
	int setNr() {
		cout << "Introduceti numarul de pagini\n";
		int s;
		cin >> s;
		return s;
	}
	char* setCity() {
		cout << "Introduceti orasul editurii\n";
		char* s = new char[100];
		cin.get();
		cin.get(s, 99);
		return s;
	}


	char* setName() {
		char* s = new char[100];
		cout << "Introduceti numele autorilor/proprietarului\n";
		cin.get();
		cin.get(s, 99);
		return s == "***" ? "Neucnoscut" : s;
	}

	char* setTitle() {

		char* s = new char[100];
		cout << "Introduceti numele referintei\n";
		cin.get();
		cin.get(s, 99);
		return s;
	}
	int setYear() {
		cout << "Introduceti anul publicarii articolului/cartii\n";
		int s;
		cin >> s;
		return s;
	}



	char* setURL() {
		cout << "Introduceti URL-ul paginii WEB\n";
		char* s = new char[100];
		cin.get();
		cin.get(s, 99);
		return s;
	}
	int* setDate() {
		cout << "Introduceti data accesarii\n";
		int* s = new int[3];

		for (int i = 0;i<3;i++)
			cin >> s[i];
		return s;
	}


	int getType() {
		cout << "1.Webografie \t2.Carte \t3.Articol\n";
		int ok;

		do {
			cin >> ok;
		} while (ok<1 || ok>3);
		return ok;
	}

	Referinta* add() {
		return new Webografie(setDate(), setURL(), setTitle(), setName());

	}
	Bibliografie* add(int a) {
		if (a == 2)return new Carte(setCity(), seteName(), setYear(), setTitle(), setName());
		return new Articol(setNr(), setNo(), seteName(), setYear(), setTitle(), setName());
	}
};




int main() {
	Referinta* obiect[10];
	Bibliografie *obiect1[10];
	Read* obj[10];
	int nr[100], mr[100];
	for (int i = 0;i<10;i++)
		mr[i] = 0;
	for (int i = 0;i<10;i++)
		obj[i] = new Read();
	int k = 0, j = 0;
	for (int i = 0;i<3;i++) {
		nr[i] = obj[i]->getType();
		if (nr[i] == 1) { obiect[k++] = obj[i]->add(); }
		else { mr[j] = nr[i];obiect1[j++] = obj[i]->add(nr[i]); }
	}

	cout << "Webografie\n";
	if (k)
		for (int i = 0;i<k;i++)cout << *obiect[i] << endl;
	cout << "Bibliografie\n";
	cout << "Articole\n";

	if (j)
		for (int i = 0;i<3;i++)if (mr[i] == 3)cout << *obiect1[i] << endl;
	cout << "Carti\n";
	if (j)
		for (int i = 0;i<3;i++)if (mr[i] == 2)cout << *obiect1[i] << endl;


	system("pause");
	return 0;
}