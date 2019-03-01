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
}

double SuperSales::getCommission() {
    // Commission calculation goes here
}

SuperSales::~SuperSales() {
}

