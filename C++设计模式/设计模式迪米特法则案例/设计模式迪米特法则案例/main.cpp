#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
//�����ط��� 
�н�����

*/
class AbstractBuilding {
public:
	virtual void sale() = 0;
	virtual string getQuality() = 0;
};
//A
class BuildingA : public AbstractBuilding {
public:
	BuildingA() {
		mQuality = "��Ʒ��";
	}
	virtual string getQuality() {
		return this->mQuality;
	}
	virtual void sale() {
		cout << "BuildingA" << this->mQuality << "������" << endl;
	}
public:
	string mQuality;
};
//B
class BuildingB : public AbstractBuilding {
public:
	BuildingB() {
		mQuality = "��Ʒ��";
	}
	virtual string getQuality() {
		return this->mQuality;
	}
	virtual void sale() {
		cout << "BuildingB" << this->mQuality << "������" << endl;
	}
public:
	string mQuality;
};

//�н�  �н���ȡά���͹���¥�̶���  ����ά������ָ��
class Mediator {
public:
	Mediator() {
		AbstractBuilding* building = new BuildingA;
		vBuilding.push_back(building);
		building = new BuildingB;
		vBuilding.push_back(building);
	}
	//�����ṩ�ӿ�
	AbstractBuilding* myBuilding(string quality){
	for (vector<AbstractBuilding*>::iterator it = vBuilding.begin(); it != vBuilding.end(); it++) {
			if ((*it)->getQuality() ==quality) {
				return *it;
			}
		}
	return NULL;
	}


	~Mediator() {
		for (vector<AbstractBuilding*>::iterator it = vBuilding.begin(); it != vBuilding.end(); it++) {
			if (*it != NULL) {
				delete *it;
			}
		}
	};
public:
	vector<AbstractBuilding*> vBuilding;//�ų����

};

void test02(){

	Mediator * m = new Mediator;
	AbstractBuilding* build = m->myBuilding("��Ʒ��");

	if (build != NULL) {
		build->sale();
	}
	else {
		cout << "û���ʺϵķ���" << endl;
	}
	


}

int main() {
	test02();
	return 0;
}