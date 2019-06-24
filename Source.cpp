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
	std::string name;
	std::string howtoget;
	std::string rarity;

	Drop(std::string& n, std::string& how, std::string& r) : name(n), howtoget(how), rarity(r) { };
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

	//adddrop
	void addDrop(std::string name, std::string how, std::string rarity) {
		drops.emplace_back(name, how, rarity);
	}
};

class Database {
private:
	std::vector<Behemoth> list;			//list filled with all behemoths
public:
	void add(std::string name, std::string type, int rpower);
	void addDropTo(std::string nameOfBehe,std::string name, std::string how, std::string rarity);
	void getInfo(std::string& name);
};

void Database::add(std::string name, std::string type, int rpower)
{
	list.emplace_back(name, type, rpower);
}

void Database::addDropTo(std::string nameOfBehe, std::string name, std::string how, std::string rarity)
{
	for (int i = 0; i < int(list.size()); ++i) {
		if (list[i].getname() == nameOfBehe) {
			list[i].addDrop(name, how, rarity);
			return;
		}
	}
	std::cout << "***'" << nameOfBehe << "'was not found***";
	system("pause");
}

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

//****************************************************************************************************************************************************************************************

Database behemoths;

void loadDrops()
{
	behemoths.addDropTo("Rockfall Skarn", "Adamantine Scale", "Slay", "Rare");
	behemoths.addDropTo("Koshai", "Aether Thorn", "Slay", "Common");
	behemoths.addDropTo("Aether Charged Behemoths (Threat Level 8+)", "Aetheric Claw", "Limbs", "Rare");
	behemoths.addDropTo("Aether Charged Behemoth(Threat Level 8+)", "Aetheric Crownplate", "Head", "Rare");
	behemoths.addDropTo("Aether Charged Behemoth(Threat Level 8+)", "Aetheric Tail", "Tail", "Rare");
	behemoths.addDropTo("Riftstalker", "Apex Riftfang", "Head", "Common");
	behemoths.addDropTo("Valomyr", "Apocalypse Horn", "Horn", "Common");
	behemoths.addDropTo("Razorwing Kharabak(Heroic)", "Assassin Soul Shard", "Slay", "Epic");
	behemoths.addDropTo("Bloodsoul Shard", "An Epic drop from slaying a Bloodfire Embermane(Heroic).");
	behemoths.addDropTo("Boreus Hide", "A Common drop from slaying any Boreus.");
	behemoths.addDropTo("Bramblespur", "A Common drop from the Limbs of any Koshai.");
	behemoths.addDropTo("Browscale", "A Common drop from the Head of any Skarn.");
	behemoths.addDropTo("Burned Gillhide", "A Common drop from the Firesacs of any Charrogg");
	behemoths.addDropTo("Burned Hindscale", "A Common drop from the Leg of any Hellion");
	behemoths.addDropTo("Burning Tailspike", "A Common drop from the Tail of any Embermane.");
	behemoths.addDropTo("Capacitail", "A Common drop from the Tail of any Stormclaw.");
	behemoths.addDropTo("Cataclysm Shard", "An Epic drop from slaying any Rezakiri.");
	behemoths.addDropTo("Caudal Thorn", "A Common drop from the Tail of any Koshai.");
	behemoths.addDropTo("Charred Browplate", "A Common drop from the Head of any Hellion.");
	behemoths.addDropTo("Charred Tailplate", "A Common drop from the Tail of any Hellion.");
	behemoths.addDropTo("Charrogg Scale", "A Common drop from slaying any Charrogg.");
	behemoths.addDropTo("Chillclaw", "A Common drop from the Leg of any Skraev.");
	behemoths.addDropTo("Claw Shell Fragment", "A Common drop from the Limbs of any Kharabak.");
	behemoths.addDropTo("Conductive Antler", "A Common drop from the Antlers of any Stormclaw.");
	behemoths.addDropTo("Conductive Shockspine", "A Rare drop from slaying a Shockjaw Nayzaga.");
	behemoths.addDropTo("Corrupted Voidfeather", "A Rare drop from slaying any Shrowd.");
	behemoths.addDropTo("Cracked Biocrystal", "A Common drop from the Head of any Rezakiri.");
	behemoths.addDropTo("Dark Bladefeather", "A Common drop from the Wing of any Shrowd.");
	behemoths.addDropTo("Dark Tailfeather", "A Common drop from the Tail of any Shrowd.");
	behemoths.addDropTo("Darkbeak Fragment", "A Common drop from the Head of any Shrowd.");
	behemoths.addDropTo("Deadeye Spinehide", "A Rare drop from slaying a Deadeye Quillshot.");
	behemoths.addDropTo("Deadly Incisor", "A Common drop from the Head of any Kharabak.");
	behemoths.addDropTo("Deadly Ovipositor", "A Common drop from the Tail of any Kharabak.");
	behemoths.addDropTo("Dewspine", "A Common drop from the Leg of any Quillshot.");
	behemoths.addDropTo("Drask Hide", "A Common drop from slaying any Drask.");
	behemoths.addDropTo("Dreadfrost Shard", "An Epic drop from slaying a Dreadfrost Boreus(Heroic).");
	behemoths.addDropTo("Electroscale", "A Common drop from the Tail of any Drask.");
	behemoths.addDropTo("Elemental Clawgem", "A rare drop from the limbs of an Elemental Behemoth, broken within 2 minutes of combat(Threat Level 8 + ) .");
	behemoths.addDropTo("Elemental Furyplate", "A rare drop from the limbs of a Raging Elemental Behemoth(Threat Level 8 + ).");
	behemoths.addDropTo("Elemental Furytail", "A rare drop from the tail of a Raging Elemental Behemoth(Threat Level 8 + ).");
	behemoths.addDropTo("Elemental Furytooth", "A rare drop from the head of a Raging Elemental Behemoth(Threat Level 8 + ).");
	behemoths.addDropTo("Elemental Skullgem", "A rare drop from the head of an Elemental Behemoth, broken within 2 minutes of combat(Threat Level 8 + ).");
	behemoths.addDropTo("Elemental Tailgem", "A rare drop from the tail of an Elemental Behemoth, broken within 2 minutes of combat(Threat Level 8 + ).");
	behemoths.addDropTo("Emberhorn", "A Common drop from the Horn of any Embermane.");
	behemoths.addDropTo("Embermane Hide", "A Common drop from slaying any Embermane.");
	behemoths.addDropTo("Exoskeletal Plate", "A Common drop from the Limbs of any Rezakiri.");
	behemoths.addDropTo("Fractal Eyetooth", "A Common drop from the Head of any Drask.");
	behemoths.addDropTo("Fractal Hide", "A Rare drop from slaying any Valomyr.");
	behemoths.addDropTo("Frosted Tailplate", "A Common drop from the Tail of any Pangar.");
	behemoths.addDropTo("Frostmantle", "A Rare drop from slaying a Skraev.");
	behemoths.addDropTo("Frostsoul Shard", "An Epic drop from slaying a Frostback Pangar(Heroic).");
	behemoths.addDropTo("Frostwing Shardfeather", "A Common drop from the Wing of any Skraev.");
	behemoths.addDropTo("Frozen Hindplate", "A Common drop from the Leg of any Pangar.");
	behemoths.addDropTo("Furious Ragescale", "A Rare drop from slaying a Ragetail Gnasher.");
	behemoths.addDropTo("Galactic Shard", "An Epic drop from slaying a Valomyr(Heroic).");
	behemoths.addDropTo("Glinttooth", "A Common drop from the Head of any Stormclaw.");
	behemoths.addDropTo("Gnasher Hide", "A Common drop from slaying any Gnasher.");
	behemoths.addDropTo("Gnasher Shinplate", "A Common drop from the Leg of any Gnasher.");
	behemoths.addDropTo("Hellhide", "A Common drop from slaying any Hellion.");
	behemoths.addDropTo("Hellstone Shard", "An Epic drop from slaying a Scorchstone Hellion(Heroic).");
	behemoths.addDropTo("Hoof Chip", "A Common drop from the Leg of any Boreus.");
	behemoths.addDropTo("Horn Fragment", "A Common drop from the Head of any Boreus.");
	behemoths.addDropTo("Iceshatter Shard", "An Epic drop from slaying a Skraev.");
	behemoths.addDropTo("Icy Browplate", "A Common drop from the Head of any Pangar.");
	behemoths.addDropTo("Icy Frostback Scale", "A Rare drop from slaying a Frostback Pangar.");
	behemoths.addDropTo("Icy Hindscale", "A Common drop from the Tail of any Boreus.");
	behemoths.addDropTo("Impaler Shard", "An Epic drop from slaying a Deadeye Quillshot(Heroic).");
	behemoths.addDropTo("Jagged Sparkscale", "A Common drop from the Leg of any Drask.");
	behemoths.addDropTo("Jagged Tailspike", "A Common drop from the Tail of any Quillshot.");
	behemoths.addDropTo("Kharabak Chitin", "A Common drop from slaying any Kharabak.");
	behemoths.addDropTo("Lumbering Flamesoul Shard", "An Epic drop from slaying a Firebrand Charrogg(Heroic).");
	behemoths.addDropTo("Luminescent Chitin", "A Rare drop from slaying any Rezakiri.");
	behemoths.addDropTo("Lustrous Tailplate", "A Common drop from the Tail of any Rezakiri.");
	behemoths.addDropTo("Nayzaga Chitin", "A Common drop from slaying any Nayzaga.");
	behemoths.addDropTo("Neutral Clawgem", "A rare drop from the limbs of an Neutral Behemoth, broken within 2 minutes of combat(Threat Level 8 + ).");
	behemoths.addDropTo("Neutral Furyplate", "A rare drop from the limbs of a Raging Neutral Behemoth(Threat Level 8 + ).");
	behemoths.addDropTo("Neutral Furytail", "A rare drop from the tail of a Raging Neutral Behemoth(Threat Level 8 + ).");
	behemoths.addDropTo("Neutral Furytooth", "A rare drop from the head of a Raging Neutral Behemoth(Threat Level 8 + ).");
	behemoths.addDropTo("Neutral Skullgem", "A rare drop from the head of an Neutral Behemoth, broken within 2 minutes of combat(Threat Level 8 + ).");
	behemoths.addDropTo("Neutral Tailgem", "A rare drop from the tail of an Neutral Behemoth, broken within 2 minutes of combat(Threat Level 8 + ).");
	behemoths.addDropTo("Nightbringer Riftspike", "A Common drop from the Tail of any Riftstalker.");
	behemoths.addDropTo("Nightmare Shard", "An Epic drop from slaying a Shrowd(Heroic).");
	behemoths.addDropTo("Pangar Scale", "A Common drop from slaying any Pangar.");
	behemoths.addDropTo("Pristine Moonfeather", "A Rare drop from slaying a Moonreaver Shrike.");
	behemoths.addDropTo("Protean Fang", "A Common drop from the Head of any Valomyr.");
	behemoths.addDropTo("Psionic Scale", "A Rare drop from slaying a Dreadfrost Boreus.");
	behemoths.addDropTo("Quillshard", "A Common drop from the Quills of any Quillshot.");
	behemoths.addDropTo("Quillshot Hide", "A Common drop from slaying any Quillshot.");
	behemoths.addDropTo("Quillshot Tusk", "A Common drop from the Head of any Quillshot.");
	behemoths.addDropTo("Radiant Aethergem", "A Common drop from the Tailgem of any Rezakiri.");
	behemoths.addDropTo("Radiant Dewclaw", "A Common drop from the Leg of any Valomyr.");
	behemoths.addDropTo("Ragesoul Shard", "An Epic drop from slaying a Ragetail Gnasher(Heroic).");
	behemoths.addDropTo("Ragetooth", "A Common drop from the Head of any Gnasher.");
	behemoths.addDropTo("Razor Beak", "A Common drop from the Head of any Shrike.");
	behemoths.addDropTo("Rending Voidclaw", "A Common drop from the Leg of any Riftstalker.");
	behemoths.addDropTo("Rezakiri Chitin", "A Common drop from slaying any Rezakiri.");
	behemoths.addDropTo("Rifthide", "A Common drop from slaying any Riftstalker.");
	behemoths.addDropTo("Riftsoul Shard", "An Epic drop from slaying a Riftstalker(Heroic).");
	behemoths.addDropTo("Rockscale", "A Common drop from slaying any Skarn.");
	behemoths.addDropTo("Savage Hooktooth", "A Common drop from the Head of any Embermane.");
	behemoths.addDropTo("Scorched Rockhide", "A Common drop from the Leg of any Charrogg.");
	behemoths.addDropTo("Scorchscale", "A Rare drop from slaying a Scorchstone Hellion.");
	behemoths.addDropTo("Sharpened Slapper", "A Common drop from the Tail of any Gnasher.");
	behemoths.addDropTo("Shattered Frostbeak", "A Common drop from the Head of any Skraev.");
	behemoths.addDropTo("Shockheart Shard", "An Epic drop from slaying a Shockjaw Nayzaga(Heroic).");
	behemoths.addDropTo("Shocktooth", "A Common drop from the Head of any Nayzaga.");
	behemoths.addDropTo("Shrike Bladefeather", "A Common drop from the Wing of any Shrike.");
	behemoths.addDropTo("Shrike Tailfeather", "A Common drop from the Tail of any Shrike.");
	behemoths.addDropTo("Shrikedown", "A Common drop from the Leg of any Shrike.");
	behemoths.addDropTo("Skraev Feather", "A Common drop from slaying any Skraev.");
	behemoths.addDropTo("Skraev Tailfeather", "A Common drop from the Tail of any Skraev.");
	behemoths.addDropTo("Sleek Razorwing Chitin", "A Rare drop from slaying a Razorwing Kharabak.");
	behemoths.addDropTo("Smoked Dewclaw", "A Common drop from the Leg of any Embermane.");
	behemoths.addDropTo("Smoldering Bloodhide", "A Rare drop from slaying a Bloodfire Embermane.");
	behemoths.addDropTo("Smoldering Firebrand Scale", "A Rare drop from slaying a Firebrand Charrogg.");
	behemoths.addDropTo("Smoldering Horn", "A Common drop from the Head of any Charrogg.");
	behemoths.addDropTo("Smoldering Tailspike", "A Common drop from the Tail of any Charrogg.");
	behemoths.addDropTo("Sparkclaw", "A Common drop from the Limbs of any Nayzaga.");
	behemoths.addDropTo("Sparkspine", "A Common drop from the Tail of any Nayzaga.");
	behemoths.addDropTo("Splintered Antler", "A Common drop from the Antlers of any Koshai.");
	behemoths.addDropTo("Stone Fragments", "A Common drop from the Armor of any Skarn.");
	behemoths.addDropTo("Stoneheart Shard", "An Epic drop from slaying a Rockfall Skarn(Heroic).");
	behemoths.addDropTo("Stony Hide", "A Common drop from the Limbs of any Skarn.");
	behemoths.addDropTo("Stormclaw Hide", "A Common drop from slaying any Stormclaw.");
	behemoths.addDropTo("Stormheart Shard", "An Epic drop from slaying a Stormclaw.");
	behemoths.addDropTo("Thornsoul Shard", "An Epic drop from slaying a Koshai(Heroic).");
	behemoths.addDropTo("Thundering Scale", "A Rare drop from slaying a Drask.");
	behemoths.addDropTo("Thundersoul Shard", "An Epic drop from slaying a Drask.");
	behemoths.addDropTo("Torn Shrikefeather", "A Common drop from slaying any Shrike.");
	behemoths.addDropTo("Twisted Shadowspur", "A Common drop from the Leg of any Shrowd.");
	behemoths.addDropTo("Unstable Nullhide", "A Rare drop from slaying a Riftstalker.");
	behemoths.addDropTo("Unstable Tailspike", "A Common drop from the Tail of any Valomyr.");
	behemoths.addDropTo("Valomyr Hide", "A Common drop from slaying any Valomyr.");
	behemoths.addDropTo("Vinetooth", "A Common drop from the Head of any Koshai.");
	behemoths.addDropTo("Vital Thorn", "A Rare drop from slaying a Koshai.");
	behemoths.addDropTo("Volthoof", "A Common drop from the Limbs of any Stormclaw.");
	behemoths.addDropTo("Voltscale", "A Rare drop from slaying a Stormclaw.");
	behemoths.addDropTo("Windsoul Shard", "An Epic drop from slaying a Moonreaver Shrike(Heroic).");
	behemoths.addDropTo("Blaze Orb", "Obtained from Blaze Patrols and from blaze Behemoths.");
	behemoths.addDropTo("Frost Orb", "Obtained from Frost Patrols and from frost Behemoths.");
	behemoths.addDropTo("Neutral Orb", "Obtained from Neutral Patrols and from neutral Behemoths.");
	behemoths.addDropTo("Peerless Arcstone", "Obtained from Threat Level 17 + Patrols.");
	behemoths.addDropTo("Shining Arcstone", "Obtained from Heroic Patrols and from Behemoths rated Threat Level 13 - 16.");
	behemoths.addDropTo("Shock Orb", "Obtained from Shock Patrols and from shock Behemoths.");
	behemoths.addDropTo("Terra Orb", "Obtained from Terra Patrols and from terra Behemoths.");
}



void loadBehes()
{
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
	std::cout << "2. Search for Drop\n";
	std::cout << "3. Clear Screen\n";
	std::cout << "4. Exit\n";
}

int main()
{
	//load data for all behemoths
	std::cout << "Loading data... Please wait..." << std::endl;
	loadBehes();
	//loadDrops();			needs to be implemented
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
			case 2: {			//Search for a drop		NEEDS TO BE IMPLEMENTED?
				/*std::string inputName;
				std::cout << "What is the name of the Drop?" << std::endl << inputPrompt;
				flushStream();
				getline(std::cin, inputName);
				searchDrop(inputName);
				break;*/
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


