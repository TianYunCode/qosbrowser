#pragma execution_character_set("utf-8")

#include "UiToolBarWidget.h"
#include "config/Common.h"
#include "ui_UiToolBarWidget.h"

#include <QFileDialog>
#include <QSignalMapper>
#include <QJsonObject>
#include <QInputDialog>

UiToolBarWidget::UiToolBarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UiToolBarWidget)
{
    ui->setupUi(this);
}

UiToolBarWidget::~UiToolBarWidget()
{
    delete ui;
}

void UiToolBarWidget::on_btnQuit_clicked()
{
    emit MG->mSignal->unLogin();
}

