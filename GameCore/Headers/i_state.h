#ifndef I_STATE_H
#define I_STATE_H

class C_GameController;

class I_State {
public:
    void Initialize(C_GameController *pOwner) {
        if (pOwner != nullptr) {
            m_pOwner = pOwner;
        }
    }
    virtual void Start() = 0;
    virtual void Enter() = 0;
    virtual void Exit() = 0;

    C_GameController *m_pOwner;
};

#endif // I_STATE_H
