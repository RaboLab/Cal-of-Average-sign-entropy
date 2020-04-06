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
	// 要读入整个文件，必须采用二进制打开 
	filestr.open("test.txt", ios::in);
	// 获取filestr对应buffer对象的指针 
	pbuf = filestr.rdbuf();

	// 调用buffer对象方法获取文件大小
	size = pbuf->pubseekoff(0, ios::end, ios::in);
	size++;
	pbuf->pubseekpos(0, ios::in);

	// 分配内存空间
	buffer = new char[size];

	// 获取文件内容
	pbuf->sgetn(buffer, size);
	buffer[size - 1] = '\0';

	filestr.close();
	// 输出到标准输出

	string str = buffer;
	start = clock();
	cout << "开始处理原始文件，字符数量为：" << str.length() << "。" << endl;
	
	delete[] buffer;

	for (int i = 0; i < str.length(); i++) {		//erase后长度会变动
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;  //特殊符号处理咋办？？？ //str.erase(i, 1)
		else if (str[i] >= 'a' && str[i] <= 'z');
		else str[i] = ' ';
	}
	//先把特殊符号改成" ", 然后遇见多个空格恢复成一个
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

	//--------------------输出,可直接删除--------------------
	FILE *fp;		//debug部分,检查输出，通过！
	fopen_s(&fp,".//answer//processed.txt", "w");

	fprintf(fp, str.c_str());

	fclose(fp);
	//------------------------------------------------------
	cout << "特殊符号处理完毕，处理完成后字符数量为：" << str.length() << "。" << endl;
	band = clock();

	cout << "用时" << (int)((band - start) / 1000) << "." << (band - start) - ((int)((band - start) / 1000)) * 1000 << "秒。" << endl;
	cout << "将处理后的文件同时保存为processed.txt" << endl;
	return str;
}