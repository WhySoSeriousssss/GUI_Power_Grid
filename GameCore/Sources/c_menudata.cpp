#include "c_menudata.h"

C_MenuData::C_MenuData() {
    option = MENU_NONE;
}

C_MenuData::~C_MenuData() {

}

MENU_OPTION C_MenuData::GetOption() {
    return this->option;
}

void C_MenuData::SetChoice(MENU_OPTION option) {
    this->option = option;
}
