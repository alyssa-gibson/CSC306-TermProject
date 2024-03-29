/* 
 * File:   SuperSales.h
 * Author: Alyssa Gibson
 *
 * Created on February 26, 2019, 3:25 PM
 */

#ifndef SUPERSALES_H
#define SUPERSALES_H
#include "Sales.h"
#include <string>

class SuperSales:public Sales {
public:
    SuperSales();
    SuperSales(const SuperSales& orig);
    SuperSales(std::string, std::string, std::string, std::string);
    std::string toString() override;
    virtual double getCommission() override;
    virtual double getSales() override;
    virtual void setCommission(double) override;
    virtual void setSales(double) override;
    virtual ~SuperSales();
};

#endif /* SUPERSALES_H */



