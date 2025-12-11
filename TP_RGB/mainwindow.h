#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_SLD_RD_valueChanged(int value);

    void on_SLD_GN_valueChanged(int value);

    void on_SLD_BL_valueChanged(int value);

    void on_SPB_BL_valueChanged(int arg1);

    void on_SPB_GN_valueChanged(int arg1);

    void on_SPB_RD_valueChanged(int arg1);

    void RGBAdjust();
    void Init();

    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int numeroc;

};
#endif // MAINWINDOW_H
