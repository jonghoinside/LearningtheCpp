#include "invalidIndex.h"

InvalidIndex::InvalidIndex(int index)
: index_(index) {

}

int InvalidIndex::invalid() const {
    return index_;
}

// int InvalidIndex::invalid() const {
//     return index_;
// }