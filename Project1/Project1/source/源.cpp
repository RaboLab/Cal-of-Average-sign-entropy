#include "include.h"
#include "process.h"
#include "calcu.h"
#include "createHTML.h"
FILE * fpa;
int main() {
	FILE * fpa = init();
	cout << "\n----------------------��ʼ����----------------------\n" << endl;
	cout << "����ʱ����1.5mins���ң����㵽H5����������������ʾ��" << endl;
	cout << "�����js��ͼ�������϶��Ϸ��������ɾֲ��Ŵ�����ƶ�������ʾֵ��\n\n\n" << endl;
	string str = process();
	calcu(str, fpa);
	close(fpa);
	system("result.html");
	system("pause");
	return 0;
}