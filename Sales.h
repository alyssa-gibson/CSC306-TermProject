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
    virtual double getCommission() override;
    bool operator<(const Sales&);
    virtual ~Sales();
protected:
    double commission;
};

#endif /* SALES_H */

