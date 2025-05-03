// program to calculate area of square, cube, rectangle and cuboid using classes

#include <iostream>

class square
{
    private:
    int side;

    public:
    square()
    {
        side = 1;
    }
    void setSide(int);
    int area();
};

class cube
{
    private:
    int side;

    public: 
    cube()
    {
        side = 1;
    }
    void setSide(int);
    int area();
};

class rectangle
{
    private:
    int length, breadth;

    public:
    rectangle()
    {
        length = 1;
        breadth = 1;
    }
    void setLength(int);
    void setBreadth(int);
    int area();
};

class cuboid
{
    private:
    int length, breadth, height;

    public:
    cuboid()
    {
        length = 1;
        breadth = 1;
        height = 1;
    }
    void setLength(int);
    void setBreadth(int);
    void setHeight(int);
    int area();
};

int main()
{
    int choice = -1;

    while(choice != 5)
    {
        std::cout << "\n\nArea of:\n1. Square\n2. Cube\n3. Rectangle\n4. Cuboid\n5. Exit\n\nEnter Choice:";
        std::cin >> choice;

        if(choice == 1)
        {
            square sq1;
            int inputSide;

            std::cout << "Enter side of the square: ";
            std::cin >> inputSide;
            sq1.setSide(inputSide);

            std::cout << "Area = " << sq1.area();
        }
        else if (choice == 2)
        {
            cube cu1;
            int inputSide;

            std::cout << "Enter side of the cube: ";
            std::cin >> inputSide;
            cu1.setSide(inputSide);

            std::cout << "Area = " << cu1.area();
        }
        else if (choice == 3)
        {
            rectangle re1;
            int inputLength, inputBreadth;

            std::cout << "Enter length: ";
            std::cin >> inputLength;
            std::cout << "Enter breadth: ";
            std::cin >> inputBreadth;
            re1.setLength(inputLength);
            re1.setBreadth(inputBreadth);

            std::cout << "Area = " << re1.area();
        }
        else if (choice == 4)
        {
            cuboid cub1;
            int inputLength, inputBreadth, inputHeight;

            std::cout << "Enter length: ";
            std::cin >> inputLength;
            std::cout << "Enter breadth: ";
            std::cin >> inputBreadth;
            std::cout << "Enter height: ";
            std::cin >> inputHeight;
            cub1.setHeight(inputHeight);
            cub1.setBreadth(inputBreadth);
            cub1.setHeight(inputHeight);

            std::cout << "Area = " << cub1.area();
        }
        else if (choice == 5)
        {
            std::cout << "Exiting...\n";
        }
        else
        {
            std::cout << "Invalid choice!\n";
        }
    }
}

void square::setSide(int inSide)
{
    side = inSide;
}

int square::area()
{
    return(side * side);
}

void cube::setSide(int inSide)
{
    side = inSide;
}

int cube::area()
{
    return(6*(side*side));
}

void rectangle::setLength(int inLen)
{
    length = inLen;
}

void rectangle::setBreadth(int inBre)
{
    breadth = inBre;
}

int rectangle::area()
{
    return(length * breadth);
}

void cuboid::setBreadth(int inBre)
{
    breadth = inBre;
}

void cuboid::setHeight(int inHei)
{
    height = inHei;
}

void cuboid::setLength(int inLen)
{
    length = inLen;
}

int cuboid::area()
{
    return(2*(length*breadth + breadth*height + length*height));
}