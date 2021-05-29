#include <cassert>
#include <cstring>
#include "stringRep.h"

StringRep::StringRep()
: str_(new char[1]), len_(0) {
    assert(str_ );
    str_[0] = '\0';
}

StringRep::StringRep(const char * str) 
: str_(new char[strlen(str) + 1]), len_(strlen(str)) {
    assert(str_);
    strcpy(str_, str);
}

StringRep::StringRep(const char * str, bool)
: str_(const_cast<char*>(str)), len_(strlen(str)) {

}


StringRep::~StringRep() {
    delete [] str_;
}