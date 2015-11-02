#include "NumeroEnteroDelegate.h"
#include <QSpinBox>

NumeroEnteroDelegate::NumeroEnteroDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

QWidget *NumeroEnteroDelegate::createEditor(QWidget *parent,
                                            const QStyleOptionViewItem &,
                                            const QModelIndex &) const
{
    auto spinBox = new QSpinBox(parent);
    spinBox->setMaximum(INT_MAX);
    spinBox->setMinimum(-INT_MAX);
    return spinBox;
}

void NumeroEnteroDelegate::setEditorData(QWidget *editor,
                                         const QModelIndex &index) const
{
    auto spinBox = static_cast<QSpinBox *>(editor);
    spinBox->setValue(index.data().toInt());
}

void NumeroEnteroDelegate::setModelData(QWidget *editor,
                                        QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    auto spinBox = static_cast<QSpinBox *>(editor);
    model->setData(index, spinBox->value());
}

void NumeroEnteroDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &) const
{
    editor->setGeometry(option.rect);
}

