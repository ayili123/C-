#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*
�߲�ҵ��;���ʵ�ֲ�ҵ�������ڳ����
����Ա��������Ա��������㣩  ����ʵ��Ա�����߲�ҵ��  Ա���ɻʵ�ֲ� ���в㣩���þ���ʵ�֡���������ǳ����

*/

//�����
class AbstractWork {
public:
	virtual void Binuss() = 0;
};

//����Ա��  
class WorkA : public AbstractWork {
public:
	virtual void Binuss() {
		cout << "i am workA..." << endl;//��̬
	}
};
class WorkB : public AbstractWork {
public:
	virtual void Binuss() {
		cout << "i am workB..." << endl;//��̬
	}
};
class WorkC : public AbstractWork {
public:
	virtual void Binuss() {
		cout << "i am workC..." << endl;//��̬
	}
};
class WorkD : public AbstractWork {
public:
	virtual void Binuss() {
		cout << "i am workD..." << endl;//��̬
	}
};

//Ա���ɻ�
void mybuniss(AbstractWork* work) {
	work->Binuss();    //ֱ�ӵ�
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
