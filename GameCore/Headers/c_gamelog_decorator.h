#ifndef C_GAMELOG_DECORATOR_H
#define C_GAMELOG_DECORATOR_H

#include "c_gamelog.h"
#include <iostream>

class C_GameLog_Decorator : public C_GameLog {
protected:
    C_GameLog* gamelog;
public:
    C_GameLog_Decorator() {

    }

    ~C_GameLog_Decorator() {

    }

    std::string GetLog() {
        return gamelog->GetLog();
    }

};

#endif // C_GAMELOG_DECORATOR_H
