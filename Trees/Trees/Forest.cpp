#include "Forest.h"

namespace Forest_nspace {
#pragma region Ctor/Dtor
	Forest::Forest() : 
		Population(0), 
		best(0) {}
	Forest::Forest(int size, int depth, double min, int range) {
		info.Size = size;
		Population.resize(info.Size);
		for (int i = 0; i < info.Size; i++) Population[i] = Tree(depth, min, range);
	}
#pragma endregion
#pragma region Methods
	void Forest::CrossOver(vector<int> order) { /*Standart*/
		vector<Tree> temp(0);
		int first_node = 0, second_node;
		for (int i = 0; i < GetSize(); i++) {
			int &first = order[i * 2];
			int &second = order[i * 2 + 1];
			do {
				 first_node = rand() % (Population[first].GetLastNode() + 1);
				 second_node = rand() % (Population[second].GetLastNode() + 1);
			} while (first_node == 0 || second_node == 0 );
			
			Tree Oak = Population[first];
			Tree Pine = Population[second];

			Node_ptr tmp1 = move(Oak.GetNode(first_node));
			Node_ptr tmp2 = move(Pine.GetNode(second_node));
			Oak.SetNode(first_node, move(tmp2));
			Pine.SetNode(second_node, move(tmp1));

			if (rand() % 2 == 0) {
				Oak.UpdateInfo();
				temp.push_back(Oak);
			}
			else {
				Pine.UpdateInfo();
				temp.push_back(Pine);
			}
		}

		Population = temp;
	}
	void Forest::TreeMutation(double probability, double min, double range) {
		for (int i = 0; i < GetSize(); i++) {
			if (RANGE_RAND(0, 1) < probability) {
				int random_node = rand() % (Population[i].GetLastNode() + 1);
				int sub_tree_depth = Population[i].GetNode(random_node)->SetLevel(0);

				Node_ptr Branch;
				if (sub_tree_depth < 1) Branch.reset(new Node(0, 0, RATIO(1, 1), min, range));
				else Branch.reset(new Node(sub_tree_depth - 1, RATIO(9, 1), RATIO(1, 9), min, range));

				Population[i].SetNode(random_node, move(Branch));
				Population[i].UpdateInfo();
			}
		}
	}
	void Forest::Print(int n, vector<double> arr_x, vector<double> arr_y) {
		for (int i = 0; i < info.Size; i++) Population[i].Fitness(100, arr_x, arr_y);
	}
	void Forest::ForestFitness(int n, vector<double> arr_x, vector<double> arr_y) {
		for (int i = 0; i < info.Size; i++)
			Population[i].Fitness(n, arr_x, arr_y);
		BestIndivid();
	}
	void Forest:: BestIndivid() {
		double best_fit = 0;
		int best_num = 0;
		for (int j = 0; j < GetSize(); j++)
			if (Population[j].GetFitness() > best_fit) {
				best_fit = Population[j].GetFitness();
				best_num = j;
			}
		best = Population[best_num];
	}
	vector<int> Forest::Selection_Tournament(int t){
		vector<int>m;
		vector<int> numbers;
		numbers.resize(GetSize() * 2);
		m.resize(t);
		int   k, best_individ = 0;
		bool a;
		double best_f;
		for (int o = 0; o < GetSize() * 2; o++) {
			for (int i = 0; i < t; i++) {
				do {
					a = 0;
					k = rand() % (info.Size);
					m[i] = k;
					for (int j = 0; j != i; j++)
						if (m[i] == m[j])
							a = 1;
				} while (a == 1);
			}
			best_f = 0;
			for (int i = 0; i < t; i++) {
				if (Population[m[i]].GetFitness() > best_f) {
					best_f = Population[m[i]].GetFitness();
					best_individ = m[i];
				}
			}
			numbers[o] = best_individ;
		}return numbers;
	}
#pragma endregion
}