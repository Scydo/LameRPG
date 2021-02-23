#include "world.h"

namespace Worlds {
	Function SetName(World& w, std::string new_name) {
		std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastaveni " << Display(TEXTS::TITLE_WORLD) << " " << w.name << " jmena na " << new_name << std::endl;
		w.name = new_name;
	}
	Function SetSize(World& w, float new_x, float new_y, float new_x2, float new_y2) {
		std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastaveni " << Display(TEXTS::TITLE_WORLD) << " " << w.name << " velikost na " 
			<< new_x << "/" << new_y << " /" << new_x2 << "/" << new_y2 << std::endl;
		w.x[0] = new_x; w.y[0] = new_y;
		w.x[1] = new_x2; w.y[1] = new_y2;
	}
	Function UpdateTime(World& w) {
		w.time[MINUTES]++;
		if (w.time[MINUTES] == 60) w.time[HOURS]++ , w.time[MINUTES] = 0;
		if (w.time[HOURS] == 24) w.time[HOURS] = 0 , w.time[DAYS]++;
	}
	uConciliate GetTime(World& w, bool get_minutes) {
		return !get_minutes ? w.time[HOURS] : w.time[MINUTES];
	}
	Ethons GetFullTime(World& w) {
		return (std::to_string(w.time[DAYS]) + ":" + std::to_string(w.time[HOURS]) + ":" + std::to_string(w.time[MINUTES]));
	}
	uConciliate GetWeather(World& w) {
		return static_cast<uConciliate>(w.weather);
	}
	Ethons GetWeatherN(World& w) {
		return _weathers[static_cast<uConciliate>(w.weather)];
	}
	Function GetWeather(World& w, WEATHERS& to_wet) {
		to_wet = w.weather;
	}
	Function SetTime(World& w, uConciliate hours, uConciliate minutes) {
		if (hours < 0 || hours > 23) hours = 0;
		if (minutes < 0 || minutes > 60) minutes = 0;
		w.time[HOURS] = hours; w.time[MINUTES] = minutes;
		std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastaveni " << Display(TEXTS::TITLE_WORLD) << " " << w.name << " " << Display(TEXTS::TITLE_TIME) << "u nastaveny na "
			<< Worlds::GetFullTime(w) << std::endl;
	}
	Function SetWeather(World& w, WEATHERS weather) {
		w.weather = weather;
	}
}

