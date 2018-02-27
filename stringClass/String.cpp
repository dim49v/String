#include "String.h"
#include "Header.h"
#include <iostream>
using namespace std;

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
	for (int i = 0; i  <=length_; i++){
		string_[i] = string[i];
	} 
}
String::String(char ch, int length){
	if (length > 0){
		length_ = length;
	}
	else{
		throw ArrLengthError("Error. Length must be >0", 1, MAX_LEGTH);
	}
	maxLengthTest(length_);
	string_ = new char[length_ + 1];
	for (int i = 0; i < length_; i++){
		string_[i] = ch;
	}
	string_[length_] = 0;
}

String::~String()
{
	delete[] string_;
}

bool String::operator<(const String& string) const{
	return (compare(string)==-1);
}
bool String::operator<=(const String& string) const{
	return (compare(string) == -1) || (compare(string) == 0);
}
bool String::operator==(const String& string) const{
	return (compare(string) == 0);
}
bool String::operator>=(const String& string) const{
	return (compare(string) == 1) || (compare(string) == 0);
}
bool String::operator>(const String& string) const{
	return (compare(string) == 1);
}

String String::operator=(const String& string){
	if (!isEqualString(string)){
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
	maxLengthTest(length_);
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


int String::find(char ch) const{
	int n = -1;
	for (int i = 0; (i < length_) && (n==-1); i++){
		if (string_[i] == ch){
			n = i;
		}
	}
	return n;
}
int String::find(const String& string) const{
	int n = -1;
	bool findBool = false;
	if (length_ >= string.length_){
		for (int i = 0; (i < length_ - string.length_ + 1) && (n==-1); i++){
			if (string_[i] == string.string_[0]){
				for (int u = 1; (u < string.length_) && (!findBool); u++){
					if (string_[i + u] != string.string_[u]){
						findBool = true;
					}
				}
				if (!findBool){
					n = i;
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
	if (index < 0){
		throw IndexError("Error. Index must be >=0", 0, length_);
	}
	if (index > length_){
		throw IndexError("Error. Index must be >=0", 0, length_);
	}
	return string_[index];
}

void String::swap(String& string){
	if (isEqualString(string)){
		SameObjectError("Swap one and the same object");
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

int String::getMaxLength(){
	return MAX_LEGTH;
}

String::String(int length){
	length_ = length;
	string_ = new char[length_ + 1];
}

bool String::isEqualString(const String& string) const{
	return(this == &string);
}
void String::maxLengthTest(int length) const{
	if (length > MAX_LEGTH){
		throw ArrLengthError("Error. String length must be <=1000", 1, MAX_LEGTH);
	}
}
int String::compare(const String& string) const{
	int temp;
	int minLength;
	temp = 0;
	if (!isEqualString(string)){
		(length_ < string.length_) ? minLength = length_ : minLength = string.length_;
		int i = 0;
		while ((string_[i] == string.string_[i]) && (i < minLength))
			i++;
		if (i < minLength){
			if (string_[i] < string.string_[i])
				temp = -1;
			else
				temp = 1;
		}
		else{
			if (length_ < string.length_)
				temp = -1;
			if (length_ > string.length_)
				temp = 1;
			if (length_ == string.length_)
				temp = 1;
		}
	}
	return temp;
}

void *operator new[](size_t size){
	void *p = malloc(size);
	if (p == 0){
		throw MemoryError("Error. Memory not allocated");
	}
	return p;
}
void operator delete[](void *p){
	if (p!=0)
		free(p);
}
