/* 
 * File:   OrderData.h
 * Author: Daniel Jirasek
 *
 * Header File for OrderData object
 * Created on January January 30, 2019
 */

#ifndef ORDERDATA_H
#define ORDERDATA_H
#include <string>
class OrderData {
    
private:
    //fields in OrderData class
    std::string id, date, quantity, paidAmount;

public:
    OrderData();
    OrderData(std::string, std::string, std::string, std::string);
    std::string toString();
    //getter methods
    std::string getId();
    std::string getDate();
    std::string getQuantity();
    std::string getPaidAmount();
    void setNewID(int);
    virtual ~OrderData();
};

#endif /* ORDERDATA_H */

