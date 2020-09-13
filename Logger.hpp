#ifndef LOGGER_HPP
#define LOGGER_HPP

// A very simple logger written in C++.
// Include this header to your project, but do not forget to compile the source file. 
// C++17 is required.

#include <sstream>

#define LOGGER_NAMESPACE log

#define LOGGER_MESSAGE_TYPE_CAPS_LOCK false
#define LOGGER_ALIGN_MESSAGES true
#define LOGGER_INSERT_SPACE_AFTER_MESSAGE_TYPE true
#define LOGGER_THROW_RUNTIME_ERROR_FOR_FATAL_ERROR false

namespace LOGGER_NAMESPACE
{
  enum class Color
  {
    eGray,
    eWhite,
    eGreen,
    eYellow,
    eRed
  };

  enum class MessageType
  {
    eVerbose,
    eInfo,
    eWarn,
    eSuccess,
    eError,
    eFatal
  };

  void print( Color color, MessageType messageType, const std::string& message );

  template <typename ...Args>
  void verbose( Args&& ...args )
  {
    std::stringstream temp;
    ( temp << ... << args );

    print( Color::eGray, MessageType::eVerbose, temp.str( ) );
  }

  template <typename ...Args>
  void info( Args&& ...args )
  {
    std::stringstream temp;
    ( temp << ... << args );

    print( Color::eWhite, MessageType::eInfo, temp.str( ) );
  }

  template <typename ...Args>
  void success( Args&& ...args )
  {
    std::stringstream temp;
    ( temp << ... << args );

    print( Color::eGreen, MessageType::eSuccess, temp.str( ) );
  }

  template <typename ...Args>
  void warning( Args&& ...args )
  {
    std::stringstream temp;
    ( temp << ... << args );

    print( Color::eYellow, MessageType::eWarn, temp.str( ) );
  }

  template <typename ...Args>
  void error( Args&& ...args )
  {
    std::stringstream temp;
    ( temp << ... << args );

    print( Color::eRed, MessageType::eError, temp.str( ) );
  }

  template <typename ...Args>
  void fatal( Args&& ...args )
  {
    std::stringstream temp;
    ( temp << ... << args );

    print( Color::eRed, MessageType::eFatal, temp.str( ) );
  }
}

#endif // LOGGER_HPP