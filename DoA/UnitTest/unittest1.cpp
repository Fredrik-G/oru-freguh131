#include "stdafx.h"
#include "CppUnitTest.h"
#include "M:\Desktop\år2\DoA\DoA\Forward_List\forward_list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTestForwardList)
	{
	public:
		TEST_METHOD(TestMethodEmpty)
		{
			forward_list<int> fl;
			fl.push_front(10);
			Assert::AreEqual(false, fl.empty());

			fl.pop_front();
			Assert::AreEqual(true, fl.empty());
		}

		TEST_METHOD(TestMethodPushFront)
		{
			forward_list<int> fl;
			fl.push_front(10);
			
			Assert::AreEqual(true,false);
		}

		TEST_METHOD(TestMethodPopFront)
		{
			forward_list<int> fl;
			fl.push_front(10);
			fl.pop_front();
			fl.pop_front();

			Assert::AreEqual(true, false);
		}

	};
}