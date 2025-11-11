#ifndef STANDARDRECEIPT_H
#define STANDARDRECEIPT_H
#include "IReceipt.h"
#include <iomanip>
#include <iostream>
#include <ctime>
#include <sstream>

class StandardReceipt : public IReceipt {
    private:
    public:
    std::string printReceipt(int minutes) override;
};

#endif