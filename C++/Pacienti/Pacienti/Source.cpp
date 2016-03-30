#include<iostream>
using namespace std;

class Pacient {
public:
	Pacient() {}
	virtual ~Pacient() {};
	virtual void show(ostream &out) {}

	friend ostream &operator<<(ostream &out, Pacient &x) {
		x.show(out);
		return out;
	}
	virtual int riscCardio() {
		return 0;
	}
	virtual int riscAvansat() {
		return 0;
	}
	virtual char* getName()const {
		return NULL;
	}
};

class Adult :public Pacient {

public:
	virtual ~Adult() {}
	friend ostream &operator<<(ostream &out, Adult &x) {
		x.show(out);
		return out;
	}
};

class Peste :public Adult {
	char* Surname;
	char* Name;
	char* Adress;
	int Age;
	int Colesterol;
	int Tensiune;
	int* DateC;
	int* DateT;
	char* Sedentar;
	int Fumator;
public:
	Peste(int _Fumator, char* _Sedentar, int* _DateT, int* _DateC, int _Tensiune, int _Colesterol, int _Age, char* _Adress, char* _Name, char* _Surname) :
		Surname(new char[strlen(_Surname) + 1]), Name(new char[strlen(_Name) + 1]), Adress(new char[strlen(_Adress) + 1]), Age(_Age), Colesterol(_Colesterol),
		Tensiune(_Tensiune), DateC(new int[3]), DateT(new int[3]), Sedentar(new char[strlen(_Sedentar) + 1]), Fumator(_Fumator) {
		Surname = _Surname;
		Name = _Name;
		Adress = _Adress;
		DateC = _DateC;
		DateT = _DateT;
		Sedentar = _Sedentar;
	}
	virtual ~Peste() {
		delete[] Surname;
		delete[] Name;
		delete[] Adress;
		delete[] DateT;
		delete[] DateC;
		delete[] Sedentar;
	}
	virtual void show(ostream &out) {
		out << this->Surname << " " << this->Name << ": Risc cardiovascular -";
		if (riscCardio() && !riscAvansat())out << "DA; ";
		if (riscAvansat())out << "RIDICAT; ";
		if (!riscCardio() && !riscAvansat())out << "NU; ";
		out << "Colesterol (" << this->DateC[0] << "." << this->DateC[1] << "." << this->DateC[2] << "): " << this->Colesterol << " mg/dl; TA (" << this->DateT[0] << "." << this->DateT[1] << "." << this->DateT[2] << "): " << this->Tensiune << "; Fumator: ";
		if (this->Fumator)
			out << "da; ";
		else out << "nu; ";
		out << "Sedentarism: " << this->Sedentar << ".\n";
	}
	virtual int riscCardio() {
		if (this->Colesterol >= 240 || this->Tensiune >= 140 || this->Sedentar == "ridicat" && this->Fumator == 1)
			return 1;
		return 0;
	}
	virtual char* getName()const {
		return this->Surname;
	}
	virtual int riscAvansat() {
		if (this->Colesterol >= 240 && this->Tensiune >= 140 || this->Tensiune >= 140 && this->Sedentar == "ridicat" && this->Fumator == 1 ||
			this->Colesterol >= 240 && this->Sedentar == "ridicat" && this->Fumator == 1)
			return 1;
		return 0;
	}

};

class Sub :public Adult {
	char* Surname;
	char* Name;
	char* Adress;
	int Age;
	int Colesterol;
	int Tensiune;
	int* DateC;
	int* DateT;

public:
	Sub(int* _DateT, int* _DateC, int _Tensiune, int _Colesterol, int _Age, char* _Adress, char* _Name, char* _Surname) :
		Surname(new char[strlen(_Surname) + 1]), Name(new char[strlen(_Name) + 1]), Adress(new char[strlen(_Adress) + 1]), Age(_Age), Colesterol(_Colesterol),
		Tensiune(_Tensiune), DateC(new int[3]), DateT(new int[3]) {
		Surname = _Surname;
		Name = _Name;
		Adress = _Adress;
		DateC = _DateC;
		DateT = _DateT;
	}
	virtual ~Sub() {
		delete[] Surname;
		delete[] Name;
		delete[] Adress;
		delete[] DateT;
		delete[] DateC;
	}
	virtual void show(ostream &out) {
		out << this->Surname << " " << this->Name << ": Risc cardiovascular -";
		if (riscCardio() && !riscAvansat())out << "DA; ";
		if (riscAvansat())out << "RIDICAT; ";
		if (!riscCardio() && !riscAvansat())out << "NU; ";
		out << "Colesterol (" << this->DateC[0] << "." << this->DateC[1] << "." << this->DateC[2] << "): " << this->Colesterol << " mg/dl; TA (" << this->DateT[0] << "." << this->DateT[1] << "." << this->DateT[2] << "): " << this->Tensiune << ".";
		out << endl;
	}
	virtual int riscCardio() {
		if (this->Colesterol >= 240 || this->Tensiune >= 140)
			return 1;
		return 0;
	}
	virtual int riscAvansat() {
		if (this->Colesterol >= 240 && this->Tensiune >= 140)
			return 1;
		return 0;
	}
	virtual char* getName()const {
		return this->Surname;
	}

};

