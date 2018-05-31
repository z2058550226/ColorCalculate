#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置只允许输入数字
    QRegExp regx("[0-9]+$");
    QValidator *validatorBlue = new QRegExpValidator(regx, ui->et_blue);
    ui->et_blue->setValidator(validatorBlue);
    QValidator *validatorGreen = new QRegExpValidator(regx, ui->et_green);
    ui->et_green->setValidator(validatorGreen);
    QValidator *validatorRed = new QRegExpValidator(regx, ui->et_red);
    ui->et_red->setValidator(validatorRed);
    ui->ivColor->setAutoFillBackground(true);
    invalidateIvBackGround();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::invalidateIvBackGround(){
    QPalette pal(ui->ivColor->palette());
    QColor color;
    color.setRgb(this->redValue,this->greenValue,this->blueValue);
    pal.setColor(QPalette::Background,color);
    ui->ivColor->setPalette(pal);
}

void MainWindow::on_btnCopy_clicked()
{
    QColor color;
    color.setRgb(this->redValue,this->greenValue,this->blueValue);
    QString colorStr = color.name();
    QClipboard *clipboard = QApplication::clipboard();   //获取系统剪贴板指针
    clipboard->setText(colorStr);                  //设置剪贴板内容
    if(ui->cbIsMessage->isChecked()){
        QMessageBox box;
        QIcon icon(":/icon/hiiragitsukasa.png");
        box.setWindowIcon(icon);
        //处理中文和日文乱码要使用QString::fromLocal8Bit()方法来包裹其他语言的字符串
        box.setWindowTitle(QString::fromLocal8Bit("良かったです"));
        box.setText(colorStr+QString::fromLocal8Bit("已复制到剪切板。"));
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
    }
}

void MainWindow::on_et_red_textChanged(const QString &arg1)
{
    if(arg1.length()==0){
        this->redValue =255;
    }else{
        this->redValue = arg1.toInt();
        if(this->redValue>255){
            this->redValue=255;
            ui->et_red->setText("255");
        }else if (this->redValue<0) {
            this->redValue=0;
        }
    }
    invalidateIvBackGround();
}

void MainWindow::on_et_green_textChanged(const QString &arg1)
{
    if(arg1.length()==0){
        this->greenValue =255;
    }else{
        this->greenValue = arg1.toInt();
        if(this->greenValue>255){
            this->greenValue=255;
            ui->et_green->setText("255");
        }else if (this->greenValue<0) {
            this->greenValue=0;
        }
    }
    invalidateIvBackGround();
}

void MainWindow::on_et_blue_textChanged(const QString &arg1)
{
    if(arg1.length()==0){
        this->blueValue =255;
    }else{
        this->blueValue = arg1.toInt();
        if(this->blueValue>255){
            this->blueValue=255;
            ui->et_blue->setText("255");
        }else if (this->blueValue<0) {
            this->blueValue=0;
        }
    }
    invalidateIvBackGround();
}

void MainWindow::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Enter)
    {
        on_btnCopy_clicked();
    }
    if(event->key() == Qt::Key_Return)
    {
        on_btnCopy_clicked();
    }
}
