#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->vehi_found->hide();
    ui->est_time_other->hide();
    ui->identify->hide();
    ui->notify->hide();
    ui->soc_other->hide();
    this->found = false;
    /* init classe reception de données */
    this->refresh_data();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh_data()
{
    /*set texte
     * if (this->found)
     * set texte other
     */
    return ;
}

void MainWindow::on_search_button_clicked()
{
    this->found = true;
    ui->search_button->hide();
    ui->vehi_found->show();
    ui->est_time_other->show();
    ui->identify->show();
    ui->notify->show();
    ui->soc_other->show();
}
