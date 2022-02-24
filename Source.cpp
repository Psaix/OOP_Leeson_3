#include <iostream>
#include <stdexcept>

//____________________________________________________________________________________________________________
//____________________________________________TASK1___________________________________________________________
//____________________________________________________________________________________________________________


//____________________________________________________________________________________________________________

//______________________________________    CLASS FIGURE    __________________________________________________

//____________________________________________________________________________________________________________



class Figure {
public:
	virtual float area() const = 0;
	virtual ~Figure() {}
};

class Parallelogram : public Figure {
private:
	float m_base = 0.00;
	float m_height = 0.00;
public:
	Parallelogram() {}
	Parallelogram(float base, float height) : m_base(base), m_height(height) {}
	float area() const override {
		return m_base * m_height;
	}
	
};

class Circle : public Figure {
private:
	const float pi = 3.14;
	float m_radius = 0.00;
public:
	Circle(float radius) : m_radius(radius) {}
	float area() const override {
		return pi * pow(m_radius, 2);
	}

};


class Rectangle : public Parallelogram {
private:
	float m_width = 0.00;
	float m_length = 0.00;
public:
	Rectangle(float width, float length) : m_width(width), m_length(length) {}
	float area() const  override {
		return m_width * m_length;
	}

};

class Square : public Parallelogram {
private:
	float m_side = 0.00;
public:
	Square(float side) : m_side(side) {}
	float area() const override {
		return pow(m_side, 2);
	}
};

class Rhombus : public Parallelogram {
private:
	float m_side = 0.00;
	float m_height = 0.00;
public:
	Rhombus(float side, float height) : m_side(side), m_height(height) {}
	float area() const override {
		return m_side * m_height;
	}
};


//____________________________________________________________________________________________________________
//____________________________________________TASK2___________________________________________________________
//____________________________________________________________________________________________________________



//____________________________________________________________________________________________________________

//______________________________________    CLASS CAR    _____________________________________________________

//____________________________________________________________________________________________________________


class Car {
protected:
	std::string m_company;
	std::string m_model;
public:
	Car() {}
	Car(std::string company, std::string model) : m_company(company), m_model(model) { 
		std::cout << "Company: " << m_company << std::endl
			<< "Model: " << m_model << std::endl;
	}
	~Car() {}
};

class PassengerCar : virtual public Car {
public:
	PassengerCar(std::string company, std::string model) :Car(company, model) {}
	PassengerCar() {
		std::cout << "Company: " << m_company << std::endl
			<< "Model: " << m_model << std::endl;
	}
};

class Bus : virtual public Car {
public:
	Bus(std::string company, std::string model) : Car(company, model) {}
	Bus() {
		std::cout << "Company: " << m_company << std::endl
			<< "Model: " << m_model << std::endl;
	}
};

class Minivan : public PassengerCar, public Bus {
public:
	Minivan(std::string company, std::string model) : PassengerCar(company, model), Bus(company, model), Car(company, model) {}
	Minivan() {
		std::cout << "Company: " << m_company << std::endl
			<< "Model: " << m_model << std::endl;
	}
};



//____________________________________________________________________________________________________________
//____________________________________________TASK3___________________________________________________________
//____________________________________________________________________________________________________________




//____________________________________________________________________________________________________________

//___________________________________    CLASS FRACTION    ___________________________________________________

//____________________________________________________________________________________________________________


class Fraction {
private:
	int m_numerator = 1;
	int m_denumerator = 1;
public:
	Fraction(int numerator, int denumerator) : m_numerator(numerator), m_denumerator(denumerator) {
		if (denumerator == 0)
			throw std::invalid_argument("Denumerator can't be zero");
	}
	
	int getNum() const {
		return m_numerator;
	}

	int getDenum() const {
		return m_denumerator;
	}


