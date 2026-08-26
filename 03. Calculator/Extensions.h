#pragma once
#include <memory>
#include "DivisionOperation.h"
#include "ms.h"
#include "InputInterpreter.h"

class AdvancedInterpreter :public InputInterpreter {
private:
	std::shared_ptr <MsOperation> ms;
public:
	AdvancedInterpreter(CalculationEngine& engine) : InputInterpreter(engine), ms(new MsOperation()) {}
	virtual std::shared_ptr<Operation> getOperation(std::string operation) override {
		if (operation == "/") {
			return std::make_shared<DivisionOperation>();
		}
		else if (operation == "ms") {
			return std::make_shared<MsOperation>();
		}
		else if (operation == "mr") {
		}

		return InputInterpreter::getOperation(operation);
	}
};

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine) {
	return std::make_shared<AdvancedInterpreter>(engine);
}