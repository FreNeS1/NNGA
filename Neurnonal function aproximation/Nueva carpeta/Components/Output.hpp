#pragma once

/*
* AUTHOR: José Antonio Díaz Mata
*/

#include <string>
#include "Constant.hpp"

namespace NNGA {

	class OutputNode : public ConstantNode
	{
	public:
		OutputNode();
		OutputNode(Data data);
		OutputNode(double value, bool valid);

		std::string	getSeed() const;
		void		setSeed(const std::string& seed);

	public:
		std::string	_seed;
	};

}