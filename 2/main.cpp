#include <iostream>

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>

using namespace std;

//--------------------------------------------------------------------
class Complex { 
  friend bool operator ==(const Complex& a, const Complex& b);
  friend Complex operator +(const Complex& a, const Complex& b);
  double real, imaginary;
public:
  Complex( double r, double i = 0 ) : real(r), imaginary(i) {}
};

bool operator ==( const Complex &a, const Complex &b )
{ 
  return a.real == b.real  &&  a.imaginary == b.imaginary; 
}

Complex operator +( const Complex &a, const Complex &b )
{ 
  return Complex(a.real + b.real, a.imaginary + b.imaginary); 
}

//--------------------------------------------------------------------

class ComplexNumberTest : public CppUnit::TestFixture { 
    CPPUNIT_TEST_SUITE(ComplexNumberTest);
    CPPUNIT_TEST(testEquality);
    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST_SUITE_END();

private:
    Complex *m_10_1, *m_1_1, *m_11_2;
public:
    void setUp(){
        m_10_1 = new Complex(10, 1);
        m_1_1 = new Complex(1, 1);
        m_11_2 = new Complex(11, 2);
    }
    
    void tearDown(){
        delete m_10_1;
        delete m_1_1;
        delete m_11_2;
    }
    
    void testEquality(){
        CPPUNIT_ASSERT(*m_10_1 == *m_10_1);
        CPPUNIT_ASSERT( !(*m_10_1 == *m_11_2) );
    }
    
    void testAddition(){
        CPPUNIT_ASSERT(*m_10_1 + *m_1_1 == *m_11_2);
    }
    
};

//--------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION(ComplexNumberTest);

int main(){
    cout << "Brianna the Beautiful !!!" << endl; 
    
    CppUnit::TextTestRunner runner;
    runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
    
    
    return runner.run();
}