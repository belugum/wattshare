#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "carInfo.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    carInfo         *my_info;
    carInfo         *other_info;

public slots:
    void on_search_button_clicked();
    //void on_identify_clicked();
    void refresh_data();
};

#endif // MAINWINDOW_H
