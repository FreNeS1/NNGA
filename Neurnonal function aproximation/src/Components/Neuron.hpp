#pragma once

/*
* AUTHOR: José Antonio Díaz Mata
*/

#include <string>
#include <vector>
#include "Constant.hpp"

namespace NNGA {

	class NeuronNode : public BaseNode
	{
	public:
		NeuronNode();

		void			configure(std::vector<BaseNode>& inputs, std::vector<BaseNode>& weights);
		void			configure(std::vector<BaseNodePtr>& inputs, std::vector<BaseNodePtr>& weights);

		Data			getData();
		std::string		getSeed() const;
		void			setSeed(const std::string& seed);

	public:
		std::string	_seed;
		size_t		_degree;
		Data		_data;
		bool		_calculated;
		bool		_infiniteLoopCatch;

		std::vector<BaseNodePtr>	_inputs;
		std::vector<BaseNodePtr>	_weights;
	};

}