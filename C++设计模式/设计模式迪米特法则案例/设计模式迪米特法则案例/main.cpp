#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
//迪米特法则： 
中介买房子

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
		mQuality = "高品质";
	}
	virtual string getQuality() {
		return this->mQuality;
	}
	virtual void sale() {
		cout << "BuildingA" << this->mQuality << "被售卖" << endl;
	}
public:
	string mQuality;
};
//B
class BuildingB : public AbstractBuilding {
public:
	BuildingB() {
		mQuality = "低品质";
	}
	virtual string getQuality() {
		return this->mQuality;
	}
	virtual void sale() {
		cout << "BuildingB" << this->mQuality << "被售卖" << endl;
	}
public:
	string mQuality;
};

//中介  中介类取维护和管理楼盘对象  所以维护父类指针
class Mediator {
public:
	Mediator() {
		AbstractBuilding* building = new BuildingA;
		vBuilding.push_back(building);
		building = new BuildingB;
		vBuilding.push_back(building);
	}
	//对外提供接口
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
	vector<AbstractBuilding*> vBuilding;//放抽象的

};

void test02(){

	Mediator * m = new Mediator;
	AbstractBuilding* build = m->myBuilding("高品质");

	if (build != NULL) {
		build->sale();
	}
	else {
		cout << "没有适合的房子" << endl;
	}
	


}

int main() {
	test02();
	return 0;
}