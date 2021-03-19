#include <iostream>
#include <windows.h>
#include <sstream>

#include "sick.h"

using namespace std;
//структуры
struct doctor
{//структура АВЛ дерева доктор
	string FIO_doctor;
	string position;
	unsigned int cabinet_number;
	string reception;
	doctor* left = NULL;
	doctor* right = NULL;
	int hieght=1;
};
struct list//структура слоёного списка
{
	string registration_number = "";
	string FIO_doctor;
	string date;
	string time;
	list* nextEl = NULL;
	list* nextSloi1 = NULL;
};
//удобные функции//
void cin_clear(){
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
}
void clear(){
	Sleep(500);
	system("cls");
}
//Функции вывода меню//
void show_main_menu(){
	cout << "\n\t/////////////////////////////////////////////////////////////////////////////////\n";
	cout << "\t//                Меню                                                         //\n";
	cout << "\t//            1 - Работа с больными                                            //\n";
	cout << "\t//            2 - Работа с врачами                                             //\n";
	cout << "\t//            3 - Регистрация выдачи больному направления к врачу              //\n";
	cout << "\t//            4 - Регистрация возврата врачом или больным направления к врачу  //\n";
	cout << "\t//            5 - Выход из программы                                           //\n";
	cout << "\t/////////////////////////////////////////////////////////////////////////////////\n";
	cout << "\n\tВвод:";
}
void show_sick_menu(){
	cout << "\n\t/////////////////////////////////////////////////////////////////////////////////\n";
	cout << "\t//                Меню                                                         //\n";
	cout << "\t//            1 - Регистрация нового больного                                  //\n";
	cout << "\t//            2 - Удаление данных о больном                                    //\n";
	cout << "\t//            3 - Просмотр всех зарегистрированных больных                     //\n";
	cout << "\t//            4 - Очистка данных о больных                                     //\n";
	cout << "\t//            5 - Поиск больного по регистрационному номеру                    //\n";
	cout << "\t//            6 - Поиск больного по его ФИО                                    //\n";
	cout << "\t//            7 - Возврат к основному меню                                     //\n";
	cout << "\t/////////////////////////////////////////////////////////////////////////////////\n";
	cout << "\n\tВвод:";
}
void show_doctor_menu(){
	cout << "\n\t/////////////////////////////////////////////////////////////////////////////////\n";
	cout << "\t//                Меню                                                         //\n";
	cout << "\t//            1 - Добавление нового врача                                      //\n";
	cout << "\t//            2 - Удаление сведений о враче                                    //\n";
	cout << "\t//            3 - Просмотр всех имеющихся врачей                               //\n";
	cout << "\t//            4 - Очистка данных о врачах                                      //\n";
	cout << "\t//            5 - поиск врача по «ФИО врача»                                   //\n";
	cout << "\t//            6 - поиск врача по фрагментам «Должность»                        //\n";
	cout << "\t//            7 - Возврат к основному меню                                     //\n";
	cout << "\t/////////////////////////////////////////////////////////////////////////////////\n";
	cout << "\n\tВвод:";
}
//Работа с хэш-таблицами//
int hashi(string registation_number,int n){ //возвращает номер позиции
	int rez = 0;
	for (int i = 0; i < registation_number.length(); i++)
		rez += pow(int(registation_number[i]), 2);
	rez %= n;
	return rez;
}
bool addhash(sick input_sick,sick *table,int n){
	int id;
	int c = 1;
	id = hashi(input_sick.get_registration_number(),n);
	for (int i = 0; i < 5; i++)//кол-во итераций поиска место
	{
		id = id + i * c;
		if (id >= 1000) break;
		if (table[id].get_registration_number()== "")
		{
			table[id] = input_sick;
			return true;
		}
	}
	return false;
}
//Проверки//
bool correct_registration_number(string input_registration_number){
	bool correct = true;
	if (input_registration_number.length() != 9)
	{
		cout << "\n\tВвод произведён не корректно!!!\n";
		cout << "\tПовторите ввод\n";
		return true;
	}
	else
	{
		for (int i = 0; i < input_registration_number.length(); i++)
		{
			if (i == 2)
			{
				if (input_registration_number[i] != '-')
					correct = false;
			}
			else
			{
				if (input_registration_number[i] != '0' && input_registration_number[i] != '1' && input_registration_number[i] != '2'
					&& input_registration_number[i] != '3' && input_registration_number[i] != '4' && input_registration_number[i] != '5'
					&& input_registration_number[i] != '6' && input_registration_number[i] != '7' && input_registration_number[i] != '8'
					&& input_registration_number[i] != '9')
					correct = false;
			}

		}
		if (correct == false)
		{
			cout << "\tВвод произведён не корректно!!!\n";
			cout << "\tПовторите ввод\n";
			return true;
		}
		else 
			return false;

	}
}
bool find_text(string text, string piece_text) {//прямой поиск в тексте
	for (int i = 0; i < text.size() - piece_text.size()+1; i++) {
		int p = 0;
		for (int j = 0; j < piece_text.size(); j++) {
			if (text[i + j] == piece_text[j]) {
				p++;
				if (p == piece_text.size())
					return true;
			}
			else break;
		}
	}
	return false;
}
string return_dmy(string dmy)
{
	string buf="";
	for (int i = 0; i < dmy.size(); i++)
	{
		if (dmy[i] == '.')
			return buf;
		buf += dmy[i];
	}
	return buf;
}
bool correct_date(string date)
{
	
	int day_i, month_i, year_i;
	string day, month, year;
	day = return_dmy(date);
	date.erase(0, day.size() + 1);
	month = return_dmy(date);
	date.erase(0, month.size() + 1);
	year = return_dmy(date);
	istringstream p1(day);
	p1 >> day_i;
	istringstream p2(month);
	p2 >> month_i;
	istringstream p3(year);
	p3 >> year_i;
	if (year_i == 2020 || year_i == 2021)
	{
		if (month_i == 1 || month_i == 3 || month_i == 5 || month_i == 7 || month_i == 8 || month_i == 10 || month_i == 12)
		{
			if (day_i < 31 && day_i > 0)
				return true;
			else
				cout << "\n\tпараметр день вверён неверно\n";
		}
		else if (month_i == 4 || month_i == 6 || month_i == 9 || month_i == 11)
		{
			if (day_i < 30 && day_i > 0)
				return true;
			else
				cout << "\n\tпараметр день вверён неверно\n";
		}
		else if (month_i == 2)
		{
			if (day_i < 28 && day_i > 0)
				return true;
			else
				cout << "\n\tпараметр день вверён неверно\n";
		}
		else cout << "\n\tпараметр месяц должен быть в допазоне 1-12\n";
	}
	else
		cout << "\n\tпараметр год должен быть в допазоне 2020-2021\n";
	return false;
}
bool correct_time(string time)
{
	int m, h;
	string minutes, hour;
	hour = return_dmy(time);
	time.erase(0, hour.size() + 1);
	minutes = return_dmy(time);
	time.erase(0, time.size() + 1);
	istringstream p1(hour);
	p1 >> h;
	istringstream p2(minutes);
	p2 >> m;
	if (h > 6 && h < 21)
		if (m > -1 && m < 61)
			return true;
		else
			cout<<"\n\tМинуты введены не корректно\n";
	else
		cout << "\n\tВремя введено не корректно\n";
	return false;
}
//Функции для работы с больным//
sick create_sick(sick *table, int n)
{
	string input_registration_number, input_FIO, input_address, input_place_of_work;
	unsigned int input_year,id,c=1;
	bool flag_while = true;
	while (flag_while) 
	{
		cout << "\n\tВведите регистрационный номер больного фармата MM-NNNNNN\n";
		cout << "\tMM –	номер участка(цифры), NNNNNN – порядковый номер(цифры)\n\t";
		getline(cin, input_registration_number);
		flag_while = correct_registration_number(input_registration_number);
		id = hashi(input_registration_number,n);
		for (int i = 0; i < 5; i++,id=id+i*c) 
			if (table[id].get_registration_number() == input_registration_number)
			{
				flag_while = true;
				cout << "\tБольной с таким регистрационным номером уже есть в базе данных!!!\n";
				break;
			}
	}
	flag_while = true;
	cout << "\n\tВведите ФИО бального\n\t";
	getline(cin, input_FIO);
	if (input_FIO.length() > 40) 
	{
		cout << "\tФИО бального было обрезано до 40 символов";
		input_FIO.erase(40, 100);
	}
	while (flag_while) 
	{
		cout << "\n\tВведите год рождения больного\n\t";
		cin >> input_year;
		cin_clear();
		if (input_year > 1900 && input_year <= 2020)
			flag_while = false;
		else
		{
			cout << "\tВвод произведён не корректно!!!\n";
			cout << "\tГод рождения должен быть в диапозоне 1900-2020\n";
			cout << "\tПовторите ввод\n";
		}
	}
	cout << "\n\tВведите адрес бального\n\t";
	getline(cin, input_address);
	if (input_address.length() > 40)
	{
		cout << "\tадрес бального было обрезано до 40 символов";
		input_address.erase(40, 100);
	}
	cout << "\n\tВведите место работы/учебы больного\n\t";
	getline(cin, input_place_of_work);
	if (input_place_of_work.length() > 40)
	{
		cout << "\tместо работы бального было обрезано до 40 символов";
		input_place_of_work.erase(40, 100);
	}
	sick input_sick(input_registration_number, input_FIO, input_year, input_address, input_place_of_work);
	return input_sick;
}
void deleted_sick(sick *table,int n)
{
	sick clear;
	string input_registration_number;
	int id, c = 1;
	bool flag_while=true;
	cout << "\n\tВведите регистрационный номер бального фармата MM-NNNN для его удаления из базы данных\n";
	cout << "\tMM –	номер участка(цифры), NNNNNN – порядковый номер(цифры)\n\t";
	getline(cin, input_registration_number);
	flag_while = correct_registration_number(input_registration_number);
	if (flag_while) 
	{
		Sleep(1000);
		system("cls");
		cout << "\n\tНекоректно введён регистрационный номер\n\n";
		return;
	}
	id = hashi(input_registration_number,n);
	for (int i = 0; i < 5; i++, id = id + i * c)
		if (table[id].get_registration_number() == input_registration_number)
		{
			table[id] = clear;
			table[id].set_deleted(true);
			Sleep(1000);
			system("cls");
			cout << "\n\tБольного был удалён\n\n";
			return;
		}
	Sleep(1000);
	system("cls");
	cout << "\n\tБольного с таким регистрационным номером нет!\n";
}
void show_all_sick(sick* table, int n)
{
	bool flag_show = false;
	for (int i = 0; i < n; i++)
	{
		if (table[i].get_registration_number() != "")
		{
			table[i].show();
			flag_show = true;
			cout << "\n_________________________________________________________________________________________\n";
		}
	}
	if (!flag_show)
		cout << "\n\tВ базе данных нет больных.\n\n";
}
void all_clear_sick(sick *table,int n)
{
	sick clear;
	for (int i = 0; i < n; i++)
		table[i] = clear;
	Sleep(1000);
	system("cls");
	cout << "\n\tВсе данные о больных очищенны\n\n";
}
void find_sick_RN(sick *table, int n)
{
	string input_registration_number;
	int id, c = 1;
	bool flag_while = true;
	cout << "\n\tВведите регистрационный номер бального фармата MM-NNNN для поиска данных о нем\n";
	cout << "\tMM –	номер участка(цифры), NNNNNN – порядковый номер(цифры)\n\t";
	getline(cin, input_registration_number);
	flag_while = correct_registration_number(input_registration_number);
	if (flag_while)
	{
		Sleep(1000);
		system("cls");
		cout << "\n\tНекоректно введён регистрационный номер\n\n";
		return;
	}
	id = hashi(input_registration_number, n);
	for (int i = 0; i < 5; i++, id = id + i * c)
		if (table[id].get_registration_number() == input_registration_number)
		{
			Sleep(1000);
			system("cls");
			table[id].show();
			cout << "\n_________________________________________________________________________________________\n";
			return;
		}
	Sleep(1000);
	system("cls");
	cout << "\n\tБольного с таким регистрационным номером нет!\n";
}
//проверить
void find_sick_FIO(sick* table, int n)
{
	string input_FIO,buff,buff2;
	bool flag = false;
	cout << "\n\tВведите ФИО бального бля поиска: ";
	getline(cin, input_FIO);
	for (int i = 0; i < n; i++)
		if (table[i].get_FIO()!="")
		{
			buff = table[i].get_FIO();
			buff2.assign(buff, 0, input_FIO.length());
			if (input_FIO == buff2)
			{
				table[i].show();
				cout << "_________________________________________________________________________________________\n";
				flag = true;
			}
		}
	if(!flag)
		cout << "\tБольного с таким регистрационным номером нет!";
}
//функции авл дерева//
int Height(doctor* R)
{
	if (R != NULL)
		return R->hieght;
	else return 0;
}
void fixheight(doctor* R)
{
	int hl = Height(R->left);
	int hr = Height(R->right);
	if (hl > hr)
		R->hieght = hl + 1;
	else
		R->hieght = hr + 1;
}
int bfactor(doctor* R)
{
	return Height(R->right) - Height(R->left);
}
doctor* right_rotate(doctor* p)
{
	doctor* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p); fixheight(q);
	return q;
}
doctor* left_rotate(doctor* q)
{
	doctor* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}
