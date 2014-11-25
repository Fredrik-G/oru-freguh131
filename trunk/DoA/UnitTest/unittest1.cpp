#include "stdafx.h"
#include "CppUnitTest.h"
//#include "M:\Desktop\år2\DoA\DoA\Forward_List\forward_list.h"
#include "forward_list.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTestForwardList)
	{
	public:
		TEST_METHOD(TestMethodEmpty)
		{
			forward_list<int> fl;
			Assert::AreEqual(true, fl.empty());

			fl.push_front(10);
			Assert::AreEqual(false, fl.empty());

		}

		TEST_METHOD(TestMethodPushFront)
		{
			forward_list<int> fl;
			fl.push_front(10);			
			Assert::AreEqual(10,fl.front());
			fl.push_front(20);
			Assert::AreEqual(20, fl.front());
			fl.push_front(30);
			Assert::AreEqual(30, fl.front());
		}

		TEST_METHOD(TestMethodPopFront)
		{
			forward_list<int> fl;
			fl.push_front(10);
			Assert::AreEqual(10, fl.front());

			fl.pop_front();
			Assert::AreEqual(true, fl.empty());
			
		}
		TEST_METHOD(TestMethodClear)
		{
			forward_list<int> fl;
			for (int i = 1; i < 15; i++)
				fl.push_front(i);			
			Assert::AreEqual(14, fl.front());

			fl.clear();
			Assert::AreEqual(true, fl.empty());
		}
		TEST_METHOD(TestMethodBeginEnd)
		{
			forward_list<int> fl;
			for (int i = 1; i < 15; i++)
				fl.push_front(i);

			int n = 14;
			for(auto it = fl.begin(); it != fl.end(); it++)
				Assert::AreEqual(n--, it->value);
			//Testar 14,13,12 osv
		}
		TEST_METHOD(TestMethodSwap)
		{
			forward_list<int> fl1, fl2;
			fl1.push_front(10);
			fl1.push_front(20);
			Assert::AreEqual(false, fl1.empty());
			Assert::AreEqual(true, fl2.empty());

			fl2.swap(fl1);
			Assert::AreEqual(true, fl1.empty());
			Assert::AreEqual(false, fl2.empty());
			Assert::AreEqual(20, fl2.front());
		}
		TEST_METHOD(TestListInsertAfter)
		{
			forward_list<int> fl;
			fl.push_front(1);
			fl.push_front(2);
			fl.push_front(99);
			for (auto it = fl.begin(); it != fl.end(); it++)
			{
				if (it->value == 99)
				{//Lägger in värdet 3 efter 99
					fl.insert_after(it, 3);
				}
			}
			Assert::AreEqual(99, fl.front());
			fl.pop_front();
			Assert::AreEqual(3, fl.front());
			fl.pop_front();
			Assert::AreEqual(2, fl.front());
		}
		TEST_METHOD(TestListEraseAfter)
		{
			forward_list<int> fl;
			fl.push_front(1);
			fl.push_front(2);
			fl.push_front(99);
			for (auto it = fl.begin(); it != fl.end(); it++)
			{
				if (it->value == 99)
				{//Tar bort värdet efter 99
					fl.erase_after(it);
				}
			}
			Assert::AreEqual(99, fl.front());
			fl.pop_front();
			Assert::AreEqual(1, fl.front());
			fl.pop_front();
			Assert::AreEqual(true, fl.empty());
		}
		TEST_METHOD(TestListCopyConstructor)
		{
			forward_list<int> fl1;
			for (int i = 1; i < 15; i++)
				fl1.push_front(i);

			Assert::AreEqual(14, fl1.front());


			forward_list<int> fl4(fl1);
		}
		TEST_METHOD(TestListCopyAssignment)
		{
			forward_list<char> flc1, flc2;
			flc1.push_front('A');
			flc1.push_front('B');
			flc2.push_front('C');

			flc2 = flc1;
			Assert::AreEqual('B', flc2.front());
			flc2.pop_front();
			Assert::AreEqual('A', flc2.front());
		}
	};
}