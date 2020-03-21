#include "calcu.h"
#include "include.h"
#include "math.h"
void calcu(string &str) {
	float list[27] = { 0 };
	int len = str.length();
	int total = 0;
	double h[4] = { 0 };
	for (char mark = 'a'; mark <= 'z'; mark++) 
		for (int i = 0; i < len; i++) if (str[i] == mark) list[mark-'a']++;
	for (int i = 0; i < len; i++) if (str[i] == ' ') list[26]++;

	//计算符号熵
	for (int i = 0; i < 27; i++) total += list[i];				//得到total
	for (int i = 0; i < 27; i++) list[i] = list[i] / total;     //得到概率
	
	for (int i = 0; i < 27; i++) {
		if (list[i]) h[0] -= list[i] * log2(list[i]); 
	}

	float **ary = new float*[27];
	for (int i = 0; i < 27; ++i) {
		ary[i] = new float[27];
	}
	for (int i = 0; i < 27; i++) for (int j = 0; j < 27; j++) ary[i][j] = 0;
	for (char mark = 'a'; mark <= 'z'; mark++) {
		for (char mark2 = 'a'; mark2 <= 'z'; mark2++) {
			for (int i = 0; i < len - 1; i++) if (str[i] == mark && str[i + 1] == mark2) ary[mark - 'a'][mark2 - 'a'] ++;
			for (int i = 0; i < len; i++) if (str[i] == ' ') ary[mark - 'a'][26]++;
		}
	}
	for (int i = 0; i < len-1; i++) if (str[i] == ' ') ary[26][str[i+1] - 'a']++;
	for (int i = 0; i < 27; i++) for (int j = 0; j < 27; j++) total += ary[i][j];				//得到total
	for (int i = 0; i < 27; i++) for (int j = 0; j < 27; j++) ary[i][j] = ary[i][j] / total;
	for (int i = 0; i < 27; i++) for (int j = 0; j < 27; j++) if (ary[i][j])h[1] -= ary[i][j] * log2(ary[i][j]);
	h[1] /= 2;
	for (int i = 0; i < 27; ++i) {
		delete[] ary[i];
	}
	delete[] ary;




			











	cout << h[0] << endl;
	cout << h[1] << endl;

	FILE *fp;		//debug部分,检查输出，通过！
	fopen_s(&fp, "calcu!.txt", "w");

	for (int i = 0; i < 2; i++) {
		fprintf(fp, "H[%d] = %lf\n", i + 1, h[i]);
	}

	fclose(fp);
}