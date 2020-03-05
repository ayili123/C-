#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*
高层业务和具体实现层业务都依赖于抽象层
银行员工：抽象员工（抽象层）  具体实现员工（高层业务）  员工干活（实现层 、中层）调用具体实现、传入参数是抽象层

*/

//抽象层
class AbstractWork {
public:
	virtual void Binuss() = 0;
};

//具体员工  
class WorkA : public AbstractWork {
public:
	virtual void Binuss() {
		cout << "i am workA..." << endl;//多态
	}
};
class WorkB : public AbstractWork {
public:
	virtual void Binuss() {
		cout << "i am workB..." << endl;//多态
	}
};
class WorkC : public AbstractWork {
public:
	virtual void Binuss() {
		cout << "i am workC..." << endl;//多态
	}
};
class WorkD : public AbstractWork {
public:
	virtual void Binuss() {
		cout << "i am workD..." << endl;//多态
	}
};

//员工干活
void mybuniss(AbstractWork* work) {
	work->Binuss();    //直接调
	delete work;//(2)
}

void test() {
	/*AbstractWork* workA = new WorkA;
	workA->Binuss();
	AbstractWork* workB = new WorkB;
	workB->Binuss();
	delete workB;
	delete workA;*/

	mybuniss(new WorkA);
	mybuniss(new WorkB);
	


}


int main()
{
	test();
	system("pause");
	return 0;
	

}
