#include "BitcoinExchange.hpp"

bool	is_valid_format(std::string& line, std::string arr[3])
{
	if (line.find(" | ") == std::string::npos)
		return false;
	
	// std::string 		date, delem, value;
	std::stringstream 	ss(line);

	ss >> arr[0]; // date
	ss >> arr[1]; // delem
	ss >> arr[2]; // value

	if (arr[1].empty() || arr[1] != "|")
		return false;
	if (arr[0].empty() || arr[0].find_first_not_of("0123456789-") != std::string::npos)
		return false;
	if (arr[2].empty() || arr[2].find_first_not_of("0123456789.-") != std::string::npos)
		return false;
		
	if (!ss.eof())
		return false;

	return true;
}
bool	is_valid_value(std::string& str, float& value)
{
	char*	end = NULL;
	
	value = strtof(str.c_str(), &end);
	if (*end)
		return false;
	if (value < 0 || value > 1000)
		return false;
	return true;
}
bool	is_valid_date(std::string& str, std::tm& date)
{
	if (!strptime(str.c_str(), "%Y-%m-%d", &date))
		return false;
	size_t pos = str.find_last_of('-');
	// to check things like: 2024-12-99
	if (str[pos + 1] > '3' && str[pos + 2] > '1')
		return false;
	return true;
}

void	print_line_res(std::string& line, BitcoinExchange& db)
{
	std::string arr[3];
	if (!is_valid_format(line, arr))
	{
		std::cout << "Error: invalid format (`date | value`): " + line << std::endl;
		return;
	}

	float 	value;
	if (!is_valid_value(arr[2], value))
	{
		std::cout << "Error: Invalid value (0-1000): " + line << std::endl;
		return;
	}
			
	std::tm date;
	if (!is_valid_date(arr[0], date))
	{
		std::cout << "Error: Invalid Date: " + line << std::endl;
		return;
	}

	float db_value  = db.getValue(date);
	if (db_value == -1)
		std::cout << "Error: Date too low: " + line << std::endl;
	else
		std::cout << arr[0] << " => " << value << " = " << value * db_value << std::endl;
}

void	print_input_res(BitcoinExchange& db, const std::string& input_path)
{
	std::ifstream 	input(input_path.c_str());
	if (!input.is_open())
		throw(std::runtime_error(ERR_FILE + std::string(std::strerror(errno))));
	
	std::string		line;
	if (!std::getline(input, line) || line != "date | value")
		throw(std::runtime_error("expected first line: `date | value`"));
	
	while (std::getline(input, line))
	{
		if (line.empty()) continue;
		print_line_res(line, db);
	}
	input.close();
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "usage: ./btc <INPUT>" << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		BitcoinExchange btc("data.csv");
		print_input_res(btc, av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}