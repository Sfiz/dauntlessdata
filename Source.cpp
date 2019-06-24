#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include <forward_list>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<algorithm>

std::string inputPrompt = ">>";
//error handling
void error(std::string s)
{
	throw std::runtime_error(s);
}
//used to flush input stream, reset state and remove any characters in buffer
void flushStream()
{
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}


//***************************************************************************************************************************************************************************************************************


class Drop {
private:
	std::string name;
	std::string nameOfBehe;
	std::string howtoget;
	std::string rarity;
public:
	//constructs
	Drop(std::string n, std::string how) : nameOfBehe("NULL"), name(n), howtoget(how), rarity("NULL") { };		//for orbs / arcstones
	Drop(std::string nameBehe, std::string n, std::string how, std::string r) : nameOfBehe(nameBehe), name(n), howtoget(how), rarity(r) { };		//for behemoths

	//gets
	std::string getBeheName() { return nameOfBehe; }
	std::string getName() { return name; }
	std::string getHow() { return howtoget; }
	std::string getRarity() { return rarity; }
};


class Behemoth {
private:
	std::string name;
	std::string type;
	void assignElements() {
		if (type == "Blaze")
			weak = "Frost";
		else if (type == "Frost")
			weak = "Blaze";
		else if (type == "Shock")
			weak = "Terra";
		else if (type == "Terra")
			weak = "Shock";
		else if (type == "Neutral")
			weak = "None";
		else if (type == "Umbral")
			weak = "Radiant";
		else if (type == "Radiant")
			weak = "Umbral";
	}
	std::string strength;
	std::string weak;
	int recpower;
	std::vector<Drop> drops;

public:
	Behemoth(std::string& n, std::string& t, int& power) {				//default constructor
		name = n;
		type = t;
		if (t == "Neutral") strength = "None";
		else strength = t;
		recpower = power;
		assignElements();
	}

	//gets
	std::string getname() { return name; }
	std::string gettype() { return type; }
	std::string getstrength() { return strength; }
	std::string getweak() { return weak; }
	int getpower() { return recpower; }	
};

class Database {
private:
	std::vector<Behemoth> list;			//list filled with all behemoths
	std::vector<Drop> drops;		//all drops
public:
	void add(std::string name, std::string type, int rpower) { list.emplace_back(name, type, rpower); }		//for behemoths
	void addDrop(std::string name, std::string how) { drops.emplace_back(name, how); }			//for orbs / arcstones
	void addDrop(std::string nameOfBehe, std::string name, std::string how, std::string rarity) { drops.emplace_back(nameOfBehe, name, how, rarity); }	//for behemoth-specific drops
	void getInfo(std::string& name);	//defined below to keep class compact and simple
	void getDrops();
};

void Database::getInfo(std::string& n)
{
	bool found = false;
	for (Behemoth x : list) {
		if (x.getname().find(n) != std::string::npos) {
			std::cout << "\nName: " << x.getname() << "\nStrength: " << x.getstrength() << "\nWeakness: " << x.getweak() << "\nRecommended Power: " << x.getpower() << std::endl;
			found = true;
		}
	}
	//Behemoth name not found
	if(!found)
		std::cout << "No Behemoth with the name '" << n << "' was found." << std::endl;
}

void Database::getDrops()			//TESTING PURPOSES
{
	for (Drop x : drops) 
		std::cout << x.getBeheName() << "\t" << x.getName() << "\t" << x.getHow() << "\t" << x.getRarity() << std::endl;
}

//****************************************************************************************************************************************************************************************

Database behemoths;

