#pragma once
#include <iostream>
#include <string>
class sick
{
	std::string registration_number;
	std::string FIO;
	unsigned int year_of_birth;
	std::string address;
	std::string place_of_work;
	bool deleted;
public:
	sick();
	sick(std::string, std::string, unsigned int, std::string, std::string);
	void set_registration_number(std::string);
	std::string get_registration_number();
	std::string get_FIO();
	void set_deleted(bool);
	bool get_deleted();
	void show();
};

