#pragma once
#include <iostream>
using namespace std;

class String
{
public:
	String();						//" "
	String(const String& string);	//copy
	String(const char* string);		//char array
	String(char ch, int length);	//"------"

	~String();
	
	bool operator<(const String& string);
	bool operator<=(const String& string);
	bool operator==(const String& string);
	bool operator>=(const String& string);
	bool operator>(const String& string);
	String operator=(const String& string);
	String operator+(const String& string);

	friend ostream &operator<<(ostream&, const String& string);
	friend istream &operator>>(istream&, String& string);

	int find(char ch);			//position first character(0 if don't finded)
	int find(String& string);		//position first string(0 if don't finded)
	int getLength();


private:
	String(int length);
	char* string_;
	int length_;
};

