#include "../include/ordinateurDeBord.h"
#include "../include/module.h"
#include <math.h>

using namespace std;
ordinateurDeBord::ordinateurDeBord (){
	angle = 3.141592;
	position.first = 3371000.0;
	position.second=0;
	vitesse.first=0;
	vitesse.second=465;
	acceleration.first=0;
	acceleration.second=0;
}

bool ordinateurDeBord::checkCarburant(module x){
	if (x.carburant<1){
		x.~module();
		return(true);
	}
	else {
		return(false);
	}
}

void ordinateurDeBord::updateCarburant(module x){
	x.carburant = x.carburant-x.consomation;
}

float ordinateurDeBord::sumPuissance(vector <module> lanceurVec){
	float sum=0;	
	for (auto x:lanceurVec){
		sum += x.puissance();
	}
	return sum;
}
void ordinateurDeBord::calculGravite(vector <module> lanceurVec){
	float masseTot=0;
	for (auto x:lanceurVec){
	masseTot+=x.masse;
	masseTot+=x.carburant;
		
	}
	gravite.first = pow(6.674,pow(10,-11))*masseTot/pow(position.first,2);
	gravite.second = pow(6.674,pow(10,-11))*masseTot/pow(position.second,2);
}

float ordinateurDeBord::densite(){
	float altitude = sqrt(pow(position.first,2)+pow(position.second,2))-3371000.0;
	float pres =0;
	if (altitude<350000){
		
		pres = 101325*pow(1-(0.0065*altitude/288.15),(sqrt(pow(gravite.first,2)*pow(gravite.second,2)))*0.0289644/(8.31447*0.0065));
	}
	else{
		pres = 0;
	}
	return pres;
}

float ordinateurDeBord::sumFrottement(vector <module> lanceurVec){
	float surfaceTot=0;
	for (auto x:lanceurVec){
		surfaceTot+=x.surfaceFrot;
	}
	float forceFrot=0;
	forceFrot = pow(vitesse.first,2)*pow(vitesse.second,2)*densite()*surfaceTot;
		
	return forceFrot;
	
}

void ordinateurDeBord::sumForce(vector <module> lanceurVec){
	calculGravite(lanceurVec);
	float power = sumPuissance(lanceurVec); 		// ATTENTION ceci ne fonction que si on décolle "vers le haut" si on part de l'autre côté de la terre on va avoir des soucis
	float frot = sumFrottement(lanceurVec);			// il est nécéssaire de bien gérer l'angle de la fussée
	SommeForces.first = gravite.first+power * sin(angle)-frot *sin(angle);
	SommeForces.second = gravite.second+power * cos(angle)-frot * cos(angle);
	
}
float ordinateurDeBord::checkMasse(vector <module> lanceurVec){
	float masseTot=0;
	for (auto x:lanceurVec){
	masseTot+=x.masse;
	masseTot+=x.carburant;	
	}
	return masseTot;
}

void ordinateurDeBord::updateMouv(float t,float masse){
	position.first = vitesse.first*t;
	position.second=vitesse.second*t;
	vitesse.first = acceleration.first*t;
	vitesse.second = acceleration.second*t;
	acceleration.first=SommeForces.first/masse;
	acceleration.second=SommeForces.second/masse;
		
}
void ordinateurDeBord::udateAngle(float temps){
	
	angle = ((1/(1+exp(-0.05*(temps-120))*1.570796)+1.570796);
	
}
