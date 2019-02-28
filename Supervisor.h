/* 
 * File:   Supervisor.h
 * Author: Alyssa Gibson
 *
 * Created on February 26, 2019, 3:33 PM
 */

#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include <string>

class Supervisor: public Manager {
public:
    Supervisor(std::string, std::string, std::string, std::string);
    double getCommission() override;
    virtual ~Supervisor();
    
private:
    double commission;
    
};

#endif /* SUPERVISOR_H */

