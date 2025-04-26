#ifndef IMPLMNT_H 
#define IMPLMNT_H
#include <cstring>
#include <exception>
#include <ios>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <filesystem>

extern std::ifstream& read_impl_file(std::ifstream& fIn,std::string name);
extern std::ifstream& read_interf_file(std::ifstream& fIn);
//extern int line_count =0 ;
std::ifstream& read_word(std::ifstream& fIn, char word[],int& num);
std::ifstream& read_first_line(std::ifstream& fIn,char line[], int max);
//char interface_name[25], new_first_line[200];
std::ifstream& read_comments(std::ifstream& fIn);
bool process_line(const char line[],int max);
int read_one_wrd(const char f[],char w[], int index);
std::ifstream& read_rest_of_interf(std::ifstream& fIn);
//bool isMethod =false;
//extern int return_count ;
char* determ_return_types(char line[] );
bool check_word(const char[] ,char[]);
std::ifstream& 	read_rest_of_edit_file(std::ifstream& fIn, std::string );
std::ofstream& add_interf_lines(std::ofstream&);
extern void copy_to_file(const char v[]  ,std::string n);
//char temp_file[] = "tmp.txt";


struct interf_line{
	char str[500];
	interf_line(char line[],char ret_statement[]){
		char *temp_line = new char[300], *temp_stat = new char[100];
		strcpy(temp_line,line);
		strcpy(temp_stat,ret_statement);


		rem_semi(temp_line, 300);
	std::strcat(str,temp_line);
	std::strcat(str,temp_stat);
	delete [] temp_line;
	delete [] temp_stat;
	}
	void rem_semi(char str[],int length){
		char *temp = new char[length];
		char c;
		int i;
		for(i = 0,  c = temp[0];( i< length) ; i++){
		char c = str[i];
		if(c!=';'){
		temp[i]=c;
		}
		if (c =='\0') {
		temp[i] = c;
		break;
		}

		}
		delete[] str;
		str = new char[length];
		std::strcpy(str,temp);
		delete[] temp;
	}
}; //*inerf_lines[20];





#endif
