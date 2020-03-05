#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*
//继承和组合优先 使用组合
*/

class AbstractCar {

public:
	virtual void run() = 0;
};

class CarA : public AbstractCar {
public:
	CarA() {	
	}
	virtual void run() {
		cout << "CarA" << "启动了" << endl;
	}
};

class CarB : public AbstractCar {
public:
	CarB() {
	}
	virtual void run() {
		cout << "CarB" << "启动了" << endl;
	}
};


class PersonA {
public:
	PersonA() {};
	void PersonA_Init(AbstractCar* car) {
		this->Ca = car;
	}

	void run_1() {
		this->Ca->run();
		if (this->Ca != NULL) {
			delete this->Ca;
			this->Ca = NULL;//**********
		}
	}
	AbstractCar* Ca;//有指针类型就要delete   抽象类
};

void test() {
	AbstractCar* p1 = new CarA;
	AbstractCar* p2 = new CarB;
	
	PersonA* pa = new PersonA;

	//pa->PersonA_Init(new CarA);
	//pa->run_1();
	//pa->PersonA_Init(new CarB);
	//pa->run_1();
	
	pa->PersonA_Init(p1);
	pa->run_1();
	pa->PersonA_Init(p2);
	pa->run_1();
	//delete p1;
	//delete p2;//不用再次删除了


}


int main() {
	test();
	return 0;
}