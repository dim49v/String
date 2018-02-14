#include "String.h"
#include <iostream>
using namespace std;
int const MAX_LEGTH = 1000;

String::String()
{
	length_ = 0;
	string_ = new char[length_ + 1]{0};
}
String::String(const String& string){
 	length_ = string.length_;
	string_ = new char[length_ + 1];
	for (int i = 0; i <= length_; i++){
		string_[i] = string.string_[i];
	}
}
String::String(const char* string){
	for (length_ = 0; string[length_] != 0; length_++)
		;
	maxLengthTest(length_);
	string_ = new char[length_ + 1];
	for (int i = 0; i < length_; i++){
		string_[i] = string[i];
	}
	string_[length_] = 0;
}
String::String(char ch, int length){
	
	try{
		if (length > 0){
			length_ = length;
		}
		else{
			throw "Error. Length must be >0";
		}
		maxLengthTest(length_);
		string_ = new char[length_ + 1];
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

bool String::operator<(const String& string) const{
	bool bl = false;
	int minLength;
	if (!equalString(string)){
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
	}
	return bl;
}
bool String::operator<=(const String& string) const{
	int minLength;
	bool bl = false;
	if (!equalString(string)){
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
	}
	else{
		bl = true;
	}
	return bl;
}
bool String::operator==(const String& string) const{
	bool equal = true;
	if (!equalString(string)){
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
	}
	return equal;
}
bool String::operator>=(const String& string) const{
	int minLength;
	bool bl = false;
	if (!equalString(string)){
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
	}
	return bl;
}
bool String::operator>(const String& string) const{
	int minLength;
	bool bl = false;
	if (!equalString(string)){
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
	}
	return bl;
}

String String::operator=(const String& string){
	if (!equalString(string)){
		char* stringChar = new char[string.length_ + 1];
		length_ = string.length_;
		for (int i = 0; i <= length_; i++){
			stringChar[i] = string.string_[i];
		}
		delete[] string_;
		string_ = stringChar;
	}
	return *this;
}
String String::operator+(const String& string) const{
	int newLength = length_ + string.length_;
	maxLengthTest(newLength);
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

void *String::operator new[](size_t size){
	void *p = malloc(size);
	if (p == 0){
		cout << "Error. Memory not allocated" << endl;
		system("pause");
		exit(1);
	}
	return p;
}

int String::find(char ch) const{
	int n = -1;
	for (int i = 0; i < length_; i++){
		if (string_[i] == ch){
			n = i;
			break;
		}
	}
	return n;
}
int String::find(const String& string) const{
	int n = -1;
	bool findBool = false;
	if (length_ >= string.length_){
		for (int i = 0; i < length_ - string.length_ + 1; i++){
			if (string_[i] == string.string_[0]){
				for (int u = 1; u < string.length_; u++){
					if (string_[i + u] != string.string_[u]){
						findBool = true;
						break;
					}
				}
				if (!findBool){
					n = i;
					break;
				}
				findBool = false;
			}
		}
	}
	return n;
}

int String::getLength() const{
	return length_;
}

char String::at(int index) const{
	try{
		if (index < 0){
			throw "Error. Index must be >=0";
		}
		if (index>length_){
			throw "Error. Index must be < length-1";
		}
	}
	catch (char* err){
		cout << err << endl;
		system("pause");
		exit(1);
	}
	return string_[index];
}

void String::swap(String& string){
	if (equalString(string)){
		cout << "Swap one and the same object" << endl;
	}
	else{
		char* ch;
		int length;
		length = length_;
		length_ = string.length_;
		string.length_ = length;
		ch = string_;
		string_ = string.string_;
		string.string_ = ch;
	}
}

void String::reverse(){
	char ch;
	for (int i = 0; i < length_ / 2; i++){
		ch = string_[i];
		string_[i] = string_[length_ - i - 1];
		string_[length_ - i - 1] = ch;
	}
}


String::String(int length){
	length_ = length;
	string_ = new char[length_ + 1];
}

bool String::equalString(const String& string) const{
	return(string_ == string.string_);
}
void String::maxLengthTest(int length) const{
	if (length > MAX_LEGTH){
		cout << "Error. String length must be <=1000" << endl;
		system("pause");
		exit(1);
	}
}