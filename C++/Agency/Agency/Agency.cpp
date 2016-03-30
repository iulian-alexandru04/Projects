#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;

class Agency{
public:
	virtual ~Agency(){}
	virtual char* getName(){
		return NULL;
	}
	virtual int* getDate(){
		return 0;
	}
};

class Rent:virtual public Agency{
public:
	virtual ~Rent(){}
	friend ostream& operator<<(ostream &out,Rent &x){
		x.showRent(out);
		return out;
	}
	virtual double getMonthlyRent(){
		return 0;
	}
	virtual void showRent(ostream &out)=0;
	virtual int* getDate2(){
		return 0;
	}
};

class Sale:virtual public Agency{
public:
	virtual ~Sale(){}
	friend ostream& operator<<(ostream &out,Sale &x){
		x.showSale(out);
		return out;
	}
	virtual int getMonths(){
		return 0;
	}
	virtual double getPrice(){
		return 0;
	}
	virtual void showSale(ostream &out)=0;
	virtual int getSurface(){
		return 0;
	}
};

class House:public Rent,public Sale{
	
	char* Name;
	int* Date1;
	int* Date2;
	int Surface;
	int Discount;
	int Price;
	int GSurface;
	int Months;
public:
	virtual ~House(){
		delete[] Date1;
		delete[] Date2;
		delete[] Name;
	}
	House(int months,int discount,int price,int gsurface,int surface,int* date1,char* name):Name(new char[strlen(name)+1]),Date1(new int[3]),Price(price),Months(months),Surface(surface),GSurface(gsurface),Discount(discount){
		Name=name;
		Date1=date1;
	}
	House(int price,int discount,int gsurface,int surface,int* date2,int* date1,char* name):Name(new char[strlen(name)+1]),Date1(new int[3]),Date2(new int[3]),Surface(surface),GSurface(gsurface),
		Discount(discount),Price(price){
			Name=name;
			Date1=date1;
			Date2=date2;
	}
	virtual double getMonthlyRent(){
		return this->Price * (this->Surface + double(0.2*GSurface)) * (1- double(this->Discount/100));
	}
	virtual double getPrice(){
		return this->Months?(this->Price*this->Surface):(0.9*this->Price*this->Surface);
	}
	virtual void showRent(ostream& out){
		cout<<"Numele chiriasului: "<<this->Name<<"\nPerioada inchirierii: "<<this->Date1[0]<<"."<<this->Date1[1]<<'.'<<this->Date1[2]<<"-"<<this->Date2[0]<<'.'<<this->Date2[1]<<'.'<<this->Date2[2]<<"\n";
		cout<<"Suprafata utila: "<<this->Surface<<"\nSuprafata curte: "<<this->GSurface<<"\nPretul (pe mp): "<<this->Price<<"\nDiscount: "<<this->Discount<<"\n";
	}
	virtual void showSale(ostream& out){
		cout<<"Numele proprietarului: "<<this->Name<<"\nData tranzactiei: "<<this->Date1[0]<<"."<<this->Date1[1]<<"."<<this->Date1[2];
		cout<<"\nPretul (pe mp): "<<this->Price;
		cout<<"\nDiscount: "<<this->Discount<<endl;
		if(Months)
			cout<<"Luni: "<<this->Months<<endl;
	}
	virtual int* getDate2(){
		return this->Date2;
	}
	virtual char* getName(){
		return this->Name;
	}
	virtual int* getDate(){
		return this->Date1;
	}
	virtual int getSurface(){
		return this->Surface+this->GSurface;
	}
	virtual int getMonths(){
		return this->Months;
	}
};

