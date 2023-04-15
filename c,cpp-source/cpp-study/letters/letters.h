#pragma once

class letters{
private:
	char* mStr;
	unsigned long long mSize;	
public:
	
	letters operator+(const letters& letters);		
	letters operator-(const letters& letters);		
	letters operator==(const letters& letters);		
	letters operator=(const letters& letters);
	letters() : mStr(nullptr), mSize(0){};
	letters(char* str) : mStr(str), mSize(0){};
	unsigned long long size() const;
	char* getstr() const;
};

