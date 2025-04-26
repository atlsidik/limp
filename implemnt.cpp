#include <cctype>
#include <cstdio>
#include <cstring>
#include <exception>
#include <ios>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <streambuf>
#include <string>
#include <filesystem>

#include "implemnt.h"

/*
#include <cctype>
#include <cstdio>
#include <cstring>
#include <exception>
#include <ios>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <streambuf>
#include <string>
#include <filesystem>

std::ifstream& read_impl_file(std::ifstream& fIn,std::string name);
std::ifstream& read_interf_file(std::ifstream& fIn);
char *lines[30];
int line_count =0;
std::ifstream& read_word(std::ifstream& fIn, char word[],int& num);
std::ifstream& read_first_line(std::ifstream& fIn,char line[], int max);
char interface_name[25], new_first_line[200];
std::ifstream& read_comments(std::ifstream& fIn);
bool process_line(const char line[],int max);
int read_one_wrd(const char f[],char w[], int index);
std::ifstream& read_rest_of_interf(std::ifstream& fIn);
bool isMethod =false;
char *return_types[15];
int return_count =0;
char *wordarr[10];
char* determ_return_types(char line[] );
bool check_word(const char[] ,char[]);
std::ifstream& 	read_rest_of_edit_file(std::ifstream& fIn, std::string );
std::ofstream& add_interf_lines(std::ofstream&);
void copy_to_file(const char[] ,std::string);
char temp_file[] = "tmp.txt";


struct interf_line{
	char str[150];
	interf_line(char line[],char ret_statement[]){
		rem_semi(line, 150);
	std::strcat(line,ret_statement);
	std::strcpy(str,line);
	}
	void rem_semi(char str[],int length){
		char *temp = new char[length];
	//	std::strcpy(str,temp);
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
	//	return temp;
	}
} *interf_lines[10];





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




}
catch(std::exception& e){
	std::cout<<"Failed"<< e.what()<<"\n";
}
	copy_to_file(temp_file, impl_file_name);
	if(std::remove(temp_file))
		std::cout<<"operation success";
	
std::cout<<"printing interface lines\n";
for (int i =0;  i < line_count; i++) {
	std::cout<<interf_lines[i]->str<<std::endl;
	
}




	return 0;
}
*/

//extern int line_count =0;

std::ifstream& read_interf_file(std::ifstream& fIn){
	char c ;
	 fIn.get(c);
//	std::cout<<"\nbegin trailing line loop\n";
	while((!isalpha(c)) && fIn.get(c)){
			 
	}
//	std::cout<<"exit loop\n";
	
	fIn.putback(c);
//	std::unique_ptr<char> word ;
	char *word ;	//word[0] = c;
	int i =0, num=5;
	//word[20]='\0';
	 int brace_enc = 0;

	while(!brace_enc){
		word = new char[21];	
		read_word(fIn,word,num);
		brace_enc = num;

		if(!brace_enc)
			delete[] word;
	 }
	
	 char first_line[150];
	 std::cout<<word<<std::endl;

	 std::strcpy(interface_name,word);
	 delete[] word;
	// read_first_line(fIn,first_line,150);
	// std::cout<<first_line<<std::endl;
//	 std::strcat(first_line,word);
//
	read_rest_of_interf(fIn);
	 return fIn;


	
}

	std::ifstream& read_rest_of_interf(std::ifstream& fIn){
		//char *lines[15];
	//	int line_count =0;
		while(!fIn.eof()){
		char c;
		 read_comments(fIn);
	 while(fIn.get(c) && c!='\n')
		 ;
	 char *newLine = new char[300]  ;
	 bool isMethod = false;
	 fIn.getline(newLine,300);
	isMethod= process_line(newLine,300);
//	std::cout<<newLine;

		if (isMethod) {
		std::cout<<'\n'<<"yes"<<'\n';
		//lines[line_count++] = newLine;
		char *ret = determ_return_types( newLine );
		char *temp_str = new char[300], *temp_ret = new char[100];
		strcpy(temp_str,newLine);
		strcpy(temp_ret,ret);
		interf_lines[line_count++] = new interf_line(temp_str,temp_ret);
		delete[] temp_ret;
			delete[] temp_str;
		}
		else{
	//	std::cout<<"no"<<'\n';
		delete[] newLine;
		}
		/*
		while((fIn.get(c)) && !isalpha(c) && c!='}')
			;

		if(isalpha(c))
			fIn.putback(c);
		if(c=='}'){
			fIn.putback(c);
			break;
		}
		*/

	}
		/*for(int i =0 ; i < line_count; i++){
			char temp[150];
		std::strcpy(temp,interf_lines[i]->str);
			std::cout<<temp<<std::endl;
		}*/

		return fIn;

	}
	
