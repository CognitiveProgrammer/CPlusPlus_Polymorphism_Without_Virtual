/*
NoVirtual_BoilerPlate.cpp

MIT License

Copyright (c) 2016 github.com/9lean & www.9lean.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
using namespace std;

// The Tag
enum class Hierarchy {
    BASE,
    DERIVED
};

// Base Class
template<Hierarchy tag>
class Base {
public:
    void TestFn() { cout<<"Base Fn..."<<endl; }
};
// Derived class : Using Specialized Templates
template <>
class Base<Hierarchy::DERIVED> : public Base<Hierarchy::BASE>{
public:
    void TestFn() { cout<<"Derived Fn..."<<endl; }
};

// Functions
template<Hierarchy hr>
void CallFn(shared_ptr<Base<hr>> BCall) {
    BCall->TestFn();
}

int main() {
    
    // Base Class Instance
    shared_ptr<Base<Hierarchy::BASE>> bfirst = make_shared<Base<Hierarchy::BASE>>();
    
    // Derived Class Instance. Remember its not assigned to Base Class
    shared_ptr<Base<Hierarchy::DERIVED>> bsecond = make_shared<Base<Hierarchy::DERIVED>>();
    
    // Calling the Function
    CallFn(bfirst);
    CallFn(bsecond);
    
}

