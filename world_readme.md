## Světy
**Konstruktor**

```C++
World();
// Nebo
World(Ethons name, Ethons ingame_name, float x, float x2, float y, float y2, float height);
```
**Obsah struktury**
| Defaultní | Argument | Popisek |
| --------- | -------- | ------- |
| `"undefined-world` | `std::string name` | Jméno světa / jméno v kódě. |
| `100.0f` | `float x[0]` | První pozice x. |
| `100.0f` | `float y[0]` | První pozice y. |
| `100.0f` | `float x[1]` | Druhá pozice y. |
| `100.0f` | `float y[1]` | Druhá pozice y. |
| `100.0f` | `float height` | Výška světa. |
| `0/0/0` | `time[3]` | Čas ve světě, `[DAYS]` pro dny, `[HOURS]` pro hodiny, `[MINUTY]` pro minuty. Formát je 1d/24h/64m. |
| `WEATHERS::WEATHER_CLEAN` | `weather` | Počasí našeho světa. |

Typy počasí: `WEATHERS`
| Číslo | Kód | Popis |
| --- | --- | --- |
| `#0` | `WEATHER_CLEAN` | Zcela čisté počasí. Bez mráčků. | 
| `#1` | `WEATHER_RAIN` | Déšť. | 
| `#2` | `WEATHER_STORM` | Velký déšť s bleskama. | 
| `#3` | `WEATHER_SNOWING` | Sněžení, pro místa kde je velká zima. | 
| `#4` | `WEATHER_CLOUDY` | Zamračeno, mraky apod. |
| `#5` | `WEATHER_AFTERNOON` | Odpolední (spíše barva než počasí) |
| `#6` | `WEATHER_DUSK` | Západ slunce (spíše barva než počasí) |
| `#7` | `WEATHER_COLOR` | Nějaká naše vlastní barva počasí, např. červená jako peklo. |

### Funkce
```C++
	Function Worlds::SetName(World& w, std::string new_name);
	Function Worlds::SetSize(World& w, float new_x, float new_y, float new_x2, float new_y2);
	Function Worlds::SetHeight(struct World& w, float new_height);
	Function Worlds::UpdateTime(World& w);
	uConciliate Worlds::GetTime(World& w, bool get_minutes = false);
	Ethons Worlds::GetFullTime(World& w);
	uConciliate Worlds::GetWeather(World& w);
	Ethons Worlds::GetWeatherN(World& w);
	Function Worlds::GetWeather(World& w, WEATHERS& to_wet);
	Function Worlds::SetTime(World& w, uConciliate hours, uConciliate minutes);
	Function Worlds::SetWeather(World& w, WEATHERS weather);
	Function Worlds::Print(struct World& w);
```
**Příklady použití** - [#world_example](https://github.com/Scydo/LameRPG/blob/main/world_example.md)
