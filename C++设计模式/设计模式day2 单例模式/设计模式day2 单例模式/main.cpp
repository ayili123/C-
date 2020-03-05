#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*
������ֻ�ܴ���һ������������----����ʽ(���ж��ڴ���)---����ʽ(����main��������)
�������߳�ʱ�ö���ʽ������ʽ����ȫ������ʽ�Ͳ�����ĵ�����
���裺
1.�����캯��˽�л�
2.���Ӿ�̬˽�еĵ�ǰ���ָ�����
3.���Ӿ�̬����ӿڣ��������û���õ�������  static      ��������::
*/

class A {
private:
	A() {
		pA = new A;
	}
public://���ص���
	static A* getA() {//���ﷵ��A*   *************  static:˽�й�����������::�ⲿ�������õ���
		return pA;            //��̬��Ա��������ͨ����������

	}
private:
	static A* pA;
};
A* A::pA = NULL;

//����ʽ

class Singleton_lazy {
private:
	Singleton_lazy() {
	}
public:
	static Singleton_lazy* getInstance() {
		if (pSingleton_lazy == NULL)
		{
			pSingleton_lazy = new  Singleton_lazy;//***********����return
		}
		return NULL;
	}
private:
	static Singleton_lazy* pSingleton_lazy;
};

Singleton_lazy* Singleton_lazy::pSingleton_lazy = NULL;

//����ʽ
class Singleton_hangry {
private:
	Singleton_hangry() {
	}
public:
	static Singleton_hangry* getInstance() {
	
			return pSingleton_hangry;
	
	}
private:
	static Singleton_hangry* pSingleton_hangry;
};

Singleton_hangry* Singleton_hangry::pSingleton_hangry = new Singleton_hangry;

void test() {
	Singleton_lazy* p1 = Singleton_lazy::getInstance();
	Singleton_lazy* p2 = Singleton_lazy::getInstance();
	if (p1 == p2) {
		cout << "�ǵ���" << endl;
	}
	else
		cout << "���ǵ���" << endl;
	cout << "_______________"<<endl;
	Singleton_hangry* p3 = Singleton_hangry::getInstance();
	Singleton_hangry* p4 = Singleton_hangry::getInstance();
	if (p3 == p4) {
		cout << "�ǵ���" << endl;
	}
	else
		cout << "���ǵ���" << endl;


}

int main() {

	test();
	system("pause");
	return 0;
}