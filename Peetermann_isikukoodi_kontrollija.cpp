//
//Keel C++
//Kristo Peetermann
//String type muutuja töötlemine
//Isikukoodi valiidsuse kontrollija
//2022-03-22



#include <iostream>			//std::cout, std::cin
#include <string>			//std::string, std::getline
#include <math.h>			//std::floor,

//funktsioon, mis kontrollib isikukoodi 7 esimest numbrit, et nad vastavad
// korrektsele formaadile.
bool isikukoodi_legitiimsuse_kontroll(std::string isikukood){
	if(isikukood.length() == 11){
		if(std::stoi(isikukood.substr(0,1)) >= 3 && std::stoi(isikukood.substr(0,1)) <= 6){
			if(std::stoi(isikukood.substr(3, 2)) >= 1 && std::stoi(isikukood.substr(3, 2)) <= 12){
				if(std::stoi(isikukood.substr(5, 2)) >= 1 && std::stoi(isikukood.substr(5, 2)) <= 31){
					return true;
	}}}
	}else return false;
	return 0;
}
//Funktsioon, mis kontrollib isikukoodi lõpus olevat kontrollnumbrit.
bool isikukoodi_nr_kontroll(std::string isikukood_sonena){
	int isikukood[11];

	for(int i=0; i< 11; i++){
		isikukood[i] = std::stoi(isikukood_sonena.substr(i,1));
	}
	int kontrollnr;

	kontrollnr = std::floor(((isikukood[0]*1)+(isikukood[1]*2)+(isikukood[2]*3)+(isikukood[3]*4)
	+(isikukood[4]*5)+(isikukood[5]*6)+(isikukood[6]*7)+(isikukood[7]*8)+(isikukood[8]*9)
	+(isikukood[9]*1))/11);
	if(kontrollnr != isikukood[10]){
		kontrollnr = floor((isikukood[0]*3+isikukood[1]*4+isikukood[2]*5+isikukood[3]*6
		+isikukood[4]*7+isikukood[5]*8+isikukood[6]*9+isikukood[7]*1+isikukood[8]*2
		+isikukood[9]*3)/11);
	}
	if(kontrollnr > 9 && isikukood[10] == 0) return true;

	if(isikukood[10] == kontrollnr) return true;

	else return false;

	return 0;
}

int main() {
	bool legitiimne = true;
	std::string isikukood;
	std::cout << "Isikukood: " << std::endl;
	std::getline(std::cin, isikukood);

	legitiimne = isikukoodi_legitiimsuse_kontroll(isikukood);
	legitiimne = isikukoodi_nr_kontroll(isikukood);

	if(legitiimne == true){
		std::cout << "Antud isikukood on legitiimne." << std::endl;
	}
	else{
		std::cout << "Antud isikukood ei ole legitiimne" << std::endl;
	}


	return 0;
}
