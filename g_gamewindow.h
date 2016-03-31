#ifndef G_GAMEWINDOW_H
#define G_GAMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class g_GameWindow;
}

class g_GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit g_GameWindow(QWidget *parent = 0);
    ~g_GameWindow();

private:
    Ui::g_GameWindow *ui;
};

#endif // G_GAMEWINDOW_H
