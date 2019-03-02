/* 
 * File:   Supervisor.h
 * Author: Alyssa Gibson
 *
 * Created on February 26, 2019, 3:33 PM
 */

#ifndef SUPERVISOR_H
#define SUPERVISOR_H
#include "Manager.h"
#include <string>

class Supervisor:public Manager {
public:
    Supervisor();
    Supervisor(const Supervisor& orig);
    Supervisor(std::string, std::string, std::string, std::string);
    virtual std::string toString() override;
    virtual double getCommission() override;
    virtual double getSales() override;
    virtual void setCommission(double) override;
    virtual void setSales(double) override;
    virtual ~Supervisor();
};

#endif /* SUPERVISOR_H */



