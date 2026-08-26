#pragma once
#include "Aggregator.h"

class SumAggregator final : public StreamAggregator {
private:
public:
	SumAggregator(std::istringstream& valuesIn) :StreamAggregator(valuesIn) {
		StreamAggregator::aggregationResult = 0;
	}
	virtual void aggregate(int next) override {
		StreamAggregator::aggregate(next);
		StreamAggregator::aggregationResult += next;
	}
};