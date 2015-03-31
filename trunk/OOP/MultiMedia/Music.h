#pragma once
#include <vector>
#include "MultiMedia.h"

class Music : public MultiMedia
{
private:
	vector<string> title;
	vector<string> genre;
	vector<int> time;

public:
	Music(void);
	~Music(void);
};

