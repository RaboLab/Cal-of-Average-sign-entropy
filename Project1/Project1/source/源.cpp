#include "include.h"
#include "process.h"
#include "calcu.h"
int main() {
	clock_t start, band;
	string str = process();
	calcu(str);
	system("pause");
	return 0;
}