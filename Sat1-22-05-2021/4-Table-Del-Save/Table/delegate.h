#ifndef DELEGATE_H
#define DELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QSize>
#include <QSpinBox>

class Delegate : public QItemDelegate
{
    Q_OBJECT

    public:
        explicit Delegate(QObject *parent = nullptr);

        QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

        void setEditorData(QWidget *editor, const QModelIndex &index) const;

        void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

        void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
#endif // DELEGATE_H