	friend Fraction operator+ (const Fraction& f1, const Fraction& f2);
	friend Fraction operator- (const Fraction& f1, const Fraction& f2);
	friend Fraction operator* (const Fraction& f1, const Fraction& f2);
	friend Fraction operator/ (const Fraction& f1, const Fraction& f2);
	Fraction operator- () const {
		return Fraction(-m_numerator, -m_denumerator);
	}
	friend bool operator!= (const Fraction& f1, const Fraction& f2);
	friend bool operator== (const Fraction& f1, const Fraction& f2);
	friend bool operator< (const Fraction& f1, const Fraction& f2);
	friend bool operator<= (const Fraction& f1, const Fraction& f2);
	friend bool operator> (const Fraction& f1, const Fraction& f2);
	friend bool operator>= (const Fraction& f1, const Fraction& f2);
};


//___________________________________________________________________________________________________________

//_______________________________________ OPERATOR '+' ______________________________________________________


Fraction operator+ (const Fraction& f1, const Fraction& f2) {
	if (f1.m_denumerator != f2.m_denumerator)
	{
		int denumerator = f1.m_denumerator * f2.m_denumerator;
		int num1 = f1.m_numerator * f2.m_denumerator;
		int num2 = f2.m_numerator * f1.m_denumerator;
		int result = num1 + num2;
		return Fraction(result, denumerator);
	}
	else
	{
		int result = f1.m_numerator + f2.m_numerator;
		return Fraction(result, f1.m_denumerator);
	}
}

//___________________________________________________________________________________________________________

//_______________________________________ OPERATOR '-' ______________________________________________________


Fraction operator- (const Fraction& f1, const Fraction& f2) {
	if (f1.m_denumerator != f2.m_denumerator)
	{

		int denumerator = f1.m_denumerator * f2.m_denumerator;
		int num1 = f1.m_numerator * f2.m_denumerator;
		int num2 = f2.m_numerator * f1.m_denumerator;
		int result = num1 - num2;
		return Fraction(result, denumerator);
	}
	else
	{
		int result = f1.m_numerator - f2.m_numerator;
		return Fraction(result, f1.m_denumerator);
	}
}

//___________________________________________________________________________________________________________

//_______________________________________ OPERATOR '*' ______________________________________________________


Fraction operator* (const Fraction& f1, const Fraction& f2) {
	int result = f1.m_numerator * f2.m_numerator;
	int result2 = f1.m_denumerator * f2.m_denumerator;
	return Fraction(result, result2);
}


//___________________________________________________________________________________________________________

//_______________________________________ OPERATOR '/' ______________________________________________________


Fraction operator/ (const Fraction& f1, const Fraction& f2) {
	int result = f1.m_numerator * f2.m_denumerator;
	int result2 = f1.m_denumerator * f2.m_numerator;
	return Fraction(result, result2);
}

//___________________________________________________________________________________________________________

//_______________________________________ OPERATOR '==' _____________________________________________________


bool operator== (const Fraction& f1, const Fraction& f2) {
	if (f1.m_denumerator != f2.m_denumerator)
	{
		int num1 = f1.m_numerator * f2.m_denumerator;
		int num2 = f2.m_numerator * f1.m_denumerator;
		if (num1 == num2)
			return true;
		else
			return false;
	}
	else
	{
		if (f1.m_numerator == f2.m_numerator)
			return true;
		else
			return false;
	}
}

//___________________________________________________________________________________________________________

//_______________________________________ OPERATOR '!=' _____________________________________________________


bool operator!= (const Fraction& f1, const Fraction& f2) {
	if (f1.m_denumerator != f2.m_denumerator)
	{
		int num1 = f1.m_numerator * f2.m_denumerator;
		int num2 = f2.m_numerator * f1.m_denumerator;
		if (num1 != num2)
			return true;
		else
			return false;
	}
	else
	{
		if (f1.m_numerator != f2.m_numerator)
			return true;
		else
			return false;
	}
}

//___________________________________________________________________________________________________________

//_______________________________________ OPERATOR '<' ______________________________________________________


bool operator< (const Fraction& f1, const Fraction& f2) {
	if (f1.m_denumerator != f2.m_denumerator)
	{
		int num1 = f1.m_numerator * f2.m_denumerator;
		int num2 = f2.m_numerator * f1.m_denumerator;
		if (num1 < num2)
			return true;
		else
			return false;
	}
	else
	{
		if (f1.m_numerator < f2.m_numerator)
			return true;
		else
			return false;
	}
}


//___________________________________________________________________________________________________________

