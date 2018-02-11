#include "Header.h"
int main(){
	String str("qwerety");
	String str1("y");
	
	cout << str << str1;
	String str2;
	str1 = str1 + str;
	int q = str.find(str1);
	cout << str1 << str1.getLength();
	system("pause");
}