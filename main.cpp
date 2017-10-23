/**
 * Author: Nikolaus Mayer, 2015 (mayern@cs.uni-freiburg.de)
 *
 * Print the current terminal size and listen to "window size
 * changed" signals
 */

/// System/STL
#include <iostream>
#include <chrono>
#include <csignal>      // signal, sig_atomic_t
#include <stdio.h>
#include <thread>
/// Local files
#include "TerminalSize.h"

volatile sig_atomic_t signal_atom = 0;


void handle_SIGWINCH( int signum )
{
  (void)signum;
  signal_atom = 1;
}

int main ( int argc, char **argv )
{
  (void)argc;
  (void)argv;
  signal( SIGWINCH, &handle_SIGWINCH );

  unsigned int w;
  unsigned int h;

  GetTerminalSize(w, h);
  std::cout << h << " lines, "
    << w << " colums."
    << std::endl;

  for (;;) {
    if ( signal_atom != 0 ) {
      signal_atom = 0;
      GetTerminalSize(w, h);
      std::cout << h << " lines, "
        << w << " colums."
        << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }

  /// Bye!
  return 0;
}

