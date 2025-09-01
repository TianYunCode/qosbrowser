#pragma execution_character_set("utf-8")

#include "uitransfer.h"
#include "config/common.h"
#include "ui_uitransfer.h"

UiTransfer::UiTransfer(QWidget *parent) :
    UiQosDialog(parent),
    ui(new Ui::UiTransfer)
{
    ui->setupUi(body());
    setTitle(STR("传输列表"));
    setFixedSize(600, 450);
}

UiTransfer::~UiTransfer()
{
    delete ui;
}
