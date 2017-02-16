#include <iostream>
#include <string>
#include <list>

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>

// Full POSIX does not exist in MinGW/MSYS
//#include <netinet/in.h>

#include "CBasicMath.hpp"

using namespace CppUnit;
using namespace std;

//--------------------------------------------------------------------------------
// Our test class
class TestBasicMath : public CppUnit::TestFixture{
    CPPUNIT_TEST_SUITE(TestBasicMath);
    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST(testMultiply);
    CPPUNIT_TEST_SUITE_END();
    
public:
    void setUp(void);
    void tearDown(void);
    
protected:
    void testAddition(void);
    void testMultiply(void);
    
private:
    CBasicMath *mTestObj;
};
//--------------------------------------------------------------------------------
void TestBasicMath::testAddition(void){
    CPPUNIT_ASSERT(5 == mTestObj->Addition(2,3));
}

void TestBasicMath::testMultiply(void){
    CPPUNIT_ASSERT(6 == mTestObj->Multiply(2,3));
}

void TestBasicMath::setUp(void){
    mTestObj = new CBasicMath();
}

void TestBasicMath::tearDown(void){
    delete mTestObj;
}

//--------------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestBasicMath );

int main(){
    cout << "Goblins WON !!!" << endl;
    
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testResult;
    
    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedResults;
    testResult.addListener(& collectedResults);
    
    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testResult.addListener(&progress);
    
    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testRunner;
    testRunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    testRunner.run(testResult);
    
    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compilerOutputter(&collectedResults, cerr);
    compilerOutputter.write();
    
    // output results in XML
    ofstream xmlFileOut("cppTestBasicMathResults.xml");
    XmlOutputter xmlOut(&collectedResults, xmlFileOut);
    xmlOut.write();
    
    return collectedResults.wasSuccessful() ? 0 : 1;
}