class Copil :public Adult {
	char* Surname;
	char* Name;
	char* Adress;
	int Age;
	int Colesterol;
	int Tensiune;
	int* DateC;
	int* DateT;
	int Antecedent;
	char* Mama;
	char* Tata;
	double Reactive;
	int* DateR;

public:
	Copil(int* _DateR, double _Reactive, char* _Tata, char* _Mama, int _Antecedent, int* _DateT, int* _DateC, int _Tensiune, int _Colesterol, int _Age, char* _Adress, char* _Name, char* _Surname) :
		DateR(new int[3]), Reactive(_Reactive), Tata(new char[strlen(_Tata) + 1]), Mama(new char[strlen(_Mama) + 1]), Antecedent(_Antecedent), Surname(new char[strlen(_Surname) + 1]), Name(new char[strlen(_Name) + 1]), Adress(new char[strlen(_Adress) + 1]), Age(_Age), Colesterol(_Colesterol),
		Tensiune(_Tensiune), DateC(new int[3]), DateT(new int[3]) {
		Surname = _Surname;
		Name = _Name;
		Adress = _Adress;
		DateC = _DateC;
		DateT = _DateT;
		Mama = _Mama;
		Tata = _Tata;
		DateR = _DateR;
	}
	virtual ~Copil() {
		delete[] Surname;
		delete[] Name;
		delete[] Adress;
		delete[] DateT;
		delete[] DateC;
		delete[] Mama;
		delete[] Tata;
	}
	virtual void show(ostream &out) {
		out << this->Surname << " " << this->Name << ": Risc cardiovascular -";
		if (riscCardio() && !riscAvansat())out << "DA; ";
		if (riscAvansat())out << "RIDICAT; ";
		if (!riscCardio() && !riscAvansat())out << "NU; ";
		out << "Colesterol (" << this->DateC[0] << "." << this->DateC[1] << "." << this->DateC[2] << "): " << this->Colesterol << " mg/dl; TA (" << this->DateT[0] << "." << this->DateT[1] << "." << this->DateT[2] << "): " << this->Tensiune << "; Proteina C reactiva (" << this->DateR[0] << "." << this->DateR[1] << "." << this->DateR[2] << "): " << this->Reactive << " mg/dl; " << "Antecedente familie: ";
		if (this->Antecedent) {
			out << "da (";
			if (Mama[0] != '\0'&& Tata[0] == '\0')
				out << Mama << "). \n";
			else if (Tata[0] != '\0'&& Mama[0] == '\0')
				out << Tata << "). \n";
			else
				out << Mama << ", " << Tata << "). \n";
		}
		else out << "nu.\n";
	}
	virtual int riscCardio() {
		if (this->Colesterol >= 240 || this->Tensiune >= 140 || this->Antecedent || this->Reactive >= 0.61)
			return 1;
		return 0;
	}
	virtual int riscAvansat() {
		if (this->Colesterol >= 240 && this->Tensiune >= 140 || this->Colesterol >= 240 && this->Antecedent || this->Colesterol >= 240 && this->Reactive >= 0.61
			|| this->Tensiune >= 140 && this->Antecedent || this->Tensiune >= 140 && this->Reactive >= 0.61 || this->Antecedent && this->Reactive >= 0.61)
			return 1;
		return 0;
	}
	virtual char* getName()const {
		return this->Surname;
	}
};

