#pragma once

class module{
// variable 
	public :
	const float masse;
	float carburant;
	float coefPuissance;
	float consomation;
	const float surfaceFrot;
	float puissance();
	module(float,float,float,float);
	~module();
};
