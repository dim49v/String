#include "Header.h"
int main(){
	String str("qwerty");
	String str1;
	cout << str << str1;
	str.reverse();
	cout << str << str1 << str.getLength();
	str = str + str1;
	cout << str << str1 << str.getLength();
	str = str1 + str;
	cout << str << str1 << str.getLength();
	system("pause");
} 