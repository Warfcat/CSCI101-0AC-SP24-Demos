#include <iostream>
#include <limits>
#include <string>

using namespace std;
/* const int BLUE = 0;
const int RED = 1;
const int GREEN = 2;
const int YELLOW = 3;
const int PURPLE = 4;
const int ORANGE = 5; */
IceCreamFlavor getIceCreamFlavor(); 
string printIceCreamFlavorName(IceCreamFlavor flavor); 
// lecture activity create an enum based on your 3 favorite ice cream flavors
// write a function to get an ice cream flavor (like inputColor)
// write a function to print the name of the ice cream (like printColorName)
// in a main create 3 ice cream variables and use the functions you created to input and output the values.
enum IceCreamFlavor {CHOCOLATE, VANILLA, STRAWBERRY};


enum colorType
{
    RED,
    BLUE,
    GREEN,
    PURPLE,
    ORANGE,
    YELLOW
};

void resetStream();

colorType inputColor();
void printColorMenu();
void printColor(colorType theColor);
std::string printColorName(colorType theColor);

int main()
{
    IceCreamFlavor flavor1, flavor2, flavor3;
    flavor1 = getIceCreamFlavor();
    flavor2 = getIceCreamFlavor();
    flavor3 = getIceCreamFlavor();
    cout << "Ice Cream Flavors:\n";
    cout << "1. " << printIceCreamFlavorName(flavor1) << endl;
    cout << "2. " << printIceCreamFlavorName(flavor2) << endl;
    cout << "3. " << printIceCreamFlavorName(flavor3) << endl;
    colorType color;
    color = inputColor();
    printColor(color);
    std::cout << printColorName(color) << std::endl;
    std::cout << "\033[0m";
    std::string myStr = "Have a nice day!";
    std::cout << myStr[0] << std::endl;
    myStr = myStr + " See you on Wednesday!";
    std::cout << myStr << std::endl;
    int x = 7;
    myStr = myStr + std::to_string(x);
    std::cout << myStr << std::endl;
    return 0;
}

colorType inputColor()
{

    colorType theColor;
    int colorInt;
    do
    {
        printColorMenu();
        std::cin >> colorInt;
        if (!std::cin)
        {
            resetStream();
        }
        else if (colorInt < 1 || colorInt > 6)
        {
            std::cout << "You must choose a number from the list." << std::endl;
        }
    } while (!std::cin || colorInt < 1 || colorInt > 6);
    switch (colorInt)
    {
    case 1:
        theColor = RED;
        break;
    case 2:
        theColor = BLUE;
        break;
    case 3:
        theColor = GREEN;
        break;
    case 4:
        theColor = PURPLE;
        break;
    case 5:
        theColor = ORANGE;
        break;
    case 6:
        theColor = YELLOW;
        break;
    }

    return theColor;
}

void printColorMenu()
{
    std::cout << "Please choose a color:" << std::endl;
    std::cout << "1. Red" << std::endl;
    std::cout << "2. Blue" << std::endl;
    std::cout << "3. Green" << std::endl;
    std::cout << "4. Purple" << std::endl;
    std::cout << "5. Orange" << std::endl;
    std::cout << "6. Yellow" << std::endl;
}

void printColor(colorType theColor)
{
    std::cout << "\033[1m";
    switch (theColor)
    {
    case RED:
        std::cout << "\033[38;5;196m\033[48;5;88m";
        break;
    case BLUE:
        std::cout << "\033[38;5;81m\033[48;5;4m";
        break;
    case GREEN:
        std::cout << "\033[38;5;118m\033[48;5;2m";
        break;
    case PURPLE:
        std::cout << "\033[38;5;135m\033[48;5;53m";
        break;
    case YELLOW:
        std::cout << "\033[38;5;226m\033[48;5;178m";
        break;
    case ORANGE:
        std::cout << "\033[38;5;214m\033[48;5;166m";
        break;
    default:
        std::cout << "\033[0m"
                  << "Unknown Color" << std::endl;
    }
    std::cout << "[ ]" << std::endl;
    std::cout << "\033[0m";
}

std::string printColorName(colorType theColor)
{
    switch (theColor)
    {
    case BLUE:
        return "Blue";
    case RED:
        return "Red";
    case YELLOW:
        return "Yellow";
    case ORANGE:
        return "Orange";
    case GREEN:
        return "Green";
    case PURPLE:
        return "Purple";
    default:
        return "Unknown Color";
    }
}

void resetStream()
{
    std::cout << "You entered something that is not a number!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


IceCreamFlavor getIceCreamFlavor() 
    {
    int choice;
    std::cout << "Choose an ice cream flavor:\n";
    std::cout << "1. Chocolate\n";
    std::cout << "2. Vanilla\n";
    std::cout << "3. Strawberry\n";
    std::cout << "Enter your choice (1-3): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            return CHOCOLATE;
        case 2:
            return VANILLA;
        case 3:
            return STRAWBERRY;
        default:
            std::cerr << "Invalid choice. Defaulting to Chocolate.\n";
            return CHOCOLATE;
    }
}

string printIceCreamFlavorName(IceCreamFlavor flavor) 
    {
    switch (flavor) {
        case CHOCOLATE:
            return "Chocolate";
        case VANILLA:
            return "Vanilla";
        case STRAWBERRY:
            return "Strawberry";
        default:
            return "Unknown Flavor";
    }
}
