//main.cpp
#include "Config.h"

int main()
{
    int port;
    std::string ipAddress;
    std::string username;
    std::string password;
    std::string ok;
    const char ConfigFile[]= "config.txt";
    Config configSettings(ConfigFile);

    port = configSettings.Read("port", 0);
    ipAddress = configSettings.Read("ipAddress", ipAddress);
    username = configSettings.Read("username", username);
    password = configSettings.Read("password", password);
    ok = configSettings.Read("ok", ok);
    std::cout<<"port:"<<port<<std::endl;
    std::cout<<"ipAddress:"<<ipAddress<<std::endl;
    std::cout<<"username:"<<username<<std::endl;
    std::cout<<"password:"<<password<<std::endl;
    std::cout<<"ok:"<<ok<<std::endl;

    return 0;
}
