#include <iostream>
using namespace std;

//------------Functions---------------
void user_page();
void manager_page();
void show_menu();
void buy_product();
void create();
void login();
void Add();
void Edit();
void manager_process(string name);

//------------Variables---------------
int menu_size = 9;
string username = "Mohamed";
string password = "123";


//-------------Arrays--------------
string products[20] =
{"Rice" , "salad" , "Meat"
,"tomatoes" , "carrots" , "Onions"
,"tissues" , "bottles" , "glue"};

int prices[20] = {10 , 20 , 30 , 40 , 50 , 60 , 70 ,80 ,90};



//--------------MainFunctions-------------

int main()
{
    int choice_Enter;
    cout << "__________ SuperMarket Sytem __________\n"
            "\n__________ Enter to open ______________\n";
    getchar();

    do
    {
            cout << "Choose The Mood From The Following: \n"
                "\n1- User"
                "\n2- Manager"
                "\n3- Exit";

            cout << "\n___________\n";
            cin >> choice_Enter;
            cout << "___________\n";

            switch (choice_Enter)
            {
            case 1:
                user_page();
                break;

            case 2:
                manager_page();
                break;

            case 3:
                break;
            }
    }
    while(choice_Enter != 3);


    return 0;
}


void user_page()
{
    string user_name;
    int choice_userDoing;
    cout << "________________________\n";
    cout << "Enter Your Name Please: \n";
    cout << "___________\n";
    cin >> user_name;
    cout <<"_________" << "Welcome " << user_name <<"_________\n";


    do
    {
        there:
        cout << "What You Can Do:"
            "\n1- Show The menu"
            "\n2- Buy a product"
            "\n3- Return To Main Page\n";
        cout << "___________\n";
        cin >> choice_userDoing;

        switch(choice_userDoing)
        {
        case 1:
            show_menu();
            break;

        case 2:
            buy_product();
            break;

        case 3:
            break;

        default:
            cout << "Enter Only 1 , 2 or 3!\n\n";
            goto there;
        }
    }
    while(choice_userDoing != 3);

}


void show_menu()
{

    for (int i=0 ; i < menu_size ; i++)
    {
        cout << i+1 << "- " << products[i]
        << "  " << prices[i] << " LE" << endl;

        if (i==2 || i==5 || i==8)
        {
            cout << "_________________\n";
        }
    }
}


void buy_product()
{
    int choice_process;
    int products_bag[15];
    int num_products;
    cout << "Enter The Number Of Products to Buy: \n";
    cout << "___________\n";
    cin >> num_products;

    do
    {
        here:
          cout << "\n\nChoose The Process: \n"
                "\n1- Add Products To cart"
                "\n2- Show The Reciept"
                "\n3- Return Back\n";

        cin >> choice_process;

        switch(choice_process)
        {
        case 1:
                for (int j = 0 ; j < num_products ; j++)
                {
                    cout << "Enter the number of product: \n";
                    cout << "___________\n";
                    cin >> products_bag[j];
                }

                cout << "Order Done!\n";
                break;

        case 2:
            {
                int sum = 0;
            cout << "________ Your Reciept ________\n";
            for (int k = 0 ; k < num_products ; k++)
            {
                sum += prices[products_bag[k]-1];

                cout << k+1 << "- " << products[products_bag[k]-1]
                << "  " << prices[products_bag[k]-1] << endl;

                cout << "_____________\n";
            }

            cout << "Total Cost is: " << sum << endl ;
        break;
        }

        case 3:
            break;

        default:
        cout << "Enter Only 1 , 2 or 3!\n\n";

        goto here ;
        }
    }
    while(choice_process != 3);

}


void manager_page()
{
    int choice_manager;
    do
    {
            cout << "\nChoose The Mood"
                    "\n1- Create A New Email"
                    "\n2- Login"
                    "\n3- Return To Main Page\n";

            cin >> choice_manager;

            switch(choice_manager)
            {
            case 1:
                create();
                break;

            case 2:
                login();
                break;

            case 3:
                break;
            }
    }
    while(choice_manager != 3);

}

