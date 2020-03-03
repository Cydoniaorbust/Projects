#pragma once

#include <string>
#include <vector>

/// randoms number with a floating point(4 digits precision) from "min" to "min + range"
#define RANGE_RAND(min, range) min + rand() % range + rand() % 10001 / 10000.
/// a to b ratio randomisation*
#define RATIO(a, b) rand() % (a + b) < b ? 0 : 1 

namespace Info_nspace {
	using namespace std;

	namespace {
		string UnaryOperations[] = { "sin", "cos", "sqr", "sqrt", "ln", "exp" };
		string BinaryOperations[] = { "+", "-", "*", "/" };
		string GiveRandOper(bool unary) { return unary ? UnaryOperations[rand() % 2] : BinaryOperations[rand() % 4]; }
		//int Ratio(int a, int b) { return rand() % (a + b) < b ? 0 : 1; } 
	}

	struct N_Info {
		int ID = NULL;
		int Level = NULL;
		bool Unary = false;
		bool Operator = false;
		string RandInfo = "";
	};
	struct T_Info {
		int Depth = NULL;
		int LastNode = NULL;
		double Fitness = NULL;
	};
	struct F_Info {
		int Size = NULL;
	};
}