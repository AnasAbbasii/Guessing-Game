#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>
using namespace std;

void effect(string text, int delay) {
    for (char a : text) {
        cout << a << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }

    while (_kbhit()) {
        getch();
    }
}

void game() {
    system("cls");
    bool guessed = false;
    char play;
    int guess, number;
    string over = "\nGAME OVER";
    string start = "Let the guessing begin!";
    string cong = "Congratulations!";
    srand(time(0));
    number = rand() % 100 + 1;
    cout << "= " << endl;
    cout << "===== ====" << endl << endl;
    cout << "GUESS IT RIGHT" << endl;
    cout << "Thinking of a number";
    for (int i = 0; i < 7; i++) {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(400));
    }
    cout << endl;
    effect(start, 20);
    cout << endl;
    for (int i = 1; i <= 5; i++) {
        string suffix;
        if (i == 1) suffix = "st";
        else if (i == 2) suffix = "nd";
        else if (i == 3) suffix = "rd";
        else suffix = "th";
        cout << "\nEnter your " << i << suffix << " guess: ";
        cin >> guess;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Try guessing a number.\n";
            continue;
        }
        if (guess == number) {
            guessed = true;
            cout << endl;
            effect(cong, 500);
            cout << endl << "You guessed it right!\n";
            cout << "\n[ ENTER ] PLAY AGAIN\n";
            cout << "[ ESC ] EXIT\n";
            while (true) {
                play = getch();
                if (play == 13) {
                    game();
                }
                else if (play == 27) {
                    cout << "\nSee you soon, Champion.";
                    exit(0);
                }
            }
        }
        else {
            int diff = abs(guess - number);
            if (guess < number) {
                if (diff <= 5) cout << "Low, but extremely close.\n";
                else if (diff <= 10) cout << "A little low, very near!\n";
                else if (diff <= 20) cout << "Low, getting there!\n";
                else if (diff <= 30) cout << "Low, but not too far!\n";
                else cout << "Too low! Way off!\n";
            }
            else {
                if (diff <= 5) cout << "High, but extremely close.\n";
                else if (diff <= 10) cout << "A little high, very near.\n";
                else if (diff <= 20) cout << "High, getting there!\n";
                else if (diff <= 30) cout << "High, but not too far!\n";
                else cout << "Too high! Way off!\n";
            }
            if (i < 5) {
                cout << "-" << (5 - i) << " attempts left\n";
            }
        }
    }

    if (!guessed) {
        effect(over, 100);
        cout << "\nI guessed " << number << ".\n";
        cout << "\n[ ENTER ] PLAY AGAIN\n";
        cout << "[ ESC ] EXIT\n";
        while (true) {
            play = getch();
            if (play == 13) {
                game();
            }
            else if (play == 27) {
                cout << "\nBasss! Nikal gayi hawa?";
                exit(0);
            }
        }
    }
}

int main() {
    char play;
    string wish = "Welcome to the world of numbers!";
    string q = "Can you outsmart the computer?";
    string rules = "Rules: ";
    string r = "- The number is between 1 and 100\n- You have only 5 tries";
    cout << "==============" << endl;
    cout << "GUESS IT RIGHT" << endl << endl;
    effect(wish, 20);
    cout << endl;
    effect(q, 20);
    cout << endl << endl;
    effect(rules, 30);
    cout << endl << r << endl;
    cout << "\n[ ENTER ] PLAY GAME\n";
    cout << "[ ESC ] EXIT\n";
    while (true) {
        play = getch();
        if (play == 13) {
            game();
        }
        else if (play == 27) {
            cout << "\nCome back when courage loads to 100%.";
            return 0;
        }
    }
}