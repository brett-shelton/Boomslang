
#ifndef DIE_H_INCLUDED
#define DIE_H_INCLUDED

/*
    (c) 2016 Isaac Shelton

    This file is part of Boomslang.

    Boomslang is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Boomslang is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Boomslang. If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <stdlib.h>

#define die(a) {std::cerr << a << std::endl; exit(1);}
#define fail(a) {std::cerr << a << std::endl; error_count++;}

extern unsigned int error_count;

#endif // DIE_H_INCLUDED
