#pragma once
#include <vector>
#include "MultiMedia.h"

class Game : public MultiMedia
{
private:
	vector<string> title;
	vector<string> publisher;
public:
	Game(void);
	~Game(void);
};

