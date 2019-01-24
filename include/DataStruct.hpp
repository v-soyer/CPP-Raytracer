/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Data Structure
*/

#ifndef DATASTRUCT_HPP_
	#define DATASTRUCT_HPP_

#include <cstdint>
#include "linalg.hpp"

#define WIDTH (1920)
#define HEIGHT (1080)

using vec3f_t = linalg::vec<double, 3>;

namespace Color {
	struct color {
		uint8_t r;
		uint8_t g;
		uint8_t b;
	};

	static constexpr color White {255,255,255};
	static constexpr color Black {0,0,0};
	static constexpr color Red {255,0,0};
	static constexpr color Green {0,255,0};
	static constexpr color Blue {0,0,255};
	static constexpr color Yellow {255,255,0};
	static constexpr color Cyan {0,255,255};
	static constexpr color Magenta {255,0,255};
}

#endif /* !DATASTRUCT_HPP_ */
