#include <iostream>
using namespace std;

//---------------------------
//MathProcesses
void math_input(struct math_processes process);
void sum();
void sub();
void mult();
void div();

//---------------------------
//StingsFunctions
void string_input(struct string_processes string_process);
void add_String();
void compare();

//---------------------------
//Structures
struct math_processes
{
    //Math-Attributes
    float first_num;
    float second_num;
    int math_choice;

    //Functions
    void sum()
    {
        cout << "\n--------------------\n";
        cout << "The result of " << first_num
        << " + " << second_num << " = "
        << first_num + second_num;
        cout << "\n--------------------\n";
    }

    void sub()
    {
        cout << "\n--------------------\n";
        cout << "The result of " << first_num
        << " - " << second_num << " = "
        << first_num - second_num;
        cout << "\n--------------------\n";
    }

    void mult()
    {
        cout << "\n--------------------\n";
        cout << "The result of " << first_num
        << " * " << second_num << " = "
        << first_num * second_num;
        cout << "\n--------------------\n";
    }

    void div()
    {
        cout << "\n--------------------\n";
        cout << "The result of " << first_num
        << " / " << second_num << " = "
        << first_num / second_num;
        cout << "\n--------------------\n";
    }

};

struct string_processes
{
    string first_string , second_string;
    int string_choice;

    void add_String()
    {
        cout << "\n--------------------\n";
        cout << "The total text is: "
        << first_string + " " + second_string;
        cout << "\n--------------------\n";
    }

    void compare()
    {
        if (first_string.length() == second_string.length())
        {
            if (first_string == second_string)
            {
                cout << "The two strings are the same\n";
            }
            else
            {
                cout << "The two strings are not the same\n";
                cout << "\n--------------------\n";
                for (int i = 0 ; i < first_string.length() ; i++)
                {
                    if (first_string[i] != second_string[i])
                    {
                        cout << "the " << i+1 << " character is different they are "
                        << "( " << first_string[i] << " != " << second_string[i] << " )" ;
                        cout << "\n--------------------\n";

                    }

                }
            }
        }

        else
        {
            cout << "The two strings are not of the same length\n";
        }


    }
};


//Main-Programm
int main()
{
    struct math_processes first_mathUsage;
    struct string_processes first_stringUsage;
    int main_choice;

    do
    {
        there:
        cout << "\nEnter The Mood You Want: \n"
                "\n1- Math Processes"
                "\n2- String Processes"
                "\n3- Exit";
        cout << "\n----------\n";
        cin >> main_choice;
        cout << "\n----------\n";

        switch(main_choice)
        {
            case 1:
                math_input(first_mathUsage);
                break;
            case 2:
                string_input(first_stringUsage);
                break;
            case 3:
                break;

            default:
                cout << "Enter A valid Number: \n";
                goto there;
        }
    }while(main_choice != 3);

    return 0;
}

//UserFunctions
void math_input(struct math_processes process)
{
    there:
    cout << "Enter The First Number: \n";
    cin >> process.first_num;
    cout << "--------------------\n";

    cout << "Enter The Second Number: \n";
    cin >> process.second_num;
    cout << "--------------------\n";
    do
    {
        input_place:
        cout << "\nEnter The Operation You Want: "
                    "\n1- Summation"
                    "\n2- Subtraction"
                    "\n3- Multiplication"
                    "\n4- Division"
                    "\n5- Enter New Numbers"
                    "\n6- Return To Main Page\n";
        cin >> process.math_choice;

        switch(process.math_choice)
        {
            case 1:
                process.sum();
                break;
            case 2:
                process.sub();
                break;
            case 3:
                process.mult();
                break;
            case 4:
                process.div();
                break;
            case 5:
              goto there;
              break;

            case 6:
                break;

            default:
                cout << "Enter A valid Number: \n";
                goto input_place;
        }

    }while(process.math_choice != 6);


}

void string_input(struct string_processes string_process)
{
    there:
    cout << "Enter The First String: \n";
    cin >> string_process.first_string;
    cout << "\n--------------------\n";

    cout << "Enter The Second String: \n";
    cin >> string_process.second_string;
    cout << "\n--------------------\n";

    do
    {


        input_place:
        cout << "\nEnter The Operation You Want: "
                    "\n1- Add the two strings"
                    "\n2- Compare the two strings"
                    "\n3- Enter New Strings"
                    "\n4- Return To Main Page\n";
        cin >> string_process.string_choice;

        switch(string_process.string_choice)
        {
            case 1:
                string_process.add_String();
                break;
            case 2:
                string_process.compare();
                break;
            case 3:
                goto there;
                break;
            case 4:
                break;
            default:
                cout << "Enter A valid Number: \n";
                goto input_place;
        }

    }while(string_process.string_choice != 4);

 }
