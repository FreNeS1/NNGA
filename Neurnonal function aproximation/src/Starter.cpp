#include <iostream>
#include "Components/Components.hpp"

int main()
{
	std::shared_ptr<NNGA::ConstantNode> x1 = std::make_shared<NNGA::ConstantNode>(NNGA::ConstantNode(1.0, true));
	std::shared_ptr<NNGA::ConstantNode> x2 = std::make_shared<NNGA::ConstantNode>(NNGA::ConstantNode(2.0, true));
	std::shared_ptr<NNGA::ConstantNode> x3 = std::make_shared<NNGA::ConstantNode>(NNGA::ConstantNode(-3.0, true));
	std::shared_ptr<NNGA::OutputNode> sum = std::make_shared<NNGA::OutputNode>(NNGA::OutputNode());
	std::shared_ptr<NNGA::OutputNode> mult = std::make_shared<NNGA::OutputNode>(NNGA::OutputNode());
	std::shared_ptr<NNGA::OutputNode> x3mult = std::make_shared<NNGA::OutputNode>(NNGA::OutputNode());

	std::shared_ptr<NNGA::ConstantNode> c1 = std::make_shared<NNGA::ConstantNode>(NNGA::ConstantNode(1.0, true));
	std::shared_ptr<NNGA::ConstantNode> c2 = std::make_shared<NNGA::ConstantNode>(NNGA::ConstantNode(3.0, true));

	std::shared_ptr<NNGA::NeuronNode> n1 = std::make_shared<NNGA::NeuronNode>(NNGA::NeuronNode());
	std::vector<NNGA::BaseNode::BaseNodePtr> n1inputs;
	std::vector<NNGA::BaseNode::BaseNodePtr> n1weights;
	n1inputs.push_back(x1);
	n1inputs.push_back(x2);
	n1inputs.push_back(x3);
	n1weights.push_back(c1);
	n1weights.push_back(c1);
	n1weights.push_back(c1);
	n1->configure(n1inputs, n1weights);

	std::shared_ptr<NNGA::NeuronNode> n2 = std::make_shared<NNGA::NeuronNode>(NNGA::NeuronNode());
	std::vector<NNGA::BaseNode::BaseNodePtr> n2inputs;
	std::vector<NNGA::BaseNode::BaseNodePtr> n2weights;
	n2inputs.push_back(x1);
	n2weights.push_back(x2);
	n2->configure(n2inputs, n2weights);

	std::shared_ptr<NNGA::NeuronNode> n3 = std::make_shared<NNGA::NeuronNode>(NNGA::NeuronNode());
	std::vector<NNGA::BaseNode::BaseNodePtr> n3inputs;
	std::vector<NNGA::BaseNode::BaseNodePtr> n3weights;
	n3inputs.push_back(x3);
	n3weights.push_back(n2);
	n3->configure(n3inputs, n3weights);

	std::shared_ptr<NNGA::NeuronNode> n4 = std::make_shared<NNGA::NeuronNode>(NNGA::NeuronNode());
	std::vector<NNGA::BaseNode::BaseNodePtr> n4inputs;
	std::vector<NNGA::BaseNode::BaseNodePtr> n4weights;
	n4inputs.push_back(n3);
	n4weights.push_back(c2);
	n4->configure(n4inputs, n4weights);

	sum->setGiver(n1);
	mult->setGiver(n3);
	x3mult->setGiver(n4);

	std::cout << "Sum of " << x1->getData().getValue() << " + " << x2->getData().getValue() << " + " << x3->getData().getValue() << " is: " << sum->getData().getValue() << " (" << sum->getData().getValid() << ")" << std::endl;
	std::cout << "Multiplication of " << x1->getData().getValue() << " * " << x2->getData().getValue() << " * " << x3->getData().getValue() << " is: " << mult->getData().getValue() << " (" << mult->getData().getValid() << ")" << std::endl;
	std::cout << "3 times last operation is " << x3mult->getData().getValue() << " (" << x3mult->getData().getValid() << ")" << std::endl;
}