#include<iostream>

#include<string>
using namespace std;

class Magazin {
public:
	Magazin() {}
	virtual void show(ostream &out) = 0;
	virtual string getName() = 0;
	virtual double getQuant() = 0;
	virtual int getPrice() = 0;
	virtual int getDiscount() = 0;
	virtual int* getExp() = 0;
	virtual int* getDate() = 0;
	virtual ~Magazin() {}
	friend ostream &operator<<(ostream &out, Magazin &x) {
		x.show(out);
		return out;
	}

};

class Bucata : public Magazin {
private:

	string name;
	double quant;
	int discount;
	int price;
	int *date;
	int* exp;
public:
	Bucata(string _name, int _price, double _quant, int *_date, int _discount, int* _exp) :Magazin(), name(_name), price(_price), quant(_quant), date(new int[3]), discount(_discount), exp(new int[3]) {
		date = _date;
		exp = _exp;

	}

	virtual ~Bucata() {}
	virtual int getPrice() {
		return this->price;
	}
	virtual int getDiscount() {
		return this->discount;
	}
	virtual string getName() {
		return this->name;
	}
	virtual double getQuant() {
		return this->quant;
	}
	virtual int* getDate() {
		return this->date;
	}
	virtual int*getExp() {
		return this->exp;
	}
	virtual void show(ostream &out) {
		if (this->discount == 0)
			out << "pe data de " << this->date[0] << " " << this->date[1] << " " << this->date[2] << ", magazinul primeste un lot de " << this->quant << " de " << this->name << " la pretul de " << this->price << " lei bucata\n";
		else
			out << "pe data de " << this->date[0] << " " << this->date[1] << " " << this->date[2] << ", magazinul primeste un lot de " << this->quant << " de " << this->name << " la pretul de " << this->price << " lei bucata, la care decide sa aplice un discount de " << this->discount << "\n";
	}


};

class Greutate : public Magazin {
private:

	string name;
	double quant;
	int discount;
	int price;
	int *date;
	int* exp;

public:

	Greutate(string _name, int _price, double _quant, int* _date, int _discount, int* _exp) :Magazin(), name(_name), price(_price), quant(_quant), date(new int[3]), discount(_discount), exp(new int[3]) {
		date = _date;
		exp = _exp;
	}
	virtual ~Greutate() {}
	virtual int getPrice() {
		return this->price;
	}
	virtual int getDiscount() {
		return this->discount;
	}
	virtual int* getExp() {
		return this->exp;
	}
	virtual string getName() {
		return this->name;
	}
	virtual double getQuant() {
		return this->quant;
	}
	virtual int* getDate() {
		return this->date;
	}
	virtual void show(ostream &out) {
		if (this->discount == 0)
			if (this->exp[0] == 0)
				out << "pe data de " << this->date[0] << " " << this->date[1] << " " << this->date[2] << ", magazinul primeste un lot de " << this->quant << " kg de " << this->name << ", la pretul de " << this->price << " lei pe kg\n";
			else
				out << "pe data de " << this->date[0] << " " << this->date[1] << " " << this->date[2] << ", magazinul primeste un lot de " << this->quant << " kg de " << this->name << ", cu termen de valabilitate " << this->exp[0] << " " << this->exp[1] << " " << this->exp[2] << ", la pretul de " << this->price << " lei pe kg\n";
		else
			if (this->exp[0] == 0)
				out << "pe data de " << this->date[0] << " " << this->date[1] << " " << this->date[2] << ", magazinul primeste un lot de " << this->quant << " kg de " << this->name << ", la pretul de " << this->price << " lei pe kg, la care decide sa aplice un discount de " << this->discount << "\n";
			else
				out << "pe data de " << this->date[0] << " " << this->date[1] << " " << this->date[2] << ", magazinul primeste un lot de " << this->quant << " kg de " << this->name << ", cu termen de valabilitate " << this->exp[0] << " " << this->exp[1] << " " << this->exp[2] << ", la pretul de " << this->price << " lei pe kg, la care decide sa aplice un discount de " << this->discount << "\n";
	}
};

class Volum : public Magazin {
private:
	string name;
	double quant;
	int discount;
	int price;
	int* date;
	int* exp;

public:
	Volum(string _name, int _price, double _quant, int* _date, int _discount, int* _exp) :Magazin(), name(_name), price(_price), quant(_quant), date(new int[3]), discount(_discount), exp(new int[3]) {
		date = _date;
		exp = _exp;
	}

