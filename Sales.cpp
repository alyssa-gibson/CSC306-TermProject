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
    grossSales = orig.grossSales;
}

Sales::Sales(string t, string n, string sid, string bid):Employee(t, n , sid, bid) {
    commission = 0;
    grossSales = 0;
}

string Sales::toString(){
    char cSale[32], cCommission[32];
    commission = getCommission();
    sprintf(cSale, "%0.2f", grossSales);
    sprintf(cCommission, "%0.2f", commission);
    return "Sales: " + name + " Gross Sales: $" + cSale + " Commission: $" + cCommission;
}

double Sales::getCommission() {
    // Commission calculations go here.
    return grossSales * 0.05;
}

double Sales::getSales() {
    return grossSales;
}

void Sales::setCommission(double c){
    commission = c;
}

void Sales::setSales(double gS) {
    grossSales = gS;
}

bool Sales::operator <(const Sales& other){
    return name < other.name;
}
Sales::~Sales() {
    
}