class Apartment:public Rent,public Sale{
	char* Name;
	int* Date1;
	int* Date2;
	int Surface;
	int Discount;
	int Price;
	int Floor;
	int Rooms;
	int Months;
public:
	virtual ~Apartment(){
		delete[] Date1;
		delete[] Date2;
		delete[] Name;
	}
	Apartment(int months,int discount,int price,int surface,int* date1,char* name):Discount(discount),Name(new char[strlen(name)+1]),Date1(new int[3]),Price(price),Months(months),Surface(surface){
		Name=name;
		Date1=date1;
	}
	Apartment(int price,int discount,int rooms,int floor,int surface,int* date2,int* date1,char* name):Name(new char[strlen(name)+1]),Date1(new int[3]),Date2(new int[3]),Surface(surface),
		Floor(floor),Rooms(rooms),Discount(discount),Price(price){
			Name=name;
			Date1=date1;
			Date2=date2;
	}

	
	virtual double getMonthlyRent(){
		return this->Price * this->Surface * (1- double(this->Discount/100));
	}
	virtual double getPrice(){
		return this->Months?(this->Price*this->Surface):(0.9*this->Price*this->Surface);
	}
	virtual void showRent(ostream& out){
		cout<<"Numele chiriasului: "<<this->Name<<"\nPerioada inchirierii: "<<this->Date1[0]<<"."<<this->Date1[1]<<'.'<<this->Date1[2]<<"-"<<this->Date2[0]<<'.'<<this->Date2[1]<<'.'<<this->Date2[2]<<"\n";
		cout<<"Etaj: "<<this->Floor<<"\nNumar camere: "<<this->Rooms<<"\n";
		cout<<"Suprafata utila: "<<this->Surface<<"\nPretul (pe mp): "<<this->Price<<"\nDiscount: "<<this->Discount<<"\n";
	}
	virtual void showSale(ostream& out){
		cout<<"Numele proprietarului: "<<this->Name<<"\nData tranzactiei: "<<this->Date1[0]<<"."<<this->Date1[1]<<"."<<this->Date1[2];
		cout<<"\nPretul (pe mp): "<<this->Price;	
		cout<<"\nDiscount: "<<this->Discount<<endl;
		if(Months)
			cout<<"Luni: "<<this->Months<<endl;
	}
	virtual int* getDate2(){
		return this->Date2;
	}
	virtual char* getName(){
		return this->Name;
	}
	virtual int* getDate(){
		return this->Date1;
	}
	virtual int getMonths(){
		return this->Months;
	}
};

