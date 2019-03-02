/* 
 * File:   Sales.h
 * Author: Alyssa Gibson
 *
 * Created on February 26, 2019, 3:24 PM
 */

#ifndef SALES_H
#define SALES_H
#include "Employee.h"
#include <string>

class Sales:public Employee {
public:
    Sales();
    Sales(const Sales& orig);
    Sales(std::string, std::string, std::string, std::string);
    std::string toString() override;
    virtual double getCommission() override;
    virtual double getSales() override;
    virtual void setCommission(double) override;
    virtual void setSales(double) override;
    bool operator<(const Sales&);
    virtual ~Sales();
protected:
    double grossSales, commission;
};

#endif /* SALES_H */

