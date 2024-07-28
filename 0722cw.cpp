#include <iostream>
#include <string>
using namespace std;

// 基類 Animal
class Animal {
protected:
    string name;
    int age;
    string gender; 

public:
    // 初始化
    Animal(string n, int a, string g) : name(n), age(a), gender(g) {}

    void display() const {//conset是是讓他部會修改成員
        cout << "Name: " << name << ", Age: " << age << ", Gender: " << gender << endl;
    } 

    void makeSound() const{
        cout << "Some generic animal sound" << endl;
    }

    // 方法：設置名字
    void setName(string n) {
        name = n;
    }

    // 方法：設置年齡
    void setAge(int a) {
        age = a;
    }

     // 方法：設置性別
    void setGender(string g) {
        gender = g;
    }

      // 附加信息(多型化)
    void display(int healthStatusScore) const {
        cout << name << "'s health status: " << healthStatusScore << endl;
    }

    void display(double foodAmount) const {
        cout << name << "'s daily food requirement: " << foodAmount << " kg" << endl;
    }

};


class Mammal : public Animal {
private:
    string furColor; // 毛色

public:
    
    Mammal(string n, int a, string g, string f) : Animal(n, a, g), furColor(f) {}

    
    void display() const {
        Animal::display();// animal裡面的display
        cout << "Fur Color: " << furColor << endl;
    }

    void makeSound() const {
        cout << "Mammal sound: Roar" << endl;
    }

    //方法：設置毛色
    void setFurColor(string f) {
        furColor=f;
    }


    void display(int healthStatusScore) const {
        Animal::display(healthStatusScore);
    }

    void display(double foodAmount) const {
        Animal::display(foodAmount);
    }

};


class Bird : public Animal {
private:
    int wingSpan; // 翅膀長度

public:
    
    Bird(string n, int a, string g, int w) : Animal(n, a, g), wingSpan(w) {}

    void display() const {
        cout << "Wing Span: " << wingSpan << " cm" << endl;
    }

    void makeSound() const {
        cout << "Bird sound: Chirp" << endl;
    }

    //方法：設置翅膀長度
    void setWingSpan(int w) {
    if (w > 0) {
        wingSpan = w;
    } else {
        cout << "Wing span number must be positive." << endl;
    }
}


    void display(int healthStatusScore) const {
        Animal::display(healthStatusScore);
    }

    void display(double foodAmount) const {
        Animal::display(foodAmount);
    }
};


class Reptile : public Animal {
private:
    string scaleType; // 鱗片類型

public:
   
    Reptile(string n, int a, string g, string s) : Animal(n, a, g), scaleType(s) {}

   
    void display() const {
        Animal::display();
        cout << "Scale Type: " << scaleType << endl;
    }


    void makeSound() const {
        cout << "Reptile sound: Hiss" << endl;
    }

    //方法：設置鱗片
    void setScaleType(string s) {
        scaleType=s;
    }


    void display(int healthStatusScore) const {
        Animal::display(healthStatusScore);
    }

    void display(double foodAmount) const {
        Animal::display(foodAmount);
    }
};

