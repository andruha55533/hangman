#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <ctime>

#define WRONGTRIES 5

using namespace std;

void DrawMan(int tries) {
    cout << endl << endl;
    cout << "  -----" << endl;
    cout << "  |   |" << endl;
    cout << "  |"; if (tries <= 1) cout << "   O    "; cout << endl;
    cout << "  |"; if (tries <= 3) cout << "  /|\\   "; cout << endl;
    cout << "  |"; if (tries <= 5) cout << "  / \\    "; cout << endl;
    cout << "  |" << endl;
    cout << "__|__" << endl;
}

int main()
{
    srand(time(NULL));
    string wordlist[5] = { "apple","peach","banana","strawberry","mango" };
    string word;
    string guessed;

    word = wordlist[rand() % 5];

    int wordlen = word.length();
    string dispword(wordlen, '_');

    int found = 0;
    char  guess = ' ';
    int tries = 5;
    int flagfound = 0;

    while (tries >= 0) {
        system("cls");
        cout << "Guess the fruit name: " << endl << endl;

        for (int i = 0; i < wordlen; i++)
            cout << " " << dispword[i] << " ";
        cout << endl << endl << endl;

        cout << "Wrong attempts: " << tries << " / " << WRONGTRIES << endl;
        cout << "Guessed letters: " << guessed << endl;

        DrawMan(tries);

        if (found == wordlen) {
            cout << endl;
            cout << "****************" << endl;
            cout << "* YOU      WIN *" << endl;
            cout << "****************" << endl;
            break;
        }
        if (tries == 0)
            break;

        cout << "Pick a letter: ";
        guess = _getch();

        guessed = guessed + " " + guess;

        if (dispword.find(guess) != string::npos)
            tries++;

        flagfound = 0;
        for (int i = 0; i < wordlen; i++) {
            if (word[i] == guess && dispword[i] == '_') {
                dispword[i] = guess;
                found++;
                flagfound = 1;
            }
        }
        if (!flagfound)
            tries--;
    }
    if (found != wordlen) {
        cout << endl;
        cout << "********************" << endl;
        cout << "*     YOU LOSE     *" << endl;
        cout << "********************" << endl;
    }
    _getch();
    return 0;
}



