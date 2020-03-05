/*
��һ��  ����24��ѧ��  ��Ϊÿ��ѧ�����в�����ţ��������Ψһ���ŵ�map������  key�Ǳ�� - valueѡ�ֶ���
vector<int> v1 ��һ�ֲ����ģ���ţ��б� map[���]  random_shuffle()
vector<int> v2 ��һ�ֱ����Ľ�������
vector<int> v3 �ڶ��ֱ����Ľ�������
vector<int> v4 �����ֱ����Ľ�������
*/

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <deque>
#include <time.h>


using namespace std;

class Player {
public:
	string mName;
	int mScore[3];//�������α����ĳɼ�����ű�����key��
};

struct myprint {
	void operator()(int a){
		cout << a << " ";
	}
};

//����ѡ��
void Creat_Player(map<int, Player>& mPlist, vector<int>& vInit) {
	string seedNAME = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24; i++) {
		Player P;
		P.mName = "ѡ��";
		for (int j = 0; j < 3; j++) {
			P.mScore[j] = 0;
		}
		P.mName += seedNAME[i];
		int uID = 100 + i;
		mPlist.insert(make_pair(uID, P));//����
		vInit.push_back(uID);//v1  ��������
	}
	
	for_each(vInit.begin(), vInit.end(), myprint());
	cout << endl;

}


void Set_Random(vector<int>& vRandom)//ѡ�ֳ�ǩ
{
	random_shuffle(vRandom.begin(), vRandom.end());
	for_each(vRandom.begin(), vRandom.end(), myprint());
	cout << endl;

}

//��v1��֣�����map�У���Ÿ�v2,index�ڼ���
void Set_Score(int index,vector<int>&  vIn, map<int, Player>& mPlist, vector<int>& vOut)//���  ����map��
{
	srand((unsigned int)time(NULL));//����
	//����**************
	//�����ͱ�ţ���������key,���Զ�����
	multimap<int,int,greater<int>> mGroup;//int int ���� ���//Ĭ�ϴ�С��������
	int groupIndex = 0;
	for (vector<int>::iterator it = vIn.begin(); it != vIn.end(); it++) {
	 
		//���
		deque<int> dScore;//deque����ͷɾ��
		for (int i = 0; i < 10; i++) {
			int score = rand() % 40 + 60;
			
			dScore.push_back(score);
		}
        //����
		sort(dScore.begin(), dScore.end());
		//ȥ��������
		dScore.pop_front();
		dScore.pop_back();
		//���
		int total_score = accumulate(dScore.begin(), dScore.end(),0);
		//ƽ����
		int avg_score = total_score /dScore.size();
		
		//����key���� 
		mPlist[*it].mScore[index-1] = avg_score;
		//�ѵ�ǰѡ�ֱ�ŷ���mGroup��
		mGroup.insert(make_pair(avg_score,*it));//����
		groupIndex++;
		if (groupIndex % 6 == 0) {
			int numIndex = 0;
			for (multimap<int, int>::iterator mIt = mGroup.begin(); mIt != mGroup.end(); mIt++) {
				if (numIndex >= 3) {
					break;
				}
				//ȡǰ����
				vOut.push_back((*mIt).second);
				numIndex++;
			}
			mGroup.clear();//���
		}
	}
	
}

//��ӡ��������
void Show_Good_Player(int index, map<int, Player>& mPlist, vector<int>& v)
{
	//v�洢�ĺ�map��intһ��
	cout << "__________________________" << endl;
	cout << "��" << index << "�ַ��������" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "������  " << mPlist[*it].mName << "," <<"������    "<< mPlist[*it].mScore[index-1] << endl;
	}
}

int main()
{
	//����map����  ���ݱ�ű���ѡ����Ϣ ��Ŵ���key��
	map<int, Player> mPlist;

	//��һ�ֱ����Ĳ����б�
	vector<int> v1;//24�� ����12��

	//�ڶ��ֱ����Ĳ����б�
	vector<int> v2;//12�� ����6��

	//�����ֱ����Ĳ����б�
	vector<int> v3;//6�� ����3��

	//����ǰ����
	vector<int> v4;

	//����ѡ��
	Creat_Player(mPlist,v1);

	//��һ�ֱ���
	Set_Random(v1);//ѡ�ֳ�ǩ
	Set_Score(1,v1,mPlist,v2);//���  ����map��
	Show_Good_Player(1,mPlist,v2);//��ӡ����ѡ��

	//�ڶ��ֱ���
	Set_Random(v2);//ѡ�ֳ�ǩ
	Set_Score(2, v2, mPlist, v3);//���  ����map��
	Show_Good_Player(2, mPlist, v3);//��ӡ����ѡ��

	//�����ֱ���
	Set_Random(v3);//ѡ�ֳ�ǩ
	Set_Score(3, v3, mPlist, v4);//���  ����map��
	Show_Good_Player(3, mPlist, v4);//��ӡ����ѡ��
	
	
	return 0;
}