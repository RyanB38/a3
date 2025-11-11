#ifndef IRECEIPT_H
#define IRECEIPT_H
#include <string>
class IReceipt {
    public:
    virtual std::string printReceipt(int minutes) = 0;
};
#endif