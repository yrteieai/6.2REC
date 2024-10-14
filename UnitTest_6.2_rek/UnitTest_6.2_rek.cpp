#include "pch.h"
#include "CppUnitTest.h"
#include "../6.2.rek/6.2.rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62rek
{
	TEST_CLASS(UnitTest62rek)
	{
	public:

		TEST_METHOD(TestCreate)
		{
			const int n = 5;
			int a[n];
			int Low = -10;
			int High = 10;

			Create(a, n, Low, High, 0);

			for (int i = 0; i < n; i++) {
				Assert::IsTrue(a[i] >= Low && a[i] <= High);
			}
		}

		TEST_METHOD(TestSumOddIndices)
		{
			int a1[5] = { -4, 1, -8, 0, -9 }; // ³νδεκρθ 1 ³ 3
			int result1 = SumOddIndices(a1, 5, 1);
			Assert::AreEqual(1, result1); 

			int a2[6] = { 2, 3, 4, 5, 6, 7 }; // ³νδεκρθ 1, 3 ³ 5
			int result2 = SumOddIndices(a2, 6, 1);
			Assert::AreEqual(15, result2);
		}

		TEST_METHOD(TestModifyArray)
		{
			int a1[5] = { -4, 1, -8, 0, -9 };
			bool isModified1 = ModifyArray(a1, 5, 0);
			Assert::IsTrue(isModified1);
			Assert::AreEqual(0, a1[1]);
			Assert::AreEqual(0, a1[4]);

			int a2[4] = { -2, 4, -6, 8 };
			bool isModified2 = ModifyArray(a2, 4, 0);
			Assert::IsFalse(isModified2);
		}
	};
}
