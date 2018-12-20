#pragma once

class module{
// variable 
	public :
	const long double masse;
	long double carburant;
	long double puissance;
	const long double surfaceFrot;
	long double consomation;
	long double throttle;
	module(long double,long double,long double,long double,long double, long double);
	~module();
};
