#pragma once
#include "Aggregator.h"

class AverageAggregator final : public StreamAggregator {
private:
	int currentSum;
public:
	AverageAggregator(std::istringstream& valuesIn) :StreamAggregator(valuesIn), currentSum(0) {
		StreamAggregator::aggregationResult = 0;
	}

	virtual void aggregate(int next) {
		StreamAggregator::aggregate(next);
		currentSum += next;
		StreamAggregator::aggregationResult = currentSum / StreamAggregator::getNumAggregated();
	}
};