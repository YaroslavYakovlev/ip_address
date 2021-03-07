#include <iostream>
#include <cstring>

bool validator(std::string strIP){
    for(int i = 0; i < strIP.length(); i++){
        if((strIP[i] == '0' && strIP[i + 1] == '0' && (strIP[i] != strIP[strIP.length() - 1]))
          || ((strIP[i] == '.' && strIP[i + 1] == '.') && (strIP[i] != strIP[strIP.length() - 1]))
            || (strIP[strIP[i]] >= '0' && strIP[strIP[i]] <= '9')
            ){
            return false;
        }
    } 
    if(strIP.length() < 1 || strIP.length() > 4){
        return false;
    }
    return true;
}
bool partOne(std::string strIP){
    std::string strPatrOne;
    strPatrOne = strIP.substr(0, strIP.find("."));
    if(strPatrOne.empty()){
        return false;
    }
    std::cout << "Part - 1: " << strPatrOne << std::endl;
    if(!validator(strPatrOne)){
        return false;
    }
    return true;
}
bool partTwo(std::string strIP){
    std::string strPartTwo;
    strPartTwo = strIP.substr((strIP.find(".") + 1), strIP.find('.'));
    // strPartTwo = std::strtok (strIP, '.');
    if(strPartTwo.empty()){
        return false;
    }
    std::cout << "Part - 2: " << strPartTwo << std::endl;
    if(!validator(strPartTwo)){
        return false;
    } 
    return true;
}
// bool partTree(std::string strIP){
//     std::string strPatrTree;
//     strPatrTree = strIP.substr(((strIP.find(".")), strIP.find('.')));
//     if(strPatrTree.empty()){
//         return false;
//     }
//     std::cout << "Part - 3: " << strPatrTree << std::endl;
//     return true;
// }
// bool partFour(std::string strIP){
//     std::string strPatrFour;
//     strPatrFour = strIP.substr((strIP.find(".") + 1), strIP.length());
//     if(strPatrFour.empty()){
//         return false;
//     }
//     std::cout << "Part - 4: " << strPatrFour << std::endl;
//     return true;
// }

int main()
{
    std::string strIP_address;  
	std::cout << "Validation IP-address" << std::endl;
    std::cin >> strIP_address;
    if(partOne(strIP_address) && partTwo(strIP_address) 
    //   && partTree(strIP_address) && partFour(strIP_address)
      ){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl; 
    }
    return 0;
}