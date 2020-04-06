#include "include.h"
#include "process.h"
#include "calcu.h"
#include "createHTML.h"
FILE * fpa;
int main() {
	FILE * fpa = init();
	cout << "\n----------------------开始计算----------------------\n" << endl;
	cout << "运行时长在1.5mins左右，计算到H5，并输出到浏览器显示。" << endl;
	cout << "浏览器js绘图较慢，拖动上方进度条可局部放大，鼠标移动可以显示值。\n\n\n" << endl;
	string str = process();
	calcu(str, fpa);
	close(fpa);
	system("result.html");
	system("pause");
	return 0;
}