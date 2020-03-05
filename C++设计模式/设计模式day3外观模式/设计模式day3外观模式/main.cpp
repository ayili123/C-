#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*
���ģʽ����ͥӰԺ��
����һЩ����ֱ�ӷ�װ����ֱ�ӵ��á�

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
		cout << "TV��ʼ����..." << endl;
	}
	virtual void machineOff() {
		cout << "TV�Ѿ��ر�..." << endl;
	}
};

//Vedio
class Vedio : public Abstract {
public:
	virtual void machineRun() {
		cout << "Vedio��ʼ����..." << endl;
	}
	virtual void machineOff() {
		cout << "Vedio�Ѿ��ر�..." << endl;
	}
};

//Light
class Light : public Abstract {
public:
	virtual void machineRun() {
		cout << "Light��ʼ����..." << endl;
	}
	virtual void machineOff() {
		cout << "Light�Ѿ��ر�..." << endl;
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