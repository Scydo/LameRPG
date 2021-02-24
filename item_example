![title](https://github.com/Scydo/LameRPG/blob/main/title.png)

**Předměty - Příklad**

```C++ 
Conciliate main() {
	// Přidáme si předmět středního léčivého lektvaru s typem Lektvar :
	Item md_potion("sh_potion", "Healing potion", ITEM_TYPES::ITEM_TYPE_POTION);

	// Přiřadil jsem mu kódové jméno stejný jako Slabší léčivý lekvar. Tak mu ho změníme :
	Items::SetCodeName(md_potion, "md_potion");

	// Nepřidal jsem před jméno ve hře "Medium, že jde o Střední. Tak mu ho přidáme :
	Items::SetName(md_potion, "Medium Healing potion");

	// Protože je to lektvar co mi vyléčí část zdraví (25 %) tak mu na to přidáme attribut :
	Items::AddAttribute(md_potion, ATTRIBUTES::ATT_HEAL, 25);

	// Můžeme přidat i více atribut, například že hráči bude regenerovat zdraví 5 % každou vteřinou :
	// (Efekty jako například doba léčení se dá přidávat pouze u předmětů typu Potion. 
	// tohle je předmět typu Item, a proto ho bude regenerovat do nekonečna) !!!
	Items::AddAttribute(md_potion, ATTRIBUTES::ATT_REGENERATION_H, 5);

	// Je lepší, než střední tak mu změníme i vzácnost :
	Items::SetRarity(md_potion, ITEM_RARITIES::RARITY_RARE);

	// Nastavíme aby šel prodat(25) za méně než ho koupit(100)
	Items::SetPrice(md_potion, 100, 25);

	// Jestliže jméno vzácnosti našeho předmětu se shoduje s jménem vzácnosti Rare:
	if (Items::GetRarity(md_potion) == Items::Name::Rarity(ITEM_RARITIES::RARITY_RARE)) {

									 // Zvýšíme kupní cenu o 900				 // Zvýšíme prodejní cenu o 75
		Items::SetPrice(md_potion, Items::GetBuyingPrice(md_potion) + 900, Items::GetSellingPrice(md_potion) + 75);
	}

	// Jestliže typ předmětu lektvaru je zbroj (což není) :
	if (Items::GetType(md_potion) == Items::Name::Type(ITEM_TYPES::ITEM_TYPE_ARMOR)) {

		// Tak mu přidáme i zbroj 15 %
		Items::AddAttribute(md_potion, ATTRIBUTES::ATT_PROTECTION, 15);
	}

	// Jestliže má atribut Regeneraci zdraví (což má) :
	if (Items::HasAttribute(md_potion, ATTRIBUTES::ATT_REGENERATION_H)) {

		// Tak mu jí odstraníme :
		Items::RemoveAttribute(md_potion, ATTRIBUTES::ATT_REGENERATION_H);

		// Tady nám to vyhodí chybu, protože nemá atribut regenerace many:
		Items::RemoveAttribute(md_potion, ATTRIBUTES::ATT_REGENERATION_M);
	}
	Items::Print(md_potion);
	/*
		[Debug] Nastavuji Predmetu jmenem sh_potion[Healing potion] kodove jmeno na md_potion
		[Debug] Nastavuji Predmetu jmenem md_potion[Healing potion] herni jmeno na Medium Healing potion
		[Debug] Nastavuji Predmetu jmenem md_potion[Medium Healing potion] attribut Healing na +25%
		[Debug] Nastavuji Predmetu jmenem md_potion[Medium Healing potion] attribut Health Regeneration na +5%
		[Debug] Nastavuji Predmetu jmenem md_potion[Medium Healing potion] raritu Rare
		[Debug] Nastavuji Predmetu jmenem md_potion[Medium Healing potion] kupni/prodejni cenu na: 100/25
		[Debug] Nastavuji Predmetu jmenem md_potion[Medium Healing potion] kupni/prodejni cenu na: 1000/100
		[Debug] Odstranuji Predmetu jmenem md_potion[Medium Healing potion] attribut Health Regeneration
		[Chyba] Predmet nema tento attribut Mana Regeneration
		-------- Predmet --------
		Codename: md_potion
		Ingame name: Medium Healing potion
		Rare
		Typ: Potion
		Price B:1000 S:100
		Healing - +25 %
		-------- Predmet --------
	*/
	return 0;
}
```
