#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

int fontcount=14;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    ui->textEdit->setFontPointSize(fontcount);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
   mfilename="";
   ui->textEdit->setText("");

}

void MainWindow::on_actionOpen_triggered()
{
    QString file= QFileDialog::getOpenFileName(this,"open File");
    if(!file.isEmpty()){

        QFile sfile(file);
        if(sfile.open(QFile::ReadOnly))
        {
            mfilename=file;
            QTextStream in(&sfile);
            QString text = in.readAll();
            sfile.close();
            ui->textEdit->setText(text);
        }
    }

}

void MainWindow::on_actionSave_triggered()
{
    QFile sfile(mfilename);
    if(sfile.open(QFile::WriteOnly))
    {
        QTextStream out(&sfile);
        out<<ui->textEdit->toHtml();
        sfile.flush();
        sfile.close();
    }

}
void MainWindow::on_actionSaveAs_triggered()
{
    QString file= QFileDialog::getSaveFileName(this,"Save File");
    if(!file.isEmpty())
    {
        mfilename=file;
        on_actionSave_triggered();
    }
}

void MainWindow::on_actionCopy_triggered()
{
 ui->textEdit->copy();
}
void MainWindow::on_actionPaste_triggered()
{
 ui->textEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
ui->textEdit->cut();
}


void MainWindow::on_actionUndo_triggered()
{
ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
ui->textEdit->redo();
}


void MainWindow::on_actionBold_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat format;
    if(!cursor.charFormat().font().bold())
    {
        ui->textEdit->setFontWeight( QFont::Bold);
        ui->actionnormal->setEnabled(true);
    }
    else
    {
         ui->textEdit->setFontWeight( QFont::Normal);
    }

}


void MainWindow::on_actionSuperscript_triggered()
{
    QTextCharFormat format;
       format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
       if(ui->textEdit->hasFocus()){
          ui->textEdit->mergeCurrentCharFormat(format);
          ui->actionnormal->setEnabled(true);
       }
}


void MainWindow::on_actionSubscript_triggered()
{
    QTextCharFormat format;
       format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
       if(ui->textEdit->hasFocus())
          ui->textEdit->mergeCurrentCharFormat(format);
       ui->actionnormal->setEnabled(true);
}


void MainWindow::on_actionnormal_triggered()
{
    QTextCharFormat format;
       format.setVerticalAlignment(QTextCharFormat::AlignNormal);
       if(ui->textEdit->hasFocus()){
          ui->textEdit->mergeCurrentCharFormat(format);
          ui->actionnormal->setEnabled(false);
       }

}


void MainWindow::on_actionZoom_out_triggered()
{
    fontcount--;
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->selectAll();
    ui->textEdit->setFontPointSize(fontcount);
 ui->textEdit->setTextCursor(cursor);
}


void MainWindow::on_actionZoom_in_triggered()
{
    fontcount++;
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->selectAll();
    ui->textEdit->setFontPointSize(fontcount);
 ui->textEdit->setTextCursor(cursor);
}


void MainWindow::on_actionAboutMe_2_triggered()
{
 secdialog = new Dialog(this);
 secdialog->show();
}

