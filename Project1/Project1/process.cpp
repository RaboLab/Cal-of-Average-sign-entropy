#include "include.h"
#include "sstream"
string process(void) {
	filebuf *pbuf;
	fstream filestr;
	ostringstream os;
	long size;
	char* buffer;
	// 要读入整个文件，必须采用二进制打开 
	filestr.open("test.txt", ios::in);
	// 获取filestr对应buffer对象的指针 
	pbuf = filestr.rdbuf();

	// 调用buffer对象方法获取文件大小
	size = pbuf->pubseekoff(0, ios::end, ios::in);
	pbuf->pubseekpos(0, ios::in);

	// 分配内存空间
	buffer = new char[size];

	// 获取文件内容
	pbuf->sgetn(buffer, size);
	buffer[size - 1] = '\0';

	filestr.close();
	// 输出到标准输出
	cout.write(buffer, size);
	string str = buffer;
	delete[] buffer;
	os << str;
	cout << os.str();
	for (int i = 0; i < str.length(); i++) {		//erase后长度会变动
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;  //特殊符号处理咋办？？？ 
		else if (str[i] >= '0' && str[i] <= '9') str.erase(i, 1);
		else if (str[i] >= 'a' && str[i] <= 'z');
		else if (str[i] = ' ');
		else 
	}
	return str;
}