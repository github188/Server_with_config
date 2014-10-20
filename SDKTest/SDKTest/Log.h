#include <time.h>
#include <iostream>
void write(std::string str){
	
	std::FILE * file;
	file=fopen("log.txt","ab+");
	time_t rawtime;
	time ( &rawtime );
	char * time = ctime(&rawtime);
	str.append(":");
	str.append(time);
	std::string rstr="\r\n";
	rstr+=str;
	fwrite(rstr.c_str(),str.size(),1,file);
	fclose(file);
}