#include "Logger.hpp"

int main( )
{
  log::verbose( "Apparently, ", 1, " + ", 2, " = ", 1 + 2 );
  log::info( "Ah, okay. Thank you for telling me!" );
  log::success( "Are you really telling me it worked?" );
  log::warning( "I guess I need to be careful now." );
  log::error( "A wild error appeared! Luckily, it's not fatal." );
  log::fatal( "Oh my god!" );
  log::verbose( "Apparently, ", 1, " + ", 2, " = ", 1 + 2 );
}
