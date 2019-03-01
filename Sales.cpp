/* 
 * File:   Sales.cpp
 * Author: Alyssa Gibson
 * 
 * Created on February 26, 2019, 3:24 PM
 */

#include "Sales.h"
#include <string>

using namespace std;

Sales::Sales(){
}

Sales::Sales(const Sales& orig){
    title = orig.title;
    name = orig.name;
    salesPersonID = orig.salesPersonID;
    bossID = orig.bossID;
    commission = orig.commission;
}

Sales::Sales(string t, string n, string sid, string bid):Employee(t, n , sid, bid) {
    commission = 0;
}

double Sales::getCommission() {
    // Commission calculations go here.
}

bool Sales::operator <(const Sales& other){
    return name < other.name;
}
Sales::~Sales() {
    
}

