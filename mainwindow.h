#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include "dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSave_triggered();

    void on_actionCopy_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSaveAs_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionBold_triggered();

    void on_actionSuperscript_triggered();

    void on_actionSubscript_triggered();

    void on_actionnormal_triggered();

    void on_actionZoom_out_triggered();

    void on_actionZoom_in_triggered();

    void on_actionAboutMe_2_triggered();

private:
    Ui::MainWindow *ui;
    Dialog *secdialog;
    QString mfilename;
};
#endif // MAINWINDOW_H
