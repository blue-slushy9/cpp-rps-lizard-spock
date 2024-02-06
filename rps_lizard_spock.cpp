// C++ Standard Library input/output stream;
#include <iostream>
/* cctype provides functions for character classification and conversion,
i.e. operations on characters, in this case the std::tolower function
for converting characters to lower-case; */
#include <cctype>
/* string provides facilities for working with strings, e.g. functions and classes
for string manipulation; in this case, we will use to scan the user input for any
upper-case letters, and then convert them to lower-case; */
#include <string>
/* std::unordered_map is an unsorted associative container, which means that while its elements 
consist of key-value pairs, they are not ordered based on the key as they would be in a std::map;
the reason we use an unordered map is for simplicity and faster access speeds, the potential trade-offs
are that the order is not guaranteed and may change over time, though that won't really matter for the
purposes of this program; */
#include <unordered_map>

// Declare our rules to the game, it is simple text that will print to the terminal;
void rules();

/* Declare the userInputv1 function---return type of the function is std::string;
std::string is a C++ Standard Library class that represents a sequence of characters
as a dynamic array, providing a wide range of functionalities for string manipulation;
const std::string& is a reference to the input prompt, which will not change; 
in C++, & is a reference, which allows you to work with the original variable 
without making a copy, but since prompt is a const it will not change anyway; */
//std::string userInput(const std::string& prompt);
// char* userInput(char* select); // Old C code

// Declare the userInputv2 function;
std::string userInput();

// Declare the toUpper function;
std::string toUpper(const std::String& input);

// Declare the toLower function;
std::string toLower(const std::string& input);

/* Declare our nested dictionary of all possible combinations and outcomes;
'std::unordered_map' is the template from the Standard Template Library (STL);
'std::string' specifies the type of keys in the outer map;
'std::unordered_map' specifies there is another map inside of the outer map;
'std::string' specifies the type of keys in the inner map;
'std::string' specifies the type of values in the inner map;
'rpslsDict' is the name of our nested dictionary; */
std::unordered_map<std::string, <std::unordered_map<std::string, std::string>> rpslsDict;

// main function will contain all other functions in this program;
int main() {
    // Call the rules function;
    rules();
    
    // USERINPUT FUNCTION BLOCK;
    // Assign output of userInput function to the variable, select, of type std::string;
    std::string select = userInput();
    // Update the select variable to store the re-formatted string ? ;
    // Print the user input;
    std::cout << "You selected " << select << std::endl;
    // END USERINPUT FUNCTION BLOCK;
    
    // 

    // Call the userInput function;
    //userInput();
    return 0;
}

// Define the rules function;
void rules() {
    std::cout << ("\nThis is Rock-Paper-Scissors-Lizard-Spock, from the hit TV show,\n"
       "Big Bang Theory! It is similar to Rock-Paper-Scissors, but with\n"
	   "two additional options: Lizard and Spock.\n\n"
       "Nobody can explain the rules like Sheldon Cooper can, so I will\n" 
	   "simply quote him: 'Scissors cuts paper, paper covers rock,\n" 
	   "rock crushes lizard, lizard poisons Spock, Spock smashes scissors,\n" 
	   "scissors decapitates lizard, lizard eats paper, paper disproves Spock,\n" 
	   "Spock vaporizes rock, and as it always has, rock crushes scissors!'\n") 
    << std::endl;
}

// Define userInputv2 function;
std::string userInput() {
    // Create the variable that will store the user input;
    std::string input;
    std::cout << "Please enter your selection: ";
    // 'std::cin' reads the user input and '>>' assigns it to the variable;
    // please note that 'std::cin' stops reading at the first whitespace,
    // however this should not be an issue in this program;
    std::cin >> input;
    // If selection is Spock, ensure first letter in output is capitalized;
    //if input == "spock"
        //if (std::isupper(input[0]))  

    // Call the toLower() function with input as argument, assign output to existing variable;
    input = toLower(input);
    return input;
}

// Define the toUpper function, which takes a 'str' as an argument;
std::string toLower(const std::string& str) {
    // Declare the variable that will store our altered string, 'str_upper';
    std::string str_upper;
    // Range-based for loop, iterates over each character 'c' in 'str';
    // the range consists of all of the individual characters in 'str';
    for (char c : str) {
        //if str[0]
        // 'str_upper +=' means the result of each iteration of the C++ standard library
        // 'toupper(c)' function gets appended to our new string, 'str_upper';
        str_upper += toupper(c);
    }
    return str_upper;
}

