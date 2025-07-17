#include "BitcoinExchange.hpp"

// this operator was added so `std::tm` can be used as a key in std::map
inline bool operator<(const std::tm& a, const std::tm& b)
{
    if (a.tm_year != b.tm_year)
        return a.tm_year < b.tm_year;
    if (a.tm_mon != b.tm_mon)
        return a.tm_mon < b.tm_mon;
    return a.tm_mday < b.tm_mday;
}

BitcoinExchange::BitcoinExchange()
{
    _load_db("data.csv");
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _records(other._records) { }
BitcoinExchange::BitcoinExchange(const std::string& db_path)
{
   _load_db(db_path);
}
BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _records = other._records;
    return *this;
}

void    BitcoinExchange::_load_db(const std::string& path)
{
    std::ifstream   db(path.c_str());
    std::string     line;

    if (!db.is_open())
        throw(std::runtime_error("DB: " ERR_FILE + std::string(std::strerror(errno))));

    // this line skips the first line in the file
    std::getline(db, line);

    while (std::getline(db, line))
    {
        if (line.empty()) continue;

        std::tm tm;
        size_t  pos = line.find(',');
        strptime(line.substr(0, pos).c_str(), "%Y-%m-%d", &tm);
        _records[tm] = strtof(line.substr(pos + 1).c_str(), NULL);
    }
    db.close();
}

float   BitcoinExchange::getValue(std::tm& tm)
{
    dataBase::iterator it = _records.find(tm);
    if (it != _records.end())
        return it->second;
    dataBase::reverse_iterator it1;
    for (it1 = _records.rbegin(); it1 != _records.rend(); ++it1)
        if (it1->first < tm) return it1->second;
    return -1;
}