#include "text.h"

constexpr unsigned short int HOURS = 0;
constexpr unsigned short int MINUTES = 1;
constexpr unsigned short int DAYS = 2;
const enum class WEATHERS : const short {
	WEATHER_CLEAR,
	WEATHER_RAIN,
	WEATHER_STORM,
	WEATHER_SNOWING,
	WEATHER_COLOR
};

struct World {
	Ethons name;
	float x[2], y[2];
	WEATHERS weather;
	uConciliate time[3];
	World () {
		this->name = Display(TEXTS::UNDEF_WORLD);
		this->weather = WEATHERS::WEATHER_CLEAR;
		this->x[0] = this->y[0] = this->x[1] = this->y[1] = 100.0F;
		time[DAYS] = time[HOURS] = time[MINUTES] = 0;
	}
};

namespace Worlds {
	Function SetName(World& w, std::string new_name);
	Function SetSize(World& w, float new_x, float new_y, float new_x2, float new_y2);
	Function UpdateTime(World& w);
	uConciliate GetTime(World& w, bool get_minutes = false);
	Ethons GetFullTime(World& w);
	uConciliate GetWeather(World& w);
	Ethons GetWeatherN(World& w);
	Function GetWeather(World& w, WEATHERS& to_wet);
	Function SetTime(World& w, uConciliate hours, uConciliate minutes);
	Function SetWeather(World& w, WEATHERS weather);
}