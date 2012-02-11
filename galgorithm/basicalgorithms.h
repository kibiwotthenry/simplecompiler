// basic grammars: easy and import algorithm
//

#ifndef _BASIC_GRAMMARS_H_SC_
#define _BASIC_GRAMMARS_H_SC_

#include "grammaralgorithm.h"

#include <list>

NAMESPACE_BEGIN(compile)
NAMESPACE_BEGIN(ga)

class removenotused : public grammar_algorithm
{
	typedef kog::smart_vector<int32> vecint;
public:
	removenotused(const grammar& gin, grammar& gout)
	: grammar_algorithm("remove not used symbol and productions")
	, gin_(&gin)
	, gout_(&gout)
	{}

public:
	/* overwrite */ virtual void invoke()
	{
		(*this)(*gin_, *gout_);
	}
private:
	void operator()(const grammar& gin, grammar& gout);

	// algorithm 2.1
	void rm_notoT(const tinygrammar& tig);// remove symbols and productions can't to be a terminate symbol
	// algorithm 2.2
	void rm_Snofm(const tinygrammar& tig);// remove symbols and productions can't start from StartSymbol

	void new_grammar(const grammar& gin, grammar& gout); // create new grammmar
	
	const grammar* gin_;
	grammar* gout_;

	vecint useds;
	vecint usedp;
};

class removesingle : public grammar_algorithm
{
public:
	removesingle(const grammar& gin, grammar& gout)
	: grammar_algorithm("remove single-production")
	, gin_(&gin)
	, gout_(&gout)
	{}

public:
	/* overwrite */ virtual void invoke()
	{
		(*this)(*gin_, *gout_);
	}
private:
	// algorithm 2.6
	void operator()(const grammar& gin, grammar& gout);
	void remove_duplicate(std::list<production>& plist);

	const grammar* gin_;
	grammar* gout_;
};

class eliminate_eplison : public grammar_algorithm
{
	typedef kog::smart_vector<int32> vecint;
public:
	eliminate_eplison(const grammar& gin, grammar& gout)
	: grammar_algorithm("remove eplison")
	, gin_(&gin)
	, gout_(&gout)
	{}

public:
	/* overwrite */ virtual void invoke()
	{
		(*this)(*gin_, *gout_);
	}
private:
	void operator()(const grammar& gin, grammar& gout);

	// algorithm 2.3
	void findtoe(const tinygrammar& tig);
	// algorithm 2.4
	void rmeplison(const tinygrammar& tig, tinygrammar& tog);

	bool is_start_in_right(const tinygrammar& tig) const;
	
	void new_start_symbol(const tinygrammar& tig, tinygrammar& tog);

	vecint toe; // symbol A->..->e?
	int32 eid; // sid of eplison
	
	const grammar* gin_;
	grammar* gout_;
};

class simplegrammar : public grammar_algorithm
{
public:
	simplegrammar(const grammar& gin, grammar& gout)
	: grammar_algorithm("simplegrammar")
	, gin_(&gin)
	, gout_(&gout)
	{}

public:
	/* overwrite */ virtual void invoke()
	{
		(*this)(*gin_, *gout_);
	}
private:
	void operator()(const grammar& gin, grammar& gout);

	const grammar* gin_;
	grammar* gout_;
};
NAMESPACE_END(ga)
NAMESPACE_END(compile)

#endif
