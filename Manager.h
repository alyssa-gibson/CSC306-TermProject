/* 
 * File:   Manager.h
 * Author: Alyssa Gibson
 *
 * Created on February 26, 2019, 3:25 PM
 */

#ifndef MANAGER_H
#define MANAGER_H

#include <string>

class Manager: public SuperSales {
public:
    Manager(std::string, std::string, std::string, std::string);
    double getCommission() override;
    virtual ~Manager();
private:
    double commission;
  
};

#endif /* MANAGER_H */

