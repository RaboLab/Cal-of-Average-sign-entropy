#include "include.h"
#include "sstream"
#include <direct.h>  
extern clock_t start;
extern clock_t band;
string process(void) {

	filebuf *pbuf;
	fstream filestr;
	ofstream out;
	ostringstream os;
	long size;
	char* buffer;
	_mkdir("answer");
	// Ҫ���������ļ���������ö����ƴ� 
	filestr.open("test.txt", ios::in);
	// ��ȡfilestr��Ӧbuffer�����ָ�� 
	pbuf = filestr.rdbuf();

	// ����buffer���󷽷���ȡ�ļ���С
	size = pbuf->pubseekoff(0, ios::end, ios::in);
	size++;
	pbuf->pubseekpos(0, ios::in);

	// �����ڴ�ռ�
	buffer = new char[size];

	// ��ȡ�ļ�����
	pbuf->sgetn(buffer, size);
	buffer[size - 1] = '\0';

	filestr.close();
	// �������׼���

	string str = buffer;
	start = clock();
	cout << "��ʼ����ԭʼ�ļ����ַ�����Ϊ��" << str.length() << "��" << endl;
	
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
	fopen_s(&fp,".//answer//processed.txt", "w");

	fprintf(fp, str.c_str());

	fclose(fp);
	//------------------------------------------------------
	cout << "������Ŵ�����ϣ�������ɺ��ַ�����Ϊ��" << str.length() << "��" << endl;
	band = clock();

	cout << "��ʱ" << (int)((band - start) / 1000) << "." << (band - start) - ((int)((band - start) / 1000)) * 1000 << "�롣" << endl;
	cout << "���������ļ�ͬʱ����Ϊprocessed.txt" << endl;
	return str;
}