void loadDrops()
{
	behemoths.addDrop("Rockfall Skarn", "Adamantine Scale", "Slay", "Rare");
	behemoths.addDrop("Koshai", "Aether Thorn", "Slay", "Common");
	behemoths.addDrop("Elemental Behemoth (Threat Level 8+)", "Aetheric Claw", "Limbs broken while Behemoth is aethercharged", "Rare");
	behemoths.addDrop("Elemental Behemoth (Threat Level 8+)", "Aetheric Crownplate", "Head broken while Behemoth is aethercharged", "Rare");
	behemoths.addDrop("Elemental Behemoth (Threat Level 8+)", "Aetheric Tail", "Tail broken while Behemoth is aethercharged", "Rare");
	behemoths.addDrop("Riftstalker", "Apex Riftfang", "Head", "Common");
	behemoths.addDrop("Valomyr", "Apocalypse Horn", "Horn", "Common");
	behemoths.addDrop("Razorwing Kharaback (Heroic)", "Assassin Soul Shard", "Slay", "Epic");
	behemoths.addDrop("Bloodfire Embermane (Heroic)", "Bloodsoul Shard", "Slay", "Epic");
	behemoths.addDrop("Boreus", "Boreus Hide", "Slay", "Common");
	behemoths.addDrop("Koshai", "Bramblespur", "Limbs", "Common");
	behemoths.addDrop("Skarn", "Browscale", "Head", "Common");
	behemoths.addDrop("Charrogg", "Burned Gillhide", "Firesacs", "Common");
	behemoths.addDrop("Hellion", "Burned Hindscale", "Leg", "Common");
	behemoths.addDrop("Embermane", "Burning Tailspike", "Tail", "Common");
	behemoths.addDrop("Stormclaw", "Capacitail", "Tail", "Common");
	behemoths.addDrop("Rezakiri", "Cataclysm Shard", "Slay", "Epic");
	behemoths.addDrop("Koshai", "Caudal Thorn", "Tail", "Common");
	behemoths.addDrop("Hellion", "Charred Browplate", "Head", "Common");
	behemoths.addDrop("Hellion", "Charred Tailplate", "Tail", "Common");
	behemoths.addDrop("Charrogg", "Charrogg Scale", "Slay", "Common");
	behemoths.addDrop("Skraev", "Chillclaw", "Leg", "Common");
	behemoths.addDrop("Kharabak", "Claw Shell Fragment", "Limbs", "Common");
	behemoths.addDrop("Stormclaw", "Conductive Antler", "Antlers", "Common");
	behemoths.addDrop("Shockjaw Nayzaga", "Conductive Shockspine", "Slay", "Rare");
	behemoths.addDrop("Shrowd", "Corrupted Voidfeather", "Slay", "Rare");
	behemoths.addDrop("Rezakiri", "Cracked Biocrystal", "Head", "Common");
	behemoths.addDrop("Shrowd", "Dark Bladefeather", "Wing", "Common");
	behemoths.addDrop("Shrowd", "Dark Tailfeather", "Tail", "Common");
	behemoths.addDrop("Shrowd", "Darkbeak Fragment", "Head", "Common");
	behemoths.addDrop("Deadeye Quillshot", "Deadeye Spinehide", "Slay", "Rare");
	behemoths.addDrop("Kharabak", "Deadly Incisor", "Head", "Common");
	behemoths.addDrop("Kharabak", "Deadly Ovipositor", "Tail", "Common");
	behemoths.addDrop("Quillshot", "Dewspine", "Leg", "Common");
	behemoths.addDrop("Drask", "Drask Hide", "Slay", "Common");
	behemoths.addDrop("Dreadfrost Boreus (Heroic)", "Dreadfrost Shard", "Slay", "Epic");
	behemoths.addDrop("Drask", "Electroscale", "Tail", "Common");
	behemoths.addDrop("Elemental Behemoth (Threat Level 8+)", "Elemental Clawgem", "Limbs broken within 2 minutes of combat", "Rare");
	behemoths.addDrop("Elemental Behemoth (Threat Level 8+)", "Elemental Furyplate", "Limbs while Behemoth is enraged", "Rare");
	behemoths.addDrop("Elemental Behemoth (Threat Level 8+)", "Elemental Furytail", "Tail while Behemoth is enraged", "Rare");
	behemoths.addDrop("Elemental Behemoth (Threat Level 8+)", "Elemental Furytooth", "Head while Behemoth is enraged", "Rare");
	behemoths.addDrop("Elemental Behemoth (Threat Level 8+)", "Elemental Skullgem", "Head broken within 2 minutes of combat", "Rare");
	behemoths.addDrop("Elemental Behemoth (Threat Level 8+)", "Elemental Tailgem", "Tail broken withtin 2 minutes of combat", "Rare");
	behemoths.addDrop("Embermane", "Emberhorn", "Horn", "Common");
	behemoths.addDrop("Embermane", "Embermane Hide", "Slay", "Common");
	behemoths.addDrop("Rezakiri", "Exoskeletal Plate", "Limbs", "Common");
	behemoths.addDrop("Drask", "Fractal Eyetooth", "Head", "Common");
	behemoths.addDrop("Valomyr", "Fractal Hide", "Slay", "Rare");
	behemoths.addDrop("Pangar", "Frosted Tailplate", "Tail", "Common");
	behemoths.addDrop("Skraev", "Frostmantle", "Slay", "Rare");
	behemoths.addDrop("Frostback Pangar (Heroic)", "Frostsoul Shard", "Slay", "Epic");
	behemoths.addDrop("Skraev", "Frostwing Shardfeather", "Wing", "Common");
	behemoths.addDrop("Pangar", "Frozen Hindplate", "Leg", "Common");
	behemoths.addDrop("Ragetail Gnasher", "Furious Ragescale", "Slay", "Rare");
	behemoths.addDrop("Valomyr (Heroic)", "Galactic Shard", "Slay", "Epic");
	behemoths.addDrop("Stormclaw", "Glinttooth", "Head", "Common");
	behemoths.addDrop("Gnasher", "Gnasher Hide", "Slay", "Common");
	behemoths.addDrop("Gnasher", "Gnasher Shinplate", "Leg", "Common");
	behemoths.addDrop("Hellion", "Hellhide", "Slay", "Common");
	behemoths.addDrop("Scorchstone Hellion(Heroic)", "Hellstone Shard", "Slay", "Epic");
	behemoths.addDrop("Boreus", "Hoof Chip", "Leg", "Common");
	behemoths.addDrop("Boreus", "Horn Fragment", "Head", "Common");
	behemoths.addDrop("Skraev", "Iceshatter Shard", "Slay", "Epic");
	behemoths.addDrop("Pangar", "Icy Browplate", "Head", "Common");
	behemoths.addDrop("Frostback Pangar", "Icy Frostback Scale", "Slay", "Rare");
	behemoths.addDrop("Boreus", "Icy Hindscale", "Tail", "Common");
	behemoths.addDrop("Deadeye Quillshot (Heroic)", "Impaler Shard", "Slay", "Epic");
	behemoths.addDrop("Drask", "Jagged Sparkscale", "Leg", "Common");
	behemoths.addDrop("Quillshot", "Jagged Tailspike", "tail", "Common");
	behemoths.addDrop("Kharabak", "Kharabak Chitin", "Slay", "Common");
	behemoths.addDrop("Firebrand Charrogg (Heroic)", "Lumbering Flamesoul Shard", "Slay", "Epic");
	behemoths.addDrop("Rezakiri", "Luminescent Chitin", "Slay", "Rare");
	behemoths.addDrop("Rezakiri", "Lustrous Tailplate", "Tail", "Common");
	behemoths.addDrop("Nayzaga", "Nayzaga Chitin", "Slay", "Common");
	behemoths.addDrop("Neutral Behemoth (Threat Level 8+)", "Neutral Clawgem", "Limbs broken within 2 minutes of combat", "Rare");
	behemoths.addDrop("Neutral Behemoth (Threat Level 8+)", "Neutral Furyplate", "Limbs while Behemoth is enraged", "Rare");
	behemoths.addDrop("Neutral Behemoth (Threat Level 8+)", "Neutral Furytail", "Tail while Behemoth is enraged", "Rare");
	behemoths.addDrop("Neutral Behemoth (Threat Level 8+)", "Neutral Furytooth", "Head while Behemoth is enraged", "Rare");
	behemoths.addDrop("Neutral Behemoth (Threat Level 8+)", "Neutral Skullgem", "Head broken within 2 minutes of combat", "Rare");
	behemoths.addDrop("Neutral Behemoth (Threat Level 8+)", "Neutral Tailgem", "Tail broken within 2 minutes of combat", "Rare");
	behemoths.addDrop("Riftstalker", "Nightbringer Riftspike", "Tail", "Common");
	behemoths.addDrop("Shrowd (Heroic)", "Nightmare Shard", "Slay", "Epic");
	behemoths.addDrop("Pangar", "Pangar Scale", "Slay", "Common");
	behemoths.addDrop("Moonreaver Shrike", "Pristine Moonfeather", "Slay", "Rare");
	behemoths.addDrop("Valomyr", "Protean Fang", "Head", "Common");
	behemoths.addDrop("Dreadfrost Boreus", "Psionic Scale", "Slay", "Rare");
	behemoths.addDrop("Quillshot", "Quillshard", "Quills", "Common");
	behemoths.addDrop("Quillshot", "Quillshot Hide", "Slay", "Common");
	behemoths.addDrop("Quillshot", "Quillshot Tusk", "Head", "Common");
	behemoths.addDrop("Rezakiri", "Radiant Aethergem", "Tailgem", "Common");
	behemoths.addDrop("Valomyr", "Radiant Dewclaw", "Leg", "Common");
	behemoths.addDrop("Ragetail Gnasher(Heroic)", "Ragesoul Shard", "Slay", "Epic");
	behemoths.addDrop("Gnasher", "Ragetooth", "Head", "Common");
	behemoths.addDrop("Shrike", "Razor Beak", "Head", "Common");
	behemoths.addDrop("Riftstalker", "Rending Voidclaw", "Leg", "Common");
	behemoths.addDrop("Rezakiri", "Rezakiri Chitin", "Slay", "Common");
	behemoths.addDrop("Riftstalker", "Rifthide", "Slay", "Common");
	behemoths.addDrop("Riftstalker (Heroic)", "Riftsoul Shard", "Slay", "Epic");
	behemoths.addDrop("Skarn", "Rockscale", "Slay", "Common");
	behemoths.addDrop("Embermane", "Savage Hooktooth", "Head", "Common");
	behemoths.addDrop("Charrogg", "Scorched Rockhide", "Leg", "Common");
	behemoths.addDrop("Scorchstone Hellion", "Scorchscale", "Slay", "Rare");
	behemoths.addDrop("Gnasher", "Sharpened Slapper", "Tail", "Common");
	behemoths.addDrop("Skraev", "Shattered Frostbeak", "Head", "Common");
	behemoths.addDrop("Shockjaw Nayzaga (Heroic)", "Shockheart Shard", "Slay", "Epic");
	behemoths.addDrop("Nayzaga", "Shocktooth", "Head", "Common");
	behemoths.addDrop("Shrike", "Shrike Bladefeather", "Wing", "Common");
	behemoths.addDrop("Shrike", "Shrike Tailfeather", "Tail", "Common");
	behemoths.addDrop("Shrike", "Shrikedown", "Leg", "Common");
	behemoths.addDrop("Skraev", "Skraev Feather", "Slay", "Common");
	behemoths.addDrop("Skraev", "Skraev Tailfeather", "Tail", "Common");
	behemoths.addDrop("Razorwing Kharabak", "Sleek Razorwing Chitin", "Slay", "Rare");
	behemoths.addDrop("Embermane", "Smoked Dewclaw", "Leg", "Common");
	behemoths.addDrop("Bloodfire Embermane", "Smoldering Bloodhide", "Slay", "Rare");
	behemoths.addDrop("Firebrand Charrogg", "Smoldering Firebrand Scale", "Slay", "Rare");
	behemoths.addDrop("Charrogg", "Smoldering Horn", "Head", "Common");
	behemoths.addDrop("Charrogg", "Smoldering Tailspike", "Tail", "Common");
	behemoths.addDrop("Nayzaga", "Sparkclaw", "Limbs", "Common");
	behemoths.addDrop("Nayzaga", "Sparkspine", "Tail", "Common");
	behemoths.addDrop("Koshai", "Splintered Antler", "Antlers", "Common");
	behemoths.addDrop("Skarn", "Stone Fragments", "Armor", "Common");
	behemoths.addDrop("Rockfall Skarn (Heroic)", "Stoneheart Shard", "Slay", "Epic");
	behemoths.addDrop("Skarn", "Stony Hide", "Limbs", "Common");
	behemoths.addDrop("Stormclaw", "Stormclaw Hide", "Slay", "Common");
	behemoths.addDrop("Stormclaw", "Stormheart Shard", "Slay", "Epic");
	behemoths.addDrop("Koshai (Heroic)", "Thornsoul Shard", "Slay", "Epic");
	behemoths.addDrop("Drask", "Thundering Scale", "Slay", "Rare");
	behemoths.addDrop("Drask", "Thundersoul Shard", "Slay", "Epic");
	behemoths.addDrop("Shrike", "Torn Shrikefeather", "Slay", "Common");
	behemoths.addDrop("Shrowd", "Twisted Shadowspur", "Leg", "Common");
	behemoths.addDrop("Riftstalker", "Unstable Nullhide", "Slay", "Rare");
	behemoths.addDrop("Valomyr", "Unstable Tailspike", "Tail", "Common");
	behemoths.addDrop("Valomyr", "Valomyr Hide", "Slay", "Common");
	behemoths.addDrop("Koshai", "Vinetooth", "Head", "Common");
	behemoths.addDrop("Koshai", "Vital Thorn", "Slay", "Rare");
	behemoths.addDrop("Stormclaw", "Volthoof", "Limbs", "Common");
	behemoths.addDrop("Stormclaw", "Voltscale", "Slay", "Rare");
	behemoths.addDrop("Shrike (Heroic)", "Windsoul Shard", "Slay", "Epic");

	//orbs and arcstones, seperate thing
	behemoths.addDrop("Blaze Orb", "Blaze Patrols and Blaze Behemoths");
	behemoths.addDrop("Frost Orb", "Frost Patrols and Frost Behemoths");
	behemoths.addDrop("Neutral Orb", "Neutral Patrols and Neutral Behemoths");
	behemoths.addDrop("Peerless Arcstone", "Threat Level 17 + Patrols");
	behemoths.addDrop("Shining Arcstone", "Heroic Patrols and Behemoths rated Threat Level 13 - 16");
	behemoths.addDrop("Shock Orb", "Shock Patrols and Shock Behemoths");
	behemoths.addDrop("Terra Orb", "Terra Patrols and Terra Behemoths");
}

