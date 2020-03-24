#include "calcu.h"
#include "include.h"
#include "math.h"

void calcu(string &str) {
	char chars[27];
	for (char mark = 'a'; mark <= 'z'; mark++)
		chars[mark - 'a'] = mark;
	chars[26] = ' ';
	float list[27] = { 0 };
	int len = str.length();
	int total = 0;
	double h[4] = { 0 };
	for (char mark = 'a'; mark <= 'z'; mark++) 
		for (int i = 0; i < len; i++) if (str[i] == mark) list[mark-'a']++;
	for (int i = 0; i < len; i++) if (str[i] == ' ') list[26]++;

	//计算符号熵

	//H[1] ----------------
	for (int i = 0; i < 27; i++) total += list[i];				//得到total
	for (int i = 0; i < 27; i++) list[i] = list[i] / total;     //得到概率
	
	for (int i = 0; i < 27; i++) {
		if (list[i]) h[0] -= list[i] * log2(list[i]); 
	}
	cout << "H[1] calculated" << endl;
	//H[2] ----------------
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
	cout << "H[2] chapter.1 Finished" << endl;
	for (int i = 0; i < len-1; i++) if (str[i] == ' ') ary[26][str[i+1] - 'a']++;
	cout << "H[2] chapter.2 Finished" << endl;
	for (int i = 0; i < 27; i++) for (int j = 0; j < 27; j++) total += ary[i][j];				//得到total
	cout << "H[2] chapter.3 Finished" << endl;
	for (int i = 0; i < 27; i++) for (int j = 0; j < 27; j++) ary[i][j] = ary[i][j] / total;
	cout << "H[2] chapter.4 Finished" << endl;
	for (int i = 0; i < 27; i++) for (int j = 0; j < 27; j++) if (ary[i][j])h[1] -= ary[i][j] * log2(ary[i][j]);
	cout << "H[2] chapter.5 Finished" << endl;
	h[1] /= 2;
	for (int i = 0; i < 27; ++i) {
		delete[] ary[i];
	}
	delete[] ary;

	//H[3] ----------------
	float ***DD;//声明指针
	DD = new float **[27];//定义X的长度

	for (int x = 0; x < 27; x++)//在X的内部，定义Y
	{
		DD[x] = new float *[27];//定义Y的长度

		for (int y = 0; y < 27; y++)//在xy的内部，定义Z
		{
			DD[x][y] = new float[27];//定义Z的长度
		}
	}

	for (int i = 0; i < 27; i++)
		for (int j = 0; j < 27; j++)
			for (int k = 0; k < 27; k++)
				DD[i][j][k] = 0;
	cout << "H[3] chapter.1 Started" << endl;
	for (char mark = 0; mark <= 26; mark++)
		for (char mark2 = 0; mark2 <= 26; mark++)
			for (char mark3 = 0; mark3 <= 26; mark++)
				for (int i = 0; i < len - 2; i++)
					if (str[i] == chars[mark] && str[i + 1] == chars[mark2] && str[i + 2] == chars[mark3])
						DD[mark][mark2][mark3] ++;
					else
					{
						cout << "calcuing" << endl;
					}
	cout << "H[3] chapter.1 Finished" << endl;
	for (int i = 0; i < 27; i++)
		for (int j = 0; j < 27; j++)
			for (int k = 0; k < 27; k++)
				total+=DD[i][j][k];
	cout << "H[3] chapter.2 Finished" << endl;
	for (int i = 0; i < 27; i++)
		for (int j = 0; j < 27; j++)
			for (int k = 0; k < 27; k++)
				DD[i][j][k] /= total;
	cout << "H[3] chapter.3 Finished" << endl;
	for (int i = 0; i < 27; i++)
		for (int j = 0; j < 27; j++)
			for (int k = 0; k < 27; k++)
				if(DD[i][j][k])
					h[2] -= DD[i][j][k] * log2(DD[i][j][k]);
	cout << "H[3] chapter.4 Finished" << endl;
	h[2] /= 3;
	for (int x = 0; x < 27; x++)
	{
		for (int y = 0; y < 27; y++)
		{
			delete[] DD[x][y];//释放Z这一层
		}
	}
	for (int x = 0; x < 27; x++)
	{
		delete[] DD[x];//释放Y这一层
	}
	delete[] DD;//释放X这一层



	cout << h[0] << endl;
	cout << h[1] << endl;
	cout << h[2] << endl;

	FILE *fp;		//debug部分,检查输出，通过！
	fopen_s(&fp, "calcu!.txt", "w");

	for (int i = 0; i < 2; i++) {
		fprintf(fp, "H[%d] = %lf\n", i + 1, h[i]);
	}

	fclose(fp);
}