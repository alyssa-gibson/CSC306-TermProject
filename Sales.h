/* 
 * File:   Sales.h
 * Author: Alyssa Gibson
 *
 * Created on February 26, 2019, 3:24 PM
 */

#ifndef SALES_H
#define SALES_H

#include <string>

class Sales: public Employee {
public:
    Sales(std::string, std::string, std::string, std::string);
    double getCommission() override;
    virtual ~Sales();
    
private:
    double commission;
    
};

#endif /* SALES_H */

