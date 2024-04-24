#include <string>
#include <iostream>
using namespace std;
#include <string.h>

class Character {
	public: string name;
	public: int life;
	public: char path[11];
	//public: friend class Monster;
	//public: friend class Hero;

public: Character(string name, int life) {
	if (life > 0) {
		this->name = name;
		if (life<1 || life>10) {
			this->life = 10;
		} else {
			this->life = life;
		}
		
		
	}	else {
		cout << "Unable to create dead character\n";
	}
	};

public: ~Character() {
		cout << "Game over for " << this->name << "\n";
};

public: bool Hit(int decreaseLife) {
	bool res;
	
	if (decreaseLife > 0 && this->life > 0) {
		if (this->life > 0) {
			this->life = this->life - decreaseLife; //Decrease life if alive and was hit
		}
		if (this->life < 1) {
			this->life = 0;
			cout << this->name << " was hit with power " << decreaseLife << " and died.\n"; //Print message if character died
		} else {
			cout << this->name << " was hit with power " << decreaseLife << " and has " << this->life << " HP left.\n"; //Print message if caharacter is stil alive
		}
	}
	if (this->life < 1) {
		res = false;
	} else {
		res = true;
	}
	return res;
};

public: int GetLife() {
	//Return life points if character alive
		return this->life;
};

public: void Go(const char* direction) {
	const char* check = "tblr";
	//cout << "Make step to " << direction << " size of path " << strlen(this->path) << " " << sizeof(this->path) << "\n";
	if (this->Hit(0)) {
		if (strstr(check, direction) != NULL) {
			if (strlen(this->path) > 9) {
				//Buffer maxed, will shift char array
				cout << "shift-- ";
				memmove(this->path,this->path + 1,10);
			}
			strcat(this->path, direction);
			cout << this->name << " goes " << direction << " and has path " << this->path << "\n";
		} else {
			cout << "Wrong direction " << direction << "\n";
		}
	} else {
		//Do nothing if died.
	}
};



public: void PrintCharacter() {
	if (this->Hit(0)) {
		cout << "Player " << this->name << " with " << this->life << " HP walked: " << this->path << "\n";
	} else {
		cout << "Player " << this->name << " was killed, he walked: " << this->path << "\n";
	}
		
	}
};


class Monster: public Character {
	public: int level;

	public: Monster(string _n, int _life, int _level): Character(_n, _life) {
		level = _level;
		cout << ".. new monster " << _n << " joins game with " << _life << " HP and level " << _level << endl;
	}
	
	public: int GetLevel() {
		return level;
	}
	
	public: Print() {
		cout << "Monster " << name << " with " << life << " HP and level " << level << " has walked a path " << path << endl;
	}
};

class Hero: public Character {
	int experience;
	
	public: Hero(string _n, int _l, int _e ) : Character(_n, _l) {
		experience = _e;
		cout << ".. new hero " << _n << " joins game with " << _l << " HP and " << _e << "EXP" << endl;
	}
	
	public: Kill(Monster& _m) {
		experience = experience + (_m.GetLife() * _m.GetLevel());
		cout << ".. hero " << name << " kills monster " << _m.name << " which results in " << experience << " EXP" << endl;
		_m.life = 0;
	}
	
	public: Print() {
		cout << "Hero " << name << " with " << life << " HP and " << experience << " EXP has walked a path " << path << endl;
	}
};

class Boss: public Monster {
	int heads;
	
	public: Boss(string _n, int _life, int _level, int _heads): Monster(_n, _life, _level) {
		heads = _heads;
		cout << ".. new boss " << _n << " joins game with " << _life << " HP and level " << _level << " having " << heads << " heads " << endl;
	}

	public: int GetHeads() {
		return heads;
	}
	
	public: Eat(Hero& _h) {
		life = life + _h.life;
		heads++;
		cout << ".. boss " << name << " eats hero " << _h.name << " and gets in total " << life << " HP and " << heads << " heads" << endl; 
		_h.life = 0;
	}
	
	public: Print() {
		cout << "Boss " << name << " with " << life << " HP and level " << level << " having " << heads << "heads, has walked a path " << path << endl; 
	}	
};
	




	
int main()
{
	Character c = Character("Jurmala", 10);
	Character d = Character("Daugavpils", 11);
	Character e = Character("Ventspils", 0);
	c.PrintCharacter();
	d.PrintCharacter();
	e.PrintCharacter();
	c.Go("a");
	c.Go("t");
	c.Go("b");
	c.Go("l");
	c.Go("r");
	c.Go("r");
	c.Go("r");
	c.Go("r");
	c.Go("r");
	c.Go("r");
	c.Go("b");
	c.Go("l");
	c.Go("r");
	c.Go("b");
	d.Go("r");
	d.Go("b");
	d.Go("l");
	d.Go("b");
	d.Go("d");
	c.Hit(4);
	d.Hit(100);	
	d.Go("b"); //Call go for dead character
	d.Hit(100); //Call hit for dead character
	c.Hit(1);
	
	cout << " ***** END OF GAME STATS: *****\n";
	c.PrintCharacter();
	d.PrintCharacter();
	
	cout << " ******** NEW GAME **********\n";
	Hero h = Hero("Spiderman",10,1);
	Monster m = Monster("Snake",10,10);
	Boss b = Boss("Godzilla",10,10,10);
	h.Print();
	m.Print();
	b.Print();
	h.Kill(m);
	b.Eat(h);
	h.Print();
	m.Print();
	b.Print();
	cout << " ******** GAME OVER **********\n";
	
	cout << " ";
	system("pause");
    //return 0;
}


