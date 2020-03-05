#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*
����ԭ����������չ���ţ����޸Ĺرա�
���ӹ�����ͨ�����Ӵ���ʵ�ֲ���ͨ���޸�Դ����
����������
*/
//���������
class AbstractCaculate {
public:
	virtual int getValue() = 0;
};

//�ӷ�
class PlusCaculate : public AbstractCaculate
{
public:
	PlusCaculate(int a,int b) {
		this->mA = a;
		this->mB = b;
	}
	virtual int getValue() {
		return mA + mB;
	}
public:
	int mA;
	int mB;
};

//����
class MinuteCaculate : public AbstractCaculate
{
public:
	MinuteCaculate(int a, int b){
		this->mA = a;
		this->mB = b;
	}
	virtual int getValue() {
		return mA - mB;
	}
public:
	int mA;
	int mB;
};

//�˷�
class MuliplyCaculate : public AbstractCaculate
{
public:
	MuliplyCaculate(int a, int b) {
		this->mA = a;
		this->mB = b;
	}
	virtual int getValue() {
		return mA * mB;
	}
public:
	int mA;
	int mB;
};
//�����Խ���ʼ�����ȥ��init������
void test() {
	//����ָ��ָ���������
	AbstractCaculate* c = new PlusCaculate(10,20);//�����Խ���ʼ�����ȥ��init������  ����ֻ���ø���ָ��
	cout << c->getValue() << endl;
	AbstractCaculate* d = new MuliplyCaculate(10, 20);
	cout << d->getValue() << endl;
	delete c;
	delete d; 
}


int main() {

	test();
	return 0;
}