#include <iostream>
#include <string>
#include <regex>



using namespace std;

int main()
{
    //yyyy-mm-dd
    //regex r{"(\\d{4})-(0?[1-9]|1[0-2])-(0?[1-9]|[1-2][0-9]|3[0-1])"};
    regex r {"(\\d{4})-(?:(?:(0?2)-(0?[1-9]|[1-2][0-9]))|(?:(0?[13578]|1[02])-(0?[1-9]|[1-2][0-9]|3[0-1]))|(?:(0?[469]|11)-(0?[1-9]|[1-2][0-9]|30)))"};
    while(true) 
    {
        cout << "Enter a date (yyyy-mm-dd) (q = quit): ";
        string str;
        if(!getline(cin, str) || str == "q")
        {
            break;
        }
        smatch m; 
        if(regex_match(str, m, r))
        {
         //   int year = stoi(m[1]);
         //   int month = stoi(m[2]);
          //  int day = stoi(m[3]);
            //if((month == 2 && day <= 29) ||
              //  (month == 1 || month == 3 || month == 5 ||month == 7 || month == 8|| month == 10 || month == 12) || 
                //((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30))
                cout << "Valid date " << m[1] << " " << m[2] << " " << m[3] << endl;// Year=" << year<< ", month=" << month << ", day=" << day <<  endl;
           //cout << format("  Valid date: Year={}, month={}, day={}", year, month, day) << endl;
          // else
//cout << "Invalid date!" << endl;
        } 
        else
        {
            cout << "Invalid date!" << endl;
        }
    }

    return 0;
}