/* 
 * File:   Manager.cpp
 * Author: Alyssa Gibson
 * 
 * Created on February 26, 2019, 3:25 PM
 */

#include "Manager.h"
#include <string>

using namespace std;

Manager::Manager(){
}

Manager::Manager(const Manager& orig){
}

Manager::Manager(string t, string n, string sid, string bid):SuperSales(t, n, sid, bid) {
    commission = 0;
    grossSales = 0;
}

string Manager::toString() {
    char cSale[32], cCommission[32];
    commission = getCommission();
    sprintf(cSale, "%0.2f", grossSales);
    sprintf(cCommission, "%0.2f", commission);
    return "Manager: " + name + " Gross Sales: $" + cSale + " Commission: $" + cCommission;
}

double Manager::getCommission() {
    // Commission calculation goes here
    return commission;
}

double Manager::getSales() {
    return grossSales;
}

void Manager::setCommission(double c) {
    commission = c;
}

void Manager::setSales(double gS)  {
    grossSales = gS;
}

Manager::~Manager() {
}

