#include <cstring>

inline std::ostream& operator<<(std::ostream& out, const String& rhs) {
	return out << rhs.str;
}

inline String::String(const char* str) {
	this->set_str(str);
}

inline String::String(const String& rhs) {
	this->set_str(rhs.str);
}

inline String::~String() {
	delete [] this->str;
}

inline bool String::operator==(const String& rhs) const{
	return strcmp(this->str, rhs.str) == 0;
}

inline const char* String::c_str() const{
	return this->str;
}

inline int String::length() const{
	return this->len;
}