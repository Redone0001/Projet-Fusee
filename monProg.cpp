#include "include/ordinateurDeBord.h"
#include "include/module.h"
#include "include/save.h"
#include <vector>

using namespace std;

int main(){
//initialisation 
	vector <module> lanceurVec;
			//masse carbu puissance surfaceFrot conso
	module soyuz(6999,1,0,2.86,0);
	module etage1(6500,105000,1000000,3.42,350);
	module etage2(2250,25200,300000,2.78,105);
	lanceurVec.push_back(soyuz);
	lanceurVec.push_back(etage2);
	lanceurVec.push_back(etage1);
	for (int i=0;i<4; i++){
		module booster(3500,40000,1000000,2.82,105);
		lanceurVec.push_back(booster);
	}
	ordinateurDeBord ENIAC;
//vol
	long double t = 0.05;
	while(t<=(5)){
//cout <<"test"<<endl;

		for (auto x:lanceurVec){
			ENIAC.checkCarburant(x);
			ENIAC.updateCarburant(x);
			
		}
//cout <<"test2"<<endl;
		ENIAC.updateAngle(t);
//cout <<"test3"<<endl;
		ENIAC.sumForce(lanceurVec);
		long double masse = ENIAC.checkMasse(lanceurVec);
		cout <<masse<<endl;
		ENIAC.updateMouv(0.05,masse);

		saveToCSV("save.csv",ENIAC);

		t+= 0.05;

	}
	

}
