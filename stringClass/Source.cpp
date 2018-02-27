#include "Header.h"
int main(){
	try{
		String str("qwertyqwertyq");
		String str1;
		cout << str << str1;
		str.reverse();
		cout << str << str1 << str.getLength();
		str = str1;
		cout << str << str1 << str.getLength();
		str = str1 + str;
		cout << str << str1 << str.getLength();
		str1 = str1 + str1;
		cout << str1 << str1.getLength();
		str = str + str;
		cout << str << str1 << str.getLength();
		str = str;
	}
	catch (IndexError &err){
		cout << "Valid values range from " << err.min_ << " to " << err.max_ << endl;
	}
	catch (ArrLengthError &err){
		cout << "Valid values range from " << err.min_ << " to " << err.max_ << endl;
	}
	catch (MemoryError &err){}
	catch (Exception &err){}
	system("pause");
	return 0;
}