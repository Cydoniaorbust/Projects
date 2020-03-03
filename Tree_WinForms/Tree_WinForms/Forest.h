#pragma once

#include "Info.h"
#include "Tree.h"
#include <iostream>

namespace Forest_nspace {
	using namespace Tree_nspace;

	class Forest {
	private:
		F_Info info;
	public:
		vector<Tree> Population;
		Tree best;
#pragma region Ctor/Dtor
		Forest();
		Forest(int size, int depth, double min, int range);
#pragma endregion
#pragma region Set/Get
		inline void SetSize(int s)	{ info.Size = s; }
		inline int	GetSize() const	{ return info.Size; }
#pragma endregion
#pragma region Methods
		void CrossOver(vector<int> order);
		void TreeMutation(double probability, double min, double range);
		void BestIndivid();
		void ForestFitness(int n, vector<double> arr_x, vector<double> arr_y);
		void Print(int n, vector<double> arr_x, vector<double> arr_y);
		vector<int> Selection_Tournament(int t);
#pragma endregion
	};
}