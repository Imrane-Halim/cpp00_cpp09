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

    // @note can throw exceptions
    void            _load_db(const std::string& path);
public:
    // loads database from crnt root dict: ./data.csv
    BitcoinExchange();
    BitcoinExchange(const std::string& db_path);
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    BitcoinExchange&    operator=(const BitcoinExchange& other);

    // @return btc value at `date`, if `date` 
    //  is not in DB it returns lowest closest date
    float           getValue(std::tm& date);
};

#endif