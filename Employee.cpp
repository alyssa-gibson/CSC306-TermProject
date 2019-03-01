/* 
 * File:   Employee.cpp
 * Author: Alyssa Gibson
 * Edited by: Daniel Jirasek
 * Created on February 26, 2019, 2:51 PM
 */

#include "Employee.h"
#include <string>

using namespace std;

Employee::Employee(){
}

Employee::Employee(const Employee& orig){
}

Employee::Employee(string t, string n, string sid, string bid) {
    // Constructor takes in 4 strings and sets them.
    title = t;
    name = n;
    salesPersonID = sid;
    bossID = bid;
    
}

// Standard get methods--
string Employee::getTitle() {
    return title;
}

string Employee::getName() {
    return name;
}

string Employee::getSalesID() {
    return salesPersonID;
}

string Employee::getBossID() {
    return bossID;
}

string Employee::toString(){
    return title+" "+name+" "+salesPersonID+" "+bossID;
}

Employee::~Employee(){
}

// -------