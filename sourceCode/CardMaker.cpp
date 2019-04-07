
#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>
using namespace std;

string descriptionCanv = "480x450";
string descriptionPos = "+45+140";
string titleCanv = "490x90";
string titlePos = "+45+60";
string pointCanv = "93x41";
string revenuePos = "+40+665";
string happinessPos = "+40+718";
string politicalPos = "+40+770";
string lossPos = "+375+665";
string sadnessPos = "+375+718";
string discreditPos = "+375+770";

struct card
{
	string type;
	string revenue;
	string happiness;
	string political;
	string loss;
	string sadness;
	string discredit;
	string description;
};

int checkLength(const char * dataName)
{
	ifstream file;
	file.open(dataName);
	int lineAmount = 0;
	while (!file.eof())
	{
		string storage;
		getline(file, storage);
		lineAmount++;
	}
	file.close();
	return lineAmount;
}

card rawCard(string line)
{
	card cardInst;
	string::size_type pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8;


	pos1 = line.find("|");
	cardInst.type = line.substr(0, pos1);
	pos2 = line.find("|", pos1 + 1);
	cardInst.revenue = line.substr(pos1+ 1, pos2 - pos1 -1);
	pos3 = line.find("|", pos2 + 1);
	cardInst.happiness = line.substr(pos2 + 1, pos3 - pos2-1);
	pos4 = line.find("|", pos3 + 1);
	cardInst.political = line.substr(pos3 + 1, pos4 - pos3-1);
	pos5 = line.find("|", pos4 + 1);
	cardInst.loss = line.substr(pos4 + 1, pos5 - pos4-1);
	pos6 = line.find("|", pos5 + 1);
	cardInst.sadness = line.substr(pos5 + 1, pos6 - pos5-1);
	pos7 = line.find("|", pos6 + 1);
	cardInst.discredit = line.substr(pos6 + 1, pos7 - pos6-1);
	pos8 = line.find("|", pos7 + 1);
	cardInst.description = line.substr(pos7 + 1);



	return cardInst;
}

card* makeCardTab(int r, const char * dataName)
{
	ifstream file;
	file.open(dataName);
	card * tab = new card[r];
	string line;
	for (int i = 0; i < r; i++)
	{
		getline(file, line);
		tab[i] = rawCard(line);
	}

	return tab;
}

void renderPoints(string type, string pos, string fileName, string descriptioncmd3, string descriptioncmd4, string descriptioncmd5)
{
	string cmd = "magick -background \"rgba(0, 0, 0, 0)\" -gravity east -font itim -pointsize 36 -size ";
	string cmd1 = " caption:\"";
	string cmd2 = "\" text.png";
	string whole = cmd + pointCanv + cmd1 + type + cmd2;
	system(whole.c_str());
	string whole2 = descriptioncmd3 + fileName + descriptioncmd4 + pos + descriptioncmd5 + fileName;
	system(whole2.c_str());
}

void determineType(card cardInst, string& type, string& title)
{
	if (cardInst.type == "plc")
	{
		type = "img/policji.png";
		title = "POLICJA";
	}
	else if (cardInst.type == "pol")
	{
		type = "img/polityczna.png";
		title = "Karta Polityczna";
	}
	else if (cardInst.type == "prz")
	{
		type = "img/przekretu.png";
		title = "Karta Przekrêtu";
	}
	else if (cardInst.type == "zsk")
	{
		type = "img/zysku.png";
		title = "Karta Zysku";
	}
	else if (cardInst.type == "crb")
	{
		type = "img/choroby.png";
		title = "Karta Choroby";
	}
	else if (cardInst.type == "szk")
	{
		type= "img/szkody.png";
		title = "Karta Szkody";
	}
	else if (cardInst.type == "prc")
	{
		type = "img/pracy.png";
		title = "Oferta Pracy";
	}
	else if (cardInst.type == "tcz")
	{
		type = "img/teczki.png";
		title = "Teczka";
	}
	else if (cardInst.type == "cba")
	{
		type = "img/cba.png";
		title = "CBA";
	}
	else if (cardInst.type == "szw")
	{
		type = "img/szwindel.png";
		title = "Karta Szwindlu";
	}
	else if (cardInst.type == "str")
	{
		type = "img/strata.png";
		title = "Karta Straty";
	}
	else if (cardInst.type == "kor")
	{
		type = "img/korzysc.png";
		title = "Karta Korzyœci";
	}
	else if (cardInst.type == "gow")
	{
		type = "img/dziecko.png";
		title = "Karta Dziecka";
	}
}

