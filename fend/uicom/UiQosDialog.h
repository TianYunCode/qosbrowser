#pragma once

#include "UiBaseDialog.h"

namespace Ui {
class UiQosDialog;
}

class UiQosDialog : public UiBaseDialog
{
    Q_OBJECT

public:
    explicit UiQosDialog(QWidget *parent = nullptr);
    ~UiQosDialog();

private:
    Ui::UiQosDialog *ui;
};
