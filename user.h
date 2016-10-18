#pragma once
#include<string>

/*
Struct made for highscores - representing user.
*/
struct user
{
	std::string name;
	int score;
	bool operator<(const user& a) const
	{
		return score > a.score;
	}
};