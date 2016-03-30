#include<iostream>
using namespace std;

class Muncitor {
public:
	virtual ~Muncitor() {}
	virtual void show(ostream &out) {}
	virtual int* getEnd() {
		return 0;
	}
	friend ostream &operator<<(ostream &out, Muncitor &x) {
		x.show(out);
		return out;
	}
};

class Temporar :public Muncitor {
	char* Name;
	char* Type;
	int* Date;
	int* End;

public:
	Temporar(int* _End, int* _Date, char* _Type, char* _Name) :End(new int[3]), Type(new char[40]), Date(new int[3]), Name(new char[40]) {
		Type = _Type;
		Date = _Date;
		Name = _Name;
		End = _End;
	}
	virtual ~Temporar() {
		delete[] Name;
		delete[] Type;
		delete[] Date;
	}
	virtual int* getEnd() {
		return this->End;
	}
	virtual void show(ostream &out) {
		out << this->Name << ", " << this->Type << ", " << this->Date[0] << "." << this->Date[1] << "." << this->Date[2] << " -- " << this->End[0] << "." << this->End[1] << "." << this->End[2] << ", prima: ";
	}
};

class Permanent :public Muncitor {
public:
	virtual ~Permanent() {}
	virtual int getChild() {
		return 0;
	}
	virtual int getWeek() {
		return 0;
	}
	virtual int Calculate(int) {
		return 0;
	}
	friend ostream &operator<<(ostream &out, Permanent &x) {
		x.show(out);
		return out;
	}
};

class Tesa :public Permanent {
	char* Name;
	char* Type;
	int* Date;
	char* Activity;
	int Week;

public:
	virtual ~Tesa() {
		delete[] Name;
		delete[] Type;
		delete[] Date;
		delete[] Activity;
	}
	Tesa(int _Week, char* _Activity, int* _Date, char* _Type, char* _Name) :
		Week(_Week), Activity(new char[40]), Date(new int[3]), Type(new char[40]), Name(new char[40]) {
		Activity = _Activity;
		Date = _Date;
		Type = _Type;
		Name = _Name;
	}
	virtual int getWeek() {
		return this->Week;
	}
	virtual void show(ostream &out) {
		out << this->Name << ", " << this->Type << ", " << this->Date[0] << "." << this->Date[1] << "." << this->Date[2] << ", " << this->Activity << ", weekend: " << this->Week << ", prima: ";
	}
};

class Lucrativ :public Permanent {
	char* Name;
	char* Type;
	int* Date;
	char* Activity;
	int Child;

public:
	Lucrativ(char* _Activity, int* _Date, char* _Type, char* _Name, int _Child) :
		Activity(new char[40]), Date(new int[3]), Type(new char[40]), Name(new char[40]), Child(_Child) {
		Activity = _Activity;
		Date = _Date;
		Type = _Type;
		Name = _Name;
	}
	virtual ~Lucrativ() {
		delete[] Name;
		delete[] Type;
		delete[] Date;
		delete[] Activity;
	}

	virtual int getChild() {
		return this->Child;
	}

	virtual int Calculate(int x) {
		return (int)(x + x*this->Child*(2014 - this->Date[2]) / 100);
	}
	virtual void show(ostream &out) {
		out << this->Name << ", " << this->Type << ", " << this->Date[0] << "." << this->Date[1] << "." << this->Date[2] << ", " << this->Activity << ", milucrri: " << this->Child << ", prima: ";
	}
};

class Resurse {
	int lucr;
	int temp;
	int tesa;
	int prima;
public:

	Resurse() {
		lucr = 0;
		temp = 0;
		tesa = 0;
		prima = 0;
	}
	~Resurse() {}
	void test(Muncitor** k, Permanent** ok) {
		cout << "Introduceti numarul angajatilor\n";
		int ang;
		cin >> ang;


		cout << "Introduceti prima\n";
		cin >> this->prima;

		do {
			ang--;
			char* nume = new char[40];
			cout << "Numele si prenumele\n";
			cin.get();
			cin.get(nume, 39);
			cout << "Tipul contractului(plata cu ora/permanent)\n";
			char* tip = new char[40];
			cin.get();
			cin.get(tip, 39);
			cout << "Data intrarii in vigoare a contractului\n";
			int* data = new int[3];
			for (int i = 0;i<3;i++)
				cin >> data[i];
			char* activitate = new char[40];
			if (!strcmp(tip, "plata cu ora")) {
				cout << "Data terminarii contractului\n";
				int* sfarsit = new int[3];
				for (int i = 0;i<3;i++)
					cin >> sfarsit[i];

				k[temp++] = new Temporar(sfarsit, data, "plata cu ora", nume);

			}
			else {
				cout << "Tipul activitatii (TESA/lucrativ)\n";

				cin.get();
				cin.get(activitate, 39);
			}

			if (!strcmp(activitate, "TESA")) {
				cout << "Alegeti numarul Weekendului pentru vacanta\n";
				int numar;
				cin >> numar;

				ok[10 + tesa] = new Tesa(numar, "TESA", data, "contract permanent", nume);
				tesa++;
			}
			if (!strcmp(activitate, "lucrativ")) {
				cout << "Numarul de copii\n";
				int numar;
				cin >> numar;

				ok[lucr++] = new Lucrativ("lucrativ", data, "contract permanent", nume, numar);
			}

		} while (ang != 0);

	}
	void show(Muncitor** k, Permanent** ok) {
		int bonus;
		for (int i = 0;i<temp;i++) {
			cout << *k[i];
			if (k[i]->getEnd()[2] == 2014)
				bonus = this->prima / 2;
			else bonus = this->prima;
			cout << bonus << endl;
		}
		for (int i = 0;i<tesa;i++)
			cout << *ok[10 + i] << this->prima << endl;

		for (int i = 0;i<lucr;i++)
			cout << *ok[i] << ok[i]->Calculate(this->prima) << endl;

	}
	void show2(Permanent** ok) {
		cout << "Angajatii care au copii \n";
		for (int i = 0;i<lucr;i++)
			if (ok[i]->getChild())cout << *ok[i] << ok[i]->Calculate(this->prima) << endl;
	}
	void show3(Permanent** ok) {
		cout << "Angajatii care au ales al doilea weekend\n";
		for (int i = 0;i<tesa;i++)
			if (ok[10 + i]->getWeek() == 2)cout << *ok[10 + i] << this->prima << endl;
	}
	void show4(Muncitor** k) {
		cout << "Angajatii in regim de plata cu ora care au contract pana cel putin in martie 2015\n";
		for (int i = 0;i<temp;i++)
			if (k[i]->getEnd()[1] >= 3 && k[i]->getEnd()[2] >= 2015)
				cout << *k[i] << this->prima;
	}


};

int main() {
	Muncitor* k[10];
	Permanent* ok[20];
	Resurse* obj = new Resurse();
	cout << endl;
	obj->test(k, ok);
	obj->show(k, ok);
	cout << endl;
	obj->show2(ok);
	cout << endl;
	obj->show3(ok);
	cout << endl;
	obj->show4(k);
	cout << endl;
	system("pause");
	return 0;
}