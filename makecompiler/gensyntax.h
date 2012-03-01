// gensyntax.h : grammar -> syntax cpp files
//

#ifndef _GENSYNTAX_H_SC_
#define _GENSYNTAX_H_SC_

#include <macros.h>
#include <basic_types.h>
#include <ostream>

#include "grammar.h"

NAMESPACE_BEGIN(compile)

class syntaxgenerator
{
public:
	syntaxgenerator();
	virtual ~syntaxgenerator();
public:
	void operator()(const grammar* aGrammar, const tstring& outfile);
private:
	void print_grammar();
	void print_symbols();
	void print_statemachines();
	void print_includes();
	void print_separators();
	void print_keywords();
	void print_printablechars();
	void print_machine(std::ostream& os, const compile::automachine& mac);
private:
	void regex_str_to_machine(const std::string& regexstr, automachine& m);
	void refine_machine(automachine& m) const;
	bool is_token_keyword(const tchar* name) const;
public:
	const grammar* syntax_;
	tstring cppfile_;
	std::ostream* cppstream_;
};

NAMESPACE_END(compile)
#endif

