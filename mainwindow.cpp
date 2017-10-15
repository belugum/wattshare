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
    ui->logo_1->hide();
    ui->logo_2->hide();
    ui->square_1->hide();
    ui->square_2->hide();
    this->my_info = nullptr;
    this->other_info = nullptr;
    /* init classe reception de données */
    QTimer::singleShot(200, this, SLOT(refresh_data()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->my_info;
    if (this->other_info)
        delete this->other_info;
}

void MainWindow::refresh_data()
{
    if (!this->my_info)
        this->my_info = new carInfo("ZoeGrise");
    ui->soc->setText("" + QString::number(this->my_info->getSoc()) + "%");
    ui->est_time->setText(""+ QString::number(this->my_info->getRemainingTime() / 60) + " h " + QString::number(this->my_info->getRemainingTime() % 60) + " min");
    if (this->other_info)
    {
        ui->soc_other->setText("" + QString::number(this->other_info->getSoc()) + "%");
        ui->est_time_other->setText(""+ QString::number(this->other_info->getRemainingTime() / 60) + " h " + QString::number(this->other_info->getRemainingTime() % 60) + " min");
    }
    /*set texte
     * if (this->found)
     * set texte other
     */
}

void MainWindow::on_search_button_clicked()
{
    ui->search_button->setText("Recherche...");
    ui->search_button->repaint();
    this->other_info = new carInfo("ZoeBleue");
    ui->search_button->hide();
    ui->vehi_found->show();
    ui->est_time_other->show();
    ui->identify->show();
    ui->notify->show();
    ui->soc_other->show();
    ui->logo_1->show();
    ui->logo_2->show();
    ui->square_1->show();
    ui->square_2->show();
    this->refresh_data();
}