bool process_line(const char w[],int max){
	char c= w[0];
	int i=0;
while(c!='('&& c!=';' && i<max && c!='\0'){
	i++;
	c= w[i];
	if (c =='(') {
	return  true;
	}
	 
}
	return false;
}
char* determ_return_types(char line[] ){
char c;
int i =0,j=0;
c = line[0];
bool not_done = true;
char *ret_stat = new char[70];


while(c!= '(' && c!='\0' && (not_done)){
	j=0;
	 char *word = new char[70];
	c=line[i];
	while(isalpha(c) || (c=='[' || c==']')){
		word[j++]=c;
		i++;
		c= line[i];
	}
	word[j]='\0';
	if (j > 0) { 
	//	return_types[return_count++] = word;
          //  std::cout << word << std::endl;
		//	char *ret_stat = new char[50];
			not_done = check_word(word,ret_stat);

			if(not_done){
			//	delete[] ret_stat;
			//	delete[] word;
			}
			else{
			std::cout<<word<<std::endl;
			}


        } else {
            delete[] word;  
		}

         while (c != '(' && !isalpha(c) && c != '\0') {
            i++;
            c = line[i];
        }
	}

	return ret_stat;
}

bool check_word(const char word[], char state_to_be[]){
		if(std::strcmp(word,"public")==0){
			return true;
		}
			if(std::strcmp(word,"static")==0){
			return true;
		}
			if(std::strcmp(word,"private")==0){
			return true;
		}
			if(std::strcmp(word,"protected")==0){
			return true;
		}
			if(std::strcmp(word,"abstract")==0){
			return true;
		}
			if(std::strcmp(word,"default")==0){
			return true;
		}
			if(std::strcmp(word,"void")==0){
				std::strcat(state_to_be,"\{\n\t\treturn ;\n\t}\n\n");
				return false;
		}

			if(std::strcmp(word,"int")==0 ||std::strcmp(word,"Integer")==0 ||std::strcmp(word,"short")==0 ){
				std::strcat(state_to_be,"{\n\t\treturn -1;\n\t}\n\n");
				return false;
		}
			if(std::strcmp(word,"double")==0 || std::strcmp(word,"float")==0 || std::strcmp(word,"Double")==0 ){
		std::strcat(state_to_be,"{\n\t\treturn -1.0;\n\t}\n\n");
				return false;
		}
			if(std::strcmp(word,"char")==0 || std::strcmp(word,"Char")==0 ){
				std::strcat(state_to_be,"{\n\t\treturn ~;\n\t}\n\n");
				return false;
		}
				if(std::strcmp(word,"long")==0){
				std::strcat(state_to_be,"{\n\t\treturn -1L ;\n\t}\n\n");
				return false;
		}


		

		std::strcat(state_to_be,"{\n\t\t\treturn null ;\n\t\t}\n");
				return false;

}



std::ifstream& read_comments(std::ifstream& fIn){
	char c ;
	while(fIn.get(c) && (!isalpha(c))&& c!='/')
		;
	char n;
	if(c=='/')
		fIn.get(n);
			if(n=='*')
		while(fIn.get(c)){
				if(c=='*'){
					fIn.get(c);
					if(c=='/')
					break;
				}

		}
			return fIn;
}

 std::ifstream& read_word(std::ifstream& fIn, char word[], int& num){
	char c ;
	int i=0;
//	empty_word(word);
	fIn.get(c);
	while(c!=' '){
		word[i]=c;

	i++;
	
	fIn.get(c);
	}
	while(!isalpha(c)&& (c!='{')&&(fIn.get(c)))
		;
	if(c=='{')
	num=1;
	else{
		num=0;
		fIn.putback(c);
	}

	word[i]= '\0';
//std::cout<<word<<"\t \t";
return fIn;



}
std::ifstream& read_first_line(std::ifstream& fIn,char line[], int max){
	char c;
	while( fIn.get(c) && !std::isalpha(c) && (c!='#'))
		;
fIn.putback(c);

int i =0;
	while(fIn.get(c) && c!='{' && i<max){
	//	std::cout<<c<<"   " ;
		line[i++] =c;
	}
	line[i]='\0';
//	std::cout<<line[i];
	
//fIn.putback(c);

return fIn;
}


