![title](https://github.com/Scydo/LameRPG/blob/main/title.png)

# LameRPG
Můj prostý kód jádra hry, který je stupidní, trapný a všechno by šlo udělat 10x lépe.

# Obsah
- [**Světy**](https://github.com/Scydo/LameRPG/blob/main/world_readme.md) - Když nestačí jen jeden svět,
- **Entity** - Vytvoř si všechny možné entity, od monster, nemrtvé až po bandity nebo hráče,
  - Humanoidi - Entity typu `ENTITY_TYPE_HUMAN` a funkce pro jeji následné úpravy,
  - Hráč - Entita typu `ENTITY_TYPE_HUMAN`.
  - Monstra - Entita typu `ENTITY_TYPE_MONSTER`.
  - Zvířata - Entita typu `ENTITY_TYPE_ANIMAL`.
  - Duchové - Entita typu `ENTITY_TYPE_GHOST`.
  - Nemrtví - Entita typu `ENTITY_TYPE_UNDEAD`.
- [**Předměty**](https://github.com/Scydo/LameRPG/blob/main/item_readme.md) - Přidávání itemů, zbraní, zbrojí, lektvarů, úkolových předmětů a více,
  - Úkolové - Předměty typu `ITEM_TYPE_QUEST`.
  - Jiné - Předměty typu `ITEM_TYPE_JUNK`.
  - Lektvary - Předměty typu `ITEM_TYPE_POTION`.
  - Jídlo - Předměty typu `ITEM_TYPE_FOOD`.
  - Zbroj - Předměty typu `ITEM_TYPE_ARMOR`.
  - Štíty - Předměty typu `ITEM_TYPE_SHIELD`.
  - Zbraně - Předměty typu `ITEM_TYPE_WEAPON`.
  - Šípy a šipky - Předměty typu `ITEM_TYPE_ARROW` a `ITEM_TYPE_BOLT`.
- [**Attributes**](https://github.com/Scydo/LameRPG/blob/main/item_example.md) - Pro předměty, přidávání různých dovednosti například zvýšení many nebo životů.
- **Skills** - Pro hráče, nastavení různých dovedností,
- **Boje** - Různé funkce pro různé momenty například ubírání životů, zjištění odblokování poškození,
- **Market** - Prodej a koupě všech předmětů, změna cen po prodeji, zjištění ceny předmětu apod,
- **Texty** - Přednastavené různé texty, jménema popisky, tituly textů apod.
- **Úkoly** - tvorba úkolů, typy úkolů, odměny, podmínky určitých momentů a tak dále.

# Hlavní data:
**Odkaz na hlavní data** -> [odkaz](https://github.com/Scydo/LameRPG/blob/main/main_data.h)

**Alternativní pojmenování**
```C++
Function -> void
Collation -> bool
Ethons -> std::string
Conciliate -> int
uConciliate -> unsigned short int
```

**Vrátit čísla ze výčtu hodnot**
```C++
// world.h
eti::w_weather(WEATHERS weather);

// item.h
eti::i_type(ITEM_TYPES type);
eti::i_rarity(ITEM_RARITIES rarity);
eti::i_att(ATTRIBUTES att);
```
**Příklad použití**
```C++
std::cout << "Rare =" << eti::i_rarity(ITEM_RARITIES::RARITY_RARE);
```

# Příklady
- Světy -> [odkaz](https://github.com/Scydo/LameRPG/blob/main/world_example.md)
- Předměty -> [odkaz](https://github.com/Scydo/LameRPG/blob/main/item_example.md)
