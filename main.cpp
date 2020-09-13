#include "Logger.hpp"

int main( )
{
  lg::verbose( "Apparently, ", 1, " + ", 2, " = ", 1 + 2 );
  lg::info( "Ah, okay. Thank you for telling me!" );
  lg::success( "Are you really telling me it worked?" );
  lg::warning( "I guess I need to be careful now." );
  lg::error( "A wild error appeared! Luckily, it's not fatal." );

  try
  {
    lg::fatal( "Oh my god! I am panicking. I am about to throw a runtime error." );  
  }
  catch( ... )
  {
    lg::success( "Haha, caught ya!" );
  }  
}
