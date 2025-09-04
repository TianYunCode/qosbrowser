#pragma execution_character_set("utf-8")

#include "UiQosDialog.h"
#include "config/Common.h"
#include "ui_UiQosDialog.h"
#include "ui_UiBaseDialog.h"

UiQosDialog::UiQosDialog(QWidget *parent) :
    UiBaseDialog(parent),
    ui(new Ui::UiQosDialog)
{
    ui->setupUi(body());
    setLogo(GLOBAL::PATH::LOGO_PATH);
    setTitle(STR("Qos"));
    m_ui->labelLogo->setFixedSize(32, 24);
    m_ui->labelTitle->setProperty("style_font", "h4");
    resize(400, 50);
}

UiQosDialog::~UiQosDialog()
{
    delete ui;
}
