/*------------------------3------------------------ */
#include<iostream>
using namespace std;

class CSE {
    int a, b;
public:
    CSE operator + (CSE ob) {
        CSE temp;
        temp.a = a + ob.a;
        temp.b = b + ob.b;
        return temp;
    }
    friend CSE operator + (int num, CSE ob) {
        CSE temp;
        temp.a = num + ob.a;
        temp.b = num + ob.b;
        return temp;
    }
    void setValues(int x, int y) {
        a = x;
        b = y;
    }
    void printValues() {
        cout << a << " " << b << endl;
    }
};

int main() {
    CSE ob1, ob2;
    ob1.setValues(10, 12);
    ob2 = 20 + ob1;
    ob2.printValues();
    return 0;
}

/*------------------------4------------------------ */
#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    // Constructor to initialize coordinates
    Point(int xCoord = 0, int yCoord = 0) {
        x = xCoord;
        y = yCoord;
    }

    // Friend function to overload the (-) operator
    friend Point operator-(const Point& p1, const Point& p2);

    // Function to display the point
    void display() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

// Overloaded (-) operator as a friend function
Point operator-(const Point& p1, const Point& p2) {
    Point temp;
    temp.x = p1.x - p2.x;
    temp.y = p1.y - p2.y;
    return temp;
    // return Point(p1.x - p2.x, p1.y - p2.y);
}

int main() {
    // Creating two points
    Point p1(10, 15);
    Point p2(5, 8);

    // Subtracting points using the overloaded operator
    Point result = p1 - p2;

    // Displaying the result
    result.display();

    return 0;
}

/*------------------------6------------------------ */
#include <iostream>
using namespace std;

class Base {
protected:
    int protectedVar;

public:
    Base() {
        protectedVar = 0;
    }

    void setProtectedVar(int val) {
        protectedVar = val;
    }

    void showProtectedVar() {
        cout << "Base protectedVar: " << protectedVar << endl;
    }
};

class Derived : public Base {
public:
    void changeProtectedVar(int val) {
        protectedVar = val;
    }

    void showDerivedProtectedVar() {
        cout << "Derived protectedVar: " << protectedVar << endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    baseObj.setProtectedVar(5);
    baseObj.showProtectedVar();

    derivedObj.changeProtectedVar(10);
    derivedObj.showDerivedProtectedVar();

    return 0;
}

/*------------------------8------------------------ */
// Constructing B1 
// Constructing B2 
// Constructing D 
// Destructing D 
// Destructing B2 
// Destructing B1

/*------------------------9------------------------ */
// Inside Q

/*------------------------10------------------------ */
#include <iostream>
using namespace std;

class Fruit {
protected:
    int totalFruits;

public:
    Fruit(int count = 0) : totalFruits(count) {}

    void addFruits(int count) {
        totalFruits += count;
    }

    int getTotalFruits() const {
        return totalFruits;
    }

    void display(const string &fruitName) const {
        cout << "Number of " << fruitName << ": " << totalFruits << endl;
    }
};

class Apples : public Fruit {
public:
    Apples(int count) : Fruit(count) {}
};

class Mangoes : public Fruit {
public:
    Mangoes(int count) : Fruit(count) {}
};

int main() {
    Apples apples(30);
    Mangoes mangoes(20);

    apples.display("Apples");
    mangoes.display("Mangoes");

    cout << "Total number of fruits: " << apples.getTotalFruits() + mangoes.getTotalFruits() << endl;

    return 0;
}
/*------------------------12------------------------ */
#include <iostream>
using namespace std;

class MyFloat {
private:
    float value;

public:
    // Constructor to initialize the float value
    MyFloat(float val = 0.0) : value(val) {}

    // Overload the + operator to add two MyFloat objects
    MyFloat operator+(const MyFloat& other) const {
        return MyFloat(value + other.value);
    }

    // Function to display the value
    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    MyFloat f1(5.5), f2(3.3);

    // Use the overloaded + operator
    MyFloat f3 = f1 + f2;

