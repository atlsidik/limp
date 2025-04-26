#include <cctype>
#include <cstdio>
#include <cstring>
#include <exception>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
 
extern std::ifstream& read_impl_file(std::ifstream& fIn,std::string name);
extern std::ifstream& read_interf_file(std::ifstream& fIn);
extern void copy_to_file(const char v[]  ,std::string n);
extern char temp_file[];


int  main (int argc, char *argv[]) {
	std::string impl_file_name, interf_file_name;
	if (argc != 3) {
		std::cout <<"Incorect number of arguments";
		return 1;
	}
		impl_file_name = argv[1];
		interf_file_name = argv[2];
	try{
	std::ifstream file_to_impl(impl_file_name);

	std::ifstream interface_file(interf_file_name);
	
	bool done = false;

	if (interface_file.is_open()) {
		std::cout<<"Begin reading file to interface_file\n";
		read_interf_file(interface_file);
	
		std::cout<<"done with interface\n";
	}
	else {
		std::cout<<"Error opening interface_file \n";

	}
	if (file_to_impl.is_open()) {
		std::cout<<"Begin reading file to edit\n";
		read_impl_file(file_to_impl,impl_file_name);

		std::cout<<"done wth file to edit\n";
		done = true;
	}
	else {
		std::cout<<"Error opening file to edit\n ";
	}


	file_to_impl.close();

	interface_file.close();


}
catch(std::exception& e){
	std::cout<<"Failed"<< e.what()<<"\n";
}
	copy_to_file(temp_file, impl_file_name);
	if(std::remove(temp_file))
		std::cout<<"operation success";
	
	return 0;
}

