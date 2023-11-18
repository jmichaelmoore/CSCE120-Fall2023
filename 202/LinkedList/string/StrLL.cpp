#include <iostream>
#include "StrLL.h"
#include "Node.h"

void StrLL::printReverse(std::ostream& os) {
    Node* cur = tail;
    while (cur != nullptr) {
        os << cur->letter;
        cur = cur->prev;
    }
}