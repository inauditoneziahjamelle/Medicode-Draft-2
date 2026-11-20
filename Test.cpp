#include <iostream>
#include <string>

using namespace std;

void genquesnum1(string &answer1)
{
    int choice;

    cout << "\nHow long have you experienced this problem?\n";
    cout << "1. Today\n2. A Few Days\nEnter choice: ";
    cin >> choice;

    if (choice == 1) answer1 = "Today";
    else if (choice == 2) answer1 = "A Few Days";
}

void genquesnum2(string &answer1, string &answer2)
{
    int choice;

    cout << "\nDo you have other symptoms?\n";
    cout << "1. Yes\n2. No\n3. Back to Previous Question\n4. Back to Main Menu\nEnter choice: ";
    cin >> choice;

    if (choice == 1) answer2 = "Yes";
    else if (choice == 2) answer2 = "No";
    else if (choice == 3)
    {
        genquesnum1(answer1);
        genquesnum2(answer1, answer2);
    }
    else if (choice == 4) cout << "main menu\n";
}

int main()
{
    string answer1 = "";
    string answer2 = "";

    genquesnum1(answer1);
    genquesnum2(answer1, answer2);

    cout << "\nAnswer 1: " << answer1 << "\n";
    cout << "Answer 2: " << answer2 << "\n";

    return 0;
}