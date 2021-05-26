#include <cstring>
#include <cassert>
#include "string.h"

std::ostream& operator<<(std::ostream& out, const String& rhs) {
	return out << rhs.str;
}

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
	this->str = const_cast<char *>(str);
	this->len = strlen(str);
}

String::String(const char* str) {
	this->set_str(str);
}

String::String(const String& rhs) {
	this->set_str(rhs.str);
}

String::~String() {
	delete [] this->str;
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

bool String::operator==(const String& rhs) const{
	return strcmp(this->str, rhs.str) == 0;
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

const char* String::c_str() const{
	return this->str;
}

int String::length() const{
	return this->len;
}
