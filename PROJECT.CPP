#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int Guess;    // Stores the user's guess
int Total;    // Stores the total score

// Question class to represent each quiz question
class Question {
private:
    string Question_Text;
    string Answer_1;
    string Answer_2;
    string Answer_3;
    string Answer_4;
    int Correct_Answer;
    int Question_Score;

public:
    // Method to set the values for a question
    void setValues(string, string, string, string, string, int, int);
    // Method to ask the question and process the answer
    void askQuestion();
};

// Function to display the main menu and gather user information
int main_menu_view() {
    // Set console color
    system("color 3F");
    
    // Display welcome message
    cout << "\t\t*************************************************************************************" << endl;
    cout << "\t\t*****            H E L L O !  W E L C O M E  T O  T H E 'B R A I N B U Z Z'     *****" << endl;
    cout << "\t\t*****                  = = = = = = = = = = = = = = = = = = = = = = = =          *****" << endl;
    cout << "\t\t*****                            = = = = = = = = = = = =                        *****" << endl;
    cout << "\t\t*****                                     B Y                                   *****" << endl;
    cout << "\t\t*****                           R A K E S H J E N A                             *****" << endl;
    cout << "\t\t*****                           I U 372                                         *****" << endl;
    cout << "\t\t*************************************************************************************" << endl;
    cout << endl;

    // Wait for user input to start the game
    cout << "Please press enter to start a game..." << endl;
    cin.get();
    system("cls");  // Clear the screen

    // Gather user information
    cout << "Please enter your information" << endl;
    string Name, Age, Respond;
    cout << "What is your name? ";
    getline(cin, Name);
    cout << "How old are you? ";
    cin >> Age;

    // Ask if the user is ready to start
    cout << "Are you ready to take the Quiz " << Name << " ? Yes/No. " << endl;
    cout << "Your choice: ";
    cin >> Respond;

    if (Respond == "yes" || Respond == "Yes") {
        cout << endl;
        cout << "OK, Good LUCK!!! " << endl;
        system("cls");
        return 1;  // Return 1 to indicate the user wants to play
    } else {
        cout << "OK. Goodbye." << endl;
        return 0;  // Return 0 to indicate the user doesn't want to play
    }
}

int main() {
    if (!main_menu_view()) {
        return 0;  // Exit if the user doesn't want to play
    }

    // Create question objects
    Question q1, q2, q3, q4, q5;

    // Set up questions
    q1.setValues("What is the primary purpose of an operating system?", 
                 "To run web browsers", 
                 "To manage hardware and software resources", 
                 "To store data permanently", 
                 "To compile programs", 
                 2, 10);
    
    q2.setValues("Which of the following is not a high-level programming language?", 
                 "Python", "Java", "Assembly", "C++", 
                 3, 10);

    q3.setValues("What does SQL stand for?", 
                 "Simple Query Language", 
                 "Structured Query Language", 
                 "System Query Language", 
                 "Sequential Query Language", 
                 2, 10);
    
    q4.setValues("Which data structure uses LIFO (Last In, First Out) principle?", 
                 "Queue", "Array", "Stack", "Tree", 
                 3, 10);
    
    q5.setValues("Which of the following is a machine learning algorithm?", 
                 "Merge Sort", "Decision Tree", "Dijkstra's Algorithm", "Quicksort", 
                 2, 10);

    // Ask questions
    q1.askQuestion();
    q2.askQuestion();
    q3.askQuestion();
    q4.askQuestion();
    q5.askQuestion();

    system("cls");  // Clear the screen

    // Display final score
    cout << "Your Total Score is " << Total << " points out of 50." << endl;

    if (Total >= 30) {
        cout << "Great you passed the Quiz!!!" << endl;
        cout << "C O N G R A T U L A T I O N S !!!" << endl;
    } else {
        cout << "Sorry, you failed the Quiz!" << endl;
        cout << "Do you want to try again ? Yes/No " << endl;
        string play_again;
        cout << "Your choice: ";
        cin >> play_again;
        if (play_again == "yes" || play_again == "Yes") {
            main();  // Restart the game
        } else {
            cout << "OK. Goodbye." << endl;
            return 0;
        }
    }

    system("pause");
    return 0;
}

// Method to set the values for a question
void Question::setValues(string q, string a1, string a2, string a3, string a4, int ca, int pa) {
    Question_Text = q;
    Answer_1 = a1;
    Answer_2 = a2;
    Answer_3 = a3;
    Answer_4 = a4;
    Correct_Answer = ca;
    Question_Score = pa;
}

// Method to ask the question and process the answer
void Question::askQuestion() {
    cout << endl;
    cout << Question_Text << endl;
    cout << "1. " << Answer_1 << endl;
    cout << "2. " << Answer_2 << endl;
    cout << "3. " << Answer_3 << endl;
    cout << "4. " << Answer_4 << endl;
    cout << endl;

    cout << "Answer: ";
    cin >> Guess;

    if (Guess == Correct_Answer) {
        cout << endl;
        cout << "Great! You are Correct." << endl;
        Total += Question_Score;
        cout << "Score: " << Question_Score << " Out of " << Question_Score << " !" << endl;
    } else {
        cout << endl;
        cout << "Oh, NO. You are Wrong." << endl;
        cout << "Score: 0" << " Out of " << Question_Score << " !" << endl;
        cout << "The correct answer is " << Correct_Answer << endl;
        cout << endl;
    }
}