/* 
 * File:   SuperSales.cpp
 * Author: Alyssa Gibson
 * 
 * Created on February 26, 2019, 3:25 PM
 */

#include "SuperSales.h"
#include <string>

using namespace std;

SuperSales::SuperSales(){
}

SuperSales::SuperSales(const SuperSales& orig){
}

SuperSales::SuperSales(string t, string n, string sid, string bid):Sales(t, n, sid, bid){
    commission = 0;
    grossSales = 0;
}

string SuperSales::toString() {
    char cSale[32], cCommission[32];
    commission = getCommission();
    sprintf(cSale, "%0.2f", grossSales);
    sprintf(cCommission, "%0.2f", commission);
    return "Super Sales: " + name + " Gross Sales: $" + cSale + " Commission: $" + cCommission;
}

double SuperSales::getCommission(){
    // Commission calculation goes here
    return grossSales * 0.065;
}

double SuperSales::getSales() {
    return grossSales;
}

void SuperSales::setCommission(double c) {
    commission = c;
}

void SuperSales::setSales(double gS) {
    grossSales = gS;
}

SuperSales::~SuperSales() {
}

