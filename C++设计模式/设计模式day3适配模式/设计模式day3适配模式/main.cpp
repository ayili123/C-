#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
����ģʽ��
  ��д�õĽӿڸ�д���Լ�ʹ�õĽӿ�
*/

//���������Ǵ�ӡ�����ĺ�������for_eachֻ��һ����ӡ����
struct Print {

	void operator()(int i,int j) {
		cout << i+j << endl;
	}
};

//��������������
class MyPrint {
public:

	virtual void operator()(int i) = 0;  //   1.���Ƚ������Ե�д���麯��
};

class shipeiqi : public MyPrint {
public:
	shipeiqi(int i) {
		this->mNUM = i;
	}
	virtual void operator()(int i) {
		mPrint(i, mNUM);
	}
public:
	Print mPrint;//ʵ��                         2.�ٰ�����Ŀ���ʵ��д����
	int mNUM;
};
//

//�����д�ɱ�����������Щ�����ӵ�
/*
shipeiqi(int i) {
		this->mNUM = i;
	}
	int mNUM;
*/
shipeiqi test2(int i) {
	return shipeiqi(i);
}

void test() {
	vector<int> a;
	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}
	for_each(a.begin(), a.end(), test2(10));

}

int main() {

	test();
	system("pause");
	return 0;
}