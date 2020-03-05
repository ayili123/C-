#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*
装饰模式：游戏装备

*/

//抽象英雄
class AbstractHero {
public:
	virtual void showstatus() = 0;
public:
	int mHP;
	int mMP;
	int mKP;
	int mKA;
};

class HeroA : public AbstractHero  {
public:
	HeroA() {
		this->mHP = 0;
		this->mMP = 0;
		this->mKP = 0;
		this->mKA = 0;
	
	}
	virtual void showstatus() {
		cout << mHP << endl;
		cout << mMP << endl;
		cout << mKP << endl;
		cout << mKA << endl;
	}

};

class AbstractEquipment : public AbstractHero {
public:
	AbstractEquipment(AbstractHero* Hero) {
		this->mHero = Hero;
	}
	virtual void showstatus() {}
public:
	AbstractHero* mHero;
};

class EquipmentA : public AbstractEquipment {
public:
	EquipmentA(AbstractHero* Hero):AbstractEquipment(Hero){
	}
	void addequipment() {
		this->mHP = this->mHero->mHP;
		this->mKA = this->mHero->mKA;
		this->mKP = this->mHero->mKP;
		this->mMP = this->mHero->mMP + 30;
		cout << "11111111111" << endl;
		delete mHero;
	}
	virtual void showstatus() {
		addequipment();
		cout << this->mHP << endl;
		cout << this->mMP << endl;
		cout << this->mKP << endl;
		cout << this->mKA << endl;
	
	};
};

class EquipmentB : public AbstractEquipment {
public:
	EquipmentB(AbstractHero* Hero) :AbstractEquipment(Hero) {
	}
	void addequipment() {
		mHP = mHero->mHP;
		mKA = mHero->mKA;
		mKP = mHero->mKP+100;
		mMP = mHero->mMP;
		delete mHero;
	}
	virtual void showstatus() {
		addequipment();
		cout << mHP << endl;
		cout << mMP << endl;
		cout << mKP << endl;
		cout << mKA << endl;

	};
};

void test() {
	AbstractHero* hero1 = new HeroA;
	//hero1->showstatus();

	hero1 = new EquipmentA(hero1);
	hero1->showstatus();
	hero1 = new EquipmentB(hero1);
	hero1->showstatus();
	

}

int main() {

	test();
	system("pause");
	return 0;
}