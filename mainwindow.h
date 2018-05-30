#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QClipboard>
#include <QDebug>
#include <QColor>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnCopy_clicked();

    void on_et_red_textChanged(const QString &arg1);

    void on_et_green_textChanged(const QString &arg1);

    void on_et_blue_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    int redValue = 255;
    int greenValue = 255;
    int blueValue = 255;

    void invalidateIvBackGround();
};

#endif // MAINWINDOW_H
