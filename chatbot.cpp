#include <iostream>
#include <string>

const std::string menu{"shoyu ramen, miso ramen, tonkotsu ramen, gyoza, sake, chicken katsu"};
const std::string quit{"that's it"};
bool ordered = false;

void getUserInput(std::string &buffer)
{
    std::getline(std::cin, buffer);
}

std::string makeBotReply(std::string input){
    std::string reply = "";
    // Create a reply
    if (menu.find(input) != std::string::npos) {
        reply = "1 " +input+ " has been added to the order.";
    }
    else if(input == quit){
        reply = "Alright, your food will be served soon.";
        ordered = true;
    }
    else
    {
        reply = "Sorry, we dont have "+input +" in our menu";
    }

    return reply;
}

int main()
{
    // Introduce yourself
    std::cout << "Hi, what is your name?" << std::endl;

    std::string userName{};
    std::getline(std::cin, userName);
    std::cout << "Hi, " << userName << "!\nWelcome to Calvin's Ramen Shop! What would you like today?" << std::endl;

    std::string reply{};
    while (ordered != true)
    {
        // Get answer to current question
        std::string input{};
        std::getline(std::cin, input);
        reply = makeBotReply(input);
        std::cout << reply << std::endl;
    }

    return 0;
}