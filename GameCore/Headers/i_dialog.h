#ifndef I_DIALOG_H
#define I_DIALOG_H

#include "i_subject.h"

class I_Dialog : public I_Subject{
public:
    virtual std::string GetPlayerLog() = 0;
    virtual std::string GetPhaseLog() = 0;
};

#endif // I_DIALOG_H
