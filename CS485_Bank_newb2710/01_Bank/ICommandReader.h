#pragma once
#include <string>

class ICommandReader {
	public:
		virtual bool open(std::string file) = 0;
	private:

};