void loadBehes()
{
	//Elemental Behemoths / Neutral Behemoths (just for adding drops to them)
	behemoths.add("Neutral Behemoth (Threat Level 8+)", "Neutral", 300);
	behemoths.add("Elemental Behemoth (Threat Level 8+)", "Any Element", 300);

	//Charrogg
	behemoths.add("Charrogg", "Blaze", 150);
	//Firebrand Charrogg
	behemoths.add("Firebrand Charrogg", "Blaze", 300);
	behemoths.add("Firebrand Charrogg (Heroic)", "Blaze", 425);

	//Embermane
	behemoths.add("Embermane", "Blaze", 200);
	//Bloodfire Embermane
	behemoths.add("Bloodfire Embermane", "Blaze", 350);
	behemoths.add("Bloodfire Embermane (Heroic)", "Blaze", 475);

	//Hellion
	behemoths.add("Hellion", "Blaze", 275);
	//Scorchstone Hellion
	behemoths.add("Scorchstone Hellion", "Blaze", 400);
	behemoths.add("Scorchstone Hellion (Heroic)", "Blaze", 500);

	//Boreus
	behemoths.add("Boreus", "Frost", 250);
	//Dreadfrost Boreus
	behemoths.add("Dreadfrost Boreus", "Frost", 325);
	behemoths.add("Dreadfrost Boreus (Heroic)", "Frost", 475);

	//Pangar
	behemoths.add("Pangar", "Frost", 275);
	//Frostback Pangar
	behemoths.add("Frostback Pangar", "Frost", 375);
	behemoths.add("Frostback Pangar (Heroic)", "Frost", 475);

	//Skraev
	behemoths.add("Skraev", "Frost", 150);

	//Drask
	behemoths.add("Drask", "Shock", 275);

	//Nayzaga
	behemoths.add("Nayzaga", "Shock", 200);
	//Shockjaw Nayzaga
	behemoths.add("Shockjaw Nayzaga", "Shock", 375);
	behemoths.add("Shockjaw Nayzaga (Heroic)", "Shock", 475);

	//Stormclaw
	behemoths.add("Stormclaw", "Shock", 250);

	//Kharabak
	behemoths.add("Kharabak", "Terra", 250);
	//Razorwing Kharabak
	behemoths.add("Razorwing Kharabak", "Terra", 350);
	behemoths.add("Razorwing Kharabak (Heroic)", "Terra", 450);

	//Koshai
	behemoths.add("Koshai", "Terra", 350);
	behemoths.add("Koshai (Heroic)", "Terra", 550);

	//Skarn
	behemoths.add("Skarn", "Terra", 100);
	//Rockfall Skarn
	behemoths.add("Rockfall Skarn", "Terra", 300);
	behemoths.add("Rockfall Skarn (Heroic)", "Terra", 425);

	//Gnasher
	behemoths.add("Gnasher", "Neutral", 100);
	//Ragetail Gnasher
	behemoths.add("Ragetail Gnasher", "Neutral", 325);
	behemoths.add("Ragetail Gnasher (Heroic)", "Neutral", 425);

	//Quillshot
	behemoths.add("Quillshot", "Neutral", 200);
	//Deadeye Quillshot
	behemoths.add("Deadeye Quillshot", "Neutral", 400);
	behemoths.add("Deadeye Quillshot (Heroic)", "Neutral", 450);

	//Shrike
	behemoths.add("Shrike", "Neutral", 150);
	//Moonreaver Shrike
	behemoths.add("Moonreaver Shrike", "Neutral", 325);
	behemoths.add("Moonreaver Shrike (Heroic)", "Neutral", 450);

	//Valomyr
	behemoths.add("Valomyr", "Radiant", 300);
	behemoths.add("Valomyr (Heroic)", "Radiant", 500);

	//Rezakiri
	behemoths.add("Rezakiri", "Radiant", 550);

	//Riftstalker 
	behemoths.add("Riftstalker", "Umbral", 325);
	behemoths.add("Riftstalker (Heroic)", "Umbral", 500);

	//Shrowd
	behemoths.add("Shrowd", "Umbral", 550);
}

