![title](https://github.com/Scydo/LameRPG/blob/main/title.png)

**Světy - Příklad**

```C++ 
Conciliate main() {
	// Vytváření světa :
	World Default;
	Worlds::SetSize(Default, 100.0F, 100.0F, 20.F, 30.0F);
	Worlds::SetName(Default, "Zakladni");
	Worlds::SetWeather(Default, WEATHERS::WEATHER_RAIN);
	Worlds::SetTime(Default, 11, 59);

	// Čas se aktualizuje ze 11:59 na 12:00 :
	Worlds::UpdateTime(Default);

	// Čas se aktualizuje ze 23:59 na 0:00 a přičte se 1 den
	// Takže výsledně bude 1:00:00 :
	Worlds::SetTime(Default, 23, 59);
	Worlds::UpdateTime(Default);

	// Zjištění hodin a minut ve světě :
	int time_h = Worlds::GetTime(Default, false);
	int time_m = Worlds::GetTime(Default, true);

	// Zjištění počasí :
	WEATHERS weat = WEATHERS::WEATHER_CLEAR;
	Worlds::GetWeather(Default, weat);

	// print:
	std::cout << Display(TEXTS::TITLE_TIME) << " je " << Worlds::GetFullTime(Default) << std::endl;
	std::cout << Display(TEXTS::TITLE_WEATHER) << " je " << Worlds::GetWeatherN(Default) << " cislo = " << static_cast<int>(weat) << std::endl;
	/*
		[Debug] Nastaveni Svet undefined-world velikost na 100/100 /20/30
		[Debug] Nastaveni Svet undefined-world jmena na Zakladni
		[Debug] Nastaveni Svet Zakladni Casu nastaveny na 0:11:59
		[Debug] Nastaveni Svet Zakladni Casu nastaveny na 0:23:59
		Cas je 1:0:0
		Pocasi je Dest cislo = 1
	*/
	return 0;
}```
