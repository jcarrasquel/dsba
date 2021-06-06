#include "myproxymodel.h"
#include <iostream>

MyProxyModel::MyProxyModel(QObject* parent)
    : QSortFilterProxyModel(parent)
{
    minPopulation = 0;
    maxPopulation = INT_MAX;
    country = QString();
}

bool MyProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, 4, sourceParent);

    int population = sourceModel()->data(index).toInt();

    QModelIndex index2 = sourceModel()->index(sourceRow, 3, sourceParent);

    QString rowCountry = sourceModel()->data(index2).toString();

    if(country.trimmed().isEmpty()) // if the user did not write a country
    {
        return (minPopulation <= population) && (population <= maxPopulation); // only filter by population
    }

    return (minPopulation <= population) && (population <= maxPopulation) && (rowCountry == country);

}

bool MyProxyModel::lessThan(const QModelIndex& left, const QModelIndex& right) const
{
    // returns "true" if element at the "left" goes first.

    int lenA = sourceModel()->data(left).toString().size();
    int lenB = sourceModel()->data(right).toString().size();

    return lenA < lenB;
}

void MyProxyModel::setFilterCountry(QString country)
{
    this->country = country.trimmed().isEmpty() ? QString() : country;
    invalidateFilter();
}

void MyProxyModel::setFilterMinPopulation(int min)
{
    minPopulation = min;
    invalidateFilter();
}

void MyProxyModel::setFilterMaxPopulation(int max)
{
    maxPopulation = max;
    invalidateFilter();
}
