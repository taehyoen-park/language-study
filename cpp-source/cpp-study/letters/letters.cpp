#include"letters.h"

letters::letters(char* str)
{
	for(int i = 0; str[i] != '\0'; i++)
		mSize++;
}

unsigned long long letters::size() const
{
	return mStr;
}

char* letters::getstr() const
{
	return mStr;
}
