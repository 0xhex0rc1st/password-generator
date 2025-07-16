#include <iostream>
#include <string>
#include <random>

// Password generator function
void password_generator(int length, std::string charsets) {
    std::string Password;
    std::random_device random_device;
    std::uniform_int_distribution<size_t> distribution(0, charsets.size() - 1);
    for (int i = 0; i < length; i++) {
        size_t random = distribution(random_device);
        Password += charsets[random];
    }
    std::cout << "Your Generated Password: " << Password << std::endl;
};

int main()
{
    int Password_Length;
    std::cout << "Enter Password Length: ";
    std::cin >> Password_Length; // Gets input for length

    // Error handling for length input
    if (Password_Length <= 0) {
        std::cout << "Invalid length!";
        return 1;
    }

    // Defining character sets
    std::string charsetlowercase = "abcdefghijklmnopqrstuvwxyz";
    std::string charsetuppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string charsetnumbers = "0123456789";
    std::string charsetsymbols = "!@#$%^&*()_+-=[]{}|;:,.<>/?~`";
    std::string charsetspace = " ";
    std::string charsetinclude; // For custom characters

    char lowercaseapproval, uppercaseapproval, numbersapproval, symbolsapproval, spaceapproval, includeapproval;

    // Get approval for each character set
    std::cout << "Include lowercase? (y/n): ";
    std::cin >> lowercaseapproval;
    std::cout << "Include uppercase? (y/n): ";
    std::cin >> uppercaseapproval;
    std::cout << "Include numbers? (y/n): ";
    std::cin >> numbersapproval;
    std::cout << "Include symbols? (y/n): ";
    std::cin >> symbolsapproval;
    std::cout << "Include space? (y/n): ";
    std::cin >> spaceapproval;
    std::cout << "Do you want to include custom characters? (y/n): ";
    std::cin >> includeapproval;

    // Input for custom characters
    if (tolower(includeapproval) == 'y') {
        std::cout << "Enter your custom characters without spaces: ";
        std::getline(std::cin >> std::ws, charsetinclude);
        // Check if input contains spaces
        if (charsetinclude.find(' ') != std::string::npos) {
            std::cout << "Error: Spaces are not allowed in custom characters.\n";
            return 1; // Exit with error
        }
    }

    // Combine each approved character set into the main character set
    std::string charsets;
    if (tolower(lowercaseapproval) == 'y') {
        charsets += charsetlowercase;
    }
    if (tolower(uppercaseapproval) == 'y') {
        charsets += charsetuppercase;
    }
    if (tolower(numbersapproval) == 'y') {
        charsets += charsetnumbers;
    }
    if (tolower(symbolsapproval) == 'y') {
        charsets += charsetsymbols;
    }
    if (tolower(spaceapproval) == 'y') {
        charsets += charsetspace;
    }
    if (tolower(includeapproval) == 'y') {
        charsets += charsetinclude;
    }

    // Check if at least one character set was selected
    if (charsets == "") {
        std::cout << "No character sets selected";
        return 1;
    }
    password_generator(Password_Length, charsets); // Call the password generator function
    return 0;
}