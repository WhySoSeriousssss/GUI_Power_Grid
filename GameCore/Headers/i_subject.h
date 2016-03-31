#ifndef I_SUBJECT_H
#define I_SUBJECT_H

#include "i_observer.h"

#include "base.h"

class I_Subject {
public:
    I_Subject() {

    }

    ~I_Subject() {

    }

    void Attach(I_Observer* observer) {
        _observers.push_back(observer);

    }

    void Detach(I_Observer* observer) {
        _observers.remove(observer);
    }

    void Notify() {
        for (auto i = _observers.begin(); i != _observers.end(); i++) {
            (*i)->Update();
        }
    }

private:
    list<I_Observer*> _observers;
};

#endif // I_SUBJECT_H
