#include <string>
#include <iostream>
using namespace std;
#include <string.h>

class Character {
	string name;
	int life;
	char path[11];

public: Character(string name, int life) {
	if (life > 0) {
		this->name = name;
		this->life = life;
		
	}	else {
		cout << "Unable to create dead character\n";
	}
	};

~Character() {
		cout << "Game over for " << this->name << "\n";
		delete this;
};

public: bool Hit(int decreaseLife) {
	bool res;
	if (decreaseLife > 0) {
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
		cout << this->name << " is died with " << this->life << "hp.\n";
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
	
	cout << " ***** END OF GAME STATS *****\n";
	c.PrintCharacter();
	d.PrintCharacter();
	cout << " ";
	system("pause");
    //return 0;
}


