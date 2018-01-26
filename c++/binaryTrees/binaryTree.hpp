#include <iostream>

template <typename T>
class BinaryTree
{
    public:
        struct Node
        {
            Node(T _data, Node* _left = nullptr, Node* _right = nullptr):
                data(_data), left(_left), right(_right)
            {
            }

            T data;
            Node *left, *right;
        };

        struct BinaryTreeIterator
        {
            BinaryTreeIterator(Node* const& startNode):
                currentPos(startNode)
            {
            }

            T getData()
            {
                return currentPos->data;
            }

            bool isNull()
            {
                return !currentPos;
            }

            void left()
            {
                if(!currentPos)
                    return;

                currentPos = currentPos->left;
            }

            void right()
            {
                if(!currentPos)
                    return;
                
                currentPos = currentPos->right;
            }

            Node* currentPos;
        };

    public:
        BinaryTree(T data, BinaryTree* const& left = nullptr, BinaryTree* const& right = nullptr):
            _root(nullptr)
        {
            _root = new Node(data, cpyTree(left), cpyTree(right));
        }

        BinaryTree(BinaryTree const& other)
        {
            _root = cpyNode(other._root);
        }

        BinaryTree& operator= (BinaryTree const& other)
        {
            if(this != &other)
            {
                deleteTree(_root);
                _root = cpyNode(other._root);
            }

            return *this;
        }

        ~BinaryTree()
        {
            deleteTree(_root);
        }

        void print()
        {
            std::cout << printTree(_root) << std::endl;
        }

        Node* getRoot() { return _root; }

        BinaryTreeIterator getIterator()
        {
            return BinaryTreeIterator(_root);
        }

    private:
        Node* cpyTree(BinaryTree* const& other)
        {
            if(!other)
                return nullptr;
            
            return cpyNode(other->_root);
        }
        
        Node* cpyNode(Node* const& other)
        {
            if(!other)
                return nullptr;
            
            return new Node (other->data, cpyNode(other->left), cpyNode(other->right));
        }

        void deleteTree(Node* root)
        {
            if(!root)
                return;

            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }

        std::string printTree(Node* const& root)
        {
            if(!root)
                return "Null";

            return std::to_string(root->data) + " (" + printTree(root->left) + ", " + printTree(root->right) + ")";
        }

        Node* _root;
};