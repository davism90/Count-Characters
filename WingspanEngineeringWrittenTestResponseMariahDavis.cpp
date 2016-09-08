/*
Written by Mariah Danielle Davis
08/16/2016
For use only to analyze coding abilities via Wingspan Engineering's Hiring team
*/

#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

multimap <char, int> letter_number (string lowercase_string){
    multimap<char, int> letter_number_map;
    
    for (int i = 0; i < lowercase_string.size(); i++){
        multimap <char, int>::iterator find_key = letter_number_map.find(lowercase_string[i]);
        if (find_key == letter_number_map.end()){
            letter_number_map.insert(pair<char, int>(lowercase_string[i], 1));
        }
        else{
            find_key->second += 1;
        }
    }
    
    return letter_number_map;
}

string lowercase (string copy_input){
    string new_string;
    for (int i = 0; i < copy_input.size(); i++){
        if (isalpha(copy_input[i])){
           new_string += tolower(copy_input[i]);
        }
        if (isspace(copy_input[i]) || isdigit(copy_input[i])){
            new_string += copy_input[i];
        }
    }
    return new_string;
}

int main()
{
    string input = "";
    cout<< "Input a string:"<<endl;
    getline(cin, input);
    string lowercase_string = lowercase(input);
    multimap<char, int> letter_number_map = letter_number(lowercase_string);
    
    multimap<char, int>::iterator key_value;
    for (key_value = letter_number_map.begin(); key_value != letter_number_map.end(); key_value++){
        cout << key_value -> first << " : " << key_value -> second <<endl;
    }
	
    return 0;
}
