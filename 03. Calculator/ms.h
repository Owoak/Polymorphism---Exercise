#pragma once
#include "Operation.h"
#include <stack>
class MsOperation : public Operation {
private:
	std::stack<int> saved;
public:
	virtual int getResult() override {
		return saved.top();
	}
	virtual bool isCompleted() override {
		saved.push(getResult());
	}
};