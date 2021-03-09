#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

bool validator(std::string strIP){
    for(int i = 0; i < strIP.length(); i++){
        if((strIP[i] == '0' && strIP[i + 1] == '0')
           || (!isdigit(strIP[i]))){
            return false;
        }
    }
    
    if((strIP[0] == '0') && (strIP[1] > '0')){
        return false;
    }
    if((strIP[0] > '2' && strIP[1] > '5' 
        && strIP[2] > '5')){
        return false;
    }
    return true;
}
std::string parthIp(std::string strIP, int part){
    for(int i = 0; i < part; i++){
        strIP = strIP.erase(0, strIP.find(".") + 1);
    }
    strIP = strIP.substr(0, strIP.find("."));
    return strIP;
}
bool partOne(std::string strIP){
    std::string strPatrOne;
    strPatrOne = strIP.substr(0, strIP.find("."));
    if(strPatrOne.empty()){
        return false;
    }
    std::cout << "Part - 1: " << strPatrOne << std::endl;
    if(!validator(strPatrOne) || strPatrOne.length() > 3){
        return false;
    }
    return true;
}
bool partTwo(std::string strIP){
    std::string strPartTwo;
    strPartTwo = parthIp(strIP, 1);
    if(strPartTwo.empty()){
        return false;
    }
    std::cout << "Part - 2: " << strPartTwo << std::endl;
    if(!validator(strPartTwo) || strPartTwo.length() > 3){
        return false;
    }
    return true;
}
bool partTree(std::string strIP){
    std::string strPatrTree;
    strPatrTree = parthIp(strIP, 2);
    if(strPatrTree.empty()){
        return false;
    }
    std::cout << "Part - 3: " << strPatrTree << std::endl;
    if(!validator(strPatrTree) || strPatrTree.length() > 3){
        return false;
    }
    return true;
}
bool partFour(std::string strIP){
    std::string strPatrFour;
    strPatrFour = parthIp(strIP, 3);
    if(strPatrFour.empty()){
        return false;
    }
    std::cout << "Part - 4: " << strPatrFour << std::endl;
    if(!validator(strPatrFour) || strPatrFour.length() > 3){
        return false;
    }
    return true;
}

int main()
{
    std::string strIP_address;  
    bool flag = true;
	std::cout << "Validation IP-address" << std::endl;
    std::cin >> strIP_address;
    for(int i = 0; i < strIP_address.length(); i++){
        if((strIP_address[i] == '.' && strIP_address[i + 1] == '.') 
          && (strIP_address[i] != strIP_address[strIP_address.length() - 1])){
            flag = false;
            break;
        }
    }
    if(strIP_address[strIP_address.length() - 1] == '.'){
        flag = false;
    }
    if(flag && partOne(strIP_address) && partTwo(strIP_address) 
    && partTree(strIP_address) && partFour(strIP_address)
      ){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl; 
    }
    return 0;
}