#include"JosephuLink.h"
void main(){
	int n;				//报数的人数
	int m;				//初始密码
	int count[30];		//密码
	cout << "输入报数的人数：";
	cin >> n;
	cout << "输入密码的初始值：";
	cin >> m;
	cout << "输入密码：";
	for (int i = 0; i < n; i++){
		cin >> count[i];
	}
	cout << "出列顺序：";
	JosephuLink j = JosephuLink(count[0]);
	for (int i = 1; i < n; i++){
		j.Insert(i, count[i]);
	}
	j.josephu(m, 1);
	return;
}