## Světy
**Konstruktor**

```C++
World();
```

| Defaultní | Argument | Popisek |
| --------- | -------- | ------- |
| `"undefined-world` | `std::string name` | Jméno světa / jméno v kódě. |
| `100.0f` | `float x[0]` | První pozice x. |
| `100.0f` | `float y[0]` | První pozice y. |
| `100.0f` | `float x[1]` | Druhá pozice y. |
| `100.0f` | `float y[1]` | Druhá pozice y. |
| `0/0/0` | `time[3]` | Čas ve světě, `[DAYS]` pro dny, `[HOURS]` pro hodiny, `[MINUTY]` pro minuty. Formát je 1d/24h/64m. |
| `WEATHERS::WEATHER_CLEAN` | `weather` | Počasí našeho světa. |

Typy počasí: `WEATHERS`
| Číslo | Kód | Popis |
| --- | --- | --- |
| `#0` | `WEATHER_CLEAN` | Zcela čisté počasí. Bez mráčků. | 
| `#1` | `WEATHER_RAIN` | Déšť. | 
| `#2` | `WEATHER_STORM` | Velký déšť s bleskama. | 
| `#3` | `WEATHER_SNOWING` | Sněžení, pro místa kde je velká zima. | 
| `#4` | `WEATHER_COLOR` | Nějaká naše vlastní barva počasí, např. červená jako peklo. | 

### Funkce
```C++
	Function Worlds::SetName(World& w, std::string new_name);
	Function Worlds::SetSize(World& w, float new_x, float new_y, float new_x2, float new_y2);
	Function Worlds::UpdateTime(World& w);
	uConciliate Worlds::GetTime(World& w, bool get_minutes = false);
	Ethons Worlds::GetFullTime(World& w);
	uConciliate Worlds::GetWeather(World& w);
	Ethons Worlds::GetWeatherN(World& w);
	Function Worlds::GetWeather(World& w, WEATHERS& to_wet);
	Function Worlds::SetTime(World& w, uConciliate hours, uConciliate minutes);
	Function Worlds::SetWeather(World& w, WEATHERS weather);
```
**Příklady použití** - [#world_example](https://github.com/Scydo/LameRPG/blob/main/world_example.md)
