#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <Windows.h>
using namespace std;
/*
����ģʽ�����Ǵ���һЩЭ��

*/

//��Ҫ�����Э��д����
class control {
public:
	void addmoney() {
		cout << "addmoney()..." << endl;
	}

	void addlevel() {
		cout << "addlevel()..." << endl;
	}

	void addequipment() {
		cout << "addequipment()..." << endl;
	}
};

//дһ��������   ȥ������ЩЭ��
class server {
public:
	virtual void servercontrol() = 0;
};

class moneyserrver :public server {
public:
	virtual void servercontrol() {
		mP.addmoney();
	}
public:
	control mP;//ֱ�ӵ�������Ӧ����ʵ��
};

class addlevelserrver :public server {
public:
	virtual void servercontrol() {
		mP.addlevel();
	}
public:
	control mP;//ֱ�ӵ�������Ӧ����ʵ��   ��Ƶ���õ�ָ������Ҫ��ʼ��
};
/*��Ƶ��
class addlevelserrver :public server {
public:
    addlevelserrver(control* P){
	  this->mP = P;
	}
	virtual void servercontrol() {
		mP->addlevel();
	}
public:
	control* mP;//ֱ�ӵ�������Ӧ����ʵ��   ��Ƶ���õ�ָ������Ҫ��ʼ��
};


*/


class addequipmentserrver :public server {
public:
	virtual void servercontrol() {
		mP.addequipment();
	}
public:
	control mP;//ֱ�ӵ�������Ӧ����ʵ��
};

class TOLserver {
public:
	void addserver(server* v) {
		mqeue.push(v);
	}
	void slove() {
		while (!mqeue.empty()) {
			
			server* slovemqueue = mqeue.front();
			slovemqueue->servercontrol();
			mqeue.pop();
			Sleep(2000);
		}
	}
public:
	queue<server*> mqeue;
};

void test() {
	TOLserver* myslove = new TOLserver;
	server* s1 = new moneyserrver;
	server* s2 = new addlevelserrver;
	server* s3 = new addequipmentserrver;
	myslove->addserver(s1);
	myslove->addserver(s2);
	myslove->addserver(s3);
	myslove->slove();
	delete s3;
	delete s2;
	delete s1;
	delete myslove;

}


int main() {
	test();
	system("pause");
	return 0;
}