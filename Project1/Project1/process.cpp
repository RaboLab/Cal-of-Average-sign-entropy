#include "include.h"
#include "sstream"
string process(void) {
	filebuf *pbuf;
	fstream filestr;
	ofstream out;
	ostringstream os;
	long size;
	char* buffer;
	// Ҫ���������ļ���������ö����ƴ� 
	filestr.open("test.txt", ios::in);
	// ��ȡfilestr��Ӧbuffer�����ָ�� 
	pbuf = filestr.rdbuf();

	// ����buffer���󷽷���ȡ�ļ���С
	size = pbuf->pubseekoff(0, ios::end, ios::in);
	pbuf->pubseekpos(0, ios::in);

	// �����ڴ�ռ�
	buffer = new char[size];

	// ��ȡ�ļ�����
	pbuf->sgetn(buffer, size);
	buffer[size - 1] = '\0';

	filestr.close();
	// �������׼���

	string str = buffer;
	delete[] buffer;

	for (int i = 0; i < str.length(); i++) {		//erase�󳤶Ȼ�䶯
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;  //������Ŵ���զ�죿���� //str.erase(i, 1)
		else if (str[i] >= 'a' && str[i] <= 'z');
		else str[i] = ' ';
	}
	//�Ȱ�������Ÿĳ�" ", Ȼ����������ո�ָ���һ��
	int mark = 1;
	while (mark) {
		mark = 0;
		for (int i = 0; i < str.length()-1; i++) {		
			if (str[i] == ' ' && str[i + 1] == ' ') {
				mark = 1;
				str.erase(i, 1);
			}
		}
	}

	//--------------------���,��ֱ��ɾ��--------------------
	FILE *fp;		//debug����,��������ͨ����
	fopen_s(&fp,"wuhu!.txt", "w");

	fprintf(fp, str.c_str());

	fclose(fp);
	//------------------------------------------------------

	return str;
}