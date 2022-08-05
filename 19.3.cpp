#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int maxpayment=0, sum=0, payment=0, id;
    std::string buffer;
    std::ifstream fin;
    std::vector<int> money;
    std::vector<std::string> name;
    std::vector<std::string> surname;

    fin.open("TextFile3.txt");

    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> buffer;
            name.push_back(buffer);
            fin >> buffer;
            surname.push_back(buffer);
            fin >> payment;
            money.push_back(payment);
            fin >> buffer;            
        }
        fin.close();        
    }
    else
    {
        std::cout << "some problem, the file address seems to be wrong\n";
    }
    for (int i = 0; i < money.size(); i++)
    {
        if (maxpayment < money[i])
        {
            maxpayment = money[i];
            id = i;
        }
        sum += money[i];
    }
    std::cout << "\nThe amount of payments is " << sum << "\nThe max of payments is " << maxpayment << std::endl;
    std::cout << "\nThe oner of the max payment is: " << name[id] << " " << surname[id] << std::endl;
}