    // Display the values
    f1.display();
    f2.display();
    f3.display();

    return 0;
}
/*------------------------13------------------------ */
#include <iostream>
using namespace std;

class MyClass {
private:
    bool value;
public:
    MyClass(bool val = false) : value(val) {}

    // Overloading the logical AND (&&) operator using a friend function
    MyClass operator&&(const MyClass& obj2) {
        MyClass temp;
        temp.value = value && obj2.value;
        return temp;
    }

    void display() const {
        cout << "Value: " << (value ? "true" : "false") << endl;
    }
};

int main() {
    MyClass obj1(true);
    MyClass obj2(false);
    MyClass obj3 = obj1 && obj2;

    obj1.display();  // Output: Value: true
    obj2.display();  // Output: Value: false
    obj3.display();  // Output: Value: false

    return 0;
}

/*------------------------13------------------------ */
#include <iostream>
using namespace std;

// Base class 1
class Base1 {
public:
    void display() {
        cout << "Base1 display" << endl;
    }
};

// Base class 2
class Base2 {
public:
    void display() {
        cout << "Base2 display" << endl;
    }
};

// Derived class
class Derived : public Base1, public Base2 {
public:
    void display() {
        Base1::display(); // Call display from Base1
        Base2::display(); // Call display from Base2
        cout << "Derived display" << endl;
    }
};

int main() {
    Derived obj;
    obj.display();
    return 0;
}

/*------------------------28------------------------ */
#include <iostream>
using namespace std;

class Vector2D {
private:
    float x, y;

public:
    // Constructor
    Vector2D(float x = 0, float y = 0) : x(x), y(y) {}

    // Overload + operator for vector addition
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // Overload - operator for vector subtraction
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    // Overload * operator for scalar multiplication
    Vector2D operator*(float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    // Display the vector
    void display() const {
        cout << "Vector(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.0, 2.0);

    Vector2D v3 = v1 + v2; // Vector addition
    Vector2D v4 = v1 - v2; // Vector subtraction
    Vector2D v5 = v1 * 2.0; // Scalar multiplication

    cout << "v1: ";
    v1.display();
    cout << "v2: ";
    v2.display();
    cout << "v3 (v1 + v2): ";
    v3.display();
    cout << "v4 (v1 - v2): ";
    v4.display();
    cout << "v5 (v1 * 2.0): ";
    v5.display();

    return 0;
}

#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

    // Function to normalize time
    void normalize() {
        minutes += seconds / 60;
        seconds %= 60;
        hours += minutes / 60;
        minutes %= 60;
        hours %= 24; // Assuming a 24-hour format
    }

public:
    // Constructor
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // Overload + operator for time addition
    Time operator+(const Time& other) const {
        return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
    }

    // Overload - operator for time subtraction
    Time operator-(const Time& other) const {
        int total_seconds1 = hours * 3600 + minutes * 60 + seconds;
        int total_seconds2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        int total_seconds = total_seconds1 - total_seconds2;

        // Handle negative time difference
        if (total_seconds < 0) {
            total_seconds = 0;
        }

        int h = total_seconds / 3600;
        total_seconds %= 3600;
        int m = total_seconds / 60;
        int s = total_seconds % 60;
        return Time(h, m, s);
    }

    // Overload ++ operator for pre-increment (incrementing by one minute)
    Time& operator++() {
        minutes += 1;
        normalize();
        return *this;
    }

    // Display the time
    void display() const {
        cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main() {
    Time t1(10, 45, 50);
    Time t2(2, 20, 30);

    Time t3 = t1 + t2; // Time addition
    Time t4 = t1 - t2; // Time subtraction

    cout << "t1: ";
    t1.display();
    cout << "t2: ";
    t2.display();
    cout << "t3 (t1 + t2): ";
    t3.display();
    cout << "t4 (t1 - t2): ";
    t4.display();

    ++t1; // Pre-increment t1 by one minute
    cout << "t1 after pre-increment: ";
    t1.display();

    return 0;
}


