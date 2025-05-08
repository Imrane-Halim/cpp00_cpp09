#include <typeinfo>
#include "Serializer.hpp"

int main(void) {
	Data	data;
	data.first_name = "Mohammed";
	data.last_name = "Ali";
	data.age = 79;
	data.gender = MALE;
	data.status = MARRIED;

	uintptr_t sdata = Serializer::serializer(&data);
	std::cout << "==> uint ptr : " << sdata << std::endl;

	Data	*ddata = Serializer::deserializer(sdata);
	std::cout << std::endl;
	std::cout << "first name: " << ddata->first_name << std::endl;
	std::cout << "last name : " << ddata->last_name << std::endl;
	std::cout << "age       : " << ddata->age << std::endl;
	std::cout << "gender    : " << ddata->gender << std::endl;
	std::cout << "m status  : " << ddata->status << std::endl;

}