void printMenu()
{
	std::cout << "1. Search for Behemoth\n";
	std::cout << "2. Display drops (TESTING PURPOSES)\n";
	std::cout << "3. Clear Screen\n";
	std::cout << "4. Exit\n";
}

int main()
{
	//load data for all behemoths
	std::cout << "Loading data... Please wait..." << std::endl;
	loadBehes();
	loadDrops();
	system("cls");

	printMenu();
	int index;

	while (true) {
		std::cout << inputPrompt;
		
		try {
			std::cin >> index;
			if (index == 0) error("Invalid index.");	//if letters are given instead of an integer, basically more error handling

			switch (index)
			{
			case 1: {			//Search for a behemoth
				std::string inputName;
				std::cout << "What is the name of the Behemoth?" << std::endl << inputPrompt;
				flushStream();
				getline(std::cin, inputName);
				behemoths.getInfo(inputName);
				break;
			}
			case 2: {			//testing purposes
				behemoths.getDrops();
				break;
			}
			case 3: {			//Clear screen
				system("cls");
				printMenu();
				break;
			}
			case 4: {			//Exit
				return 1;
			}
			default:
				error("Invalid index.");
				break;
			}
		}
		catch (std::runtime_error& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			flushStream();
		}	

		std::cout << std::endl;		//just for spacing
	}
}


