/**
 ** This file is part of BoneOS.
 **
 **   BoneOS is free software: you can redistribute it and/or modify
 **   it under the terms of the GNU General Public License as published by
 **   the Free Software Foundation, either version 3 of the License, or
 **   (at your option) any later version.

 **   BoneOS is distributed in the hope that it will be useful,
 **   but WITHOUT ANY WARRANTY; without even the implied warranty of
 **   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **   GNU General Public License for more details.

 **   You should have received a copy of the GNU General Public License
 **   along with BoneOS.  If not, see <http://www.gnu.org/licenses/>.
 **
 **/

#include "printkc.h"

/*
 * @function private @class stkl
 *		printf:
 *				prints a string to
 *              the kernel, effectively
 *              using the standard text mode
 *              loaded from BIOS(MDA) for backward
 *              compatability.
 *
 */

stkl::printkc printk;

void stkl::printkc::printf(char* str)
{	
	uint16_t* VideoMemory = (uint16_t*)0xB8000;
    uint16_t* terminal_buffer = (uint16_t*)0xB8000;
    uint8_t terminal_color = make_color(FG,BG);

	for(int32_t i=0;str[i]!='\0'; ++i)
	{
		if(str[i]=='\n')
		{
			terminal_column++;
			terminal_row=0;
		}
		else
		{
			const size_t index =  (terminal_column * VGA_WIDTH +  terminal_row);
		
			if((str[i+1]!='\0'))
			{
			   VideoMemory[index] = make_vgaentry(' ', terminal_color);
			   VideoMemory[index+1] = make_vgaentry(' ', terminal_color);
			}

  		    VideoMemory[index]= (VideoMemory[index] & 0xFF00)|str[i];
			terminal_row++;

		}
		
     }
}