#include "../include/module.h"
using namespace std;

module::module(long double Masse,long double Carburant, long double coef, long double SurfaceFrot):masse(Masse),carburant(Carburant),coefPuissance(coef),surfaceFrot(SurfaceFrot){
    consomation = 0;
}

module::~module(){}

long double module::puissance(){
    long double puissance = coefPuissance * consomation;
    return puissance;
}
