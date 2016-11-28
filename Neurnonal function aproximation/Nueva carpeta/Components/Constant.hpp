#pragma once

/*
* AUTHOR: Jos� Antonio D�az Mata
*/

#include "Data.hpp"

namespace NNGA {

	class ConstantNode
	{
	public:
		ConstantNode();
		ConstantNode(Data data);
		ConstantNode(double value, bool valid);

		Data			getdata() const;

		virtual void	setData(Data data);
		virtual void	setData(double value, bool valid);

	protected:
		Data			_data;
	};

}