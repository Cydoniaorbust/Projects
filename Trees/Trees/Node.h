#pragma once

#include "Info.h"
#include <iostream>
#include <string>
#include <memory>

#define Node_ptr unique_ptr<Node>

namespace Node_nspace {
	using namespace Info_nspace;

	class Node {
	private:
		N_Info info;
		Node_ptr l;
		Node_ptr r;
	public:
		Node();
		Node(const Node & t);								/*Copy*/
		Node(Node &&t);										/*Move*/
		Node(int d, bool o, bool u, double min, int range);	/*Param*/
		~Node() {}

		inline	void		SetInfo(N_Info i)		{ info = i; }
		inline	N_Info		GetInfo() const			{ return info; }

				int			SetID(int d);
		inline	int			GetID()	const			{ return info.ID; }

				int			SetLevel(int l);
		inline	int			GetLevel() const		{ return info.Level; }

		inline	void		SetType(bool o, bool u)	{ info.Operator = o; info.Unary = u; }
		inline	bool		GetUnary() const		{ return info.Unary; }
		inline	bool		GetOperator() const		{ return info.Operator; }
		
		inline	void		SetRandInfo(double i)	{ info.RandInfo = to_string(i); }
		inline	void		SetRandInfo(string i)	{ info.RandInfo = i; }
		inline	string		GetRandInfo() const		{ return info.RandInfo; }

				Node_ptr	SetNode(int target, Node_ptr node);
				Node_ptr	GetNode(int target);

		string Print();
		double Evaluate(double x);

		void Swap(Node &t);
		Node &operator=(const Node &t);	/*Copy-assignment*/
		Node &operator=(Node &&t);		/*Move-assignment*/
	};

	namespace { Node_ptr copy_unique(const Node_ptr& t) { return t ? make_unique<Node>(*t) : nullptr; } /*Deep-copy helper*/ }
}