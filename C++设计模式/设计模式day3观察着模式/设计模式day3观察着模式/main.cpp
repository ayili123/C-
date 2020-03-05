#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <Windows.h>
using namespace std;
/*
观察者模式：打BOSS

*/
class AbstrctHero {
public:
	virtual void Update() = 0;
};

class HeroA : public AbstrctHero {
	virtual void Update() {
		cout << "HeroA正在撸BOSS" << endl;
	}
};
class HeroB : public AbstrctHero {
	virtual void Update() {
		cout << "HeroB正在撸BOSS" << endl;
	}
};
class HeroC : public AbstrctHero {
	virtual void Update() {
		cout << "HeroC正在撸BOSS" << endl;
	}
};


class AbstractBoss {
public:
	virtual void addHero(AbstrctHero* P) = 0;
	virtual void deleteHero(AbstrctHero* P) = 0;
	virtual void updateHrro() = 0;//************通知所有的

};

class BossA : public AbstractBoss {
public:
	
	virtual void addHero(AbstrctHero* P) {
		mP.push_back(P);
	}
	virtual void deleteHero(AbstrctHero* P) {
		mP.remove(P);//根据值删除
	}
	virtual void updateHrro() {
		for (list<AbstrctHero*>::iterator it = mP.begin(); it != mP.end(); it++) {
			(*it)->Update();
		}
	}
public:
	list<AbstrctHero*> mP;
};





void test() {             //两种写法*********************************************************
	BossA* b = new BossA ;//BossA b(这样要用.不能用->) AbstractBoss* b = new bossA***********
	AbstrctHero* heroa = new HeroA;
	AbstrctHero* herob = new HeroB;
	AbstrctHero* heroc = new HeroC;
	b->addHero(heroa);
	b->addHero(herob);
	b->addHero(heroc);
	b->updateHrro();
	b->deleteHero(herob);
	cout << ":::::::::::::"<<endl;
	b->updateHrro();
	delete heroc;
	delete herob;
	delete heroa;
	delete b;
	

}


int main() {
	test();
	system("pause");
	return 0;
}