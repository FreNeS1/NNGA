#pragma once

/*
* AUTHOR: José Antonio Díaz Mata
*/

#include <string>
#include "Constant.hpp"

namespace NNGA {

	class OutputNode : public BaseNode
	{
	public:
		OutputNode();

		Data			getData();
		std::string		getSeed() const;

		void	setSeed(const std::string& seed);
		void	setGiver(BaseNode& giver);
		void	setGiver(BaseNodePtr giver);
			
	public:
		std::string	_seed;
		BaseNodePtr	_giver;
	};

}