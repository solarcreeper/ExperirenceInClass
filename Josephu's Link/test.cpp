#include"JosephuLink.h"
void main(){
	int n;				//����������
	int m;				//��ʼ����
	int count[30];		//����
	cout << "���뱨����������";
	cin >> n;
	cout << "��������ĳ�ʼֵ��";
	cin >> m;
	cout << "�������룺";
	for (int i = 0; i < n; i++){
		cin >> count[i];
	}
	cout << "����˳��";
	JosephuLink j = JosephuLink(count[0]);
	for (int i = 1; i < n; i++){
		j.Insert(i, count[i]);
	}
	j.josephu(m, 1);
	return;
}