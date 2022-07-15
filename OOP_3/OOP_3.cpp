#include <iostream>
#include <string>
using namespace std;

class Figure {
protected:
    string name;
    float a = 0;
public:
    Figure(string m_name, float m_a = 0) : name(m_name),
        a(m_a) {}
    virtual float area() = 0;
};

class Parallelogram : public Figure {
protected:
    float h = 0;
public:
    Parallelogram(float a, float m_h = 0) : Figure("Parallelogram", a),  h(m_h) {}
    float area() override { return a * h; }
    ~Parallelogram(){}
};

class Circle : public Figure {
protected:
    float r = 0;
public:
    Circle(float m_r) : Figure("Circle"),  r(m_r) {}
    float area() override { return pow(r, 2) * 3.14; }
    ~Circle(){}
};

class Rectangle : public Parallelogram {
protected:
    float b = 0;
public:
    Rectangle(float a, float m_b) : Parallelogram(a), b(m_b) {}
    float area() override { return a * b; }
    ~Rectangle() {}
};

class Rhombus : public Parallelogram {
public:
    Rhombus(float a, float h) : Parallelogram(a, h) {}
    float area() override { return a * h; }
    ~Rhombus() {}
};

class Square : public Parallelogram {
public:
    Square(float a) : Parallelogram(a) {}
    float area() override { return pow(a, 2); }
    ~Square() {}
};

class Car {
protected:
    string company = "NN";
    string model = "NN";
public:
    string get_comp() { return company; }
    string get_model() { return model; }
    Car(string m_company, string m_model) : company(m_company), model(m_model) {
        cout << "Car of company " << get_comp() << " and model " << get_model();
    }
    ~Car() {}
};

class PassengerCar : virtual public Car {
public:
    PassengerCar(string company, string model) : Car(company, model) { 
        cout << "Passenger car of company " << get_comp() << " and model " << get_model(); 
    }
    ~PassengerCar() {}
};

class Bus : virtual public Car {
public:
    Bus(string company, string model) : Car(company, model) {
        cout << "Bus of company " << get_comp() << " and model " << get_model();
    }
    ~Bus() {}
};

class Minivan : public PassengerCar, Bus {
    Minivan(string company, string model) :
        Car(company, model), PassengerCar(company, model), Bus(company, model)
    {
        cout << "Minivan of company " << get_comp() << " and model " << get_model();
    }
    ~Minivan() {}
};



int main()
{
    Parallelogram p0(2, 2);
    Circle c0(2);
    Rectangle r0(3, 4);
    Rhombus rh0(2, 3);
    Square s0(4);

    cout << "Areas of figure: \nParallelogram:" << p0.area() 
        << "\nCircle: " << c0.area() 
        << "\nRectangle: " << r0.area() 
        << "\nRhombus: " << rh0.area() 
        << "\nSquare:" << s0.area();

    Car car("CAT", "X");
    PassengerCar pCar("Tesla", "X");
    Bus bus("Kamaz", "-");
    Minivan minivan("-", "-");


}