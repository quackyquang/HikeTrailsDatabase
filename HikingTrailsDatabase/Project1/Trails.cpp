#include <iostream>
#include "Trails.h"

class Trails{
private:
	std::string name;
	std::string park;
	std::string location;
	double distance;
	double difficulty;
	double popularity;
public:
	Trails() = default;
	Trails(std::string name, std::string park, std::string location,
		double distance, double difficutly, double popularity) : name(name), park(park), location(location),
		distance(distance), difficulty(difficulty), popularity(popularity){}
};