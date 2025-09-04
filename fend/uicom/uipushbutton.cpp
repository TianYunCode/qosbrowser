#pragma execution_character_set("utf-8")

#include "UiPushButton.h"

UiPushButton::UiPushButton(QWidget* parent): QPushButton(parent)
{

}

void UiPushButton::enterEvent(QEvent *event)
{
    setCursor(Qt::PointingHandCursor);
}

void UiPushButton::leaveEvent(QEvent *event)
{
    setCursor(Qt::ArrowCursor);
}
