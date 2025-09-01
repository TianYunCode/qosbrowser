#pragma once

#include <QLineEdit>

class UiLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    UiLineEdit(QWidget* parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event);
};
