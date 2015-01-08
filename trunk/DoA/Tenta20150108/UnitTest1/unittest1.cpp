#include "stdafx.h"
#include <string>
#include "CppUnitTest.h"
#include "..\Tenta20150108\circular_list.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(CircularList)
	{
	public:
		
		TEST_METHOD(CircularListAdd)
		{
			circular_list cl1;
			Assert::AreEqual(cl1.empty(), true);
			cl1.add("kalle");
			Assert::AreEqual(cl1.empty(), false);
		}
		TEST_METHOD(CircularListRemove)
		{
			circular_list cl1;
			cl1.add("kalle");
			cl1.add("abc");
			string asd = "abc";

			Assert::AreEqual(asd, cl1.front());

			cl1.remove();
			asd = "kalle";
			Assert::AreEqual(asd, cl1.front());

		}
		TEST_METHOD(CircularListCount)
		{
			circular_list cl;
			for (int i = 0; i < 15; i++)
			{
				string asd = static_cast<ostringstream*>(&(ostringstream() << i))->str();
				cl.add(asd);
			}

			Assert::AreEqual(15, cl.count());

		}
		//TEST_METHOD(CircularListCopyConstructor)
		//{
		//	circular_list cl1;
		//	cl1.add("kalle");
		//	cl1.add("abc");
		//	circular_list cl2(cl1);

		//	Assert::AreEqual(cl1.empty(), false);
		//	Assert::AreEqual(cl2.empty(), false);
		//}

		TEST_METHOD(TestListeginIteratorEnd)
		{
			circular_list cl;
			for (int i = 1; i < 15; i++)
			{
				string asd = static_cast<ostringstream*>(&(ostringstream() << i))->str();
				cl.add(asd);
			}
			int n = 14;
			for (auto it = cl.begin(); it != cl.end(); it++)
			{
				string asd = static_cast<ostringstream*>(&(ostringstream() << n--))->str();
				Assert::AreEqual(asd, it->value);
			}
			//Testar 14,13,12 osv
		}
	};
}