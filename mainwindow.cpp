#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    text1 = new QTextEdit;
    QFont f;
    f.setPixelSize(30);
    text1->setFont(f); // 设置text1字体的大小为30
//    QColor c;
//    c.setRgb(255, 0, 0);
//    text1->setTextColor(c); // 设置颜色为红色
    this->setCentralWidget(text1); // 将这个TextEdit放到对话框的中间

    file = this->menuBar()->addMenu("文件"); // 在菜单栏加入一个菜单项
    edit = this->menuBar()->addMenu("编辑"); // 在菜单栏加入一个编辑项
    help = this->menuBar()->addMenu("帮助"); // 在菜单栏加入一个帮助项

    fileOpen = new QAction("打开", this); // 建立一个Action
    fileOpen->setShortcut(tr("Ctrl+O")); // 将open菜单的快捷方式设置为ctrl+O
    file->addAction(fileOpen); // 将fileOpen这个Action加入到file菜单下面
    fileExit = new QAction("退出", this);
    file->addSeparator(); // 加入一个分割符
    file->addAction(fileExit); // 将fileExit这个Action加入到file菜单下面

    helpAbout = new QAction("关于", this);
    help->addAction(helpAbout);
    helpAbout->setShortcut(tr("Ctrl+H"));

    editCopy = new QAction("拷贝", this);
    edit->addAction(editCopy);

    editPaste = new QAction("粘贴", this);
    edit->addAction(editPaste);

    editCut = new QAction("剪切", this);
    edit->addAction(editCut);

    editSelectAll = new QAction("全选", this);
    edit->addAction(editSelectAll);

    // QT的消息槽机制
    connect(fileOpen, SIGNAL(triggered(bool)), this, SLOT(onOpen()));
    // 第一个参数是触发这个事件控件，第二个参数是对于ACTION来讲，固定写SIGNAL(triggered())
    // 第三个参数固定写this
    // 第四个参数指定点击Action后会执行哪个函数

    connect(helpAbout, SIGNAL(triggered(bool)), this, SLOT(onAbout()));
    connect(fileExit, SIGNAL(triggered(bool)), this, SLOT(onExit()));
    connect(editCopy, SIGNAL(triggered(bool)), this, SLOT(onCopy()));
    connect(editPaste, SIGNAL(triggered(bool)), this, SLOT(onPaste()));
    connect(editCut, SIGNAL(triggered(bool)), this, SLOT(onCut()));
    connect(editSelectAll, SIGNAL(triggered(bool)), this, SLOT(onSelectAll()));


}

MainWindow::~MainWindow()
{
    delete text1;
}

void MainWindow::onOpen()
{
    QMessageBox::information(this, "提示", "测试");
}

void MainWindow::onAbout()
{
    QMessageBox::information(this, "关于", "张耀琦：版权所有\n2015-2020");
}

void MainWindow::onExit()
{
    exit(0);
}

void MainWindow::onCopy()
{
    text1->copy();
}

void MainWindow::onPaste()
{
    text1->paste();
}

void MainWindow::onCut()
{
    text1->cut();
}

void MainWindow::onSelectAll()
{
    text1->selectAll();
}