void renderCard(card cardInst, int i)
{
	
	// ========================== USTALANIE TYPU KARTY =============================
	string type;
	string title;
	determineType(cardInst, type, title);
	

	// ================================================================================
	
	
	
	
	// ====================================== description =========================================
	string descriptioncmd = "magick -background \"rgba(0, 0, 0, 0)\" -fill \"#333333\" -gravity north -font itim -pointsize 36 -size ";
	string descriptioncmd1 = " caption:\"";
	string descriptioncmd2 = "\" text.png";
	string descriptionWhole = descriptioncmd + descriptionCanv + descriptioncmd1 + cardInst.description + descriptioncmd2;
	system(descriptionWhole.c_str());
	string descriptioncmd3 = "magick ";
	string descriptioncmd4 = " text.png -geometry ";
	string descriptioncmd5 = " -composite ";
	
	string tmp;
	itoa(i, (char*)tmp.c_str(), 10);
	string iterator = tmp.c_str();
	string fileName = iterator + ".png";
	
	string descriptionWhole2 = descriptioncmd3 + type + descriptioncmd4 + descriptionPos + descriptioncmd5 + fileName;
	system(descriptionWhole2.c_str());
	// ===================================== description =============================================
	
	
	
	
	
	
	// ======================================= header ===================================
	string titlecmd = "magick -background \"rgba(0, 0, 0, 0)\" -gravity north -font itim -pointsize 55 -size ";
	string titlecmd1 = " caption:\"";
	string titlecmd2 = "\" text.png";
	string titleWhole = titlecmd + titleCanv + titlecmd1 + title + titlecmd2;
	system(titleWhole.c_str());
	string titleWhole2 = descriptioncmd3 + fileName + descriptioncmd4 + titlePos + descriptioncmd5 + fileName;
	system(titleWhole2.c_str());
	// ======================================= header ==================================
	
	
	//======================================== points ===================================
	
	renderPoints(cardInst.revenue, revenuePos, fileName, descriptioncmd3, descriptioncmd4, descriptioncmd5);
	renderPoints(cardInst.happiness, happinessPos, fileName, descriptioncmd3, descriptioncmd4, descriptioncmd5);
	renderPoints(cardInst.political, politicalPos, fileName, descriptioncmd3, descriptioncmd4, descriptioncmd5);
	renderPoints(cardInst.loss, lossPos, fileName, descriptioncmd3, descriptioncmd4, descriptioncmd5);
	renderPoints(cardInst.sadness, sadnessPos, fileName, descriptioncmd3, descriptioncmd4, descriptioncmd5);
	renderPoints(cardInst.discredit, discreditPos, fileName, descriptioncmd3, descriptioncmd4, descriptioncmd5);
	
	//======================================== points ===================================
	
}



void  renderAll(card * tab, int r)
{
	for (int i = 0; i < r; i++)
	{
		renderCard(tab[i], i);
		printf("\r");
		cout << "Making cards (" << i+1 << "/" << r << ")";
	}
	remove("text.png");
}

int main()
{
	string dataName;
	while(true)
	{
	cout << "Please insert data location (f.e. dataBase.txt)" << endl;
	cin >> dataName;
	ifstream data;
	data.open(dataName.c_str());
		if(data.good())
		{
			break;
		} 
		else
		{
		cout << "Data location is wrong. Insert proper location." << endl;
		}
	}
	
	int r = checkLength(dataName.c_str());
	
	
	
	cout << "Preparing...";
	card * tab = makeCardTab(r, dataName.c_str());
	renderAll(tab, r);

	cout << endl << "Done" << endl;
	system("pause");
	return 0;


}




