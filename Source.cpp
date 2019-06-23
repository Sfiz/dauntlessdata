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

class Drop {
public:
	std::string name;
	std::string desc;

	Drop(std::string n, std::string d) : name(n), desc(d) { };			//default construct
};

class Behemoth {
public:
	//DATA MEMBERS
	std::string name;
	std::string element;
	int threatLevel;
	int threatLevel_h = -1;		//_h is for heroic, only certain behemoths have heroic version, this will be set to -1 if it is not a thing
	int recPower;
	int recPower_h = -1;		//read above ^^^

	//FUNCTIONS
	void printInfo();								//defined below class 

	//CONSTRUCTORS
	Behemoth(std::string n, std::string ele, int threat, int power) : name(n), element(ele), threatLevel(threat), recPower(power) { }; //default constructor
	
	Behemoth(std::string n, std::string ele, int threat, int power, int threat_h, int power_h) {									  //additional constructor for heroic
		name = n;
		element = ele; 
		threatLevel = threat; 
		recPower = power;
		threatLevel_h = threat_h;
		recPower_h = power_h;
	};
};

void Behemoth::printInfo()
{
	//heroic check
	bool heroicVersion = false;
	if (threatLevel_h != -1) heroicVersion = true;

	//information of behemoth
	std::cout << std::endl;
	std::cout << "***INFORMATION***" << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Element: " << element << std::endl;
	std::cout << "Threat Level: " << threatLevel;
	if (heroicVersion) std::cout << " / " << threatLevel_h << " (Heroic)" << std::endl;
	else std::cout << std::endl;
	std::cout << "Recommended Power: " << recPower;
	if (heroicVersion) std::cout << " / " << recPower_h << " (Heroic)" << std::endl;
	else std::cout << std::endl;
}

class Database {
public:
	std::vector<Behemoth> behemoths;
	std::vector<Drop> drops;
};

Database database;

