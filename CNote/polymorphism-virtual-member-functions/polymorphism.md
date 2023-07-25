# Polymorphism

**Polymorphism** refers to determining which program behavior to execute depending on data types. Two main types of
polymorphism exist:

- **Compile-time polymorphism** is when the compiler determines which function to call at compile-time.
- **Runtime polymorphism** is when the compiler is unable to determine which function to call at compile-time, so the
  determination is made while the program is running.

Function overloading is an example of compile-time polymorphism where the compiler determines which of several
identically-named functions to call based on the function's arguments.

One scenario requiring runtime polymorphism involves derived classes. Programmers commonly create a collection of
objects of both base and derived class types. Ex: The statement `vector<Business*> businessList;` creates a vector that
can contain pointers to objects of type Business or Restaurant, since Restaurant is derived from Business. Similarly,
polymorphism is also used for references to objects. Ex: Business& primaryBusiness declares a reference that can refer
to Business or Restaurant objects.

## Compile-time polymorphism

```c++
void DriveTo(string restaurant) {
   cout << "Driving to " << restaurant << endl;
}

void DriveTo(Restaurant restaurant) {
   cout << "Driving to " << restaurant.GetDescription() << endl;
}

int main() {
   DriveTo("Big Mac's");  // Call string version
}
```

## Runtime polymorphism

```c++
void DriveTo(Business* businessPtr) {
   cout << "Driving to " << businessPtr->GetDescription() << endl;
}

int main() {
   int index;
   vector<Business*> businessList;
   Business* businessPtr;
   Restaurant* restaurantPtr;
   ...
   businessList.push_back(businessPtr);
   businessList.push_back(restaurantPtr);

   index = rand() % businessList.size();
   DriveTo(businessList.at(index));
}

```

- The DriveTo() function is overloaded. The first version has a string parameter, and the second version a Restaurant
  parameter.
- With compile-time polymorphism, the compiler knows at compile-time to call the first DriveTo() because the argument "
  Big Mac's" is a string.
- The DriveTo() function has a Business pointer parameter and calls the GetDescription() function.
- businessList is a vector of Business pointers. Several pointers to Business and Restaurant objects are pushed onto
  businessList.
- index is assigned with a randomly chosen integer. The compiler cannot determine at compile-time if DriveTo() is called
  with a Business pointer or Restaurant pointer.
- With runtime polymorphism, the decision is made at runtime to call Restaurant GetDescription() instead of Business
  GetDescription() for a Restaurant pointer.

The program above uses a C++ feature called **derived/base class pointer conversion**, where a pointer to a derived
class is converted to a pointer to the base class without explicit casting. The above statement businessList.push_back(
restaurantPtr); uses derived/base class pointer conversion to convert the Restaurant pointer to a Business pointer (
businessList is a vector of Business pointers).

## Virtual functions

Runtime polymorphism only works when an overridden member function in a base class is virtual. A **virtual function** is
a
member function that may be overridden in a derived class and is used for runtime polymorphism. A virtual function is
declared by prepending the keyword "virtual". Ex: virtual string GetDescription() const. At runtime, when a virtual
function is called using a pointer, the correct function to call is dynamically determined based on the actual object
type to which the pointer or reference refers.

The **override** keyword is an optional keyword used to indicate that a virtual function is overridden in a derived
class. Good practice is to use the override keyword when overriding a virtual function to avoid accidentally misspelling
the function name or typing the wrong parameters.

```c++
class Business {
public:
   string GetDescription() const {
      return name + " -- " + address;
   }
   ...
};

class Restaurant : public Business {
public:
   string GetDescription() const {
      return name + " -- " + address +
         "\n  Rating: " + to_string(rating);
   }
   ...
};

int main() {
   Business* businessPtr;
   Restaurant favoriteCafe;
   favoriteCafe.SetName("Friends Cafe");
   favoriteCafe.SetAddress("500 2nd Ave");
   favoriteCafe.SetRating(5);

   // Point to favoriteCafe
   businessPtr = &favoriteCafe;

   cout << businessPtr->GetDescription();
}
```

- Restaurant overrides GetDescription() from the base class Business without using the "override" keyword.
- businessPtr points to favoriteCafe. businessPtr->GetDesciption() calls Business GetDescription() instead of Restaurant
  GetDescription() because runtime polymorphism does not work without virtual functions.
- The "virtual" keyword makes GetDescription() a virtual function. The "override" keyword indicates that Restaurant
  GetDescription() overrides the base class GetDescription().
- Running the program with an overridden virtual function causes runtime polymorphism to call Restaurant
  GetDescription().

### Virtual table

To implement virtual functions, the compiler creates a virtual table that allows the computer to quickly lookup which
function to call at runtime. The virtual table contains an entry for each virtual function with a function pointer that
points to the most-derived function that is accessible to each class. Looking up which function to call makes runtime
polymorphism slower than compile-time polymorphism.

## Pure virtual functions

Sometimes a base class should not provide a definition for a member function, but all derived classes must provide a
definition. Ex: A Business may require all derived classes to define a GetHours() function, but the Business class does
not provide a default GetHours() function.

A **pure virtual function** is a virtual function that provides no definition in the base class, and all derived classes
must override the function. A pure virtual function is declared like a virtual function with the "virtual" keyword but
is assigned with 0. Ex: `virtual string GetHours() const = 0;` declares a pure virtual function GetHours().

A class that has at least one pure virtual function is known as an **abstract base class**. An abstract base class
object cannot be declared. Ex: The variable declaration `Business someBusiness;` generates a syntax error if Business is
an abstract base class.

```c++
class Business {
public:
   void SetName(string busName) {
      name = busName;
   }

   void SetAddress(string busAddress) {
      address = busAddress;
   }

   virtual string GetDescription() const {
      return name + " -- " + address;
   }

   virtual string GetHours() const = 0;     // pure virtual function

protected:
   string name;
   string address;
};
```

In the above example, the programmer may intend to create several classes derived from Business, such as Restaurant,
LawnService, and CoffeeShop. The abstract base class Business implements functionality common to all derived classes,
thus avoiding redundant code in all derived classes, and supporting uniform treatment of a collection (e.g., vector) of
objects of derived classes via polymorphism. Not overriding the pure virtual function in a derived class makes the
derived class an abstract base class too.