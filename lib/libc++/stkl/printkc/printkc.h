#ifndef _LIB_LIBCPP_STKL_PRINTKC_
#define _LIB_LIBCPP_STKL_PRINTKC_

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>

/*
 * @namespace stkl:
 *     Standard Kernel Library
 */
namespace stkl
{

   /*
    *@class printkc:
    *    Class for printing
    *    characters on the screen
    *    using 80*25 normal text mode
    *
    *        @operator<<:
    *            stream operator that allows
    *            to print characters on the
    *            screen. Simmilar usage to
    *            cout << in C++.
    */

    class printkc
    {
      public:
         printkc() = default;
         printkc(printkc const&) = delete;
         void operator=(printkc const&) = delete;
         
         printkc& operator<<(char* input)
         {
            printf(input);
            return *this;
         }

         uint8_t FG = 0x7; // FG - White
         uint8_t BG = 0x0; // BG - BLACK

      protected:
         size_t terminal_row = 0;
         size_t terminal_column = 0;
         const size_t VGA_WIDTH = 80;
         const size_t VGA_HEIGHT = 25;

      private:
         inline uint8_t make_color(uint8_t fg, uint8_t bg) const noexcept
         {
           return fg | bg << 4;
         }

         inline uint16_t make_vgaentry(char c, uint8_t color) const noexcept
         {
            uint16_t c16 = c;
            uint16_t color16 = color;
            return c16 | color16 << 8;
         }
         
         void printf(char* str);
    };

  extern "C" printkc printk;

};

#endif /*_LIB_LIBCPP_STKL_PRINTKC_*/