int main() {
    // 創造動物
    Mammal lion("Leo", 5, "Male", "Golden");
    Bird eagle("Eagy", 3, "Female", 200);
    Reptile snake("Susan", 2, "Male", "Smooth");

    lion.display();
    lion.makeSound();
    cout << endl;

    eagle.display();
    eagle.makeSound();
    cout << endl;

    snake.display();
    snake.makeSound();
    cout << endl;

    // 附加
    lion.display(85); 
    eagle.display(1.5); 

    while(true) {//修改資訊
        string yesOrNo;
        cout << "Do you want to change the information? (Y/N): ";
        cin >> yesOrNo;
        if(yesOrNo == "N" || yesOrNo == "n") {
            break;
        } else {
            string animalType, animalName, attribute;
            cout << "Which type of animal do you want to edit? (Mammal, Bird, Reptile): ";
            cin >> animalType;
            cout << "Which animal? (example: Lion, Eagle, Snake): ";
            cin >> animalName;
            
            // Handle input for specific animal type and name
            if (animalType == "Mammal" && animalName == "Lion") {
                cout << "What do you want to change? (name, age, gender, furColor): ";
                cin >> attribute;
                if (attribute == "name") {
                    string newName;
                    cout << "Enter new name: ";
                    cin >> newName;
                    lion.setName(newName);
                } else if (attribute == "age") {
                    int newAge;
                    cout << "Enter new age: ";
                    cin >> newAge;
                    lion.setAge(newAge);
                } else if (attribute == "gender") {
                    string newGender;
                    cout << "Enter new gender: ";
                    cin >> newGender;
                    lion.setGender(newGender);
                } else if (attribute == "furColor") {
                    string newFurColor;
                    cout << "Enter new fur color: ";
                    cin >> newFurColor;
                    lion.setFurColor(newFurColor);
                }
                cout << " " << endl;
                lion.display();
            } else if (animalType == "Bird" && animalName == "Eagle") {
                cout << "What do you want to change? (name, age, gender, wingSpan): ";
                cin >> attribute;
                if (attribute == "name") {
                    string newName;
                    cout << "Enter new name: ";
                    cin >> newName;
                    eagle.setName(newName);
                } else if (attribute == "age") {
                    int newAge;
                    cout << "Enter new age: ";
                    cin >> newAge;
                    eagle.setAge(newAge);
                } else if (attribute == "gender") {
                    string newGender;
                    cout << "Enter new gender: ";
                    cin >> newGender;
                    eagle.setGender(newGender);
                } else if (attribute == "wingSpan") {
                    int newWingSpan;
                    cout << "Enter new wing span (cm): ";
                    cin >> newWingSpan;
                    eagle.setWingSpan(newWingSpan);
                }
                cout << " " << endl;
                eagle.display();
            } else if (animalType == "Reptile" && animalName == "Snake") {
                cout << "What do you want to change? (name, age, gender, scaleType): ";
                cin >> attribute;
                if (attribute == "name") {
                    string newName;
                    cout << "Enter new name: ";
                    cin >> newName;
                    snake.setName(newName);
                } else if (attribute == "age") {
                    int newAge;
                    cout << "Enter new age: ";
                    cin >> newAge;
                    snake.setAge(newAge);
                } else if (attribute == "gender") {
                    string newGender;
                    cout << "Enter new gender: ";
                    cin >> newGender;
                    snake.setGender(newGender);
                } else if (attribute == "scaleType") {
                    string newScaleType;
                    cout << "Enter new scale type: ";
                    cin >> newScaleType;
                    snake.setScaleType(newScaleType);
                }
                cout << " " << endl;
                snake.display();
            } else {
                cout << "Invalid animal type or name." << endl;
            }
        }
    }

    while (true) {//新增動物
        string yesOrNo;
        cout << "Do you want to add a new animal? (Y/N): ";
        cin >> yesOrNo;
        if(yesOrNo == "N" || yesOrNo == "n") {
            break;
        } else {
            string animalType, animalSpecies, name, gender;
            int age;
            cout << "Which type of animal do you want to add? (Mammal, Bird, Reptile): ";
            cin >> animalType;
            cout << "Which specie of animal do you want to add? (elephant, rabbit etc): ";
            cin >> animalSpecies;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter gender: ";
            cin >> gender;

            if (animalType == "Mammal") {
                string furColor;
                cout << "Enter fur color: ";
                cin >> furColor;
                cout << " " << endl;
                Mammal newAnimal(name, age, gender, furColor);
                newAnimal.display();
            } else if (animalType == "Bird") {
                int wingSpan;
                cout << "Enter wing span (cm): ";
                cin >> wingSpan;
                cout << " " << endl;
                Bird newAnimal(name, age, gender, wingSpan);
                newAnimal.display();
            } else if (animalType == "Reptile") {
                string scaleType;
                cout << "Enter scale type: ";
                cin >> scaleType;
                cout << " " << endl;
                Reptile newAnimal(name, age, gender, scaleType);
                newAnimal.display();
            } else {
                cout << "Invalid animal type." << endl;
            }
        }
        
    }

    return 0;
}