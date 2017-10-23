
/**
 * Author: Nikolaus Mayer, 2015 (mayern@cs.uni-freiburg.de)
 *
 * Get the current terminal display size in characters/lines
 */

#ifndef TERMINALSIZE_H__
#define TERMINALSIZE_H__


/// System/STL
#include <sys/ioctl.h>    // ioctl
#include <unistd.h>       // STDOUT_FILENO



/**
 * Read out the terminal emulators display size in columns/rows
 *
 * @param w Terminal width in characters (output parameter)
 * @param h Terminal height in lines (output parameter)
 */
void GetTerminalSize( unsigned int& w, 
                      unsigned int& h 
                    )
{
  struct winsize ws;
  ioctl( STDOUT_FILENO, TIOCGWINSZ, &ws );
  w = ws.ws_col;
  h = ws.ws_row;
}



#endif  // TERMINALSIZE_H__

