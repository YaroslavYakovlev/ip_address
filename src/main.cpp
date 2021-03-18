#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

bool validator(std::string strIP){
    for(int i = 0; i < strIP.length(); i++){
        if(!isdigit(strIP[i]))
            return false; 
    }
    if((strIP.length() > 1) && (strIP[0] == '0'))
        return false;    

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
        int part = std::stoi(strPatr);
        if(part > 255){
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

// В функции validator вам нужно цикл делать не пока i <= strIP.length(), а должно быть строгое сравнение i < strIP.length(). Иначе вот здесь будут ошибки:

//     for (int i = 1; i <= strIP.length(); i++)
//     {
//         if ((((strIP[0] == '0') && (strIP[i] == '0' && strIP[i + 1] == '0'))
// На последней итерации обращение к i-му элементу будет уже за границы (так как обращение к N-му элементу, а индексы элементов всего от 0 до N-1). А при обращении к i+1-му тем более

// Дальше в цикле то же самое

// Вам нужно проходить по IP-адресу от точки до точки. Как только встретили точку, то всё, что прошли, можно взять в отдельную строку и рассматривать как отдельное число. Если в этом числе больше одного символа и первый символ 0, то это ошибка (так как не может быть числа 01, например). Дальше, это число можно сконвертировать в целое с помощью функции std::stoi. Если конвертация прошла успешна и число не > 255, значит всё хорошо. И всё, больше особо ничего не нужно проверять