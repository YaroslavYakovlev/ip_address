#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

bool validator(std::string strIP){
    for(int i = 1; i <= strIP.length(); i++){
         if((((strIP[0] == '0') && (strIP[i] == '0' && strIP[i + 1] == '0')) 
           && (strIP[i - 1] != strIP[strIP.length() - 1]))
             || (!isdigit(strIP[i - 1]))
                 || ((strIP[i - 1] == '0') && (strIP[i] > '0'))){
            return false;
        }
    }    
    if(((strIP[0] == '0') && (strIP[1] == '0'))){
        return false;
    }
    for(int i = 0; i < strIP.length(); i++){
        if((strIP[i] >= '2') && ((strIP[i+1] >= '5') 
           && (strIP[i] != strIP[strIP.length() - 1])) 
             && ((strIP[i+2] > '5') 
               && (strIP[i] != strIP[strIP.length() - 1]))){
            return false;
            
        }
    }
    return true;
}
std::string parsIp(std::string strIP, int part){
    for(int i = 0; i < part; i++){
        strIP = strIP.erase(0, strIP.find(".") + 1);
    }
    strIP = strIP.substr(0, strIP.find("."));
    return strIP;
}
bool genelalPart(std::string strIP, int countPoint){
    std::string strPatr;
    for(int i = 0; i < countPoint; i++){
        strPatr = parsIp(strIP, i);
        if(!validator(strPatr) || strPatr.length() > 3){
            return false;
        }
    }
    if(strPatr.empty()){
        return false;
    }
    return true;
}

int main()
{
    std::string strIP_address;  
    bool flag = true;
    int countPoint = 0;
	std::cout << "Validation IP-address" << std::endl;
    std::cin >> strIP_address;
    for(int i = 0; i < strIP_address.length() - 1; i++){
        if((strIP_address[i] == '.' && strIP_address[i + 1] == '.') 
          && (strIP_address[i] != strIP_address[strIP_address.length() - 1])){
            flag = false;
            break;
        }
        else if((strIP_address[i] == '.')){
            countPoint++;
        }
        
    }
    if((strIP_address[strIP_address.length() - 1] != '.')){
        countPoint++;
    }
    if((strIP_address[strIP_address.length() - 1] == '.') || strIP_address[0] == '.'){
        flag = false;
    }

    if(flag && genelalPart(strIP_address, countPoint)){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl; 
    }
    return 0;
}