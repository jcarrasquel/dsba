#ifndef MYPROXYMODEL_H
#define MYPROXYMODEL_H
#include <QSortFilterProxyModel>

class MyProxyModel : public QSortFilterProxyModel
{
    public:
        MyProxyModel(QObject* parent = 0);

        //getters
        int filterMinPopulation() const { return minPopulation; }
        int filterMaxPopulation() const { return maxPopulation; }

        QString filterCountry() const { return country; }

        //setters
        void setFilterMinPopulation(int min);
        void setFilterMaxPopulation(int max);

        void setFilterCountry(QString country);

    // override the function that makes the filtering --
    protected:

        bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override;

        bool lessThan(const QModelIndex& left, const QModelIndex& right) const override;

    private:

        int minPopulation;

        int maxPopulation;

        QString country;

};

#endif // MYPROXYMODEL_H
