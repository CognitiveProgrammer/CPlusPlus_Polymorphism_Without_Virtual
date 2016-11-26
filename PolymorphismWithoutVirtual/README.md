# Module - 2 : Polymorphism without __virtual__ using __Template Specialization__

Its heartening to see that the polymorphic behavior which we have seen in [Module - 1]() can be achieved , but its also lightweight and gives control back to the developers.

At any point of time, the __Programmer__ will always be aware of which function will be called and they will program accordingly.

*I'll be demonstrating the same using C++11 templates, I found this approach quiet satisfying*

## 2.1 Creating a template class for hierarchies

Let's assume that we need to create a __BASE - DERIVED__ hierarchy for simplicity purpose. Let's start with having a enum defined for those
```
enum class Hierarchy {
    BASE,
    DERIVED
};
```
Now we can create the template Base class as coded below. Just mind the fact that the functions are not virtual
```
template<Hierarchy tag>
class Base {
public:
    void TestFn() { cout<<"Base Fn..."<<endl; }
};
```
and the derived class can be defined as specialized template of the base class as coded below
```
template <>
class Base<Hierarchy::DERIVED> : public Base<Hierarchy::BASE>{
public:
    void TestFn() { cout<<"Derived Fn..."<<endl; }
};

```
Not lets also define a function which should exhibit same polymorphic behavior which we've got using virtual functions. Since we're talking about templates, the function shall be declared with templates as coded below

```
template<Hierarchy hr>
void CallFn(shared_ptr<Base<hr>> BCall) {
    BCall->TestFn();
}
```

## 2.2 : Using template hierarchical classes

Now we can create the actual instance of the classes which we can use.
```
// Base Class Instance
shared_ptr<Base<Hierarchy::BASE>> bfirst = make_shared<Base<Hierarchy::BASE>>();

// Derived Class Instance. Remember its not assigned to Base Class    
shared_ptr<Base<Hierarchy::DERIVED>> bsecond = make_shared<Base<Hierarchy::DERIVED>>();

```
Both the instance can be used to with __CallFn__ , even without using templates explicitly and will exhibit proper behavior

```
// Calls Base::TestFn();
CallFn(bfirst);

// Calls Derived::TestFn()
CallFn(bsecond);
```
These calls could otherwise be written as
```
CallFn<Hierarchy::BASE>(bfirst);
CallFn<Hierarchy::DERIVED>(bsecond);
```    
We can see  that it automatically exhibits polymorphic behavior in __CallFn__ function. At the same time the programmer which is calling the function is well aware of the fact which function should and will get called.

There is another advantage, the templates will decide the function to call. so from derived we can even call the Base function just by passing the templates
```
// Calls Derived::TestFn()
CallFn<Hierarchy::DERIVED>(bsecond);

// Calls BASE::TestFn()
CallFn<Hierarchy::BASE>(bsecond);
```
__This approach also prevents any runtime overheads which is created by virtual keyword__