// Define the toLower function, which takes a 'str' as an argument;
std::string toLower(const std::string& str) {
    // Declare the variable that will store our altered string, 'str_lower';
    std::string str_lower;
    // Range-based for loop, iterates over each character 'c' in 'str';
    // the range consists of all of the individual characters in 'str';
    for (char c : str) {
        // 'str_lower +=' means the result of each iteration of the C++ standard library
        // 'tolower(c)' function gets appended to our new string, 'str_lower';
        str_lower += tolower(c);
    }
    return str_lower;
}

/* Version 1 of userInput function;
// Define the userInput function;
std::string userInput(const std::string& prompt, const std::string& select) {
    std::string select = userInput("Please enter your selection now: ");
    return select;
}
*/

/* GPT CODE FOR AN INPUT FUNCTION;
#include <iostream>
#include <string>

std::string userInput(const std::string& prompt);

int main() {
    std::string userSelection = userInput("Enter your selection: "); // "Enter your selection: " is our value
    // 'cout' prints to console; << insertion operator sends data... // for the 'prompt' variable;
    // ...to output stream; '<< userSelection' inserts the variable...
    // ...data into the output stream; '<< std::endl' inserts newline character into output stream,
    // it is also a manipulator that flushes the output buffer;
    std::cout << "You entered: " << userSelection << std::endl;      

    return 0;
}

// Define userInputv1---please note additional definition will be needed in main();
std::string userInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}
*/

/* Old C code;
// Define the userInput function;
char* userInput(char* select) {
    // Print the prompt to the terminal;
    printf("Please enter your selection now: ");
    // Take user input as string, up to 9 characters;
    scanf("%9s", select);
    // FOR TESTING PURPOSES
    printf("Test: %s\n", select);
    // Return variable so that other functions can use it;
    //return select;
*/


/* #include <stdio.h>
// ctype.h contains tolower function, which converts all user-input text to
// lower-case, to control for user error;
#include <ctype.h> */

/* Define a struct for key-value pairs, which we will in turn use to create our dictionary;
struct KeyValue {
    // None of the possible options have more than 10 characters, so we can
    // set the limit there for memory preservation and security purposes;
    char key[10];
    char value[50];
}; */

/*
// Define our dictionary struct of all possible user-computer combinations;
struct Dict {
    // Define structs, one of each possible sign;
    struct KeyValue rock;
    struct KeyValue paper;
    struct KeyValue scissors;
    struct KeyValue lizard;
    struct KeyValue spock;
};
*/

