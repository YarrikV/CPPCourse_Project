#ifndef CLASSPARSER_H
#define CLASSPARSER_H

#include <string>

#include "world.h"

class classParser
{
public:
    std::string pathToFile;
    classParser(std::string);

    std::string parseWord();
    int parseInt();
    float parseFloat();
    void parseSymbol(std::string);
    void parseWhiteSpace();

    Feature parseFeature();
    Vehicle parseVehicle();


};

#endif // CLASSPARSER_H
