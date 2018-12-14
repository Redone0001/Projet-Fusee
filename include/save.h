#include <iostream>
#include <fstream>
#include <string>

bool saveToCSV(std::string fileName, ordinateurDeBord ENIAC){
	std::ofstream fs (fileName, std::fstream::app);
	if (! fs.is_open()) return 0;
	/*
	pair <float,float> gravite;
	pair <float,float> position; // la possition de la fussée est repéré dans un référentiel placé au centre de la terre et immobile
	pair <float,float> vitesse; // la vitesse est dans le même repère que la possition 
	pair <float,float> acceleration; //idem
	pair <float,float> SommeForces;
	float angle; // angle de la fusée / à la verticale
	*/
	fs <<ENIAC.position.first<<","<<ENIAC.position.second<<","<<ENIAC.vitesse.first<<","<<ENIAC.vitesse.second<<","<<ENIAC.acceleration.first<<","<<ENIAC.acceleration.second;
	
}
