#include "stdafx.h"
#include "CppUnitTest.h"
#include "BaseApplication.h"
#include "BaseApplication.cpp"
//#include "Cube.h"
#include "Cube.cpp"
//#include "Character.h"
#include "Character.cpp"
//#include "MinecraftApplication.h"
#include "MinecraftApplication.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OgreTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(split)
		{
			std::vector<std::string> result;
			result.push_back("Cube");
			result.push_back("1");
			result.push_back("2");
			result.push_back("3");
			std::string input = "Cube:1:2:3";
			std::vector<std::string> inputResult = Cube::split(input, ':');
			Assert::AreEqual(inputResult.at(0), result.at(0));
			Assert::AreEqual(inputResult.at(1), result.at(1));
			Assert::AreEqual(inputResult.at(2), result.at(2));
			Assert::AreEqual(inputResult.at(3), result.at(3));
		}

	};
}