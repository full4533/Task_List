//
// int main()
// void display_menu()
// void add_task(vector<string>& tasks)
// void delete_task(vector<string>& tasks)
// void view_tasks(const vectro<string>& tasks)
// void load_tasks<vector<string>& tasks)
// void delete_tasks<vector<string>& tasks0
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm> // for del by contents

int display_menu() // view, add, delete, exit
{
    
    // create menu items that will respond to number input from user
    // used a for loop so that menu updates can be easily displayed if changed later
    std::unordered_map<int, std::string>menu;
    
    menu[1] = "View tasks";
    menu[2] = "Add a task";
    menu[3] = "Delete a task";
    menu[4] = "Exit";
    
    std::cout << "________Menu Options________ \n";
    
    for (int i = 1; i <= menu.size(); ++i)
    {
        std::cout << i << "). " << menu[i] << '\n';
    }
    
    std::cout << "Please enter a number to select a menu option \n";
    int user_input;
    std::cin >> user_input;
    std::cout << "You selected: " << menu[user_input] << '\n';
    
    return user_input;
    
}

void view_tasks(std::vector<std::string>& tasks)
{
    if (tasks.empty())
    {
        std::cout << "There are no tasks to view \n";
        return;
    }
    
    std::string user_response;
    
    for (int i = 0; i < tasks.size(); ++i)
    {
        std::cout << i + 1 << "). " << tasks[i] << '\n';
    }
    while (true)
    {
        std::cout << "Enter 'Exit' to return to the menu \n";
        std::getline(std::cin, user_response);
        
        if (user_response == "exit" || user_response == "Exit")
        {
            break;
        }
    }
    
    
}

void add_tasks(std::vector<std::string>& tasks)
{
    //want to loop this so n number of task can be added
    std::cout << "Type the task you'd like me to add or type 'exit' to exit. \n";
    std::string task_to_add;
    while (true)
    {
        std::getline(std::cin, task_to_add);
        if (task_to_add == "exit" || task_to_add == "Exit")
        {
            break; //does this exit function or entire project
        }
        tasks.push_back(task_to_add);
    }
}


void delete_tasks(std::vector<std::string>& tasks)
{
    
    for (int i = 0; i < tasks.size(); ++i) //chose not to funct call view_tasks as this func offers exit option. simple to display here directly too.
    {
        std::cout << i + 1 << "). " << tasks[i] << '\n';
    }
    std::cout << "Enter the number of the tasks that you would like to delete or type '0' to exit. \n"; //fix this to accept "Exit" not "0" to exit.
    int task_to_delete;
    while (true)
    {
        std::cin >> task_to_delete;
        if (task_to_delete >= 1 && task_to_delete <= tasks.size())
        {
            tasks.erase(tasks.begin() + task_to_delete - 1);
        }
        else if (task_to_delete == 0)
        {
            break;
        }
    }
}

int main()
{
    std::vector<std::string>tasks;
    int user_request;
    while (true)
    {
        user_request = display_menu();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (user_request)
        {
            case 1:
                view_tasks(tasks);
                break;
            case 2:
                add_tasks(tasks);
                break;
            case 3:
                delete_tasks(tasks);
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}