void create()
{
    cout << "Enter Your Name: \n";
    string newManager_name;
    cin >> newManager_name;

    cout << "Enter Your Password: \n";
    string newManager_pass;
    cin >> newManager_pass;

    cout << "Now Login To open the Programm: \n";
    cout << "ReEnter Your Name: \n";
    string rename_newManager;
    cin >> rename_newManager;

    cout << "ReEnter Your PassWord: \n";
    string repass_newManager;
    cin >> repass_newManager;

    if (newManager_name == rename_newManager &&newManager_pass ==  repass_newManager)
    {
        manager_process(newManager_name);
    }
    else
    {
        cout << "Wrong input Enter valid Data Please \n";
        create();
    }

}

void login()
{
    cout << "Enter Your Name: \n";
    string name_try;
    cin >> name_try;

    cout << "Enter Your Password: \n";
    string pass_try;
    cin >> pass_try;

    if (name_try == username && pass_try == password)
    {
        manager_process(username);
    }
    else
    {
        login();
    }

}


void manager_process(string name)
{
    int choice_process;
    cout << "\n________________________\n";
    cout << "Welcome " << name << endl;
    cout << "________________________\n";

    do
    {
        cout << "\nChoose The process: "
            "\n1- Add Element To Menu"
            "\n2- Edit An Element in The Menu"
            "\n3- Return Back\n";

        cin >> choice_process;

        switch(choice_process)
        {
            case 1:
                Add();
                break;

            case 2:
                Edit();
                break;

            case 3:
                break;

        }
    }
    while(choice_process != 3);

}


void Add()
{
    cout << "The Menu Is Now 9 Elements\n"
            "Enter The New Size You Want\n";

    cin >> menu_size ;

    if (menu_size > 9)
    {
            for (int x = 0 ; x < menu_size-9 ; x++)
            {
            cout << "Enter The Product Name: \n";
            cin >> products[x+9];

            cout << "Enter The Product Price: \n";
            cin >> prices[x+9];

            }

            cout << "Done!\n";
            cout << "Want To Show The New Menu? (yes / no)";
            string check;
            cin >> check;

             if (check == "yes")
            {
                show_menu();
            }

            else if (check == "no")
            {
                manager_process("sir");
            }

    }

    else if(menu_size < 9 && menu_size > 0)
    {
        cout << "Done!\n";
        cout << "Want To Show The New Menu? (yes / no)";
        string check;
        cin >> check;

        if (check == "yes")
        {
            show_menu();
        }

        else if (check == "no")
        {
            manager_process("sir");
        }
    }


}

void Edit()
{
    int newprice;
    string check_show;
    string newname;
    int choice_edit;
    int product_num;
    cout << "How many Products To Edit: \n";
    int num_products;
    cin >> num_products;

    for (int q = 0 ; q < num_products ; q++)
    {
        cout << "\nNumber Of product To Edit: \n";
        cin >> product_num;

        cout << "Want To edit name or price: \n "
                "\n1- name"
                "\n2- price\n"
                "\n3- Both";
        cin >> choice_edit;
        switch(choice_edit)
        {

            case 1:
                cout << "Enter the new name: \n";
                cin >> newname;
                products[product_num-1] = newname;
                break;

            case 2:
                cout << "Enter the new price: \n";
                cin >> newprice;
                prices[product_num-1] = newprice;
                break;

            case 3:
                cout << "Enter the new name: \n";
                cin >> newname;
                products[product_num-1] = newname;

                cout << "Enter the new price: \n";
                cin >> newprice;
                prices[product_num-1] = newprice;
                break;
        }
    }

    cout << "Want To show the menu? (yes / no) \n";
    cin >> check_show;

    if (check_show == "yes")
    {
        show_menu();
    }
    else if (check_show == "no")
    {
        manager_process("sir");
    }

}

