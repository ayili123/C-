#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
策略模式：
游戏使用不同武器，开不同车
*/

//首相将不同策略的公共方法抽象出来

class AbstractWeapon {
public:
	virtual void Useweapon() = 0;

};

class Knife :public AbstractWeapon {
public:
	virtual void Useweapon() {
		cout << "使用Knife..." << endl;
	}
};
class AK47 :public AbstractWeapon {
public:
	virtual void Useweapon() {
		cout << "使用AK47..." << endl;
	}
};

class Character {
public:
	void set(AbstractWeapon* P) {
		this->mP = P;
	}
	Character() {}

	void runWeapon() {
		this->mP->Useweapon();
	}
public:
	AbstractWeapon* mP;
};

void test() {
	Character* people = new Character;
	AbstractWeapon* knife = new Knife;
	AbstractWeapon* ak47 = new AK47;
	people->set(knife);
	people->runWeapon();
	people->set(ak47);
	people->runWeapon();
	delete ak47;
	delete knife;
	delete people;
}


int main() {
	test();
	system("pause");
	return 0;
}