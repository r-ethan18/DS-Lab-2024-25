// Program to Implement the Tree data structure using C++

#include <iostream>
#include <queue>
#include <stack>

class tree
{
private:
    struct node
    {
        char data;
        struct node *left;
        struct node *right;
    };
    struct node *root;
    struct node *expRoot;

    struct node *foundPos;

public:
    tree();
    int insert(char);
    struct node *freeLOPos();
    void traversalSelect(int);
    struct node *inorder(struct node *);
    struct node *preorder(struct node *);
    struct node *postorder(struct node *);
    struct node *searchFor(char, struct node *);
    bool isFound(char);

    void makeExpTree(std::string);
};

std::string convertInToPost(std::string);
bool isValidOperator(char);

int main()
{
    tree WTOG;
    tree expTree;
    int choice = 0;

    std::string postfixExp;

    while (choice != 11)
    {
        std::cout << "\nMENU:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Inorder\n";
        std::cout << "3. Preorder\n";
        std::cout << "4. Postorder\n";
        std::cout << "5. Search\n";
        std::cout << "6. To Postfix\n";
        std::cout << "7. Make Expression Tree\n";
        std::cout << "8. Expression Tree Inorder\n";
        std::cout << "9. Expression Tree Preorder\n";
        std::cout << "10. Expression Tree Postorder\n";
        std::cout << "11. Exit\n";
        std::cout << "\nEnter Choice: ";

        std::cin >> choice;

        if (choice == 1)
        {
            char inChar;

            std::cout << "Enter the input Character: ";
            std::cin >> inChar;

            WTOG.insert(inChar);
        }
        else if (choice == 2 || choice == 3 || choice == 4 || choice == 8 || choice == 9 || choice ==10)
        {
            WTOG.traversalSelect(choice);
        }
        else if (choice == 5)
        {
            char key;

            std::cout << "Enter the key: ";
            std::cin >> key;

            if (WTOG.isFound(key))
            {
                std::cout << key << " exists in the tree!\n";
            }
            else
            {
                std::cout << key << " does not exist in the tree!\n";
            }
        }
        else if (choice == 6)
        {
            std::string usrInfix;
            
            std::cout << "Enter the infix expression: ";
            std::cin >> usrInfix;

            postfixExp = convertInToPost(usrInfix);

            std::cout << "Postfix Expression Saved!\n";
        }
        else if (choice == 7)
        {
            if (postfixExp != "")
            {
                WTOG.makeExpTree(postfixExp);
            }
            else
            {
                std::cout << "No postfix Expression Loaded!\n";
            }
        }
        else if (choice == 11)
        {
            std::cout << "Exiting...\n";
        }
        else
        {
            std::cout << "Invalid Choice!\n";
        }
    }
}

tree::tree()
{
    root = NULL;
    expRoot = NULL;
    foundPos = NULL;
}

// Function to insert the char into the appropriate location in the Tree
// (based on level order)
int tree::insert(char inData)
{
    node *newNode = new struct node;
    newNode->data = inData;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
        std::cout << "Inserted to the ROOT at: " << root << "\n";
        return 0;
    }
    else
    {
        node *insertPos = freeLOPos();

        if (insertPos->left == NULL)
        {
            insertPos->left = newNode;
            std::cout << "Inserted " << inData << " to the left of " << insertPos << " (" << insertPos->data << ")" << " at: " << insertPos->left << "\n";
        }
        else
        {
            insertPos->right = newNode;
            std::cout << "Inserted " << inData << " to the right of " << insertPos << " (" << insertPos->data << ")" << " at: " << insertPos->right << "\n";
        }

        return 0;
    }

    return 1;
}

// Function to find the first free level order address in the tree
tree::node *tree::freeLOPos()
{
    std::queue<node *> treeQ;
    node *temp = root;

    treeQ.push(temp);

    while (1)
    {
        if (temp->left != NULL)
        {
            treeQ.push(temp->left);
        }
        else
        {
            return temp;
        }
        if (temp->right != NULL)
        {
            treeQ.push(temp->right);
        }
        else
        {
            return temp;
        }

        treeQ.pop();
        // std::cout << "Free Pos: " << treeQ.front() << "\n";
        temp = treeQ.front();
    }
}

