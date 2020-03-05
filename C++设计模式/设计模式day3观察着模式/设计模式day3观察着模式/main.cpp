#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <Windows.h>
using namespace std;
/*
�۲���ģʽ����BOSS

*/
class AbstrctHero {
public:
	virtual void Update() = 0;
};

class HeroA : public AbstrctHero {
	virtual void Update() {
		cout << "HeroA����ߣBOSS" << endl;
	}
};
class HeroB : public AbstrctHero {
	virtual void Update() {
		cout << "HeroB����ߣBOSS" << endl;
	}
};
class HeroC : public AbstrctHero {
	virtual void Update() {
		cout << "HeroC����ߣBOSS" << endl;
	}
};


class AbstractBoss {
public:
	virtual void addHero(AbstrctHero* P) = 0;
	virtual void deleteHero(AbstrctHero* P) = 0;
	virtual void updateHrro() = 0;//************֪ͨ���е�

};

class BossA : public AbstractBoss {
public:
	
	virtual void addHero(AbstrctHero* P) {
		mP.push_back(P);
	}
	virtual void deleteHero(AbstrctHero* P) {
		mP.remove(P);//����ֵɾ��
	}
	virtual void updateHrro() {
		for (list<AbstrctHero*>::iterator it = mP.begin(); it != mP.end(); it++) {
			(*it)->Update();
		}
	}
public:
	list<AbstrctHero*> mP;
};





void test() {             //����д��*********************************************************
	BossA* b = new BossA ;//BossA b(����Ҫ��.������->) AbstractBoss* b = new bossA***********
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