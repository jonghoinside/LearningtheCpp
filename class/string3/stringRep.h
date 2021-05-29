#ifndef STRINGREP_H
#define STRINGREP_H

class StringRep {
friend class String;
private:
    char *str_;
    int len_;
    int rc_;
    
    StringRep();
    StringRep(const char * str);
    StringRep(const char * str, bool);
    ~StringRep();

    // not use..
    StringRep(const StringRep& rhs);
    StringRep& operator=(const StringRep& rhs);

public:

};

#endif