#ifndef NUMEROENTERODELEGATE_H
#define NUMEROENTERODELEGATE_H

#include <QItemDelegate>

class NumeroEnteroDelegate : public QItemDelegate
{
public:
    NumeroEnteroDelegate(QObject *parent = nullptr);
protected:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
    void setEditorData(QWidget *editor,
                       const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;
};

#endif // NUMEROENTERODELEGATE_H
