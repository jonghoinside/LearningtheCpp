#ifndef INVALID_INDEX_H
#define INVALID_INDEX_H

class InvalidIndex {
private:
    int index_;

public:
    InvalidIndex(int index);

    int invalid() const;
};

#endif