doctor* balance(doctor* R)
{
	fixheight(R);
	if (bfactor(R) == 2)
	{
		if (bfactor(R->right) < 0)
			R->right = right_rotate(R->right);
		return left_rotate(R);
	}
	if (bfactor(R) == -2)
	{
		if (bfactor(R->left) > 0)
			R->left = left_rotate(R->left);
		return right_rotate(R);
	}
	return R; // балансировка не нужна 
}
doctor* addEl(doctor*&R, doctor* input_doc)
{
	if (R == NULL)
	{
		R = input_doc;
		return R;
	}
	int result = R->FIO_doctor.compare(input_doc->FIO_doctor);
	if (result > 0)
		addEl(R->left, input_doc);
	else
		addEl(R->right, input_doc);
	R = balance(R);
}
doctor* find_min(doctor* R)
{
	if (R->left == NULL)
		return R;
	else find_min(R->left);
}
doctor* remmin(doctor* R)
{
	if (R->left == NULL)
		return R->right;
	R->left = remmin(R->left);
	return balance(R);
}
bool search(doctor* root,string input_doc, bool flag)
{
	if (root != NULL)
	{
		int result = root->FIO_doctor.compare(input_doc);
		if (result == 0)
			return true;
		else if (result > 0)
			flag = search(root->left, input_doc, flag);
		else
			flag = search(root->right, input_doc, flag);
	}
	return flag;
}
doctor* create_doctor(doctor *root)
{
	string input_FIO_doctor, input_position, input_reception;
	unsigned int input_cabinet_number;
	bool flag_while=true;
	while (flag_while)	{
		cout << "\n\tВведите ФИО врача формата(фамилия врача и его инициалы) - ";
		getline(cin, input_FIO_doctor);
		if (input_FIO_doctor.length() > 24)
			cout << "\n\tФИО врача не может быть длиннее 25 сисволов\n";
		else 
			flag_while = false;
	}
	flag_while = true;
	while (flag_while)	{
		cout << "\n\tВведите должность врача - ";
		getline(cin, input_position);
		if (input_FIO_doctor.length() > 34)
			cout << "\n\tФИО врача не может быть длиннее 35 сисволов\n";
		else 
			flag_while = false;
	}
	flag_while = true;
	cout << "\n\tВведите номер кабинета врача - ";
	cin>> input_cabinet_number;
	cin_clear();
	while (flag_while)	{
		cout << "\n\tВведите график приёма врача - ";
		getline(cin, input_reception);
		if (input_FIO_doctor.length() > 44)
			cout << "\n\tФИО врача не может быть длиннее 45 сисволов\n";
		else 
			flag_while = false;
	}

	doctor* input_doc = new doctor;
	(input_FIO_doctor, input_position, input_cabinet_number, input_reception);
	input_doc->cabinet_number = input_cabinet_number;
	input_doc->FIO_doctor = input_FIO_doctor;
	input_doc->position = input_position;
	input_doc->reception = input_reception;

	bool flag = false;
	if (search(root, input_doc->FIO_doctor, flag)){
		clear();
		cout << "\n\tТакой врач уже есть!\n\n";
	}
	else {
		root = addEl(root, input_doc);
		clear();
		cout << "\n\tВрач добавлен в базу данных.\n\n";
	}
	return root;
}
doctor* delete_doc(doctor* R,string buf)
{
	if (R == NULL)
	{
		clear();
		cout << "\n\tВ базе данных нет такого врача\n\n";
		return 0;
	}
	int result = R->FIO_doctor.compare(buf);
	if (result > 0)
		R->left = delete_doc(R->left,buf);
	else if (result < 0)
		R->right = delete_doc(R->right,buf);
	else {
		doctor* l = R->left;
		doctor* r = R->right;
		delete R;
		if (r == NULL) 
		{
			clear();
			cout << "\n\tВрач удалён из базы данных\n\n";
			return l;
		}
		doctor* min = find_min(r);
		min->right = remmin(r);
		min->left = l;
		clear();
		cout << "\n\tВрач удалён из базы данных\n\n";
		return balance(min);
	}
	return balance(R);
}
void show_doc(doctor* root)
{
	cout << "\n\t"<<root->FIO_doctor<<endl;
	cout << "\tДолжность:" << root->position << endl;
	cout << "\tНомер кабинета:" << root->cabinet_number << endl;
	cout << "\tГрафик приема:" << root->reception << endl;
	cout << "_________________________________________________________________________________________\n\n";
}
void show_all_doc(doctor* root)
{//симетричный обход
	if (root != NULL) 
	{
		show_all_doc(root->left);
		show_doc(root);
		show_all_doc(root->right);
	}
}
void all_clear_doc(doctor *root)
{//удаление происходит обратным обходом чтобы небыло утечек памяти
	if (root != NULL) {
		all_clear_doc(root->left);
		all_clear_doc(root->right);
		delete root;
		}
}
void find_doc_FIO(doctor *root)
{
	cout << "need 3 list";
}
void find_doc_position(doctor *root, string piece_text,bool &flag)
{//симетричный обход
	if (root != NULL)
	{
		find_doc_position(root->left, piece_text,flag);
		if (find_text(root->position, piece_text)) {
			show_doc(root);
			flag = false;
		}
		find_doc_position(root->right, piece_text, flag);
	}
}
////////////////////////////
list* create_list(list* head, sick* table, int n,doctor* root)
{
	string input_registration_number, input_FIO_doctor, input_date, input_time;
	bool flag_while = false,flag_correct;
	unsigned int id, c = 1;
	while (!flag_while)
	{
		cout << "\n\tВведите регистрационный номер больного фармата MM-NNNNNN\n";
		cout << "\tMM –	номер участка(цифры), NNNNNN – порядковый номер(цифры)\n\t";
		getline(cin, input_registration_number);
		flag_correct = correct_registration_number(input_registration_number);
		if (!flag_correct) {
			id = hashi(input_registration_number, n);
			for (int i = 0; i < 5; i++, id = id + i * c)
				if (table[id].get_registration_number() == input_registration_number)				{
					flag_while = true;
					break;
				}
		}
		else
			continue;
		if (!flag_while) 
		{
			system("cls");
			cout<<"\n\tБольного с таким регистрационным номерос нет в базе данных!\n";
			return head;
		}
	}
	cout << "\n\tВведите ФИО врача формата(фамилия врача и его инициалы) - ";
	getline(cin, input_FIO_doctor);
	if (input_FIO_doctor.length() > 24)
		cout << "\n\tФИО врача не может быть длиннее 25 сисволов\n";
	if (!search(root, input_FIO_doctor, false))
	{
		clear();
		cout << "\n\tТакого врача нет в базе данных!\n\n";
		return head;
	}
	cout << "\n\tВведите дату направления формата д.м.г - ";
	getline(cin, input_date);
	if (!correct_date(input_date))
	{
		clear();
		cout << "\n\tДата введена не корректно!\n\n";
		return head;
	}
	cout << "\n\tВведите время направления формата ч.м(7.00 - 20.00) - ";
	getline(cin, input_time);
	if (!correct_time(input_time))
	{
		clear();
		cout << "\n\tДата введена не корректно!\n\n";
		return head;
	}
	return head;
}
///////////////////////////////
void function_sick(sick *table,int n)
{
	clear();
	sick input_sick;
	int sick_menu = 1;
	bool flag;
	while (sick_menu !=7)
	{
		show_sick_menu();
		cin >> sick_menu;
		cin_clear();
		switch (sick_menu)
		{
		case 1:
		{
			input_sick=create_sick(table,n);
			flag = addhash(input_sick, table,n);
			if (flag) 
			{
				clear();
				cout << "\n\tБольной добавлен в базу\n\n";
			}

			else 
			{
				clear();
				cout << "\n\tБольной добавлен в базу\n\n";
				cout << "\tБольной не был добавлен в базу\n";
			}
			
			break;
		}
		case 2:
		{
			deleted_sick(table,n);
			break;
		}
		case 3:
		{
			clear();
			show_all_sick(table,n);
			break;
		}
		case 4:
		{
			all_clear_sick(table,n);
			break;
		}
		case 5:
		{//ЕЩЕ РЕАЛИЗОВАТЬ ПОИСК НАПРАВЛЕНИЯ
			find_sick_RN(table, n);
			break;
		}
		case 6:
		{
			find_sick_FIO(table, n);
			break;
		}
		case 7:
		{
			cout << "\n\tВозврат к основному меню\n";
			break;
		}
		default:
			cout << "_________________________________________________________________________________________\n";
			cout << "\n\tОшибка ввода!!!\n";
			cout << "\tПовторите ввод!!!\n";
			cout << "_________________________________________________________________________________________\n";
			clear();
			break;
		}

	}
}
doctor* function_doctor(doctor *root)
{
	clear();
	int doctor_menu = 1;
	doctor input_doc;
	
	while (doctor_menu != 7)
	{
		show_doctor_menu();
		cin >> doctor_menu;
		cin_clear();

		switch (doctor_menu)
		{
		case 1:
		{
			root = create_doctor(root);
			break;
		}
		case 2:
		{
			string buf;
			cout << "\n\tВведите ФИО врача которого хотите удалить формата(фамилия врача и его инициалы) - ";
			getline(cin, buf);
			root = delete_doc(root,buf);
			break;
		}
		case 3:
		{
			system("cls");
			show_all_doc(root);
			break;
		}
		case 4:
		{
			system("cls");
			all_clear_doc(root);
			root = NULL;
			break;
		}
		case 5://unfull
		{
			system("cls");
			find_doc_FIO(root);
			break;
		}
		case 6:
		{
			cout << "\n\tВведите должность врача для поиска - ";
			string piece_text;
			getline(cin, piece_text);
			system("cls");
			bool flag = true;
			find_doc_position(root, piece_text,flag);
			if(flag)
				cout << "\n\tВрач с такой должнастью не найден\n\n";
			break;
		}
		case 7:
		{
			cout << "\n\tВозврат к основному меню\n";
			return root;
			break;
		}
		default:
			cout << "_________________________________________________________________________________________\n";
			cout << "\n\tОшибка ввода!!!\n";
			cout << "\tПовторите ввод!!!\n";
			cout << "_________________________________________________________________________________________\n";
			clear();
			break;
		}

	}
}
///////////////////////////////////////////////////////
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int n = 1000;

	sick table[n];
	doctor* root = NULL;
	list* head = NULL;
	int main_menu = 1;
	while (main_menu !=5)
	{
		show_main_menu();
		cin >> main_menu;
		cin_clear();

		switch (main_menu)
		{
		case 1:
		{
			function_sick(table,n);
			clear();
			break;
		}
		case 2:
		{
			root = function_doctor(root);
			clear();
			break;
		}
		case 3:
		{
			head = create_list(head,table,n,root);
			break;
		}
		case 4:
		{

			break;
		}
		case 5:
		{

			break;
		}
		default:
			cout << "_________________________________________________________________________________________\n";
			cout << "\n\tОшибка ввода!!!\n";
			cout << "\tПовторите ввод!!!\n";
			cout << "_________________________________________________________________________________________\n";
			clear();
			break;
		}
	}
	return 1;
}