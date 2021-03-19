#include "sick.h"
sick::sick(std::string input_registration_number, std::string input_FIO, unsigned int input_year, std::string input_address, std::string input_place_of_work)
{
	registration_number = input_registration_number;
	FIO = input_FIO;
	year_of_birth = input_year;
	address = input_address;
	place_of_work = input_place_of_work;
	deleted = false;
}
sick::sick()
{
	registration_number = "";
	FIO = "";
	year_of_birth = 0;
	address = "";
	place_of_work = "";
	deleted = false;
}
void sick::set_registration_number(std::string str){registration_number=str;}

std::string sick::get_registration_number(){return registration_number;}

void sick::set_deleted(bool input){	deleted = input;}

bool sick::get_deleted(){return deleted;}

std::string sick::get_FIO() { return FIO; }

void sick::show() 
{
	std::cout << "\n\tРегистрационный номер больного "<<registration_number;
	std::cout << "\n\tФИО больного " << FIO;
	std::cout << "\n\tГод рождения " << year_of_birth;
	std::cout << "\n\tАдрес проживания больного " << address;
	std::cout << "\n\tМесто работы/учебы " << place_of_work;
}
