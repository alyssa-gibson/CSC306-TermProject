/* 
 * File:   Manager.h
 * Author: Alyssa Gibson
 *
 * Created on February 26, 2019, 3:25 PM
 */

#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include "SuperSales.h"
class Manager:public SuperSales {
public:
    Manager();
    Manager(const Manager& orig);
    Manager(std::string, std::string, std::string, std::string);
    virtual std::string toString() override;
    virtual double getCommission() override;
    virtual double getSales() override;
    virtual void setCommission(double) override;
    virtual void setSales(double) override;
    virtual ~Manager();
};

#endif /* MANAGER_H */


