#include <iostream>
#include <string>
#include <string>
#include <locale>
#include <codecvt>
#include <fstream>
#include <bitset>
// #include <string.h>
// #include <ctime>
// #include <stdio.h>
// #include <cstdlib>
// #include <math.h>

std::string map_to_utf8(const int val) {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    return converter.to_bytes(static_cast<char32_t>(val));
}

int main(){
	std::ofstream out("all_unicode.txt");
	unsigned int unihex = 0x000fffff;
	if(out.is_open()){
		for(int i=0; i<=unihex; i++){
			if(i%16==0) out << std::hex << i << "~" << i+15 << ": ";
			out << map_to_utf8(i);
			(i%16==15)?out << "\n":out << " ";
		}
		out.close();
	}
	
	return 0;
} 