class Read{
private:
	int nr;
	int sales;
	int rents;
	void Transactions(){
		cout<<"Introduceti numarul de tranzactii ce vor fi inregistrate in baza de date\n";
		cin>>this->nr;
	}
	char* Name(){
		char* name=new char[40];
		cout<<"Introduceti numele clientului\n";
		cin>>name;
		return name;
	}
	int* Data(){
		int* data=new int[3];
		cout<<"Introduceti data\n";
		for(int i=0;i<3;i++)
			cin>>data[i];
		return data;
	}
	int Surface(){
		int surface;
		cout<<"Introduceti suprafata\n";
		cin>>surface;
		return surface;
	}
	int Rooms(){
		int rooms;
		cout<<"Introduceti numarul de camere\n";
		cin>>rooms;
		return rooms;
	}
	int Floor(){
		int floor;
		cout<<"Introduceti etajul apartamentului\n";
		cin>>floor;
		return floor;
	}
	int Garden(){
		int garden;
		cout<<"Introduceti suprafata curtii\n";
		cin>>garden;
		return garden;
	}
	int Price(){
		int price;
		cout<<"Introduceti pretul (pe mp)\n";
		cin>>price;
		return price;
	}
	int Discount(){
		int discount;
		cout<<"Introduceti discount-ul\n";
		cin>>discount;
		return discount;
	}
	int Months(){
		int months;
		cout<<"Introduceti numarul de luni\n";
		cin>>months;
		return months;
	}

public:
	void add(Rent** k,Sale** ok){
		Transactions();
		while(this->nr){
			this->nr--;
			cout<<"Inchiriere/Vanzare\n";
			char* option=new char[40];
			cin>>option;
			if(!strcmp(option,"Vanzare")){
				cout<<"Casa/Apartament\n";
				char* option=new char[40];
				cin>>option;
				if(!strcmp(option,"Casa"))
					ok[sales++]=new House(Months(),Discount(),Price(),Garden(),Surface(),Data(),Name());
				else if(!strcmp(option,"Apartament"))
					ok[sales++]=new Apartment(Months(),Discount(),Price(),Surface(),Data(),Name());
			}
			else if(!strcmp(option,"Inchiriere")){
				cout<<"Casa/Apartament\n";
				char* option=new char[40];
				cin>>option;
				if(!strcmp(option,"Casa"))
					k[rents++]=new House(Price(),Discount(),Garden(),Surface(),Data(),Data(),Name());
				else if(!strcmp(option,"Apartament"))
					k[rents++]=new Apartment(Price(),Discount(),Rooms(),Floor(),Surface(),Data(),Data(),Name());
			}
		}
	}
	void show(Rent** rent,Sale** sale){
		for(int i=0;i<rents;i++)
			cout<<*rent[i];
		cout<<endl<<endl;
		for(int i=0;i<sales;i++)
			cout<<*sale[i]<<endl;
		cout<<endl;
	}
	void show(Sale** sale,Rent** rent){
		time_t t=time(NULL);
		tm* Time=localtime(&t);// pentru a putea compila project->properties->preprocessor->edit->_CRT_SECURE_NO_WARNINGS
		int nr=0;
		//nu se va afisa de doua ori(daca a fost inchiriat apoi cumparat)
		if(this->sales)
			cout<<this->sales<<" locuinte vandute.\n";
		for(int i=0;i<this->sales;i++)
			cout<<sale[i]->getName()<<endl;
		for(int i=0;i<this->rents;i++)
			if(rent[i]->getDate2()[1]>=Time->tm_mon+1 && rent[i]->getDate2()[2]>=Time->tm_year+1900)
				nr++;
		if(nr){
			cout<<nr<<" locuinte inchiriate.\n";
			for(int i=0;i<this->rents;i++)
				if(rent[i]->getDate2()[1]>=Time->tm_mon+1 && rent[i]->getDate2()[2]>=Time->tm_year+1900)
					cout<<rent[i]->getName()<<endl;
		}
		cout<<endl;
	}
	double profit(Sale** sale,Rent** rent){
		double sum=0;
		//profitul pe primele 6 luni ale lui 2015
		for(int i=0;i<this->sales;i++)
			if(sale[i]->getDate()[2]==2015 && sale[i]->getDate()[1]<7)
				sum+=sale[i]->getPrice();
		for(int i=0;i<this->rents;i++)
			if(rent[i]->getDate()[2]<2015 && rent[i]->getDate2()[2]>=2015)
				sum+=min(6,rent[i]->getDate2()[1])*rent[i]->getMonthlyRent();
			else if(rent[i]->getDate()[2]==2015 && rent[i]->getDate()[1]<7)
				sum+=min(6-rent[i]->getDate()[1],rent[i]->getDate2()[1])*rent[i]->getMonthlyRent();
		return sum;
	}
	int* bestMonth(Rent** rent,Sale** sale){
		int **v,*m=new int[2];
		m[0]=m[1]=0;
		v=new int*[12];
		for(int i=0;i<12;i++)
			v[i]=new int[16];
		for(int i=0;i<this->sales;i++)
			if(sale[i]->getSurface()>500)
				v[sale[i]->getDate()[1]-1][sale[i]->getDate()[2]%2000-1]++;
		for(int i=0;i<16;i++){
			int max=v[0][i];
			for(int j=0;j<12;j++)
				if(max<v[j][i])
					max=v[j][i],m[0]=2001+i,m[1]=j+1;
		}
		for(int i=0;i<12;i++)
		delete[] v[i];
		delete[] v;
		return m;
		delete[] m;
	}
	int bestYear(Rent** rent,Sale** sale){
		int* m=new int[16];
		for(int i=0;i<this->rents;i++)
			if(dynamic_cast<Apartment*>(rent[i]))
				m[rent[i]->getDate()[2]%2000-1]++;
		int max=m[0];
		int year=0;
		for(int i=0;i<16;i++)
			if(max<m[i])
				max=m[i],
				year=2001+i;
		return year;
		delete[] m;
	}
	void debt(Sale** sale){
		time_t t=time(NULL);
		tm* Time=localtime(&t);

		for(int i=0;i<this->sales;i++){
			int k=sale[i]->getMonths()-12*(Time->tm_year+1900-sale[i]->getDate()[2])-Time->tm_mon-1+sale[i]->getDate()[1];
			if(k>=120)
				cout<<sale[i]->getName()<<", "<<k<<" luni ramase."<<endl;
		}
	}
};

int main(){
	Sale* sale[10];
	Rent* rent[10];
	Read* k=new Read();
	k->add(rent,sale);
	k->show(rent,sale);
	k->show(sale,rent);
	if(k->profit(sale,rent))
		cout<<"Profitul companiei in prima jumatate a anului 2015 este: "<<k->profit(sale,rent)<<endl;
	if(k->bestMonth(rent,sale)[1])cout<<"Luna in care s-au vandut cele mai multe case cu o suprafata mai mare de 500 mp: "<<k->bestMonth(rent,sale)[1]<<" ("<<k->bestMonth(rent,sale)[0]<<").\n";
	if(k->bestYear(rent,sale))cout<<"Anul in care s-au inchiriat cele mai multe apartamente: "<<k->bestYear(rent,sale)<<".\n";
	k->debt(sale);
	cout<<endl;
	system("pause");
	return 0;
}