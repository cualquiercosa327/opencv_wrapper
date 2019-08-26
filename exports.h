#pragma once

#ifndef EXPORTS
# if (defined _WIN32 || defined WINCE || defined __CYGWIN__)
#   define EXPORTS __declspec(dllexport)
# elif ((defined __GNUC__ && __GNUC__ >= 4) || defined(__APPLE__))
#   define EXPORTS __attribute__ ((visibility ("default")))
# endif
#endif

#ifndef EXPORTS
# define EXPORTS
#endif