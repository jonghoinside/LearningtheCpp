#ifndef STRING_H
#define STRING_H
#include <iostream>
#include "stringRep.h"

class String {
friend std::ostream& operator<<(std::ostream& out, const String& rhs);
private:
	StringRep * rep_;
	
	String(const char* str, bool);
	
public:
	String();
	String(const char* str);
	String(const String& rhs);
	~String();
	
	String& operator=(const String& rhs);
//	String& operator=(const char* str);
	
	bool operator==(const String& rhs) const;
	const String operator+(const String& rhs) const;
	
	const char* c_str() const;
	int length() const;
};

#endif