//_______________________________________ OPERATOR '<=' _____________________________________________________


bool operator<= (const Fraction& f1, const Fraction& f2) {
	if (f1.m_denumerator != f2.m_denumerator)
	{
		int num1 = f1.m_numerator * f2.m_denumerator;
		int num2 = f2.m_numerator * f1.m_denumerator;
		if (num1 <= num2)
			return true;
		else
			return false;
	}
	else
	{
		if (f1.m_numerator <= f2.m_numerator)
			return true;
		else
			return false;
	}
}

//___________________________________________________________________________________________________________

//_______________________________________ OPERATOR '>' ______________________________________________________



bool operator> (const Fraction& f1, const Fraction& f2) {
	if (f1.m_denumerator != f2.m_denumerator)
	{
		int num1 = f1.m_numerator * f2.m_denumerator;
		int num2 = f2.m_numerator * f1.m_denumerator;
		if (num1 > num2)
			return true;
		else
			return false;
	}
	else
	{
		if (f1.m_numerator > f2.m_numerator)
			return true;
		else
			return false;
	}
}

//___________________________________________________________________________________________________________

//_______________________________________ OPERATOR '>=' _____________________________________________________



bool operator>= (const Fraction& f1, const Fraction& f2) {
	if (f1.m_denumerator != f2.m_denumerator)
	{
		int num1 = f1.m_numerator * f2.m_denumerator;
		int num2 = f2.m_numerator * f1.m_denumerator;
		if (num1 >= num2)
			return true;
		else
			return false;
	}
	else
	{
		if (f1.m_numerator >= f2.m_numerator)
			return true;
		else
			return false;
	}
}


//____________________________________________________________________________________________________________
//____________________________________________TASK4___________________________________________________________
//____________________________________________________________________________________________________________


class Card {
public:
	enum rank : int {
		HEARTS,
		DIAMONDS,
		SPADES,
		CLUBS
	};
	enum suit : char {
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING,
		ACE,
	};

private:
	bool m_IsFaceUp;
	rank m_Rank;
	suit m_Suit;

public:

	Card(bool Face, rank Rank, suit Suit) : m_IsFaceUp(Face), m_Rank(Rank), m_Suit(Suit) {}

	bool Flip() {
		if (m_IsFaceUp)
			m_IsFaceUp = false;
		else
			m_IsFaceUp = true;
		return m_IsFaceUp;
	}

	int GetValue() {
		switch (m_Suit) {
		case TWO:
			return 2;
			break;
		case THREE:
			return 3;
			break;
		case FOUR:
			return 4;
			break;
		case FIVE:
			return 5;
			break;
		case SIX:
			return 6;
			break;
		case SEVEN:
			return 7;
			break;
		case EIGHT:
			return 8;
			break;
		case NINE:
			return 9;
			break;
		case TEN:
			return 10;
			break;
		case JACK:
			return 10;
			break;
		case QUEEN:
			return 10;
			break;
		case KING:
			return 10;
			break;
		case ACE:
			return 1;
			break;
		default:
			break;
		}
	}

	~Card() {}
};



int main()
{

//______________________________________TASK2__________________________________________________________________

	Car car("Mitsubishi", "Lancer");
	PassengerCar passenger("Volkswagen", "Tiguan");
	Bus bus("Toyota", "Hiace");
	Minivan mini("Volvo", "Geely");


//______________________________________TASK3__________________________________________________________________


	Fraction frac(3, 4);
	Fraction frac2(9, 2);

	Fraction fracsub = frac - frac2;
	Fraction fracsum = frac + frac2;
	Fraction fracmult = frac * frac2;
	Fraction fracdiv = frac / frac2;

	-frac.getNum();
	-frac.getDenum();

	bool result;
	result = frac == frac2;
	result = frac != frac2;
	result = frac < frac2;
	result = frac <= frac2;

	try
	{
	}
	catch (std::invalid_argument) {
		std::cout << "Fraction class object - denumerator can't be zero" << std::endl;
	}



//______________________________________TASK4__________________________________________________________________



	Card card(true, Card::rank::SPADES, Card::suit::QUEEN);


	return 0;
}

