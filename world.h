#include "text.h"

constexpr unsigned short int HOURS = 0;
constexpr unsigned short int MINUTES = 1;
constexpr unsigned short int DAYS = 2;

static uConciliate _worlds;

const enum class WEATHERS : const short {
	WEATHER_CLEAR,
	WEATHER_RAIN,
	WEATHER_STORM,
	WEATHER_SNOWING,
	WEATHER_CLOUDY,
	WEATHER_AFTERNOON,
	WEATHER_DUSK,
	WEATHER_COLOR
};

struct World {
	Ethons name;
	Ethons ingame_name;
	float x[2], y[2], height;
	WEATHERS weather;
	uConciliate time[3];
	World () {
		this->name = (Display(TEXTS::UNDEF_WORLD) + "_" + std::to_string(_worlds));
		this->ingame_name = Display(TEXTS::UNDEF_WORLD);
		this->weather = WEATHERS::WEATHER_CLEAR;
		this->x[0] = this->y[0] = this->x[1] = this->y[1] = 100.0F;
		this->height = 3.0F;
		time[DAYS] = time[HOURS] = time[MINUTES] = 0;
		_worlds++;
	}
	World(Ethons name, Ethons ingame_name, float x, float x2, float y, float y2, float height) : World() {
		this->name = name; this->ingame_name = ingame_name; 
		this->x[0] = x; this->x[1] = x2;
		this->y[0] = y; this->y[1] = y2;
		this->height = height;
	}
};

namespace eti {
	uConciliate w_weather(enum class WEATHERS weather);
}

namespace Worlds {
	Function SetCodeName(struct World& w, std::string new_name);
	Function SetName(struct World& w, std::string new_name);
	Function SetSize(struct World& w, float new_x, float new_y, float new_x2, float new_y2);
	Function SetHeight(struct World& w, float new_height);
	Function UpdateTime(struct World& w);
	uConciliate GetTime(struct World& w, bool get_minutes = false);
	Ethons GetFullTime(struct World& w);
	uConciliate GetWeather(struct World& w);
	Ethons GetWeatherN(struct World& w);
	Function GetWeather(struct World& w, enum class WEATHERS& to_wet);
	Function SetTime(struct World& w, uConciliate hours, uConciliate minutes);
	Function SetWeather(struct World& w, enum class WEATHERS weather);
	Function Print(struct World& w);
}