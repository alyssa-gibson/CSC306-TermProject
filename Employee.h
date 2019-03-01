/* 
 * File:   Employee.h
 * Author: Alyssa Gibson
 *
 * Created on February 26, 2019, 2:51 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
    public:
        Employee();
        Employee(const Employee& orig);
        Employee(std::string, std::string, std::string, std::string);
        virtual double getCommission() = 0;
        std::string getTitle(); // returns the Employee's title
        std::string getName(); // returns the Employee's name
        std::string getSalesID(); // returns the Employee's sale ID
        std::string getBossID(); // returns the Employee's boss ID
        std::string toString();// returns all of the Employee's data
        virtual ~Employee();
    protected:
        std::string title;
        // Title: Whether this specific Employee is a:
        //        - Sales Employee
        //        - SuperSales Employee
        //        - Supervisor Employee
        //        - Manager Employee
        std::string name;
        // Name: The first and last name of the Employee.
        std::string salesPersonID;
        // Sales Person ID: The ID number of this specific individual.
        std::string bossID;
        // Boss ID: The ID number of the person who manages this specific
        //          individual, if applicable.    
};
#endif /* EMPLOYEE_H */

