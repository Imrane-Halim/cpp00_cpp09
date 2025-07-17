#pragma once
#ifndef __BITCOINEXCHANGE__
#define __BITCOINEXCHANGE__

#include <iostream>
#include <map>
#include <ctime>
#include <sstream>
#include <exception>
#include <fstream>
#include <cerrno>
#include <cstring>
#include <algorithm>

#define ERR_FILE         "Can't open file: "
#define ERR_BADINPUT     "Bad input!: "

class BitcoinExchange
{
    typedef std::map<std::tm, float> dataBase;
    dataBase _records;

    void            _load_db(const std::string& path);
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& db_path);
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    BitcoinExchange&    operator=(const BitcoinExchange& other);

    float           getValue(std::tm& date);
};

#endif