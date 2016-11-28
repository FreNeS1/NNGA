#pragma once

/*
* AUTHOR: José Antonio Díaz Mata
*/

#include <memory>
#include "Data.hpp"

namespace NNGA {

	class ConstantNode : public BaseNode
	{
	public:
		ConstantNode();
		ConstantNode(Data data);
		ConstantNode(double value, bool valid);

		Data			getData();

		virtual void	setData(Data data);
		virtual void	setData(double value, bool valid);

	protected:
		Data			_data;
	};

}