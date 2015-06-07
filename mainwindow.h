#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit> // QT已经写好了一个控件
#include <QMenu>
#include <QMenuBar>
#include <QAction>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QString filename;
    QTextEdit *text1;
    QMenu *file;
    QMenu *edit;
    QMenu *build;
    QMenu *help;

    QAction *fileOpen;
    QAction *fileSave;
    QAction *fileExit;

    QAction *buildCompile;
    QAction *buildRun;
    QAction *helpAbout;

    QAction *editCopy;
    QAction *editPaste;
    QAction *editCut;
    QAction *editSelectAll;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onOpen();
    void onSave();
    void onAbout();
    void onExit();
    void onCopy();
    void onPaste();
    void onCut();
    void onSelectAll();
    void onCompile();
    void onRun();
};

#endif // MAINWINDOW_H
