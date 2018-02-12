#include "String.h"
#include <iostream>
using namespace std;

String::String()
{
	length_ = 0;
	try{
		string_ = new char[length_ + 1]{0};
		if (string_ == 0){
			throw "Error. Memory not allocated";
		}
	}
	catch (char* err){
		cout << err << endl;
		system("pause");
		exit(1);
	}
}
String::String(const String& string){
 	length_ = string.length_;
	try{
		string_ = new char[length_ + 1];
		if (string_ == 0){
			throw "Error. Memory not allocated";
		}
		for (int i = 0; i <= length_; i++){
			string_[i] = string.string_[i];
		}
	}
	catch (char* err){
		cout << err << endl;
		system("pause");
		exit(1);
	}
}
String::String(const char* string){
	for (length_ = 0; string[length_] != 0; length_++)
		;
	try{
		string_ = new char[length_ + 1];
		if (string_ == 0){
			throw "Error. Memory not allocated";
		}
		for (int i = 0; i < length_; i++){
			string_[i] = string[i];
		}
		string_[length_] = 0;
	}
	catch (char* err){
		cout << err << endl;
		system("pause");
		exit(1);
	}
}
String::String(char ch, int length){
	
	try{
		if (length > 0){
			length_ = length;
		}
		else{
			throw "Error. Length must be >0";
		}
		string_ = new char[length_ + 1];
		if (string_ == 0){
			throw "Error. Memory not allocated";
		}
		for (int i = 0; i < length_; i++){
			string_[i] = ch;
		}
		string_[length_] = 0;
	}
	catch (char* err){
		cout << err << endl;
		system("pause");
		exit(1);
	}
}

String::~String()
{
	if (string_ != 0)
		delete[] string_;
}

bool String::operator<(const String& string){
	int minLength;
	bool bl = false;
	(length_ < string.length_) ? minLength = length_ : minLength = string.length_;
	int i = 0;
	while ((string_[i] == string.string_[i]) && (i < minLength))
		i++;
	if (i < minLength){
		if (string_[i] < string.string_[i])
			bl = true;
	}
	else{
		if (length_ < string.length_)
			bl = true;
	}
	return bl;
}
bool String::operator<=(const String& string){
	int minLength;
	bool bl = false;
	(length_ < string.length_) ? minLength = length_ : minLength = string.length_;
	int i = 0;
	while ((string_[i] == string.string_[i]) && (i < minLength))
		i++;
	if (i < minLength){
		if (string_[i] < string.string_[i])
			bl = true;
	}
	else{
		if (length_ <= string.length_)
			bl = true;
	}
	return bl;
}
bool String::operator==(const String& string){
	bool equal = true;
	if (length_ == string.length_){
		for (int i = 0; i < length_; i++){
			if (string_[i] != string.string_[i]){
				equal = false;
				break;
			}
		}
	}
	else{
		equal = false;
	}
	return equal;
}
bool String::operator>=(const String& string){
	int minLength;
	bool bl = false;
	(length_ < string.length_) ? minLength = length_ : minLength = string.length_;
	int i = 0;
	while ((string_[i] == string.string_[i]) && (i < minLength))
		i++;
	if (i < minLength){
		if (string_[i] > string.string_[i])
			bl = true;
	}
	else{
		if (length_ >= string.length_)
			bl = true;
	}
	return bl;
}
bool String::operator>(const String& string){
	int minLength;
	bool bl = false;
	(length_ < string.length_) ? minLength = length_ : minLength = string.length_;
	int i = 0;
	while ((string_[i] == string.string_[i]) && (i < minLength))
		i++;
	if (i < minLength){
		if (string_[i] > string.string_[i])
			bl = true;
	}
	else{
		if (length_ > string.length_)
			bl = true;
	}
	return bl;
}

String String::operator=(const String& string){
	try{
		char* stringChar = new char[string.length_ + 1];
		if (stringChar == 0){
			throw "Error. Memory not allocated";
		}	
		length_ = string.length_;
		for (int i = 0; i <= length_; i++){
			stringChar[i] = string.string_[i];
		}
		delete[] string_;
		string_ = stringChar;
	}
	catch (char* err){
		cout << err << endl;
		system("pause");
		exit(1);
	}
	return *this;
}
String String::operator+(const String& string){
	int newLength = length_ + string.length_;
	String newString(newLength);
	int i;
	for (i = 0; i < length_; i++){
		newString.string_[i] = string_[i];
	}
	for (i; i <= newString.length_; i++){
		newString.string_[i] = string.string_[i - length_];
	}
	return newString;
}

ostream &operator<<(ostream& out, const String& string){
	if (string.length_ > 0){
		out << string.string_;
	}
	out << endl;
	return out;
}

//istream &operator>>(istream& in, string& string){
//	cout << "enter " << string.length_ << " characters):" << endl;
//	in >> string.string_;
//	for (string.length_ = 0; string.string_[string.length_] != 0; string.length_++)
//		;
//	return in;
//}

int String::find(char ch){
	int n = 0;
	for (int i = 0; i < length_; i++){
		if (string_[i] == ch){
			n = i + 1;
			break;
		}
	}
	return n;
}
int String::find(String& string){
	int n = 0;
	bool findBool = false;
	for (int i = 0; i < length_ - string.length_ + 1; i++){
		if (string_[i] == string.string_[0]){
			for (int u = 1; u < string.length_; u++){
				if (string_[i + u] != string.string_[u]){
					findBool = true;
					break;
				}
			}
			if (!findBool){
				n = i + 1;
				break;
			}
			findBool = false;
		}
	}
	return n;
}
int String::getLength(){
	return length_;
}

String::String(int length){
	length_ = length;
	try{
		string_ = new char[length_ + 1];
		if (string_ == 0){
			throw "Error. Memory not allocated";
		}
	}
	catch (char* err){
		cout << err << endl;
		system("pause");
		exit(1);
	}
}