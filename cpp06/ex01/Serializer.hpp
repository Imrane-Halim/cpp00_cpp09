#pragma once
#ifndef	__SERIALIZER__
#define	__SERIALIZER__

#include <iostream>
#include <stdint.h>
#include "data.hpp"

class Serializer
{
	Serializer();
	~Serializer();
public:
	static uintptr_t	serializer(Data *ptr);
	static Data*		deserializer(uintptr_t raw);
};

#endif