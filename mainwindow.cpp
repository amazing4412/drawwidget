#include "mainwindow.h"
#include <QToolBar>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    draw = new drawwidget;
    setCentralWidget(draw);
    createToolBar();
    setMinimumSize(600,400);
    ShowStyle();
    draw->setWidth(widthSpinBox->value());
    draw->setColor(Qt::black);

}

MainWindow::~MainWindow()
{

}

void MainWindow::createToolBar()
{
    QToolBar *toolBar = addToolBar("Tool");
    styleLabel = new QLabel(tr("线性风格"));
    styleCommboBox = new QComboBox;
    styleCommboBox->addItem(tr("SolidLine"),static_cast <int> (Qt::SolidLine));

    styleCommboBox->addItem(tr("DashLine"),static_cast <int> (Qt::DashLine));

    styleCommboBox->addItem(tr("DotLine"),static_cast <int> (Qt::DotLine));

    styleCommboBox->addItem(tr("DashDotLine"),static_cast <int> (Qt::DashDotLine));

    styleCommboBox->addItem(tr("DashDotDotLine"),static_cast <int> (Qt::DashDotDotLine));

    connect(styleCommboBox,SIGNAL(activated(int)),this,SLOT(ShowStyle()));

    widthLabel = new QLabel(tr("线宽"));
    widthSpinBox = new QSpinBox;
    connect(widthSpinBox,SIGNAL(valueChanged(int)),draw,SLOT(setWidth(int)));

    colorBtn = new QToolButton;
    QPixmap pixmap(20,20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(ShowColor()));

    clearBtn = new QToolButton();
    clearBtn->setText(tr("清除"));
    connect(clearBtn,SIGNAL(clicked()),draw,SLOT(clear()));

    toolBar->addWidget(styleLabel);
    toolBar->addWidget(styleCommboBox);
    toolBar->addWidget(widthLabel);
    toolBar->addWidget(widthSpinBox);
    toolBar->addWidget(colorBtn);
    toolBar->addWidget(clearBtn);
    

}

void MainWindow::ShowStyle()
{
 draw->setStyle(styleCommboBox->itemData(styleCommboBox->currentIndex(),Qt::UserRole).toInt());
}

void MainWindow::ShowColor()
{
    QColor color = QColorDialog::getColor(static_cast <int> (Qt::black),this);

    if(color.isValid())
    {
        draw->setColor(color);
        QPixmap p(20,20);
        p.fill(color);
        colorBtn->setIcon(QIcon(p));
    }

}
