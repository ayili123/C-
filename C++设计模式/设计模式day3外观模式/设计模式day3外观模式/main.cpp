#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*
外观模式：家庭影院。
即将一些功能直接封装起来直接调用。

*/

class Abstract {
public:
	virtual void machineRun() = 0;
	virtual void machineOff() = 0;
};

//TV
class TV : public Abstract {
public:
	virtual void machineRun() {
		cout << "TV开始运作..." << endl;
	}
	virtual void machineOff() {
		cout << "TV已经关闭..." << endl;
	}
};

//Vedio
class Vedio : public Abstract {
public:
	virtual void machineRun() {
		cout << "Vedio开始运作..." << endl;
	}
	virtual void machineOff() {
		cout << "Vedio已经关闭..." << endl;
	}
};

//Light
class Light : public Abstract {
public:
	virtual void machineRun() {
		cout << "Light开始运作..." << endl;
	}
	virtual void machineOff() {
		cout << "Light已经关闭..." << endl;
	}
};

class ModeA {
public:
	ModeA() {
		 mTV = new TV;
		 mVedio = new Vedio;
		 mLight = new Light;
	}


	void RUN() {
		mTV->machineRun();
		mVedio->machineRun();
		mLight->machineRun();	
	}
	void OFF() {
		mTV->machineOff();
		mVedio->machineOff();
		mLight->machineOff();
	
	}  
	~ModeA() {
		cout << "1" << endl;
		delete mTV;
		delete mVedio;
		delete mLight;
	}
public:
	Abstract* mTV;
	Abstract* mVedio;
	Abstract* mLight;
	
};

void test() {
	ModeA* modea = new ModeA();
	modea->RUN();
	modea->OFF();
	delete modea;

}
int main() {


	test();
	system("pause");
	return 0;
}