//if new content is added for drops just add in function below
void loadDrops()
{
	database.drops.emplace_back("Adamantine Scale", "A Rare drop from slaying a Rockfall Skarn.");
	database.drops.emplace_back("Aether Thorn", "A Common drop from slaying any Koshai.");
	database.drops.emplace_back("Aetheric Claw", "A rare drop from the limbs of an Aether Charged Behemoth(Threat Level 8 + ).");
	database.drops.emplace_back("Aetheric Crownplate", "A rare drop from the head of an Aether Charged Behemoth(Threat Level 8 + ).");
	database.drops.emplace_back("Aetheric Tail", "A rare drop from the tail of an Aether Charged Behemoth(Threat Level 8 + ).");
	database.drops.emplace_back("Apex Riftfang", "A Common drop from the Head of any Riftstalker.");
	database.drops.emplace_back("Apocalypse Horn", "A Common drop from the Horns of any Valomyr.");
	database.drops.emplace_back("Assassin Soul Shard", "An Epic drop from slaying a Razorwing Kharabak(Heroic).");
	database.drops.emplace_back("Bloodsoul Shard", "An Epic drop from slaying a Bloodfire Embermane(Heroic).");
	database.drops.emplace_back("Boreus Hide", "A Common drop from slaying any Boreus.");
	database.drops.emplace_back("Bramblespur", "A Common drop from the Limbs of any Koshai.");
	database.drops.emplace_back("Browscale", "A Common drop from the Head of any Skarn.");
	database.drops.emplace_back("Burned Gillhide", "A Common drop from the Firesacs of any Charrogg");
	database.drops.emplace_back("Burned Hindscale", "A Common drop from the Leg of any Hellion");
	database.drops.emplace_back("Burning Tailspike", "A Common drop from the Tail of any Embermane.");
	database.drops.emplace_back("Capacitail", "A Common drop from the Tail of any Stormclaw.");
	database.drops.emplace_back("Cataclysm Shard", "An Epic drop from slaying any Rezakiri.");
	database.drops.emplace_back("Caudal Thorn", "A Common drop from the Tail of any Koshai.");
	database.drops.emplace_back("Charred Browplate", "A Common drop from the Head of any Hellion.");
	database.drops.emplace_back("Charred Tailplate", "A Common drop from the Tail of any Hellion.");
	database.drops.emplace_back("Charrogg Scale", "A Common drop from slaying any Charrogg.");
	database.drops.emplace_back("Chillclaw", "A Common drop from the Leg of any Skraev.");
	database.drops.emplace_back("Claw Shell Fragment", "A Common drop from the Limbs of any Kharabak.");
	database.drops.emplace_back("Conductive Antler", "A Common drop from the Antlers of any Stormclaw.");
	database.drops.emplace_back("Conductive Shockspine", "A Rare drop from slaying a Shockjaw Nayzaga.");
	database.drops.emplace_back("Corrupted Voidfeather", "A Rare drop from slaying any Shrowd.");
	database.drops.emplace_back("Cracked Biocrystal", "A Common drop from the Head of any Rezakiri.");
	database.drops.emplace_back("Dark Bladefeather", "A Common drop from the Wing of any Shrowd.");
	database.drops.emplace_back("Dark Tailfeather", "A Common drop from the Tail of any Shrowd.");
	database.drops.emplace_back("Darkbeak Fragment", "A Common drop from the Head of any Shrowd.");
	database.drops.emplace_back("Deadeye Spinehide", "A Rare drop from slaying a Deadeye Quillshot.");
	database.drops.emplace_back("Deadly Incisor", "A Common drop from the Head of any Kharabak.");
	database.drops.emplace_back("Deadly Ovipositor", "A Common drop from the Tail of any Kharabak.");
	database.drops.emplace_back("Dewspine", "A Common drop from the Leg of any Quillshot.");
	database.drops.emplace_back("Drask Hide", "A Common drop from slaying any Drask.");
	database.drops.emplace_back("Dreadfrost Shard", "An Epic drop from slaying a Dreadfrost Boreus(Heroic).");
	database.drops.emplace_back("Electroscale", "A Common drop from the Tail of any Drask.");
	database.drops.emplace_back("Elemental Clawgem", "A rare drop from the limbs of an Elemental Behemoth, broken within 2 minutes of combat(Threat Level 8 + ) .");
	database.drops.emplace_back("Elemental Furyplate", "A rare drop from the limbs of a Raging Elemental Behemoth(Threat Level 8 + ).");
	database.drops.emplace_back("Elemental Furytail", "A rare drop from the tail of a Raging Elemental Behemoth(Threat Level 8 + ).");
	database.drops.emplace_back("Elemental Furytooth", "A rare drop from the head of a Raging Elemental Behemoth(Threat Level 8 + ).");
	database.drops.emplace_back("Elemental Skullgem", "A rare drop from the head of an Elemental Behemoth, broken within 2 minutes of combat(Threat Level 8 + ).");
	database.drops.emplace_back("Elemental Tailgem", "A rare drop from the tail of an Elemental Behemoth, broken within 2 minutes of combat(Threat Level 8 + ).");
	database.drops.emplace_back("Emberhorn", "A Common drop from the Horn of any Embermane.");
	database.drops.emplace_back("Embermane Hide", "A Common drop from slaying any Embermane.");
	database.drops.emplace_back("Exoskeletal Plate", "A Common drop from the Limbs of any Rezakiri.");
	database.drops.emplace_back("Fractal Eyetooth", "A Common drop from the Head of any Drask.");
	database.drops.emplace_back("Fractal Hide", "A Rare drop from slaying any Valomyr.");
	database.drops.emplace_back("Frosted Tailplate", "A Common drop from the Tail of any Pangar.");
	database.drops.emplace_back("Frostmantle", "A Rare drop from slaying a Skraev.");
	database.drops.emplace_back("Frostsoul Shard", "An Epic drop from slaying a Frostback Pangar(Heroic).");
	database.drops.emplace_back("Frostwing Shardfeather", "A Common drop from the Wing of any Skraev.");
	database.drops.emplace_back("Frozen Hindplate", "A Common drop from the Leg of any Pangar.");
	database.drops.emplace_back("Furious Ragescale", "A Rare drop from slaying a Ragetail Gnasher.");
	database.drops.emplace_back("Galactic Shard", "An Epic drop from slaying a Valomyr(Heroic).");
	database.drops.emplace_back("Glinttooth", "A Common drop from the Head of any Stormclaw.");
	database.drops.emplace_back("Gnasher Hide", "A Common drop from slaying any Gnasher.");
	database.drops.emplace_back("Gnasher Shinplate", "A Common drop from the Leg of any Gnasher.");
	database.drops.emplace_back("Hellhide", "A Common drop from slaying any Hellion.");
	database.drops.emplace_back("Hellstone Shard", "An Epic drop from slaying a Scorchstone Hellion(Heroic).");
	database.drops.emplace_back("Hoof Chip", "A Common drop from the Leg of any Boreus.");
	database.drops.emplace_back("Horn Fragment", "A Common drop from the Head of any Boreus.");
	database.drops.emplace_back("Iceshatter Shard", "An Epic drop from slaying a Skraev.");
	database.drops.emplace_back("Icy Browplate", "A Common drop from the Head of any Pangar.");
	database.drops.emplace_back("Icy Frostback Scale", "A Rare drop from slaying a Frostback Pangar.");
	database.drops.emplace_back("Icy Hindscale", "A Common drop from the Tail of any Boreus.");
	database.drops.emplace_back("Impaler Shard", "An Epic drop from slaying a Deadeye Quillshot(Heroic).");
	database.drops.emplace_back("Jagged Sparkscale", "A Common drop from the Leg of any Drask.");
	database.drops.emplace_back("Jagged Tailspike", "A Common drop from the Tail of any Quillshot.");
	database.drops.emplace_back("Kharabak Chitin", "A Common drop from slaying any Kharabak.");
	database.drops.emplace_back("Lumbering Flamesoul Shard", "An Epic drop from slaying a Firebrand Charrogg(Heroic).");
	database.drops.emplace_back("Luminescent Chitin", "A Rare drop from slaying any Rezakiri.");
	database.drops.emplace_back("Lustrous Tailplate", "A Common drop from the Tail of any Rezakiri.");
	database.drops.emplace_back("Nayzaga Chitin", "A Common drop from slaying any Nayzaga.");
	database.drops.emplace_back("Neutral Clawgem", "A rare drop from the limbs of an Neutral Behemoth, broken within 2 minutes of combat(Threat Level 8 + ).");
	database.drops.emplace_back("Neutral Furyplate", "A rare drop from the limbs of a Raging Neutral Behemoth(Threat Level 8 + ).");
	database.drops.emplace_back("Neutral Furytail", "A rare drop from the tail of a Raging Neutral Behemoth(Threat Level 8 + ).");
	database.drops.emplace_back("Neutral Furytooth", "A rare drop from the head of a Raging Neutral Behemoth(Threat Level 8 + ).");
	database.drops.emplace_back("Neutral Skullgem", "A rare drop from the head of an Neutral Behemoth, broken within 2 minutes of combat(Threat Level 8 + ).");
	database.drops.emplace_back("Neutral Tailgem", "A rare drop from the tail of an Neutral Behemoth, broken within 2 minutes of combat(Threat Level 8 + ).");
	database.drops.emplace_back("Nightbringer Riftspike", "A Common drop from the Tail of any Riftstalker.");
	database.drops.emplace_back("Nightmare Shard", "An Epic drop from slaying a Shrowd(Heroic).");
	database.drops.emplace_back("Pangar Scale", "A Common drop from slaying any Pangar.");
	database.drops.emplace_back("Pristine Moonfeather", "A Rare drop from slaying a Moonreaver Shrike.");
	database.drops.emplace_back("Protean Fang", "A Common drop from the Head of any Valomyr.");
	database.drops.emplace_back("Psionic Scale", "A Rare drop from slaying a Dreadfrost Boreus.");
	database.drops.emplace_back("Quillshard", "A Common drop from the Quills of any Quillshot.");
	database.drops.emplace_back("Quillshot Hide", "A Common drop from slaying any Quillshot.");
	database.drops.emplace_back("Quillshot Tusk", "A Common drop from the Head of any Quillshot.");
	database.drops.emplace_back("Radiant Aethergem", "A Common drop from the Tailgem of any Rezakiri.");
	database.drops.emplace_back("Radiant Dewclaw", "A Common drop from the Leg of any Valomyr.");
	database.drops.emplace_back("Ragesoul Shard", "An Epic drop from slaying a Ragetail Gnasher(Heroic).");
	database.drops.emplace_back("Ragetooth", "A Common drop from the Head of any Gnasher.");
	database.drops.emplace_back("Razor Beak", "A Common drop from the Head of any Shrike.");
	database.drops.emplace_back("Rending Voidclaw", "A Common drop from the Leg of any Riftstalker.");
	database.drops.emplace_back("Rezakiri Chitin", "A Common drop from slaying any Rezakiri.");
	database.drops.emplace_back("Rifthide", "A Common drop from slaying any Riftstalker.");
	database.drops.emplace_back("Riftsoul Shard", "An Epic drop from slaying a Riftstalker(Heroic).");
	database.drops.emplace_back("Rockscale", "A Common drop from slaying any Skarn.");
	database.drops.emplace_back("Savage Hooktooth", "A Common drop from the Head of any Embermane.");
	database.drops.emplace_back("Scorched Rockhide", "A Common drop from the Leg of any Charrogg.");
	database.drops.emplace_back("Scorchscale", "A Rare drop from slaying a Scorchstone Hellion.");
	database.drops.emplace_back("Sharpened Slapper", "A Common drop from the Tail of any Gnasher.");
	database.drops.emplace_back("Shattered Frostbeak", "A Common drop from the Head of any Skraev.");
	database.drops.emplace_back("Shockheart Shard", "An Epic drop from slaying a Shockjaw Nayzaga(Heroic).");
	database.drops.emplace_back("Shocktooth", "A Common drop from the Head of any Nayzaga.");
	database.drops.emplace_back("Shrike Bladefeather", "A Common drop from the Wing of any Shrike.");
	database.drops.emplace_back("Shrike Tailfeather", "A Common drop from the Tail of any Shrike.");
	database.drops.emplace_back("Shrikedown", "A Common drop from the Leg of any Shrike.");
	database.drops.emplace_back("Skraev Feather", "A Common drop from slaying any Skraev.");
	database.drops.emplace_back("Skraev Tailfeather", "A Common drop from the Tail of any Skraev.");
	database.drops.emplace_back("Sleek Razorwing Chitin", "A Rare drop from slaying a Razorwing Kharabak.");
	database.drops.emplace_back("Smoked Dewclaw", "A Common drop from the Leg of any Embermane.");
	database.drops.emplace_back("Smoldering Bloodhide", "A Rare drop from slaying a Bloodfire Embermane.");
	database.drops.emplace_back("Smoldering Firebrand Scale", "A Rare drop from slaying a Firebrand Charrogg.");
	database.drops.emplace_back("Smoldering Horn", "A Common drop from the Head of any Charrogg.");
	database.drops.emplace_back("Smoldering Tailspike", "A Common drop from the Tail of any Charrogg.");
	database.drops.emplace_back("Sparkclaw", "A Common drop from the Limbs of any Nayzaga.");
	database.drops.emplace_back("Sparkspine", "A Common drop from the Tail of any Nayzaga.");
	database.drops.emplace_back("Splintered Antler", "A Common drop from the Antlers of any Koshai.");
	database.drops.emplace_back("Stone Fragments", "A Common drop from the Armor of any Skarn.");
	database.drops.emplace_back("Stoneheart Shard", "An Epic drop from slaying a Rockfall Skarn(Heroic).");
	database.drops.emplace_back("Stony Hide", "A Common drop from the Limbs of any Skarn.");
	database.drops.emplace_back("Stormclaw Hide", "A Common drop from slaying any Stormclaw.");
	database.drops.emplace_back("Stormheart Shard", "An Epic drop from slaying a Stormclaw.");
	database.drops.emplace_back("Thornsoul Shard", "An Epic drop from slaying a Koshai(Heroic).");
	database.drops.emplace_back("Thundering Scale", "A Rare drop from slaying a Drask.");
	database.drops.emplace_back("Thundersoul Shard", "An Epic drop from slaying a Drask.");
	database.drops.emplace_back("Torn Shrikefeather", "A Common drop from slaying any Shrike.");
	database.drops.emplace_back("Twisted Shadowspur", "A Common drop from the Leg of any Shrowd.");
	database.drops.emplace_back("Unstable Nullhide", "A Rare drop from slaying a Riftstalker.");
	database.drops.emplace_back("Unstable Tailspike", "A Common drop from the Tail of any Valomyr.");
	database.drops.emplace_back("Valomyr Hide", "A Common drop from slaying any Valomyr.");
	database.drops.emplace_back("Vinetooth", "A Common drop from the Head of any Koshai.");
	database.drops.emplace_back("Vital Thorn", "A Rare drop from slaying a Koshai.");
	database.drops.emplace_back("Volthoof", "A Common drop from the Limbs of any Stormclaw.");
	database.drops.emplace_back("Voltscale", "A Rare drop from slaying a Stormclaw.");
	database.drops.emplace_back("Windsoul Shard", "An Epic drop from slaying a Moonreaver Shrike(Heroic).");
	database.drops.emplace_back("Blaze Orb", "Obtained from Blaze Patrols and from blaze Behemoths.");
	database.drops.emplace_back("Frost Orb", "Obtained from Frost Patrols and from frost Behemoths.");
	database.drops.emplace_back("Neutral Orb", "Obtained from Neutral Patrols and from neutral Behemoths.");
	database.drops.emplace_back("Peerless Arcstone", "Obtained from Threat Level 17 + Patrols.");
	database.drops.emplace_back("Shining Arcstone", "Obtained from Heroic Patrols and from Behemoths rated Threat Level 13 - 16.");
	database.drops.emplace_back("Shock Orb", "Obtained from Shock Patrols and from shock Behemoths.");
	database.drops.emplace_back("Terra Orb", "Obtained from Terra Patrols and from terra Behemoths.");
}

