#include <iostream>
#include <string>
using namespace std;

class Cartus
{
public:
	string producator;
	int nrTotalPagini;

};

class Imprimanta
{
private:
	const int serialNumber = 0;
	char* producator;
	int nrPaginiPrintate;
	static string tipImprimanta;
	Cartus cas;

	//1. Modificati constructorul implicit din clasa Imprimanta de mai sus
	//acesta va initializa producatorul cu un sir de caractere vid ("")
	//si numarul de pagini printate cu 0
public:
	Imprimanta() : serialNumber(1)
	{
		this->producator = new char[10];
		strcpy_s(this->producator,sizeof(this->producator), "");
		this->nrPaginiPrintate = 0;
		//serialNumber = 1;
	}

	//2. Modificati constructorul cu 3 parametri: serialNumber, producator, nrPaginiPrintate
	//acesta va initializa cele 3 atribute cu valorile primite
	//atributul constant nu va mai fi initializat la definire
	//constructorul implicit va initializa acest atribut cu 1

	Imprimanta(int serialNumber, char* producator, int nrPaginiPrintate) : serialNumber(serialNumber)
	{
		//serialNumber = serialNumber;
		this->producator = new char[sizeof(producator)];
		strcpy_s(this->producator, sizeof(producator), producator);
		this->nrPaginiPrintate = nrPaginiPrintate;
	}

	//3. Adaugati un destructor in clasa pentru a dezaloca
	//campul(urile) alocate dinamic
	~Imprimanta() {
		delete[] producator;
	}

	//4. Adaugati clasei un constructor de copiere astfel incat
	//sa se realizeze o copie in profunzime (deep copy) a obiectelor
	//se va realiza si copierea campului constant
	Imprimanta(Imprimanta &imp) : serialNumber(imp.serialNumber) {
		this->producator = new char[sizeof(imp.producator) + 1];
		strcpy_s(this->producator, sizeof(this->producator), imp.producator);
		//strcpy_s(this->producator, sizeof(imp.producator), imp.producator);
		this->nrPaginiPrintate = imp.nrPaginiPrintate;
	}
	
	//5. Modificati supraincarcarea pentru operator=
	//aceasta va realiza o copie in profunzime (deep copy) a obiectelor
	//operatorul accepta apeluri in cascada
	Imprimanta operator=(Imprimanta imp)
	{
		if (this != &imp) {
			delete[] producator;  ///stergem locatia continutul memorie vechi
			this->producator = new char[sizeof(imp.producator) + 1];
			strcpy_s(this->producator, sizeof(this->producator), imp.producator);
			this->nrPaginiPrintate = imp.nrPaginiPrintate;

		}
		return *this;
	}
	//11. Modificati supraincarcarea operatorului <
//acesta va compara numarul de pagini al celor doi operanzi de tip Imprimanta
	bool operator<(Imprimanta t)
	{
		if(t.nrPaginiPrintate < this->nrPaginiPrintate)
			return false;
		else {
			return true;
		}
	}

	static string getTipImprimanta()
	{
		return tipImprimanta;
	}

	static void setTipImprimanta(string tipImprimanta)
	{
		Imprimanta::tipImprimanta = tipImprimanta;
	}

	static long getTotalPaginiPerProducator(Imprimanta* imprimante, int nrImprimante, char* producator)
	{
		long paginitotal = 0;
		if (imprimante != NULL ) {
			for (int i = 0; i < nrImprimante; i++) {
				if (strcmp((&*imprimante + i)->producator , producator)==0) {
					paginitotal += (&*imprimante + i)->nrPaginiPrintate;
				}
			}
		}
		
		return paginitotal;
	}
public:
	void setCartus(Cartus c)
	{	
		cas.nrTotalPagini = c.nrTotalPagini;
		cas.producator = c.producator;
	}

	Cartus getCartus()
	{
		Cartus c;
		c.nrTotalPagini = cas.nrTotalPagini;
		c.producator=cas.producator;
		return c;
	}

	int getNumarPaginiRamase()
	{
		return 0;
	}

	void serialize(string fileName)
	{

	}

	void deserialize(string fileName)
	{

	}
	friend ostream& operator<<(ostream& os, const Imprimanta& dt);
};

//6. Initializati membrul static tipImprimanta cu valoarea "Cerneala"
string Imprimanta::tipImprimanta = "Cerneala";



