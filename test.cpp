/*****************************************************************************
 * main.cpp: Simple test program
 *****************************************************************************
 * Copyright © 2015 libvlcpp authors & VideoLAN
 *
 * Authors: Hugo Beauzée-Luyssen <hugo@beauzee.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include "vlcpp/vlc.hpp"

#include <stdio.h>

#include <iostream>
#include <thread>
#include <cstring>

int main(int ac, char** av)
{
    // if (ac < 2)
    // {
    //     std::cerr << "usage: " << av[0] << " <file to play>" << std::endl;
    //     return 1;
    // }
    const char* vlcArgs = "-vv";
    auto instance = VLC::Instance(1, &vlcArgs);

    instance.addIntf("");

    char* test; 
    std::cin >> test;
    const char* c_test = test;

    printf("%s", c_test);

    return 0;
}
