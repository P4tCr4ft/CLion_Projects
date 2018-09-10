#include <iostream>

// Generally speaking, general code goes in the base class,
// specific code goes in derived classes, ie, add or change methods
// as create new derived classes

// When instantiate derived class, base class constructor called first,
// and then derived constructor

// So in this example, there won't actually be any instances of of the
// base class DogPiece, they will all be instances of derived classes

class DogPiece
{
public:
    int serial_number;
    int size;

    DogPiece(int num)
    {
        serial_number = num;
        std::cout << "DogPiece constructor" << std::endl;
    }
};

// use an enum for what is being processed in chip objects
// so this actually creates a type. And variables of
// the type PROCESS_THINGS can take on any of the values
// "pictures", "sounds", etc

enum PROCESS_THINGS {pictures, sounds, food, thoughts, nothing};


// public means everything public in DogPiece is public in ComputerChip

class ComputerChip : public DogPiece
{
public:
    PROCESS_THINGS processes;

    ComputerChip(PROCESS_THINGS which, int num) : DogPiece(num)
    {
        processes = which;
        std::cout << "ComputerChip constructor" << std::endl;
    }
};

class Brain : public ComputerChip
{
public:
    int memory;

    // Note: we pass an actual value, thoughts, to ComputerChip constructor,
    // but thoughts is not something passed in at instantiation,
    // whereas we pass in integer num at instantiation

    Brain(int num) : ComputerChip(thoughts, num)
    {
        std::cout << "Brain constructor" << std::endl;
    }

    void remember(int what)
    {
        memory = what;
    }

    void forget()
    {
        memory = 0;
    }
};


int main()
{
    Brain one_and_only(12); // serial number is 12

    std::cout << "Serial number: " << one_and_only.serial_number << std::endl;

    // Note: below prints integer 3 even though the value was "thoughts"
    // because it's an enum, ie is the 3rd element of enum
    std::cout << "Processes: " << one_and_only.processes << std::endl;

    one_and_only.remember(5);
    std::cout << "Remembering " << one_and_only.memory << std::endl;
    one_and_only.remember(10);
    std::cout << "Now remembering " << one_and_only.memory << std::endl;
    one_and_only.forget();
    std::cout << "Now all I know is " << one_and_only.memory << std::endl;


    return 0;
}