#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Tenta20141218\bounded_vector.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTestBoundedVector)
	{
	public:
		TEST_METHOD(BoundedVectorConstructor)
		{
			bounded_vector bv1, bv2(0,3);
			
			Assert::AreEqual(bv2[0], 0);
		}
		TEST_METHOD(BoundedVectorCopyConstructor)
		{
			bounded_vector bv1(0,3), bv2(bv1);
			

			Assert::AreEqual(bv2[0], bv1[0]);
			Assert::AreEqual(bv2[3], bv1[3]);
		}
		TEST_METHOD(BoundedVectorCopyAssignment)
		{
			bounded_vector bv, bv2(0,3);
			bv=bv2;

			Assert::AreEqual(bv2[0], bv[0]);
			Assert::AreEqual(bv2[3], bv[3]);
		}
	};
}