// Function to implement INORDER traversal
tree::node *tree::inorder(node *cur)
{
    if (cur == NULL)
    {
        return NULL;
    }
    else
    {
        inorder(cur->left);
        std::cout << cur->data << " ";
        inorder(cur->right);
    }
    return NULL;
}

// Function to implement PREORDER traversal
tree::node *tree::preorder(node *cur)
{
    if (cur == NULL)
    {
        return NULL;
    }
    else
    {
        std::cout << cur->data << " ";
        preorder(cur->left);
        preorder(cur->right);
    }
    return NULL;
}

// Function to implement POSTORDER traversal
tree::node *tree::postorder(node *cur)
{
    if (cur == NULL)
    {
        return NULL;
    }
    else
    {
        postorder(cur->left);
        postorder(cur->right);
        std::cout << cur->data << " ";
    }
    return NULL;
}

// Helper function to select the traversal method according to the parameter 'inChoice'
// 2 - Inorder | 3 - Preorder | 4 - Postorder
void tree::traversalSelect(int inChoice)
{
    if (inChoice == 2)
    {
        inorder(root);
        std::cout << "\n";
    }
    else if (inChoice == 3)
    {
        preorder(root);
        std::cout << "\n";
    }
    else if (inChoice == 4)
    {
        postorder(root);
        std::cout << "\n";
    }
    else if (inChoice == 8)
    {
        inorder(expRoot);
        std::cout << "\n";
    }
    else if (inChoice == 9)
    {
        preorder(expRoot);
        std::cout << "\n";
    }
    else if (inChoice == 10)
    {
        postorder(expRoot);
        std::cout << "\n";
    }
}

// Function to search for a value in the tree, if it doesn't exist returns NULL
tree::node *tree::searchFor(char inKey, node *cur)
{
    if (cur == NULL)
    {
        return NULL;
    }
    else
    {
        searchFor(inKey, cur->left);
        if (cur->data == inKey)
        {
            foundPos = cur;
        }
        searchFor(inKey, cur->right);
    }
    return foundPos;
}

// Function to check if an element exists in the tree
bool tree::isFound(char inKey)
{
    if (searchFor(inKey, root) != NULL)
    {
        foundPos = NULL;
        return true;
    }
    else
        return false;
}

// Function to convert an infix expression into a postfix expression
std::string convertInToPost(std::string infix)
{
    std::string postfix = "";
    int strLen = infix.size();

    std::stack<char> opStack;

    for (int i = 0; i < strLen; i++)
    {
        char chr = infix[i];

        if (isValidOperator(chr))
        {
            if (chr == '*' || chr == '/' || chr == '%')
            {
                postfix = postfix + infix[i+1];
                i = i+1;

                opStack.push(chr);
                while (!opStack.empty())
                {
                    postfix = postfix + opStack.top();
                    opStack.pop();
                }
            }
            else if (chr == '+' || chr == '-')
            {
                if (!opStack.empty())
                {
                    postfix = postfix + opStack.top();
                    opStack.pop();
                }
                opStack.push(chr);
            }
        }
        else
        {
            postfix = postfix + chr;
        }
    }
    while (!opStack.empty())
    {
        postfix = postfix + opStack.top();
        opStack.pop();
    }

    return postfix;
}

// Function to check if the character is a valid operator (+, -, /, *, %, or =)
bool isValidOperator(char inChar)
{
    if (inChar == '+' || inChar == '-' || inChar == '*' || inChar == '/' || inChar == '%' || inChar == '=')
        return true;
    else
        return false;
}

void tree::makeExpTree(std::string postfix)
{
    std::stack<node*> nodeStack;
    int strLen = postfix.size();

    for (int i = 0; i < strLen; i++)
    {
        char chr = postfix[i];

        node *newNode = new node;
        newNode->data = chr;
        
        if (isValidOperator(chr))
        {
            newNode->right = nodeStack.top();
            nodeStack.pop();
            newNode->left = nodeStack.top();
            nodeStack.pop();

            nodeStack.push(newNode);
        }
        else
        {
            newNode->left = NULL;
            newNode->right = NULL;

            nodeStack.push(newNode);
        }
    }

    expRoot = nodeStack.top();
    nodeStack.pop();
}