#pragma once
#include "module.h"
#include <vector>
#include <utility>

class ordinateurDeBord{
	public :
	ordinateurDeBord ();
	bool checkCarburant(module); //vérifie que le carburant est pas trop bas et si c'est à un niveau critique éjecte(supprime) le module
	void updateCarburant(module);//update le carburant 
	float sumPuissance(std::vector <module>);// dans le sens du mouvement
	void sumForce(std::vector <module>); // modifie la pair de float Somme des forces
	void calculGravite(std::vector <module>);  // modifie la pair de float gravite
	float sumFrottement(std::vector <module>);//dans le sens opposé au mouvement
	void updateMouv(float,float);
	float checkMasse(std::vector <module>);
	float pression();
	void udateAngle(float);
	std::pair <float,float> gravite;
	std::pair <float,float> position; // la possition de la fussée est repéré dans un référentiel placé au centre de la terre et immobile
	std::pair <float,float> vitesse; // la vitesse est dans le même repère que la possition 
	std::pair <float,float> acceleration; //idem
	std::pair <float,float> SommeForces;
	float angle; // angle de la fusée / à la verticale
	
};



