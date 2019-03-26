#include "Header.h"

int main() {
	Node party;
	party.player = new Warrior();
	party.next = new Node();
	party.next->player = new Mage();
	trainingDay(party);

	system("pause");
	return 0;
}
Chartemp::Chartemp() {
	intl = (rand() % 15) + 3;
	wis = (rand() % 15) + 3;
	charm = (rand() % 15) + 3;
	dex = (rand() % 15) + 3;
	agi = (rand() % 15) + 3;
	str = (rand() % 15) + 3;
	con = (rand() % 15) + 3;
}
void Chartemp::setName() {
	cout << "What is the name?";
	cin>>name;
}
void Chartemp::setRace() {
	int temp;
	cout << "Choope race 1. dwarf 2,elf and so on" << endl;
	cin >> temp;
	if (temp == 1)
		race = "Dwarf";
	if (temp == 2)
		race = "Elf";
	//and so on
}
int Chartemp::melee() {
	int dam = rand() % 4;
	if (str > 15)
		dam += 3;
	return dam;
}
Warrior::Warrior() {
	hp = rand() % 12 + 3;
	if (con > 15)
		hp += 3;
	setName();
	setRace();
	weapon.setWeapon("Warrior");
	stats();
}
Warrior::Warrior(int roll) {
	hp = roll % 12 + 3;
	if (con > 15)
		hp += 3;
	setName();
	setRace();
	weapon.setWeapon("Warrior");
	stats();
}
Mage::Mage() {
	hp = rand() % 4 + 3;
	if (con > 15)
		hp += 3;
	setName();
	setRace();
	weapon.setWeapon("Mage");
	stats();
}
Mage::Mage(int roll) {
	hp = roll % 4 + 3;
	if (con > 15)
		hp += 3;
	setName();
	setRace();
	weapon.setWeapon("Mage");
	stats();
}
void Weapon::setWeapon(string typeClass) {
	if (typeClass == "Warrior") {
		//do a bunch of warriuor crap
		cout << "Sword 1 axe 2" << endl;
		int ans;
		cin >> ans;
		if (ans == 1) {
			typeWeapon = "sword";
			damage = 5;
		}
		else {
			typeWeapon = "axe";
			damage = 6;
		}
	}
	if (typeClass == "Mage") {
		//do a bunch of mage crap
		cout << "Dagger 1 Staff 2" << endl;
		int ans;
		cin >> ans;
		if (ans == 1) {
			typeWeapon = "dagger";
			damage = 3;
		}
		else {
			typeWeapon = "staff";
			damage = 2;
		}
	}
}

Node::Node() {
	next = NULL;
	previous = NULL;
}

void Chartemp::stats() {
	cout << hp <<" "<< intl << " " << wis << " " << charm <<
		" " << dex << " " << agi << " " << str << " " << con << endl;
}

Bugbear::Bugbear() {
	name = "Bugbear";
	race = "Goblin";
	hp = rand() % 12 + 9;
	stats();
}

int Warrior::attack() {
	int dam = rand() % weapon.damage + 1;
	cout <<name<< " attacks the monster for " << dam << "." << endl;
	return dam;
}
int Mage::attack() {
	int dam = rand() % weapon.damage + 1;
	cout <<name << " attacks the monster for " << dam << "." << endl;
	return dam;
}
int Bugbear::attack() {
	int dam = rand() % 14 + 1;
	cout << "The Bugbear attacks you for " << dam << "." << endl;
	return dam;
}

void trainingDay(Node party) {
	cout << "You walk into the bar and in the corner is a mean Bugbear." << endl <<
		"It calls your mama a troll. What do you do? 1. fight 2. run" << endl;
	int ans;
	Bugbear* monster = new Bugbear();
	cin >> ans;
	if (ans == 1)
	{
		while (monster->getHealth() > 0 || ((party.player->getHealth() > 0 && party.next->player->getHealth() > 0))) {
			if (party.player->getHealth() > 0 || monster->getHealth() <= 0) {
				monster->setHealth(party.player->attack());
			}
			if (party.next->player->getHealth() > 0 || monster->getHealth() <= 0) {
				monster->setHealth(party.next->player->attack());
			}
			if (monster->getHealth() > 0) {
				int target = rand() % 2;
				if (target == 0) {
					party.player->setHealth(monster->attack());
				}
				else {
					party.next->player->setHealth(monster->attack());
				}
			}
		} //while
		if (monster->getHealth() <= 0) {
			cout << "You've defeated the monster.\n";
		}
		else {
			cout << "Your party has been wiped!\n";
		}
	}
	else
	{
		cout << "You ran\n";
	}

}

void Chartemp::setHealth(int damage) {
	cout << "You took " << damage << " points of damage." << endl;
	if (hp <= 0)
		cout << "And you died."<<endl;
	hp -= damage;
}
int Chartemp::getHealth(){
	return hp;
}