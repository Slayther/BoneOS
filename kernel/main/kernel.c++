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

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include "../../lib/libc++/stkl/printkc/printkc.h"


/*
 * Calling all global objects
 * in order for kernel to recognize
 * all the other global objects
 *   @type constructor void();
 *   @function callConstructors();
 */
typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}



/*
 * @function kernelMain:
 *		Main function of the kernel,
 *		the function the GRUB bootloader
 *		calls when Loading the kernel.
 *
 */
extern "C" void kernelMain(void* multiboot_structure,uint32_t magicnumber)
{
   stkl::printk << "BoneOS\n";
   stkl::printk.FG = 0x4;
   stkl::printk << "---------";
   while(1);	
}

