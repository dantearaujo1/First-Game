#ifndef UTILS_HPP
#define UTILS_HPP

#include <tuple>

namespace utils
{
	template <typename T>
	unsigned int getItemfrom2D(unsigned int row, unsigned int column, T** vetor , unsigned int width, unsigned int height)
	{
		if (row <= width && column <= height)
		{
			return vetor[row + column * width];
		}
		return -1;
	}

	std::tuple<unsigned int, unsigned int> get2Dfrom1D(unsigned int position, unsigned int width)
	{
		unsigned int x = position % width;
		unsigned int y = position / width;
		return std::tuple<unsigned int, unsigned int>(x,y);
	}
}
#endif
