#pragma once
#include <vector>
#include "MultiMedia.h"

class Book : public MultiMedia
{
private:
	int pages;
public:
	Book(void);
	~Book(void);
};

