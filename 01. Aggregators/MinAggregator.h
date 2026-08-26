#pragma once
#include "Aggregator.h"
#include <climits>

class MinAggregator final : public StreamAggregator {
private:
public:
	MinAggregator(std::istringstream& valuesIn) :StreamAggregator(valuesIn) {
		StreamAggregator::aggregationResult = INT_MAX;
	}
	virtual void aggregate(int next) override {
		StreamAggregator::aggregate(next);
		if (next < StreamAggregator::aggregationResult) {
			StreamAggregator::aggregationResult = next;
		}
	}
};