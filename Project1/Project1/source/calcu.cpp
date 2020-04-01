#include "calcu.h"
#include "include.h"
#include "math.h"
long int start;
long int band;
class h1struct		//H2		结构体声明，计算出现概率
{
public:
	char type[2] = { 0,0 };		//字符类型
	float count = 0;			//计数
};
class h2struct
{
public:
	char type[3] = { 0,0,0 };
	float count = 0;
};
class h3struct
{
public:
	char type[4]={0,0,0,0};
	float count=0;
};
class h4struct
{
public:
	char type[5] = { 0,0,0,0,0 };
	float count = 0;
};
class h5struct
{
public:
	char type[6] = { 0,0,0,0,0 };
	float count = 0;
}; class h6struct
{
public:
	char type[7] = { 0,0,0,0,0 };
	float count = 0;
};
void calcu(string &str) {
	int numb = 0;
	float list[27] = { 0 };		//H1记录 
	int len = str.length();
	int total = 0;
	double h[6] = { 0 };


	start = clock();
	for (char mark = 'a'; mark <= 'z'; mark++) 
		for (int i = 0; i < len; i++) if (str[i] == mark) list[mark-'a']++;
	for (int i = 0; i < len; i++) if (str[i] == ' ') list[26]++;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
			list[26]++;
		else
			list[str[i] - 'a']++;
	}
	for (int i = 0; i < 27; i++) total += list[i];				//得到total
	for (int i = 0; i < 27; i++) list[i] = list[i] / total;     //得到概率
	for (int i = 0; i < 27; i++) {
		if (list[i]) h[0] -= list[i] * log2(list[i]); 
	}
	cout << "H[1] calculated" << endl;
	cout << h[0] << endl;
	band = clock();
	cout << "用时" << (int)((band - start) / 1000) << "." << (band - start) - ((int)((band - start) / 1000)) * 1000 << "秒。" << endl;

	//H[2] ----------------
	start = clock();
	h1struct *p1 = new h1struct[len - 1];
	for (int i = 0; i < len - 1; i++)	//遍历字符串
	{
	begin1:
		if (i >= len - 1) break;
		for (int n = 0; n <= i; n++)		//现有保存字符和新字符串对比，相同count+1；不同就新建一个字符类型，count+1
		{
			if (p1[n].type[0] == str[i + 0] &&
				p1[n].type[1] == str[i + 1]
				)
			{
				p1[n].count++;
				i++;
				goto begin1;
			}
		}
		p1[numb].type[0] = str[i + 0];
		p1[numb].type[1] = str[i + 1];
		p1[numb].count++;
		numb++;
	}
	total = 0;
	for (int i = 0; i < numb; i++)				//计算H2
		total += p1[i].count;
	for (int i = 0; i < numb; i++)
		p1[i].count /= total;
	for (int i = 0; i < numb; i++)
		h[1] -= p1[i].count * log2(p1[i].count);
	h[1] /= 2;
	delete[] p1;
	numb = 0;
	cout << "H[2] calculated" << endl;
	cout << h[1] << endl;
	band = clock();
	cout << "用时" << (int)((band - start) / 1000) << "." << (band - start)-((int)((band - start) / 1000))*1000 <<"秒。" << endl;

	//H[3] ----------------
	start = clock();
	h2struct *p2 = new h2struct[len - 2];
	for (int i = 0; i < len - 2; i++)
	{
	begin2:
		if (i >= len - 2) break;
		for (int n = 0; n <= i; n++)
		{
			if (p2[n].type[0] == str[i + 0] &&
				p2[n].type[1] == str[i + 1] &&
				p2[n].type[2] == str[i + 2])
			{
				p2[n].count++;
				i++;
				goto begin2;
			}
		}
		p2[numb].type[0] = str[i + 0];
		p2[numb].type[1] = str[i + 1];
		p2[numb].type[2] = str[i + 2];
		p2[numb].count++;
		numb++;
	}
	total = 0;
	for (int i = 0; i < numb; i++)
		total += p2[i].count;
	for (int i = 0; i < numb; i++)
		p2[i].count /= total;
	for (int i = 0; i < numb; i++)
		h[2] -= p2[i].count * log2(p2[i].count);
	h[2] /= 3;
	delete[] p2;
	numb = 0;
	cout << "H[3] calculated" << endl;
	cout << h[2] << endl;
	band = clock();
	cout << "用时" << (int)((band - start) / 1000) << "." << (band - start) - ((int)((band - start) / 1000)) * 1000 << "秒。" << endl;
	//End---------------H[3] ----------------


	//H[4] ----------------
	start = clock();
	h3struct *p = new h3struct[len - 3];

	for (int i = 0; i < len - 3; i++)
	{
	begin3:
		if (i >= len - 3) break;
		for (int n = 0; n <= i; n++)
		{
			if (p[n].type[0] == str[i + 0] &&
				p[n].type[1] == str[i + 1] &&
				p[n].type[2] == str[i + 2] &&
				p[n].type[3] == str[i + 3]
				)
			{
				p[n].count++;
				i++;
				goto begin3;
			}
		}
		p[numb].type[0] = str[i + 0];
		p[numb].type[1] = str[i + 1];
		p[numb].type[2] = str[i + 2];
		p[numb].type[3] = str[i + 3];
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
	numb = 0;
	cout << "H[4] calculated" << endl;
	cout << h[3] << endl;
	band = clock();
	cout << "用时" << (int)((band - start) / 1000) << "." << (band - start) - ((int)((band - start) / 1000)) * 1000 << "秒。" << endl;


	//End----------H[4]-------------
	start = clock();
	h4struct *p4 = new h4struct[len - 4];
	for (int i = 0; i < len - 4; i++)
	{
	begin4:
		if (i >= len - 4) break;
		for (int n = 0; n <= i; n++)
		{
			if (p4[n].type[0] == str[i + 0] &&
				p4[n].type[1] == str[i + 1] &&
				p4[n].type[2] == str[i + 2] &&
				p4[n].type[3] == str[i + 3] &&
				p4[n].type[4] == str[i + 4])
			{
				p4[n].count++;
				i++;
				goto begin4;
			}
		}
		p4[numb].type[0] = str[i + 0];
		p4[numb].type[1] = str[i + 1];
		p4[numb].type[2] = str[i + 2];
		p4[numb].type[3] = str[i + 3];
		p4[numb].type[4] = str[i + 4];
		p4[numb].count++;
		numb++;
	}
	total = 0;
	for (int i = 0; i < numb; i++)
		total += p4[i].count;
	for (int i = 0; i < numb; i++)
		p4[i].count /= total;
	for (int i = 0; i < numb; i++)
		h[4] -= p4[i].count * log2(p4[i].count);
	h[4] /= 5;
	delete[] p4;
	numb = 0;
	cout << "H[5] calculated" << endl;
	cout << h[4] << endl;
	band = clock();
	cout << "用时" << (int)((band - start) / 1000) << "." << (band - start) - ((int)((band - start) / 1000)) * 1000 << "秒。" << endl;

	cout << "\n----------------------计算完成----------------------\n" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "H" << i + 1 << "的值为： " << h[i] << "." <<  endl;
	}
	cout << "将文件保存到了answer.txt" << endl;
	FILE *fp;		//debug部分,检查输出，通过！
	fopen_s(&fp, "answer.txt", "w");

	for (int i = 0; i < 5; i++) {
		fprintf(fp, "H[%d] = %lf\n", i + 1, h[i]);
	}

	fclose(fp);
}