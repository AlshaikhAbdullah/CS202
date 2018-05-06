//Abdullah Alshaikh
//program 2 - CS202
//the main.cpp which will interact with the user of how to use the program and explain importsnt things 
//and based on that it will create the managers taht will help the user 
#include "forms.h"
int main()
{
    manager *test;
    char response;
    int many =0;
    int i =0;
        cout << "Welcome\nThis program will help you organize your social accounts."
        << "\nYou will get to choose how many managers you will have."
        <<"\nHowever, in each manager you can onlu have one version of an account."
        <<"\nSo for example you can only have one facebook in a manager."
        <<"\nEnter any key to continue... : ";
        cin >> response; cin.ignore(100,'\n');

        cout << "First how managers would you like to have today(Numbers): ";
        cin >> many; cin.ignore(100,'\n');
        test = new manager [many];
        cout << many << " Managers has been created." << endl;
        if(many > 1)
        {
            do{
            cout << "Which manager would you like to work with(You have " << many << " ): ";
            cin >> i; cin.ignore(100,'\n'); 
            test[i -1].start();
            }while(again());
        }
        else
        {
            do{
                test[0].start();
            }while(again());
        }
        if(test)
        {
            delete [] test;
            test = NULL;
        }
return 0;
}
