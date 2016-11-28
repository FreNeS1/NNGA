#include <iostream>
#include "Components/Components.hpp"

int main()
{
	NNGA::ConstantNode a = NNGA::ConstantNode(2.0, true);
	NNGA::ConstantNode b = a;
	b.setData(4.0, true);
	NNGA::OutputNode c = NNGA::OutputNode();
	c.setData(a.getdata() + b.getdata());

	std::cout << c.getdata().getValue() << "/" << c.getdata().getValid();

	c.setData(0, true);

}