// statemachine.h: state machine
//

#ifndef _STATE_MACHINE_H_SC_
#define _STATE_MACHINE_H_SC_

#include "automachine.h"

NAMESPACE_BEGIN(compile)

class state_machine : public automachine
{
public:
	state_machine();
	state_machine(const shared_sheet& asheet);
	virtual ~state_machine();
public:
	/* overwrite */ virtual void init();
	/* overwrite */ virtual bool eta(int meta);
//public:
//	class sheetrow : public automachine::sheetrow
//	{
//	public:
//		
//	};
public:
	MEMBER_VARIABLE_GET_SET(tstring, str, str_);
public:
	// param@regexstr: easy regex string
	// param@m: result machine
	// 	regex 
	// 		any char .
	//		zero more *
	//		one more +
	//		braces () []
	//		or |
	//		inv \
	//
//	static state_machine& construct_fromstring(const tstring& regexstr, state_machine& m);
public:
	void swap(state_machine& other)
	{
		if(this == &other) return;
		((automachine*)this)->swap(other);
		str_.swap(other.str_);
	}
private:
	tstring str_;
};

NAMESPACE_END(compile)
#endif
