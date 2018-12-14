#include "include/ordinateurDeBord.h"
#include "include/module.h"
#include "include/save.h"
#include <vector>

using namespace std;

int main(){
//initialisation 
	vector <module> lanceurVec;
	module soyuz(750,10,0,2);
	module etage1(500,500,5,10);
	module etage2(750,750,5,10);
	lanceurVec.push_back(soyuz);
	lanceurVec.push_back(etage1);
	lanceurVec.push_back(etage2);
	for (int i=0;i<4; i++){
		module booster(1000,500,5,10);
		lanceurVec.push_back(booster);
	}
	ordinateurDeBord ENIAC;
//vol
	long double t = 0.05;
	while(t<=(20)){
//cout <<"test"<<endl;
		for (auto x:lanceurVec){
			ENIAC.checkCarburant(x);
			ENIAC.updateCarburant(x);
			
		}
		ENIAC.updateAngle(t);
		ENIAC.sumForce(lanceurVec);
		long double masse = ENIAC.checkMasse(lanceurVec);
		
		ENIAC.updateMouv(t,masse);
//cout <<"test2"<<endl;
		saveToCSV("save.csv",ENIAC);
//cout <<"test3"<<endl;
		t+= 0.05;

	}
	

}
