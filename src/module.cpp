#include "../include/module.h"
using namespace std;

module::module(float Masse,float Carburant, float coef, float SurfaceFrot):masse(Masse),carburant(Carburant),coefPuissance(coef),surfaceFrot(SurfaceFrot){
    consomation = 0;
}

module::~module(){}

float module::puissance(){
    float puissance = coefPuissance * consomation;
    return puissance;
}
