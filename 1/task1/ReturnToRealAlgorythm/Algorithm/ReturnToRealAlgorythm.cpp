#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <unordered_set>
#include <set>

// id и error нужно сделать в класс и выводить тот который первый!!!
// бинарный поиск то есть вывести этого студента  по его id. 

void SortirovkaLista(std::list<std::string> students)
{
    students.sort([](const std::string& a, const std::string& b) {
        std::string aSubstr = a.substr(a.find_last_of(',') + 1);
        std::string bSubstr = b.substr(b.find_last_of(',') + 1);
        return std::stoi(aSubstr) < std::stoi(bSubstr);
        });

    for (std::string stu : students)
    {
        std::cout << stu << "\n";
    }
}

void binarySearch(std::list<std::string>& students, double num)
{
    bool found = false;

    for (std::string stu : students)
    {
        size_t pos1 = stu.find(',');
        size_t pos2 = stu.find(',', pos1 + 1);
        std::string numStr = stu.substr(pos2 + 1);
        double studentNum = std::stod(numStr);

        if (studentNum == num)
        {
            found = true;
            std::cout << "\n" << stu;
            break;
        }
    }

    if (!found)
    {
        std::cout << "\nNIL";
    }
}


int main()
{
    std::list<std::string> students;
    
    while (true) {
        std::string alls;
        std::string yn;
        
            std::getline(std::cin, alls);
            
            if (alls == "R") 
            {
           
                SortirovkaLista(students);

                for (std::string stu : students)
                {
                    std::cout << "\n R " << stu << "\n";
                }

                double num;
                std::cout << "\nsearch -> ";
                std::cin >> num;


                /*binariSearch(students);*/
                binarySearch(students, num);
            }

            else if (alls == "U")
            {
                std::string input;
                std::cout << " new input ";
                std::getline(std::cin, input);

                size_t firstCommaPos = alls.find(',');
                size_t secondCommaPos = alls.find(',', firstCommaPos + 1);
                std::string modifiedString = alls.substr(0, secondCommaPos + 1) + input;

                alls = modifiedString;
            }

            students.push_back(alls);
            std::string submessage = alls.substr(0, alls.find(','));

            bool isDuplicate = false;

            for (auto it = students.begin(); it != students.end(); ++it)
            {
                if (*it == alls) continue;
                std::string stuSubstr = it->substr(0, it->find(','));
                if (stuSubstr == submessage)
                {
                    isDuplicate = true;
                    break;
                }
            }

            if (isDuplicate)
            {
                std::cout << "DUPLICATE";
            }

           /* for (std::string stu : students)
            {
                std::cout << "\n C " << stu << "\n";
            }*/        
    }
    return 0;
}


