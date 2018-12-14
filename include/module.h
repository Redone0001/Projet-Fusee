#pragma once

class module{
// variable 
	public :
	const long double masse;
	long double carburant;
	long double coefPuissance;
	long double consomation;
	const long double surfaceFrot;
	long double puissance();
	module(long double,long double,long double,long double);
	~module();
};
