#include <iostream>
#include <random>
#include <algorithm>
#include <string>


using namespace std;

int main()
{
    string query = "", lastname = "", firstname = "", newpassword="", birthyear= "", favFood = "";
    char randomBank[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '!', '#', '$', '*', '/', '?', '.', '-', '1', '2', '3', '4', '5', '6', '7', '8', '9' ,'0'};
    int index = 0;
    string details[1000] = {};
    int count = 0;
    cout <<"Welcome to Password Generator, we'd help you create complex passwords"<<endl;
    cout <<"To have characters from your name and other details, type Y for yes, if you just want random characters, type N for no:"<<endl;
    cin >> query;
    if(query == "Y" || query == "y")
    {
        cout<<"You have selected to form your password from your details! "<<endl;
        cout<<"The details include your First name, Last name, Birth year and Favourite Food"<<endl;

        cout<<"Enter First name: ";
        cin>> firstname;
        for(int i = 0; i<firstname.length(); i++)
        {
            if(firstname[i] == ' ')
            {
                continue;

            }
            else
                details[i] = firstname[i];


        }
        index = firstname.length();


        cout<<"Enter Last name: ";
        cin>> lastname;
        for(int i = 0; i<lastname.length(); i++)
        {
              if(lastname[i] == ' ')
            {
                 continue;
            }
            index += 1;
            details[index] = lastname[i];
        }

        cout<<"Enter birth year: ";
        cin>> birthyear;
        for(int i = 0; i<birthyear.length(); i++)
        {
              if(birthyear[i] == ' ')
            {
                 continue;
            }
            index += 1;
            details[index] = birthyear[i];
        }

        cout<<"Enter favourite food: ";
        cin>> favFood;
        for(int i = 0; i<favFood.length(); i++)
        {
              if(favFood[i] == ' ')
            {
                 continue;
            }
            index += 1;
            details[index] = favFood[i];
        }

        cout<<"How many characters do you want your password to be (Not more than 16): "<<endl;
        int charNum;
        cin >> charNum;
        int total = lastname.length() + firstname.length() + birthyear.length() + favFood.length();

         if (charNum < 16)
            {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distr(0, total);

                for(int n = 0; n<charNum; n++)
                {
                    newpassword += details[distr(gen)];
                }
                cout<<"Your new password is: "<< newpassword<<endl;
            }

            else
            {
                cout<<"16 is the maximum number of characters"<<endl;
            }

        }
        else if(query == "N" || query == "n")
        {
            cout<<"You have chosen to get a random password!"<<endl;
            cout<<"How many characters do you want your password to be (Not more than 16): "<<endl;
            int charNum;
            cin >> charNum;

            int len = sizeof(randomBank)/sizeof(randomBank[0]);
         if (charNum < 16)
            {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distr(0, len);

                for(int n = 0; n<charNum; n++)
                {
                    newpassword += randomBank[distr(gen)];
                }
                cout<<"Your new password is: "<< newpassword<<endl;
            }

            else
            {
                cout<<"16 is the maximum number of characters"<<endl;
            }
        }

    return 0;
}














