#include <iostream>
#include <string>
using namespace std;

// Base class: Meal
class Meal {
protected:
    string mealType;
    int calorieCount;

public:
    Meal(string type = "", int calories = 0) : mealType(type), calorieCount(calories) {}

    virtual void prepare() {
        cout << "Preparing meal: " << mealType << endl;
    }

    void calculateCalorieCount(int componentCalories) {
        calorieCount += componentCalories;
    }

    int getCalorieCount() const {
        return calorieCount;
    }
};

// Derived class: Breakfast
class Breakfast : public Meal {
protected:
    bool hasCoffee;

public:
    Breakfast(string type = "Breakfast", int calories = 0, bool coffee = false)
        : Meal(type, calories), hasCoffee(coffee) {}

    void prepareBreakfast() {
        prepare();
        if (hasCoffee) {
            cout << "Adding coffee to breakfast." << endl;
        }
    }
};

// Derived class: Dinner
class Dinner : public Meal {
protected:
    bool isSpecialDinner;

public:
    Dinner(string type = "Dinner", int calories = 0, bool special = false)
        : Meal(type, calories), isSpecialDinner(special) {}

    void prepareDinner() {
        prepare();
        cout << "Preparing dinner." << endl;
    }

    void prepareSpecialDinner() {
        if (isSpecialDinner) {
            cout << "Enhancing dinner with special ingredients." << endl;
        }
    }
};

// Derived class: Cereal
class Cereal : public Breakfast {
private:
    string cerealType;
    string milkType;

public:
    Cereal(string cereal, string milk, int calories, bool coffee = false)
        : Breakfast("Cereal", calories, coffee), cerealType(cereal), milkType(milk) {}

    void addMilk() {
        cout << "Adding " << milkType << " to " << cerealType << " cereal." << endl;
    }
};

// Derived class: Omelette
class Omelette : public Breakfast {
private:
    string eggType;
    string fillingType;

public:
    Omelette(string egg, string filling, int calories, bool coffee = false)
        : Breakfast("Omelette", calories, coffee), eggType(egg), fillingType(filling) {}

    void cookOmelette() {
        cout << "Cooking an omelette with " << eggType << " eggs and " << fillingType << " filling." << endl;
    }
};

// Derived class: MeatDish
class MeatDish : public Dinner {
private:
    string meatType;
    string sideDish;

public:
    MeatDish(string meat, string side, int calories, bool special = false)
        : Dinner("Meat Dish", calories, special), meatType(meat), sideDish(side) {}

    void cookMeatDish() {
        cout << "Cooking " << meatType << " with a side of " << sideDish << "." << endl;
    }
};

// Derived class: VegetarianDish
class VegetarianDish : public Dinner {
private:
    string mainIngredient;
    string additionalIngredient;

public:
    VegetarianDish(string main, string additional, int calories, bool special = false)
        : Dinner("Vegetarian Dish", calories, special), mainIngredient(main), additionalIngredient(additional) {}

    void prepareVegetarianDish() {
        cout << "Preparing vegetarian dish with " << mainIngredient << " and " << additionalIngredient << "." << endl;
    }
};

int main() {
    // Example usage
    Cereal myCereal("Cornflakes", "Almond Milk", 200, true);
    myCereal.prepareBreakfast();
    myCereal.addMilk();
    myCereal.calculateCalorieCount(50);
    cout << "Total calories: " << myCereal.getCalorieCount() << endl;

    Omelette myOmelette("Chicken", "Cheese", 300);
    myOmelette.prepareBreakfast();
    myOmelette.cookOmelette();
    myOmelette.calculateCalorieCount(100);
    cout << "Total calories: " << myOmelette.getCalorieCount() << endl;

    MeatDish myMeatDish("Steak", "Mashed Potatoes", 500, true);
    myMeatDish.prepareDinner();
    myMeatDish.cookMeatDish();
    myMeatDish.prepareSpecialDinner();
    myMeatDish.calculateCalorieCount(200);
    cout << "Total calories: " << myMeatDish.getCalorieCount() << endl;

    VegetarianDish myVegDish("Tofu", "Broccoli", 400);
    myVegDish.prepareDinner();
    myVegDish.prepareVegetarianDish();
    myVegDish.calculateCalorieCount(150);
    cout << "Total calories: " << myVegDish.getCalorieCount() << endl;

    return 0;
}