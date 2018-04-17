// /***********************BIG SIX**********************/
// HuffmanNode::HuffmanNode(char k, int f) : key(k), frequency(f)
// {
//     // std::cout << "Constructor with initialisation called" << std::endl;

//     //default constructor - define in .cpp
// }

// HuffmanNode::HuffmanNode(std::shared_ptr<HuffmanNode> left_child, std::shared_ptr<HuffmanNode> right_child) : left_child_node(left_child), right_child_node(right_child)
// {
//     // std::cout << "Parent of children constructor called" << std::endl;
//     frequency = left_child->getFrequency() + right_child->getFrequency();
// }

// HuffmanNode::HuffmanNode()
// {
//     // std::cout << "Default constructor called" << std::endl;
// }

// HuffmanNode::~HuffmanNode()
// {
//     //destructor - define in .cpp file
// }
// HuffmanNode::HuffmanNode(const HuffmanNode &other) : key(other.key), frequency(other.frequency)
// {
//     // std::cout << "Copy constructor called" << std::endl;

//     //Copy constructor
//     if (other.getLeftChild() != nullptr)
//         setLeftChild(other.getLeftChild());
//     if (other.getRightChild() != nullptr)
//         setRightChild(other.getRightChild());
// }

// HuffmanNode &HuffmanNode::operator=(const HuffmanNode &other)
// {
//     // std::cout << "Assignment operator called" << std::endl;

//     //Assignment operator
//     this->frequency = other.getFrequency();
//     this->key = other.getKey();
//     if (other.getLeftChild() != nullptr)
//         setLeftChild(other.getLeftChild());
//     if (other.getRightChild() != nullptr)
//         setRightChild(other.getRightChild());

//     return *this;
// }

// HuffmanNode::HuffmanNode(HuffmanNode &&other) : key(char('\0')), frequency(0), left_child_node(nullptr), right_child_node(nullptr)
// {
//     // std::cout << "Move constructor called" << std::endl;

//     //Move constructor
//     setKey(other.getKey());
//     setFrequency(other.getFrequency());
//     setLeftChild(std::move(other.getLeftChild()));   //std::make_shared<HuffmanNode>(std::move(other.left));
//     setRightChild(std::move(other.getRightChild())); //std::make_shared<HuffmanNode>(std::move(other.right));

//     other.setKey(char(-2));
//     other.setFrequency(0);
//     other.setLeftChild(nullptr);
//     other.setRightChild(nullptr);
// }

// HuffmanNode &HuffmanNode::operator=(HuffmanNode &&other)
// {
//     // std::cout<<"Move assignment operator called"<<std::endl;
//     //Move assignment operator
//     if (this != &other)
//     {
//         setLeftChild(nullptr);
//         setRightChild(nullptr);
//         setKey(char(-2));
//         setFrequency(0);

//         setKey(other.getKey());
//         setFrequency(other.getFrequency());
//         setLeftChild(std::move(other.getLeftChild()));   //std::make_shared<HuffmanNode>(std::move(other.left));
//         setRightChild(std::move(other.getRightChild())); //std::make_shared<HuffmanNode>(std::move(other.right));

//         other.setKey(char(-2));
//         other.setFrequency(0);
//         other.setLeftChild(nullptr);
//         other.setRightChild(nullptr);
//     }
// }
// ///////////////////////////////////////////////////

// /****************RELATIONAL OPERATOR OVERLOADING***************/
// bool HuffmanNode::operator==(const HuffmanNode &other) const
// {
//     if (getKey() != other.getKey())
//         return false;

//     if (getFrequency() != other.getFrequency())
//         return false;

//     if (getLeftChild() == nullptr && other.getLeftChild() == nullptr)
//         return true;
//     if (!(getLeftChild() == nullptr) != !(other.getLeftChild() == nullptr))
//         return false; //Implement XOR, if one is null but the other isn't then they aren't equal
//     if (*getLeftChild() != *other.getLeftChild())
//         return false;
//     if (getRightChild() == nullptr && other.getRightChild() == nullptr)
//         return true;
//     if (!(getRightChild() == nullptr) != !(other.getRightChild() == nullptr))
//         return false;
//     if (*getRightChild() != *other.getRightChild())
//         return false;

//     return true;
// }

// bool HuffmanNode::operator!=(const HuffmanNode &other) const
// {

//     return !(*this == other); //Isn't always true (generally) but works for this assignment
// }
// ///////////////////////////////////////////////////