//when new content is released add one line corresponding to behe in function listed below
void loadBehes()
{
	//Charrogg
	database.behemoths.emplace_back("Charrogg", "Blaze", 4, 150);
	//Firebrand Charrogg
	database.behemoths.emplace_back("Firebrand Charrogg", "Blaze", 8, 300, 13, 425);

	//Embermane
	database.behemoths.emplace_back("Embermane", "Blaze", 5, 200);
	//Bloodfire Embermane
	database.behemoths.emplace_back("Bloodfire Embermane", "Blaze", 10, 350, 15, 475);

	//Hellion
	database.behemoths.emplace_back("Hellion", "Blaze", 7, 275);
	//Scorchstone Hellion
	database.behemoths.emplace_back("Scorchstone Hellion", "Blaze", 12, 400, 16, 500);

	//Boreus
	database.behemoths.emplace_back("Boreus", "Frost", 6, 250);
	//Dreadfrost Boreus
	database.behemoths.emplace_back("Dreadfrost Boreus", "Frost", 9, 325, 15, 475);

	//Pangar
	database.behemoths.emplace_back("Pangar", "Frost", 7, 275);
	//Frostback Pangar
	database.behemoths.emplace_back("Frostback Pangar", "Frost", 11, 375, 15, 475);

	//Skraev
	database.behemoths.emplace_back("Skraev", "Frost", 4, 150);

	//Drask
	database.behemoths.emplace_back("Drask", "Shock", 7, 275);

	//Nayzaga
	database.behemoths.emplace_back("Nayzaga", "Shock", 5, 200);
	//Shockjaw Nayzaga
	database.behemoths.emplace_back("Shockjaw Nayzaga", "Shock", 11, 375, 15, 475);

	//Stormclaw
	database.behemoths.emplace_back("Stormclaw", "Shock", 6, 250);

	//Kharabak
	database.behemoths.emplace_back("Kharabak", "Terra", 6, 250);
	//Razorwing Kharabak
	database.behemoths.emplace_back("Razorwing Kharabak", "Terra", 10, 350, 14, 450);

	//Koshai
	database.behemoths.emplace_back("Koshai", "Terra", 10, 350, 17, 550);

	//Skarn
	database.behemoths.emplace_back("Skarn", "Terra", 3, 100);
	//Rockfall Skarn
	database.behemoths.emplace_back("Rockfall Skarn", "Terra", 8, 300, 13, 425);

	//Gnasher
	database.behemoths.emplace_back("Gnasher", "Neutral", 3, 100);
	//Ragetail Gnasher
	database.behemoths.emplace_back("Ragetail Gnasher", "Neutral", 9, 325, 13, 425);

	//Quillshot
	database.behemoths.emplace_back("Quillshot", "Neutral", 5, 200);
	//Deadeye Quillshot
	database.behemoths.emplace_back("Deadeye Quillshot", "Neutral", 12, 400, 14, 450);

	//Shrike
	database.behemoths.emplace_back("Shrike", "Neutral", 4, 150);
	//Moonreaver Shrike
	database.behemoths.emplace_back("Moonreaver Shrike", "Neutral", 9, 325, 14, 450);

	//Valomyr
	database.behemoths.emplace_back("Valomyr", "Radiant", 8, 300, 16, 500);

	//Rezakiri
	database.behemoths.emplace_back("Rezakiri", "Radiant", 17, 550);

	//Riftstalker 
	database.behemoths.emplace_back("Riftstalker", "Umbral", 9, 325, 16, 500);

	//Shrowd
	database.behemoths.emplace_back("Shrowd", "Umbral", 17, 550);
}

void searchBehe(std::string& s)			//s represents name of behemoth
{
	for (int i = 0; i < int(database.behemoths.size()); ++i) {
		if (s == database.behemoths[i].name) {
			database.behemoths[i].printInfo();			//behemoth found, print all information and return
			return;
		}
	}
	//name not found
	std::cout << "Could not find behemoth with the name '" << s << "'." << std::endl;
}

//used to prompt user for input, just for sake of clarity it was named inputPrompt (used in main)
std::string inputPrompt = ">>";

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
				searchBehe(inputName);
				break;
			}
			case 2: {			//Search for a drop		NEEDS TO BE IMPLEMENTED?
				
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
		}	

		std::cout << std::endl;		//just for spacing
	}
}


