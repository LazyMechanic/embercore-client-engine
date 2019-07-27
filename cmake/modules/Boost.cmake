if (DEFINED Boost_SHARED_LIBS AND "${Boost_SHARED_LIBS}")
    set(BUILD_SHARED_LIBS 1)
endif()

find_package(Boost COMPONENTS system program_options REQUIRED)

if (NOT ${Boost_FOUND})
    message(FATAL_ERROR "Boost couldn't be located")
endif()

set(BOOST_LIBRARIES_IN
        Boost::system
        Boost::program_options)