// StationConsole.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#ifndef WIN32
#include <sys/wait.h>
#include <sys/time.h>
#else
#include <winsock2.h>
#define strdup _strdup
#endif
#include <time.h>
#include <getopt.h>
#include <errno.h>
#include <artnet/artnet.h>