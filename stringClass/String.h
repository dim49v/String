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
	
	bool operator<(const String& string) const;
	bool operator<=(const String& string) const;
	bool operator==(const String& string) const;
	bool operator>=(const String& string) const;
	bool operator>(const String& string) const;
	String operator=(const String& string);
	String operator+(const String& string) const;

	friend ostream &operator<<(ostream& out, const String& string);
	
	int find(char ch) const;					//position first character(-1 if don't finded)
	int find(const String& string) const;		//position first string(-1 if don't finded)
	int getLength() const;
	char at(int index) const;
	void swap(String& string);
	void reverse();
	int getMaxLength();

private:
	String(int length);
	bool isEqualString(const String& string) const;
	void maxLengthTest(int lenght) const;
	int compare(const String& strng) const;
	char* string_;
	int length_;

	static int const MAX_LEGTH = 1000;
};