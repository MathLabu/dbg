/**
 *	Printer debug macro header-only library
 *
 *	Copyright (C) 2018 by Mathieu Labussiere <mathieu.labu@gmail.com>
 * 
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * @license GPL-3.0+ <http://spdx.org/licenses/GPL-3.0+>
 **/
 
#pragma once

#if defined(DBG_DEBUG_FLAG_) && DBG_DEBUG_FLAG_
	#define DBG_PRINT(...) (std::cout <<  __VA_ARGS__ << std::endl)
#else
	#define DBG_PRINT(...)
#endif

#if defined(DBG_DEBUG_FLAG_) && DBG_DEBUG_FLAG_
	#define DBG_PRINT_ERR(...) (std::cerr << "\033[1;31mERROR:\033[0m " << __VA_ARGS__ << std::endl)
#else
	#define DBG_PRINT_ERR(...)
#endif

#if defined(DBG_DEBUG_FLAG_) && DBG_DEBUG_FLAG_
	#define DBG_PRINT_WARN(...) (std::cout << "\033[4;33mWARNING:\033[0m " << __VA_ARGS__ << std::endl)
#else
	#define DBG_PRINT_WARN(...)
#endif

#if defined(DBG_DEBUG_FLAG_) && DBG_DEBUG_FLAG_
	#define DBG_PRINT_INFO(...) (std::cout << "\033[32mINFO:\033[0m " << __VA_ARGS__ << std::endl)
#else
	#define DBG_PRINT_INFO(...)
#endif
