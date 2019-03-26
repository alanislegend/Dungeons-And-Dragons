#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Chartemp {
protected:
	int hp, intl, wis, charm, dex, agi, str, con;
	string name, race;
public:
	Chartemp();
	void setName();
	void setRace();
	int melee();
	void stats();
	virtual int attack() = 0;
	void setHealth(int damage);
	int getHealth();
};



class Weapon {
private:
	string typeWeapon;
public:
	void setWeapon(string pClass);
	int damage;
};
class Warrior : public Chartemp {
public:
	Warrior();
	Warrior(int roll);
	int attack();
private:
	Weapon weapon;
};

class Mage : public Chartemp {
public:
	Mage();
	Mage(int roll);
	int attack();
private:
	Weapon weapon;
};

class Node {
public:
	Node* next;
	Node* previous;
	Chartemp* player;
	Node();
};

class Bugbear : public Chartemp {
public:
	Bugbear();
	int attack();
};

void trainingDay(Node party);