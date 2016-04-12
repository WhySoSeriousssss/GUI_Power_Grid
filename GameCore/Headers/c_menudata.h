#ifndef C_MENUDATA_H
#define C_MENUDATA_H

enum MENU_OPTION {
    MENU_NEW_GAME,
    MENU_LOAD_GAME,
    MENU_NONE
};

class C_MenuData {
public:
    C_MenuData();
    ~C_MenuData();

    void SetChoice(MENU_OPTION option);

    MENU_OPTION GetOption();

private:
    MENU_OPTION option;
};

#endif // C_MENUDATA_H
