#include "Logger.hpp"

#include <iostream>
#include <chrono>

#if defined( _WIN32 ) || defined( _WIN64 )
  #include <window.h>
#elif defined( unix ) || defined( __unix ) || defined( __unix__ )
#else
  #error "Operating system not supported by logger."
#endif

namespace LOGGER_NAMESPACE
{
  const bool capsLock = LOGGER_MESSAGE_TYPE_CAPS_LOCK;
  const bool align = LOGGER_ALIGN_MESSAGES;
  const bool insertSpace = LOGGER_INSERT_SPACE_AFTER_MESSAGE_TYPE;
  const bool throwError = LOGGER_THROW_RUNTIME_ERROR_FOR_FATAL_ERROR;

  std::string applyColor( Color color )
  {
    std::string colorMessage;

    switch ( color )
    {
      case Color::eWhite:
        colorMessage = "\033[37m";
      break;

      case Color::eGreen:
        colorMessage = "\033[32m";
      break;

      case Color::eYellow:
        colorMessage = "\033[33m";
      break;

      case Color::eRed:
        colorMessage = "\033[31m";
      break;
    }

    return colorMessage;
  }

  std::string getTime( )
  {
    auto date = std::chrono::system_clock::now( );
    
    std::time_t tt = std::chrono::system_clock::to_time_t ( date );
    std::string time = std::ctime( &tt );
    // Remove the line break inserted by ctime.
    time = time.substr( 0, time.size( ) - 1 );

    std::string result = "[" + time + "] ";

    return result;
  }

  std::string formatMessageType( MessageType messageType )
  {
    std::string result;

    switch ( messageType )
    {
      case MessageType::eVerbose:
        capsLock ? result = "VERBOSE" : result = "Verbose"; 
        break;      

      case MessageType::eInfo:
        capsLock ? result = "INFO" : result = "Info"; 
        if ( align ) result += "   ";
        break;

      case MessageType::eWarn:
        capsLock ? result = "WARNING" : result = "Warning"; 
        break;

      case MessageType::eSuccess:
        capsLock ? result = "SUCCESS" : result = "Success"; 
        break;

      case MessageType::eError:
        capsLock ? result = "ERROR" : result = "Error"; 
        if ( align ) result += "  ";
        break;

      case MessageType::eFatal:          
        capsLock ? result = "FATAL" : result = "Fatal"; 
        if ( align ) result += "  ";
        break;
    }

    if ( insertSpace )
      result += " ";

    return result;
  }

  void print( Color color, MessageType messageType, const std::string& message )
  {
    std::stringstream res;
    res << applyColor( color ) 
        << formatMessageType( messageType ) 
        << getTime( ) 
        << message 
        << applyColor( Color::eWhite );

    if ( messageType == MessageType::eFatal)
      std::cerr << res.str( ) << std::endl;

    else if ( messageType == MessageType::eVerbose )
      std::clog << res.str( ) << std::endl;

    else
      std::cout << res.str( ) << std::endl;       
  }

  void info( const char* message )
  {
    info( std::string( message ) );
  }

  void info( const std::string& message )
  {
    print( Color::eWhite, MessageType::eInfo, message );
  }

  void success( const char* message )
  {
    success( std::string( message ) );
  }

  void success( const std::string& message )
  {
    print( Color::eGreen, MessageType::eSuccess, message );
  }

  void warning( const char* message )
  {
    warning( std::string( message ) );
  }

  void warning( const std::string& message )
  {
    print( Color::eYellow, MessageType::eWarn, message );
  }

  void error( const char* message )
  {
    error( std::string( message ) );
  }

  void error( const std::string& message )
  {
    print( Color::eRed, MessageType::eError, message );
  }

  void fatal( const char* message )
  {
    fatal( std::string( message ) );
  }

  void fatal( const std::string& message )
  {
    print( Color::eRed, MessageType::eFatal, message );
    
    if ( throwError ) throw std::runtime_error( message );
  }
}
