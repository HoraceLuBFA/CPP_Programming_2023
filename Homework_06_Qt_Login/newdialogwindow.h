#ifndef NEWDIALOGWINDOW_H
#define NEWDIALOGWINDOW_H

#include <QDialog>

namespace Ui {
class NewDialogWindow;
}

class NewDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewDialogWindow(QWidget *parent = nullptr);
    ~NewDialogWindow();

private:
    Ui::NewDialogWindow *ui;
};

#endif // NEWDIALOGWINDOW_H
