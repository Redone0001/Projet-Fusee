#include <iostream>
#include <fstream>
#include <string>

void initialisationCSV(std::string fileName){
	std::ofstream fs(fileName);
	fs<<"x,y\n";
	fs.close();

}
void saveToCSV(std::string fileName, ordinateurDeBord ENIAC){
	std::ofstream fs (fileName, std::fstream::app);
	fs <<ENIAC.position.first<<","<<ENIAC.position.second<<"\n";
	fs.close();
}
