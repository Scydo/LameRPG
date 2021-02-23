![title](https://github.com/Scydo/LameRPG/blob/main/title.png)

**Světy - Příklad**

```C++ 
Conciliate main() {
	// Vytváření světa :
	World Default;
	Worlds::SetCodeName(Default, "default");
	Worlds::SetName(Default, "Zakladni");
	Worlds::SetSize(Default, 100.0F, 100.0F, 20.F, 30.0F);	
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
	Worlds::Print(Default);
	/*
		[Debug] Nastavuji Svetu jmenem undefined-world296[undefined-world] kodove jmeno na default
		[Debug] Nastavuji Svetu jmenem default[undefined-world] kodove jmeno na Zakladni
		[Debug] Nastaveni Svet default velikost na 100/100 /20/30
		[Debug] Nastaveni Svet default Casu nastaveny na 0:11:59
		[Debug] Nastaveni Svet default Casu nastaveny na 0:23:59
		Cas je 1:0:0
		Pocasi je Dest cislo = 1
		-------- Svet --------
		Codename: default
		Name: Zakladni
		Velikost: 100/100 20/30
		Cas = 1:0:0
		Pocasi = Dest
		-------- Svet --------
	*/
	return 0;
}```
