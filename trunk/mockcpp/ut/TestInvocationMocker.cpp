
#include <cppunit/extensions/HelperMacros.h>
#include <InvocationMocker.h>
#include <Invocation.h>
#include <Namespace.h>
#include <InvocationMockBuilder.h>
#include <ChainingMockHelper.h>
#include <Any.h>
#include <InvokedTimesRecorder.h>

using namespace mockcpp;


class TestInvocationMocker : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( TestInvocationMocker );
	CPPUNIT_TEST( testShouldReturnSettedStubWhenCallingInvoke );
	CPPUNIT_TEST( testShouldSetInvokedStateAfterItsInvoked );
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp() { }
	void tearDown() { }

	/////////////////////////////////////////////////////////

	void testShouldReturnSettedStubWhenCallingInvoke()
	{
		InvocationMocker mocker(0);
      Invocation inv;

      mocker.setStub(returnValue(10));

		CPPUNIT_ASSERT(10 == any_cast<int>(mocker.invoke(inv)));
	}

   void testShouldSetInvokedStateAfterItsInvoked()
   {
		InvocationMocker mocker(0);
      Invocation inv;

		CPPUNIT_ASSERT(!mocker.hasBeenInvoked());
		mocker.invoke(inv);
		CPPUNIT_ASSERT(mocker.hasBeenInvoked());
   }

};

CPPUNIT_TEST_SUITE_REGISTRATION( TestInvocationMocker );