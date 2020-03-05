#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
����ģʽ��
��Ϸʹ�ò�ͬ����������ͬ��
*/

//���ཫ��ͬ���ԵĹ��������������

class AbstractWeapon {
public:
	virtual void Useweapon() = 0;

};

class Knife :public AbstractWeapon {
public:
	virtual void Useweapon() {
		cout << "ʹ��Knife..." << endl;
	}
};
class AK47 :public AbstractWeapon {
public:
	virtual void Useweapon() {
		cout << "ʹ��AK47..." << endl;
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