/*This program is a word-based two-player game
* that receives a word from each user and assigns
* some points to each word according to a specific
*  scoring system
* this program is inspired by a task in CS50 course
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// Points assigned to each letter of the alphabet
int POINTS[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };

int compute_score(string word); 
void display_table();

int main(void)
{
    int trial = 1;
    int sum1 = 0;
    int sum2 = 0;
    string word1;
    string word2;
    int count;
    cout << "This game recieves a word from each player for a number of rounds and assigns every word a number of points according to the following table\n";
    cout << "How many rounds do you want to play?\n";
    int num;

    //receiving the number of game iterations from the users
    cin >> num; 

    int* score1 = new int[num];
    int* score2 = new int[num];

    while (trial < num+1) //repeat for (num) times 
    {
        display_table(); //displaying the table of the points distribution
        count = trial - 1;
        cout << "Trial number " << trial<< endl;
        // Get input words from both players
        cout << "Player 1: ";
        cin >> word1;
        cout << endl;
        cout << "Player 2: ";
        cin >> word2;
        cout << endl;
        // Score both words
        score1[count] = compute_score(word1);
        score2[count] = compute_score(word2);
        //comparing the two words to determine the winner of the round
        if (score1[count] > score2[count])
        {
            cout << "Player 1 wins trial " << trial << endl;
        }
        else if (score2[count] > score1[count])
        {
            cout << "Player 2 wins trial " << trial << endl;
        }
        else
        {
            cout << "Tie in trial " << trial << endl;
        }
        trial++; //going to the next round
    }
    //calculating the sum of all points
    for (int i = 0; i < num; i++)
    {
        sum1 += score1[i];
        sum2 += score2[i];
    }
    //printing the total scores
    cout << "The total score for player 1 is " << sum1 << endl;
    cout << "The total score for player 2 is " << sum2 << endl;
    //determining the overall winner
    if (sum1 > sum2)
    {
        cout << "Player 1 wins the game!...\n";
    }
    else if (sum2 > sum1)
    {
        cout << "Player 2 wins the game!...\n";
    }
    else
    {
        cout << "Tie!\n";
    }
    //deallocating the allocated memory
    delete[] score1;
    delete[] score2;
}

//the function that calculates the score of the words
int compute_score(string word)
{
    int score = 0;
    int length = word.size();
    char* lword = new char [length];
    for (int i = 0; i < length; i++)
    {
        //converting all the letters to lower case for the convenience
        lword[i] = tolower(word[i]);
        for (int j = 0; j < 26; j++)
        {
            if ((lword[i] - 'a') == j)
            {
                score += POINTS[j];
            }
        }
    }
    // deallocating the dynamic memory allocated
    delete[] lword;
    // returning the score value of the whole word
    return score;
}

// a function that displays the table of points system
void display_table() {
    cout << setw(5) << "A" << setw(5) << "B" << setw(5) << "C" << setw(5) << "D" << setw(5) << "E" << setw(5) << "F" << setw(5) << "G" << setw(5) << "H";
    cout << setw(5) << "I" << setw(5) << "J" << setw(5) << "K" << setw(5) << "L" << setw(5) << "M" << setw(5) << "N" << setw(5) << "O" << setw(5) << "P";
    cout << setw(5) << "Q" << setw(5) << "R" << setw(5) << "S" << setw(5) << "T" << setw(5) << "U" << setw(5) << "V" << setw(5) << "W" << setw(5) << "X";
    cout << setw(5) << "Y" << setw(5) << "Z";
    cout << endl;
    cout << setw(5) << "1" << setw(5) << "3" << setw(5) << "3" << setw(5) << "2" << setw(5) << "1" << setw(5) << "4" << setw(5) << "2" << setw(5) << "4";
    cout << setw(5) << "1" << setw(5) << "8" << setw(5) << "5" << setw(5) << "1" << setw(5) << "3" << setw(5) << "1" << setw(5) << "1" << setw(5) << "3";
    cout << setw(5) << "10" << setw(5) << "1" << setw(5) << "1" << setw(5) << "1" << setw(5) << "1" << setw(5) << "4" << setw(5) << "4" << setw(5) << "8";
    cout << setw(5) << "4" << setw(5) << "10";
    cout << endl;

}