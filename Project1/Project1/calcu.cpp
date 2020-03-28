#include "calcu.h"
#include "include.h"
#include "math.h"

class h3struct
{
public:
	char type[4]={0,0,0,0};
	float count=0;
};
int numb = 0;
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

	for (int i = 0; i < len; i++)
	{
		cout << "calcuing" << endl;
		if (str[i] == ' ')
			list[26]++;
		else
			list[str[i] - 'a']++;
	}
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
	for (int i = 0; i < len-1; i++)
	{
		if(str[i] == ' ' && str[i+1] == ' ')
			ary[26][26]++;
		else if (str[i] == ' ')
			ary[26][str[i + 1] - 'a']++;
		else if (str[i + 1] == ' ')
			ary[str[i] - 'a'][26]++;
		else
			ary[str[i] - 'a'][str[i + 1] - 'a']++;
	}
	total = 0;
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
	for (int i = 0; i < len - 2; i++)
	{
		if (str[i] == ' ') {
			if (str[i + 2] == ' ')
				DD[26][str[i + 1] - 'a'][26]++;
			else
				DD[26][str[i + 1] - 'a'][str[i + 2] - 'a']++;
		}
		else if (str[i+1] == ' ')
			DD[str[i] - 'a'][26][str[i + 2] - 'a']++;
		else if (str[i+2] == ' ')
			DD[str[i] - 'a'][str[i + 1] - 'a'][26]++;
		else
			DD[str[i] - 'a'][str[i + 1] - 'a'][str[i + 2] - 'a']++;
	}

	for (int i = 0; i < 27; i++)
		for (int j = 0; j < 27; j++)
			for (int k = 0; k < 27; k++)
				total+=DD[i][j][k];
	for (int i = 0; i < 27; i++)
		for (int j = 0; j < 27; j++)
			for (int k = 0; k < 27; k++)
				DD[i][j][k] /= total;
	for (int i = 0; i < 27; i++)
		for (int j = 0; j < 27; j++)
			for (int k = 0; k < 27; k++)
				if(DD[i][j][k])
					h[2] -= DD[i][j][k] * log2(DD[i][j][k]);
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

	//End---------------H[3] ----------------



	cout << "Calculating H4" << endl;
	//H[4] ----------------
	
	h3struct *p = new h3struct [len - 3];

	for (int i = 0; i < len - 3; i++)
	{
begin:
		for (int n = 0; n <= i; n++)
		{
			if (p[n].type[i + 0] == str[i + 0] &&
				p[n].type[i + 1] == str[i + 1] &&
				p[n].type[i + 2] == str[i + 2] &&
				p[n].type[i + 3] == str[i + 3]) 
			{
				p[n].count++;
				i++;
				goto begin;
			}
		}
		p[numb].type[i + 0] = str[i + 0];
		p[numb].type[i + 1] = str[i + 1];
		p[numb].type[i + 2] = str[i + 2];
		p[numb].type[i + 3] = str[i + 3];
		p[numb].count++;
		numb++;

	}
	total = 0;
	for (int i = 0; i < numb; i++)
		total += p[i].count;
	for (int i = 0; i < numb; i++)
		p[i].count /= total;
	for (int i = 0; i < numb; i++)
			h[3] -= p[i].count * log2(p[i].count);
	h[3] /= 4;

	delete[] p;

	//End----------H[4]-------------
	cout << h[0] << endl;
	cout << h[1] << endl;
	cout << h[2] << endl;
	cout << h[3] << endl;

	FILE *fp;		//debug部分,检查输出，通过！
	fopen_s(&fp, "calcu!.txt", "w");

	for (int i = 0; i < 2; i++) {
		fprintf(fp, "H[%d] = %lf\n", i + 1, h[i]);
	}

	fclose(fp);
}