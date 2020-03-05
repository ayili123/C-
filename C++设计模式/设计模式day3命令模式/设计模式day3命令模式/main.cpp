#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <Windows.h>
using namespace std;
/*
命令模式：就是处理一些协议

*/

//把要处理的协议写出来
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

//写一个服务器   去处理那些协议
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
	control mP;//直接调，所以应该是实体
};

class addlevelserrver :public server {
public:
	virtual void servercontrol() {
		mP.addlevel();
	}
public:
	control mP;//直接调，所以应该是实体   视频里用的指针所以要初始化
};
/*视频里
class addlevelserrver :public server {
public:
    addlevelserrver(control* P){
	  this->mP = P;
	}
	virtual void servercontrol() {
		mP->addlevel();
	}
public:
	control* mP;//直接调，所以应该是实体   视频里用的指针所以要初始化
};


*/


class addequipmentserrver :public server {
public:
	virtual void servercontrol() {
		mP.addequipment();
	}
public:
	control mP;//直接调，所以应该是实体
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