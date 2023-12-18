#include "newdialogwindow.h"
#include "ui_newdialogwindow.h"

NewDialogWindow::NewDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialogWindow)
{
    ui->setupUi(this);
}

NewDialogWindow::~NewDialogWindow()
{
    delete ui;
}
