#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <limits>

class TodoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {}; //basic constructor
    ~TodoItem() = default; //destructor

    int getId() {
        return id;
    } //getter

    std::string getDescription() { 
        return description;
    } //getter

    bool isCompleted() { return completed; }; //getter

    bool create(std::string new_description) {
        id = rand() % 100 + 1; //generates random int between 1 and 100
        description = new_description; 
        return true;
    }

    void setCompleted(bool val) {
        completed = val;
    }

};


int main()
{
    char input_option;
    int input_id;
    std::string input_description;
    std::string version = "v0.0.0";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;

    srand(time(NULL));

    todoItems.clear(); //clear to do list
    

    while (1) { //infinite loop to continously display list (and clear etc)
        system("cls");

        std::cout << "To Do List Maker\n" << version << std::endl;
        std::cout << std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {

            std::string completed = it->isCompleted() ? "done" : "not done"; //if iterator is completed (true) then set string "completed" to done, and if not completed, set to "not done"



            std::cout << it->getId() << " | " << it->getDescription() << " | " << completed << std::endl; //iterator
        }

        if (todoItems.empty()) {
            std::cout << "Add your first todo item!" << std::endl;
        }

        std::cout << "=====================" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "[a]dd a new todo" << std::endl;
        std::cout << "[c]omplete a todo" << std::endl;
        std::cout << "[q]uit" << std::endl;

        std::cout << "choice: ";

        std::cin >> input_option;

        if (input_option == 'q') {
            std::cout << "Goodbye!" << std::endl;
            break;
        }

        else if (input_option == 'a')
        {
            std::cout << "Add a new description: " << std::endl;
            std::cin.clear(); //clear input string buffer
            std::cin.ignore(); //ignore first return
            std::getline(std::cin, input_description); //capture input into input desc variable

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem); //add new item
        }


        else if (input_option == 'c') {
            std::cout << "Enter id to mark completed: " << std::endl;
            std::cin >> input_id;
            

            for (it = todoItems.begin(); it != todoItems.end(); it++) { //iterate through 
                
                
                if (input_id == it->getId()) { //if id = an id then..
                    it->setCompleted(true); //set to complete
                    break;
                }

                else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            
            }


        }
        


    }
    
    return 0;
    system("pause>0");

}
