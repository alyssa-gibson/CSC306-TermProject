/* 
 * File:   Supervisor.cpp
 * Author: Alyssa Gibson
 * 
 * Created on February 26, 2019, 3:33 PM
 */

#include "Supervisor.h"
#include "Manager.h"
#include <string>

using namespace std;

Supervisor::Supervisor(){
}

Supervisor::Supervisor(const Supervisor& orig){
}

Supervisor::Supervisor(string t, string n, string sid, string bid):Manager(t, n, sid, bid) 
{
    commission = 0;
    grossSales = 0;
}

string Supervisor::toString()  {
    char cSale[32], cCommission[32];
    commission = getCommission();
    sprintf(cSale, "%0.2f", grossSales);
    sprintf(cCommission, "%0.2f", commission);
    return "Supervisor: " + name + " Gross Sales: $" + cSale + " Commission: $" + cCommission;
}

double Supervisor::getCommission(){
    // Commission calculations go here.
    return commission;
}

double Supervisor::getSales() {
    return grossSales;
}

void Supervisor::setCommission(double c) {
    commission = c;
}

void Supervisor::setSales(double gS) {
    grossSales = gS;
}

Supervisor::~Supervisor() {
}

