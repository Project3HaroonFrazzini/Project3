#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int split(string input_string,char separator,string arr[],int arr_size){
    if(input_string == ""){
        return 0;
    }
    int count = 0;
    for(int i = 0; i < input_string.length(); i++){
        if(input_string[i] == separator){
            arr[count] = input_string.substr(0,i);
            input_string = input_string.substr(i+1);
            count++;
            i = 0;
        }
    }
    arr[count] = (input_string);
    if(count +1 > arr_size){
        return -1;
    }
    return ++count;
}