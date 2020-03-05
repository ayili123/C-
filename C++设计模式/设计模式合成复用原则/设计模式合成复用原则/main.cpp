#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*
//�̳к�������� ʹ�����
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
		cout << "CarA" << "������" << endl;
	}
};

class CarB : public AbstractCar {
public:
	CarB() {
	}
	virtual void run() {
		cout << "CarB" << "������" << endl;
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
	AbstractCar* Ca;//��ָ�����;�Ҫdelete   ������
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
	//delete p2;//�����ٴ�ɾ����


}


int main() {
	test();
	return 0;
}