//Serial number: serialNumber
//Producator: producator
//Numar pagini printate: nrPaginiPrintate
ostream& operator<<(ostream& out, Imprimanta)
{
	
	return out;
}

istream& operator>>(istream& in, Imprimanta)
{
	return in;
}

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//!!! Signatura anumitor operatori poate fi modificata pentru a permite functionarea lor conform specificatiilor

//1. Modificati constructorul implicit din clasa Imprimanta de mai sus
//acesta va initializa producatorul cu un sir de caractere vid ("")
//si numarul de pagini printate cu 0

//2. Modificati constructorul cu 3 parametri: serialNumber, producator, nrPaginiPrintate
//acesta va initializa cele 3 atribute cu valorile primite
//atributul constant nu va mai fi initializat la definire
//constructorul implicit va initializa acest atribut cu 1

//3. Adaugati un destructor in clasa pentru a dezaloca
//campul(urile) alocate dinamic

//4. Adaugati clasei un constructor de copiere astfel incat
//sa se realizeze o copie in profunzime (deep copy) a obiectelor
//se va realiza si copierea campului constant

//5. Modificati supraincarcarea pentru operator=
//aceasta va realiza o copie in profunzime (deep copy) a obiectelor
//operatorul accepta apeluri in cascada

//6. Initializati membrul static tipImprimanta cu valoarea "Cerneala"

//7. Modificati metodele de acces pentru campul static
//astfel incat acestea sa permita modificarea si obtinerea valorii acestui camp

//8. Modificati metoda getTotalPaginiPerProducator pentru a returna numarul total de pagini
//printate de toate imprimantele din vectorul de imprimante primit ca parametru
//care sunt produse de producatorul primit drept parametru
//De ex daca avem 3 imprimante: "Dell" - 120 de pagini, "HP" - 150 de pagini, "Dell" - 170 de pagini
//functia va returna 290 de pagini daca primeste ca parametru producatorul "Dell"
//si 150 de pagini daca primeste ca parametru producatorul "HP"
//pentru orice alt producator functia va returna 0

//9. Modelati o relatie de compunere intre clasa Cartus si clasa Imprimanta
//astfel incat sa reiasa faptul ca Imprimanta are (foloseste) un Cartus
//Modificati metoda setCartus astfel incat sa puteti schimba cartusul curent al imprimantei
//cu cel primit drept parametru si metoda getCartus pentru a returna cartusul curent

//10. Modificati metoda getNumarPaginiRamase astfel incat sa returneze numarul de pagini
//pe care imprimanta respectiva la mai poate printa avand in vedere ca stim 
//cate pagini se pot printa maxim cu cartusul curent si cate pagini au fost printate pana acum
//functia nu poate returna o valoare negativa, asa ca daca numarul curent de pagini il
//depaseste pe cel maxim, va returna 0

//11. Modificati supraincarcarea operatorului <
//acesta va compara numarul de pagini al celor doi operanzi de tip Imprimanta

//12. Modificati operatorul de scriere la consola pentru a afisa informatiile despre Imprimanta
//se pot folosi functii friend sau getteri
//afisarea va fi de forma:
//Serial number: serialNumber
//Producator: producator
//Numar pagini printate: nrPaginiPrintate


//13. Modificati operatorul de citire de la consola pentru a citi informatii despre Imprimanta
//se vor citi in ordine urmatoarele informatii (fiecare pe o linie noua)
//producator
//nrPaginiPrintate
//se pot folosi setteri sau functii friend
//operatorul trebuie sa poata citi siruri de caractere ce contin spatii

//14. Supraincarcati operatorii de scriere si citire din fisiere text
//operatorii functioneaza pe fisiere text deschise deja

//15. Modificati metodele serialize si deserialize pentru a scrie
//si a citi obiectul curent de clasa Imprimanta intr-un/dintr-un fisier binar
//se vor serializa toate campurile (ordinea nu conteaza)
//cu exceptia celor constante si statice
//numele fisierului este primit drept parametru
//metodele deschid si inchid fisierele specificate

int main()
{

	Cartus c;
	c.producator = "Auchan";
	c.nrTotalPagini = 500;
	Imprimanta x;
	x.setCartus(c);
	Cartus d = x.getCartus();

	cout << d.nrTotalPagini;
	
}