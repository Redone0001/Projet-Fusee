#include <iostream>
#include <fstream>
#include <string>

void saveToCSV(std::string fileName, ordinateurDeBord ENIAC){
	std::ofstream fs (fileName, std::fstream::app);
	fs <<ENIAC.position.first<<","<<ENIAC.position.second<<","<<ENIAC.vitesse.first<<","<<ENIAC.vitesse.second<<","<<ENIAC.acceleration.first<<","<<ENIAC.acceleration.second<<"\n";
}
