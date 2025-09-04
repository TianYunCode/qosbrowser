#pragma execution_character_set("utf-8")

#include "UiTransfer.h"
#include "config/Common.h"
#include "ui_UiTransfer.h"

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
