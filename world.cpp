#include "world.h"

namespace eti {
	uConciliate w_weather(WEATHERS weather) {
		return static_cast<uConciliate>(weather);
	}
}

namespace Worlds {
	Function SetCodeName(struct World& w, std::string new_name) {
		if (new_name.empty()) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] Nelze " << Display(TEXTS::TITLE_WORLD) << "u nastavit zadne jmeno!" << std::endl;
		else if (w.name.compare(new_name) == 0) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] " << Display(TEXTS::TITLE_WORLD) << " " << w.name << "[" << w.ingame_name << "] uz ma toto jmeno!" << std::endl;
		else {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_WORLD) << "u jmenem " << w.name << "[" << w.ingame_name << "] kodove jmeno na " << new_name << std::endl;
			w.name = new_name;
		}
	}
	Function SetName(struct World& w, std::string new_name) {
		if (new_name.empty()) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] Nelze " << Display(TEXTS::TITLE_WORLD) << "u nastavit zadne jmeno!" << std::endl;
		else if (w.ingame_name.compare(new_name) == 0) std::cout << "[" << Display(TEXTS::TITLE_ERROR) << "] " << Display(TEXTS::TITLE_WORLD) << " " << w.name << "[" << w.ingame_name << "] uz ma toto jmeno!" << std::endl;
		else {
			std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastavuji " << Display(TEXTS::TITLE_WORLD) << "u jmenem " << w.name << "[" << w.ingame_name << "] kodove jmeno na " << new_name << std::endl;
			w.ingame_name = new_name;
		}
	}
	Function SetSize(struct World& w, float new_x, float new_y, float new_x2, float new_y2) {
		std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastaveni " << Display(TEXTS::TITLE_WORLD) << " " << w.name << " velikost na "
			<< new_x << "/" << new_y << " /" << new_x2 << "/" << new_y2 << std::endl;
		w.x[0] = new_x; w.y[0] = new_y;
		w.x[1] = new_x2; w.y[1] = new_y2;
	}

	Function SetHeight(struct World& w, float new_height) {
		std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastaveni " << Display(TEXTS::TITLE_WORLD) << " " << w.name << " vysky na "
			<< new_height << std::endl;
		w.height = new_height;
	}

	Function UpdateTime(struct World& w) {
		w.time[MINUTES]++;
		if (w.time[MINUTES] == 60) w.time[HOURS]++, w.time[MINUTES] = 0;
		if (w.time[HOURS] == 24) w.time[HOURS] = 0, w.time[DAYS]++;
	}
	uConciliate GetTime(struct World& w, bool get_minutes) {
		return !get_minutes ? w.time[HOURS] : w.time[MINUTES];
	}
	Ethons GetFullTime(struct World& w) {
		return (std::to_string(w.time[DAYS]) + ":" + std::to_string(w.time[HOURS]) + ":" + std::to_string(w.time[MINUTES]));
	}
	uConciliate GetWeather(struct World& w) {
		return eti::w_weather(w.weather);
	}
	Ethons GetWeatherN(struct World& w) {
		return _weathers[eti::w_weather(w.weather)];
	}
	Function GetWeather(struct World& w, enum class WEATHERS& to_wet) {
		to_wet = w.weather;
	}
	Function SetTime(struct World& w, uConciliate hours, uConciliate minutes) {
		if (hours < 0 || hours > 23) hours = 0;
		if (minutes < 0 || minutes > 60) minutes = 0;
		w.time[HOURS] = hours; w.time[MINUTES] = minutes;
		std::cout << "[" << Display(TEXTS::TITLE_DEBUG) << "] Nastaveni " << Display(TEXTS::TITLE_WORLD) << " " << w.name << " " << Display(TEXTS::TITLE_TIME) << "u nastaveny na "
			<< Worlds::GetFullTime(w) << std::endl;
	}
	Function SetWeather(struct World& w, enum class WEATHERS weather) {
		w.weather = weather;
	}
	Function Print(struct World& w) {
		std::cout << "-------- " << Display(TEXTS::TITLE_WORLD) << " --------" << std::endl;
		std::cout << "Codename: " << w.name << std::endl;
		std::cout << "Name: " << w.ingame_name << std::endl;
		std::cout << "Vyska: " << w.height << std::endl;
		std::cout << "Velikost: " << w.x[0] << "/" << w.y[0] << " " << w.x[1] << "/" << w.y[1] << std::endl;
		std::cout << Display(TEXTS::TITLE_TIME) << " = " << Worlds::GetFullTime(w) << std::endl;
		std::cout << Display(TEXTS::TITLE_WEATHER) << " = " << Worlds::GetWeatherN(w) << std::endl;
		std::cout << "-------- " << Display(TEXTS::TITLE_WORLD) << " --------" << std::endl;
	}
}

