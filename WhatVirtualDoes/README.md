# Module - 1 : understanding __virtual__ Keyword in C++

The __virtual__ keyword allows *C++ compilers* to insert the code in such a way that at runtime functional call is dependent upon the Dynamic type than Static type

## 1.1 Creating an __IS-A__ relationship

Let's create a IS-A relationship with base and derived class. Both contains the same function in them
```
class Base {
public:
    virtual void fn() { cout<<"Base Fn"<<endl; }
};
class Derived : public Base {
public:
    virtual void fn() { cout<<"Derived"<<endl;}
};
```
Now lets create another function which takes the __Base__ class as parameter. Lets use C++11 __shared_ptr__ instead of using plain old pointer syntax which anyway is not recommended to be used Now
```
void CallFn(shared_ptr<Base> bn) {
    bn->fn();
}
```
Then call the function using both __Base Class__ and __Derived Class__ instantiation

```
int main() {
    shared_ptr<Base> bfirst = make_shared<Base>();
    CallFn(bfirst); // Will Call Base::fn()

    shared_ptr<Base> bSecond = make_shared<Derived>();
    CallFn(bSecond); // Will Call Derived::fn()

    return 0;
}
```
Here, the virtual does the trick when we call the function __CallFn__ with __Derived__ class.

*Last but not the least, both classes will have an overhead of 4/8 bytes (depending upon the platform) overhead.*

## 1.2 : Why this kind of inheritance is a problems

Let revisit the class __Base__ and __Derived__, there is nothing to qualify it for having a __IS-A__ relationship. These kinds of class hierarchies spread around code with multiple level which not only creates a confusion but also deprive programmers from taking a command on their code.

*Code optimizations by compilers doesn't alter the basic functionality of the code, but in this case the* __Compiler__ *and not the* __Programmer__ *will decide which function should get called at runtime.

This also prevents programmers from understanding the inheritance hierarchies which leads to a bad code.*

__These are some of the reasons why we shouldn't use Virtual unless otherwise absolutely necessary__
