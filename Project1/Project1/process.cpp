#include "include.h"
#include "sstream"
string process(void) {
	filebuf *pbuf;
	fstream filestr;
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
	cout.write(buffer, size);
	string str = buffer;
	delete[] buffer;
	os << str;
	cout << os.str();
	for (int i = 0; i < str.length(); i++) {		//erase�󳤶Ȼ�䶯
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;  //������Ŵ���զ�죿���� 
		else if (str[i] >= '0' && str[i] <= '9') str.erase(i, 1);
		else if (str[i] >= 'a' && str[i] <= 'z');
		else if (str[i] = ' ');
		else 
	}
	return str;
}