/* 
 * File:   SuperSales.h
 * Author: Alyssa Gibson
 *
 * Created on February 26, 2019, 3:25 PM
 */

#ifndef SUPERSALES_H
#define SUPERSALES_H

#include <string>

class SuperSales: public Sales {
public:
    SuperSales();
    double getCommission() override;
    virtual ~SuperSales();
    
private:
    double commission;
};

#endif /* SUPERSALES_H */