std::ifstream& read_impl_file(std::ifstream& fIn,std::string name){
	read_first_line(fIn, new_first_line, 200);
	std::strcat(interface_name," {");
//	std::strcpy(ne/w_first_line,f_l);
//	std::strcpy(new_first_line,interface_name);

	std::strcat(new_first_line," implements ");
	std::strcat(new_first_line,interface_name);

	std::cout<<new_first_line<<std::endl;

	read_rest_of_edit_file(fIn,name);
return fIn;
}

std::ifstream& read_rest_of_edit_file(std::ifstream& fIn,std::string file_name){
	std::ofstream ostr("tmp.txt", std::ios_base::out | std::ios_base::trunc);
	if(ostr.is_open()){
//	std::streambuf* saw  = ostr.rdbuf() ;
//	saw->open("temp.txt",std::ios_base::out);
	
	//	std::cout<<"success"<<std::endl;
	//
	
	int first_seq_count =0;
	char first_seq_ch = new_first_line[0];
		while ( first_seq_ch!='\0' ) {
			//	saw->sputc(first_seq_ch);
				first_seq_ch  = new_first_line[first_seq_count++];
				if(first_seq_ch!='\0')
					ostr.put(first_seq_ch);
		//	std::cout<<first_seq_ch<<"   ";

			}
			
			char c ;
			bool empty_file = false;
             // saw->sputc('x');
		
			 fIn.get(c);
			
			 while(!isalpha(c) && fIn.get(c) && c!='}')
				 ;

			if(c=='}')
				empty_file = true;	
				 
				 if(!empty_file){
					 fIn.get(c);
			 bool is_end =false, extra_brace = false;
			while( !fIn.eof()){
				
				if(c=='}'){
					char n;
					fIn.get(n);
					while(fIn.get(n) && (!fIn.eof()) && (!isalpha(n)) && n!='}')
						;
					
					if(fIn.eof()){
						is_end = true;
						break;
					}
					if(isalpha(n)){
						is_end = false;
						fIn.putback(n);
					}
					if(n=='}'){
						extra_brace =true;
						ostr.put(c);
						break;
					}


				}
				
			ostr.put(c);
			fIn.get(c);
		}
				 }
			
			
			
		//	ostr.flush();
		//	ostr.close();
	
	}
	else{
		std::cout<<"fail"<<std::endl;
	}

	add_interf_lines(ostr);
		ostr.flush();
		ostr.close();

//   copy_to_file("temp.txt",file_name);
	return fIn;
}

std::ofstream& add_interf_lines(std::ofstream& fOut){
	fOut.put('\n');
	for(int i = 0; i< line_count ; i++){
		int j = 0;
		char c = interf_lines[i]->str[j];
		fOut.put('\n');
		while(interf_lines[i]->str[j]!='\0'){
			
			c = interf_lines[i]->str[j++];
			if(c!='\0')
				fOut.put(c);
		
		}
		
		fOut.put('\n');
	//	fOut.put('\0');
	}

	fOut.put('}');
		return fOut;
}

void copy_to_file(const char src_file_name[], std::string dest_file_name){
	try{
	std::ifstream fIn(src_file_name);
//	std::ofstream be();
	std::ofstream fOut(dest_file_name, std::ios_base::trunc );
	std::streambuf *src_buf, *dest_buf;

	if(fIn.is_open() && fOut.is_open()){
		src_buf = fIn.rdbuf();
		dest_buf = fOut.rdbuf();
		int c ;
		c = src_buf->sbumpc();

		while (c != EOF){
			dest_buf->sputc(c);
			c = src_buf->sbumpc();
		}
		/*
		fOut.flush();
		fIn.close();
		fOut.close();
		*/
		


	}
	else{
		std::cerr<<"processs failed";
		std::exit(1);
	}
		fOut.flush();
		fIn.close();
		fOut.close();
	}
	catch(std::exception e ){
			std::cerr<<"wtf";
	}


	
}


