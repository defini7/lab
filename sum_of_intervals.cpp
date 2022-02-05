#include <vector>
#include <utility>
#include <set>

int sum_intervals(std::vector<std::pair<int, int>> intervals) 
{
	std::set<int> out;
	for (const auto i : intervals)
	{
		for (int j = i.first; j < i.second; j++)
			out.insert(j);
	}

	return out.size();
}
