#include <cstring>
#include <cassert>
#include "string.h"

#ifndef INLINE
#define inline
#include "string.inl"
#endif

void String::set_str(const char *str) {
	if (str ) {
		this->str = new char[strlen(str) + 1];
		assert(this->str );
		strcpy(this->str, str);
		this->len = strlen(str);
	} else {
		this->str = new char[1];
		assert(this->str );
		this->str[0] = '\0';
		this->len = 0;
	}
}

String::String(const char *str, bool) {
	this->str = (char *)str;
	this->len = strlen(str);
}

String& String::operator=(const String& rhs) {
	if (this != &rhs) {				// self assignment test.
		delete [] this->str;
		this->set_str(rhs.str);
	}
	return *this;
}

String& String::operator=(const char* str) {
	if (this->str != str) {				// self assignment test.
		delete [] this->str;
		this->set_str(str);
	}
	return *this;
}


/*
const String String::operator+(const String& rhs) {
	char* tmp = new char[strlen(this->str) + strlen(rhs.str) + 1];
	assert(tmp );
	strcpy(tmp, this->str);
	strcat(tmp, rhs.str);
	
	String result(tmp);
	delete [] tmp;
	
	return result;
}
*/

const String String::operator+(const String& rhs) const{
	char* tmp = new char[strlen(this->str) + strlen(rhs.str) + 1];
	assert(tmp );
	strcpy(tmp, this->str);
	strcat(tmp, rhs.str);
	
	String result(tmp, true);
	
	return result;
}