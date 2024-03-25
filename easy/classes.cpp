#include <iostream>
#include <sstream>
using namespace std;

class Student{
    private:
        int age;
        int stardard;
        string first_name;
        string last_name;
    public:
        void set_age(int age){
            this->age = age;
        }

        void set_standard(int standard){
            this->stardard = standard;
        }

        void set_first_name(string first_name){
            this->first_name = first_name;
        }

        void set_last_name(string last_name){
            this->last_name = last_name;
        }

        int get_age(){
            return this->age;
        };

        string get_last_name(){
            return this->last_name;
        }

        string get_first_name(){
            return this->first_name;
        }

        int get_standard(){
            return this->stardard;
        }

        string to_string(){
            std::string formattedString;
            formattedString.resize(1024); 

            int length = snprintf(&formattedString[0], formattedString.size(), "%d,%s,%s,%d", age, first_name.c_str(), last_name.c_str(), stardard);

            formattedString.resize(length);    

            return formattedString;    
        }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}