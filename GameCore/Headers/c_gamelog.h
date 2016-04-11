#ifndef C_GAMELOG_H
#define C_GAMELOG_H

#include "i_observer.h"
#include <iostream>

class C_GameLog : public I_Observer {
public:
    C_GameLog() {

    }

    ~C_GameLog() {

    }

    std::string GetLog() {
        return "GameTime:xxxx\n";
    }

};

#endif // C_GAMELOG_H
