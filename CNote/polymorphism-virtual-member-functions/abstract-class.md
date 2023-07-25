# Abstract classes

Object-oriented programming (OOP) is a powerful programming paradigm, consisting of several features. Three key features
include:

- Classes: A class encapsulates data and behavior to create objects.
- Inheritance: Inheritance allows one class (a subclass) to be based on another class (a base class or superclass). Ex:
  A Shape class may encapsulate data and behavior for geometric shapes, like setting/getting the Shape's name and color,
  while a Circle class may be a subclass of a Shape, with additional features like setting/getting the center point and
  radius.
- Abstract classes: An abstract class is a class that guides the design of subclasses but cannot itself be instantiated
  as an object. Ex: An abstract Shape class might also specify that any subclass must define a ComputeArea() function.

## Abstract and concrete classes

- A **pure virtual function** is a virtual function that is not implemented in the base class, thus all derived classes
  must
  override the function. A pure virtual function is declared with the "virtual" keyword and is assigned with 0. Ex:
  `virtual double ComputeArea() const = 0;` declares a pure virtual function ComputeArea().

- An **abstract class** is a class that cannot be instantiated as an object, but is the superclass for a subclass and
  specifies how the subclass must be implemented. Any class with one or more pure virtual functions is abstract.

- A **concrete class** is a class that is not abstract, and hence can be instantiated.

```c++
class Shape {
   protected:
      Point position;

   public:
      virtual ~Shape() { }
      virtual double ComputeArea() const = 0;

      Point GetPosition() const {
         return position;
      }

      void SetPosition(Point newPosition) {
         position = newPosition;
      }

      void MovePositionRelative(Point otherPosition) {
         double x = position.GetX() + otherPosition.GetX();
         double y = position.GetY() + otherPosition.GetY();

         position.SetX(x);
         position.SetY(y);
      }
};

int main(int argc, const char* argv[]) {
   Shape* shape = new Shape();
   ...
}
```

- The Shape class has the pure virtual ComputeArea() function. The Shape class is abstract due to having a pure virtual
  function.
- An abstract class cannot be instantiated.