class Fisa {
	int copii;
	int adultisub;
	int adultipeste;
public:
	Fisa() {
		copii = 0;
		adultipeste = 0;
		adultisub = 0;
	}
	void add(Pacient** copil, Adult** adult) {

		int num;
		cout << "Introduceti numarul pacientilor pe care vreti sa ii introduceti\n";
		cin >> num;
		do {
			char* nume = new char[40], *prenume = new char[40], *sedentarism = new char[40], *adresa = new char[50], *mama = new char[40], *tata = new char[40];
			int varsta, colesterol, tensiune, *datac = new int[3], *datat = new int[3], fumator, *datar = new int[3], antecedent, ok;
			double reactiv;
			num--;
			cout << "Numele Pacientului\n";
			cin.get();
			cin.get(nume, 39);
			cout << "Prenumele Pacientului\n";
			cin.get();
			cin.get(prenume, 39);
			cout << "Varsta\n";
			cin.get();
			cin >> varsta;
			cout << "Adresa\n";
			cin.get();
			cin.get(adresa, 49);
			cout << "Colesterol\n";
			cin.get();
			cin >> colesterol;
			cin.get();

			cout << "Data efectuarii analizei pentru colesterol\n";
			for (int i = 0;i<3;i++)
				cin >> datac[i];
			cout << "Tensiune\n";
			cin.get();

			cin >> tensiune;
			cout << "Data efectuarii analizei pentru tensiune\n";
			cin.get();

			for (int i = 0;i<3;i++)
				cin >> datat[i];

			if (varsta>40) {
				cout << "Indicati sedentarismul(scazut, mediu sau ridicat)\n";
				cin.get();
				cin.get(sedentarism, 39);
				cout << "Fumator?\n";
				cin.get();
				cin >> fumator;
				adult[adultipeste++] = new Peste(fumator, sedentarism, datat, datac, tensiune, colesterol, varsta, adresa, prenume, nume);
			}
			else if (varsta >= 18 && varsta <= 40) {
				adult[10 + adultisub] = new Sub(datat, datac, tensiune, colesterol, varsta, adresa, prenume, nume);
				adultisub++;
			}
			else if (varsta<18) {
				cout << "Antecedente in familie?(1/0)\n";
				cin.get();
				cin >> antecedent;
				if (antecedent == 1) {
					cout << "Ce parinte are antecedente(mama=1,tata=0,ambii=2)?\n";
					cin.get();
					cin >> ok;
					if (ok == 0) {
						cout << "Prenumele tatalui\n";
						cin.get();
						cin.get(tata, 39);
						mama[0] = '\0';
					}
					else if (ok == 1)
					{
						cout << "Prenumele mamei\n";
						cin.get();
						cin.get(mama, 39);
						tata[0] = '\0';
					}
					else if (ok == 2) {
						cout << "Prenumele tatalui\n";
						cin.get();
						cin.get(tata, 39);
						cout << "Prenumele mamei\n";
						cin.get();
						cin.get(mama, 39);
					}
				}
				else
				{
					mama[0] = '\0';
					tata[0] = '\0';
				}
				cout << "Proteina C reactiva\n";
				cin.get();
				cin >> reactiv;
				cout << "Data cand a fost efectuata analiza pentru proteina c reactiva\n";
				cin.get();
				for (int i = 0;i<3;i++)
					cin >> datar[i];


				copil[copii++] = new Copil(datar, reactiv, tata, mama, antecedent, datat, datac, tensiune, colesterol, varsta, adresa, prenume, nume);
			}
		} while (num);
	}
	void show(Pacient** copil, Adult** adult) {
		cout << "Adulti\n";
		if (adultipeste) {
			cout << "Adulti peste 40 de ani\n";
			for (int i = 0;i<adultipeste;i++)
				cout << *adult[i];
			cout << endl;
		}
		if (adultisub) {
			cout << "Adulti sub 40 de ani\n";
			for (int i = 0;i<adultisub;i++)
				cout << *adult[10 + i];
			cout << endl;
		}
		if (copii) {
			cout << "Copii\n";
			for (int i = 0;i<copii;i++)
				cout << *copil[i];
			cout << endl;
		}
	}
	void show(Adult** adult) {
		for (int i = 0;i<adultipeste;i++)
			if (adult[i]->riscAvansat())
				cout << *adult[i];
		for (int i = 0;i<adultisub;i++)
			if (adult[10 + i]->riscAvansat())
				cout << *adult[10 + i];
	}
	void show(Pacient** copil) {
		if (copii)
			for (int i = 0;i<copii;i++)
				if (copil[i]->riscCardio() && !copil[i]->riscAvansat())
					cout << *copil[i];
	}
	void show(Adult** adult, Pacient** copil) {
		cout << "Introduceti numele de familie\n";
		char *nume = new char[40];
		cin.get();
		cin.get(nume, 39);
		if (adultipeste) {
			for (int i = 0;i<adultipeste;i++)
				if (!strcmp(nume, adult[i]->getName()))
					cout << *adult[i];
		}
		if (adultisub)
			for (int i = 0;i<adultisub;i++)
				if (!strcmp(nume, adult[10 + i]->getName()))
					cout << *adult[10 + i];
		if (copii)
			for (int i = 0;i<copii;i++)
				if (!strcmp(nume, copil[i]->getName()))
					cout << *copil[i];
		cout << endl;
	}
};

int main() {

	Fisa *obj = new Fisa();
	Pacient* copil[10];
	Adult* adult[20];
	obj->add(copil, adult);
	obj->show(copil, adult);
	obj->show(adult);
	obj->show(copil);
	obj->show(adult, copil);

	system("pause");
	return 0;
}
