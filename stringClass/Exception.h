#pragma once
#include <iostream>
using namespace std;

class Exception
{
public:
	Exception(const char* msg){
		cout << msg << endl;
	};
	~Exception(){};
};
class IndexError: public Exception
{
public:
	IndexError(const char* msg) :Exception(msg){};
	IndexError(const char* msg, int min, int max) :Exception(msg), min_(min), max_(max){};
	~IndexError(){};
	
	int min_, max_;
};
class ArrLengthError : public Exception
{
public:
	ArrLengthError(const char* msg) :Exception(msg){};
	ArrLengthError(const char* msg, int min, int max) :Exception(msg), min_(min), max_(max){};
	~ArrLengthError(){};

	int min_, max_;
};

class SameObjectError : public Exception
{
public:
	SameObjectError(const char* msg) :Exception(msg){};
	~SameObjectError(){};
};

class MemoryError : public Exception
{
public:
	MemoryError(const char* msg) :Exception(msg){};
	~MemoryError(){};
};