/*
// Define our main nested dictionary;
struct Dict nestDict = {
    .rock = { .key = "paper", .value = "Paper covers rock, therefore you lose!"},
	    { .key = "scissors", .value = "Rock crushes scissors, therefore you win!"},
	    { .key = "lizard", .value = "Rock crushes lizard, therefore you win!"},
	    { .key = "spock", .value = "Spock vaporizes rock, therefore you lose!"}
    
    .paper = { .key = "scissors", .value = "Scissors cuts paper, therefore you lose!"},
	     { .key = "lizard", .value = "Lizard eats paper, therefore you lose!"},
	     { .key = "spock", .value = "Paper disproves Spock, therefore you win!"}

    .scissors = { .key = "lizard", .value = "Scissors decapitate lizard, therefore you win!"},
	        { .key = "spock", .value = "Spock smashes scissors, therefore you lose!"}

    .lizard = { .key = "spock", .value = "Lizard poisons Spock, therefore you win!"}
};

// Define our dictionary struct of all possible user input combinations;
//struct Dict {
//    // Define struct of type KeyValue, mySign, as an array consisting of 30 elements;
//    struct KeyValue computer[50];
//    // We will use the size variable to store the number of dictionary entries;
//    int size;
//    // DEBUGGING
//    char id[10];
//    // DEBUGGING
//    struct KeyValue subDict[50];
//};

// Define our subdictionary struct, which will contain the computer's possible "choices";
//struct nestDict {
//    // We use char to define the name of our subdictionary as an array of up to 6 characters;
//    char id[10];
//    // We place our sub-struct of type Dict inside of our main Dict, then specify a max number
//    // of subDicts of 5;
//    struct Dict subDicts[5];
//    // We will use the size variable to store the number of dictionary entries;
//    int numSubDicts;
//};

// Now we define our nested dictionary;
//struct nestDict rpslsDict = {
//    .id = "rpslsDict",
//    .numSubDicts = 5,
//    .subDicts = {
//        {
//            .id = "Rock",
//            .subDict = {
//                .computer = {
//	            {"Paper", "Paper covers rock, therefore you lose!"},
//	            {"Scissors", "Rock crushes scissors, therefore you win!"},
//	            {"Lizard", "Rock crushes lizard, therefore you win!"},
//	            {"Spock", "Spock vaporizes rock, therefore you lose!"}
//	        },
//                .size = 4
//            }
//        },
//        {
//            .id = "Paper",
//            .subDict = {
//                .computer = {
//	            {"Scissors", "Scissors cuts paper, therefore you lose!"},
//	            {"Lizard", "Lizard eats paper, therefore you lose!"},
//	            {"Spock", "Paper disproves Spock, therefore you win!"}
//	        },
//                .size = 3
//	    } 
//        },
//	{
//            .id = "Scissors",
//            .subDict = {
//                .computerSign = {
//	            {"Lizard", "Scissors decapitate lizard, therefore you win!"},
//	            {"Spock", "Spock smashes scissors, therefore you lose!"}
//	        },
//	        .size = 2
//	    }
//        },
//        {
//	    .id = "Lizard",
//            .subDict = {
//                .computer = {
//	            {"Spock", "Lizard poisons Spock, therefore you win!"}
//	        },
//	        .size = 1
//            }
//        }
//    }
//};

// Define a type-Dict dictionary, rpslsDict;
//struct Dict rpslsDict = {
//    .mySign = {
//        {"rock", "paper"},
//	{"rock", "scissors"},
//	{"rock", "lizard"},
//	{"rock", "spock"},
//	{"paper", "scissors"},
//	{"paper", "lizard"},
//	{"paper", "spock"},
//	{"scissors", "lizard"},
//	{"scissors", "spock"},
//	{"lizard", "spock"}
//    },
//    .size = 10
//};
// BLOCK COMMENT


// Declare our rules to the game, it is simple text that will print to the terminal;
void rules();

// Declare the function that will prompt the user for their selection, and then store it in the variable, select;
char* userInput(char* select);

// Declare our printDict function;
void printDict(const struct Dict *dict);

// main function will contain all other functions in this program;
int main() {
    // Call the rules function;
    rules();
    // Declare the select variable we will use in our userInput function,
    // specify maximum number of input characters;
    char select[10];
    // Set the local variable, choice, to the userInput;
    char* choice = userInput(select);
    // Call the userInput function;
    //userInput(select);
    // This might not need to be here, using it for DEBUGGING;
    printf("Selection: %s\n", choice);
    // DEBUGGING
    printDict(&rpslsDict);
    return 0;
}

// Define the rules function;
void rules() {
    printf("\nThis is Rock-Paper-Scissors-Lizard-Spock, from the hit TV show,\n"
           "Big Bang Theory! It is similar to Rock-Paper-Scissors, but with\n"
	   "two additional options: Lizard and Spock.\n\n"
           "Nobody can explain the rules like Sheldon Cooper can, so I will\n" 
	   "simply quote him: 'Scissors cuts paper, paper covers rock,\n" 
	   "rock crushes lizard, lizard poisons Spock, Spock smashes scissors,\n" 
	   "scissors decapitates lizard, lizard eats paper, paper disproves Spock,\n" 
	   "Spock vaporizes rock, and as it always has, rock crushes scissors!'\n\n");
}

// Define the userInput function;
char* userInput(char* select) {
    // Print the prompt to the terminal;
    printf("Please enter your selection now: ");
    // Take user input as string, up to 9 characters;
    scanf("%9s", select);
    // FOR TESTING PURPOSES
    printf("Test: %s\n", select);
    // Return variable so that other functions can use it;
    //return select;

    // Convert the input to lower-case by looping through every character one-by-one;
    for (int i = 0; select[i]; i++) {
        select[i] = tolower(select[i]);
    }
    // DEBUGGING
    printf("%s\n", select);
    // Return the input, now in lower-case;
    return select;
}

// Define the printDict function;
void printDict(const struct Dict *nestDict) {
    printf("Dictionary:\n");
    // dict->size is an arrow function that can also be expressed as (*dict).size ...
    for (int i=0; i<dict->size; i++) { // ... i.e. the arrow function dereferences a pointer... 
        printf("Key: %s, Value: %s\n", nestDict->KeyValue[i].key, nestDict->KeyValue[i].value);
    } // ...to a structure and then accesses a member of that structure;
}

*/