	virtual ~Volum() {}
	virtual int getPrice() {
		return this->price;
	}
	virtual int getDiscount() {
		return this->discount;
	}
	virtual int* getExp() {
		return this->exp;
	}
	virtual string getName() {
		return this->name;
	}
	virtual double getQuant() {
		return this->quant;
	}
	virtual int* getDate() {
		return this->date;
	}
	virtual void show(ostream &out) {
		if (this->discount == 0)
			if (this->exp[0] == 0)
				out << "pe data de " << this->date[0] << " " << this->date[1] << " " << this->date[2] << ", magazinul primeste un lot de " << this->quant << " litri de " << this->name << ", la pretul de " << this->price << " lei pe litru\n";
			else
				out << "pe data de " << this->date[0] << " " << this->date[1] << " " << this->date[2] << ", magazinul primeste un lot de " << this->quant << " litri de " << this->exp[0] << " " << this->exp[1] << " " << this->exp[2] << ", cu termen de valabilitate " << this->exp << ", la pretul de " << this->price << " lei pe litru\n";
		else
			if (this->exp[0] == 0)
				out << "pe data de " << this->date[0] << " " << this->date[1] << " " << this->date[2] << ", magazinul primeste un lot de " << this->quant << " litri de " << this->name << ", la pretul de " << this->price << " lei pe litru, la care decide sa aplice un discount de " << this->discount << "\n";
			else
				out << "pe data de " << this->date[0] << " " << this->date[1] << " " << this->date[2] << ", magazinul primeste un lot de " << this->quant << " litri de " << this->name << ", cu termen de valabilitate " << this->exp[0] << " " << this->exp[1] << " " << this->exp[2] << ", la pretul de " << this->price << " lei pe litru, la care decide sa aplice un discount de " << this->discount << "\n";
	}
};

class Proprietar {

public:
	Proprietar() {}


	string getname() {
		string a;
		cout << "Introduceti numele produsului\n";
		cin >> a;
		return a;
	}
	double getquant() {
		double a;
		cout << "Introduceti cantitatea\n";
		cin >> a;
		return a;
	}
	int getprice() {
		int a;
		cout << "Introduceti pretul\n";
		cin >> a;
		return a;
	}
	int *getdate() {
		int *a = new int[3];
		cout << "Introduceti data primirii produsului (DD/MM/YYYY)\n";
		for (int i = 0;i<3;i++)cin >> a[i];
		return a;
	}
	int getdisc() {
		int a;
		cout << "Introduceti discountul produsului\n";
		cin >> a;
		return a;
	}
	int *getexp() {
		int*a = new int[3];
		cout << "Introduceti data expirarii produsului(DD/MM/YYYY)\n";
		for (int i = 0;i<3;i++) {
			cin >> a[i];if (a[i] == 0)break;
		}
		return a;
	}


	Magazin* addprod() {
		int ok;

		do {
			cout << "1. Greutate\t2. Volum\t3. Bucata\n";
			cin >> ok;
		} while (ok<1 && ok>3);
		if (ok == 1)return new Greutate(getname(), getprice(), getquant(), getdate(), getdisc(), getexp());

		if (ok == 2)return new Volum(getname(), getprice(), getquant(), getdate(), getdisc(), getexp());
		return new Bucata(getname(), getprice(), getquant(), getdate(), getdisc(), getexp());
	}
	int check(Magazin *produs, int *a, int *b) {

		if (produs->getDate()[2]>a[2] && produs->getDate()[2]<b[2])
			return 1;
		if (produs->getDate()[2] >= a[2] && produs->getDate()[2] <= b[2] && produs->getDate()[1]>a[1] && produs->getDate()[1]<b[1])
			return 1;
		if (produs->getDate()[2] >= a[2] && produs->getDate()[2] <= b[2] && produs->getDate()[1] >= a[1] && produs->getDate()[1] <= b[1] && produs->getDate()
			[0] >= a[0] && produs->getDate()[0] <= b[0])
			return 1;
		return 0;

	}
	int valabil(Magazin* produs, int *a) {

		if (produs->getExp()[2]>a[2])
			return 1;
		if (produs->getExp()[2] >= a[2] && produs->getExp()[1]>a[1])
			return 1;
		if (produs->getExp()[2] >= a[2] && produs->getExp()[1] >= a[1] && produs->getExp()[0] >= a[0])
			return 1;
		return 0;
	}

};

int main() {
	static int j = 0;
	Proprietar *k[99];
	k[j++] = new Proprietar();

	Magazin *kk[99];
	kk[j - 1] = k[j - 1]->addprod();
	int *a = new int[3], *b = new int[3];
	for (int i = 0;i<j;i++)
		cout << *kk[i] << endl;
	//cout<<"Introduceti data initiala (DD/MM/YYYY)\n";

	//for(int i=0;i<3;i++)
	//	cin>>a[i];
	//cout<<"Introduceti data finala (DD/MM/YYYY)\n";
	//for(int i=0;i<3;i++)
	//cin>>b[i];
	//cout<<"Produsele primite intre 2 date calendaristice\n";
	//for(int i=0;i<j;i++)
	//	if(k[i]->check(kk[i],a,b))cout<<*kk[i]<<endl;
	// cout<<"Introduceti data curenta\n";
	//for(int i=0;i<3;i++)
	//	cin>>a[i];
	for (int i = 0;i<j;i++)
		if (k[i]->valabil(kk[i], a))
			cout << *kk[i] << endl;
	system("pause");
	return 0;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
}