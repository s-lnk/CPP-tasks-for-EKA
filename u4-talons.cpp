#include <string>
#include <iostream>
using namespace std;
#include <string.h>
#include <ctime>

class ETalons {
	public: string serial;
	
	public: ETalons(string _s) {
		serial = _s;
	}
	
	//virtual bool Print() = 0;
	virtual void Print() { };
	virtual bool Use() { };
	virtual void Add(int _i) { };
};


class DiennaktsET : public ETalons {
	time_t activation_date;
	bool activated;
	
	public: DiennaktsET(string _s) : ETalons(_s) {
		activated = false;
	}
	
	public: virtual void Print() {
		char* dt = ctime(&activation_date);
		if (activated) {
			cout << "Diennakts " << serial << " is activated on " << dt << endl;
		} else {
			cout << "Diennakts " << serial << " not activated " << endl;
		}	
	}
	
	public: bool Use() {
		activated = true;
		activation_date = time(0);
		return true;
	}
};

class BraucienuskET: public ETalons {
	int trips;
	public: BraucienuskET(string _s, int _t): ETalons(_s) {
		trips = _t;
	}
	
	public: void Print() {
		cout << "Braucienus " << serial << " has " << trips << " trips left." << endl;
	}
	
	public: bool Use() {
		if (trips > 0) {
			trips--;
			cout << "..GREEN: Braucienus trip used." << endl;
			return true;
		} else {
			cout << "..RED: No more trips allowed." << endl;
			return false;
		}
	}
};


class PersoniskaisET: public ETalons {
	int trips;
	string name;
	string surname;
	public: PersoniskaisET(string _s, int _t, string _n, string _sn) : ETalons(_s) {
		trips = _t;
		name = _n;
		surname = _sn;
	}
	
	public: void Print() {
		cout << "Personiskais " << serial << " owned by " << name << " " << surname << " has " << trips << " trips left" << endl;
	}
	
	public: bool Use() {
		if (trips > 0) {
			trips--;
			cout << "..GREEN: Personiskais trip used." << endl;
			return true;
		} else {
			cout << "..RED: No more trips allowed." << endl;
			return false;
		}
	}
	
	public: void Add(int _x) {
		trips = trips + _x;
		cout << "Personiskais added " << _x << " trips, in total " << trips << " trips allowed" << endl;
	}
};

int main()
{
	
	ETalons* e[] = { new DiennaktsET("S123"),new DiennaktsET("S234"),new BraucienuskET("S345",1),new BraucienuskET("S456",1),new PersoniskaisET("S567",2,"Ivars","Kuzmics"),new PersoniskaisET("S678",1,"Ailis","Beate") };
	cout << "*************" << endl;
	e[5]->Add(1);
	for(int i=0; i < 6; i++) {
		e[i]->Use();
		e[i]->Print();
	}
	cout << "*************" << endl;
	
	cout << " ";
	system("pause");
    //return 0;
}
