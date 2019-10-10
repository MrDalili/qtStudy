#include "mouseevent.h"

MouseEvent::MouseEvent(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant MouseEvent::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex MouseEvent::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex MouseEvent::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int MouseEvent::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int MouseEvent::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant MouseEvent::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
